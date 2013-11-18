/*---------------------------------------------------------------------------
John Stelben
Jon Runkel
10/13/2013
Grid.cpp
----------------------------------------------------------------------------*/
#pragma once
#include "Grid.h"
#include <stdlib.h>
#include "Vertex.cpp"
#include "NodeList.h"

//Lists of Nodes
NodeList Open;
NodeList Closed;
NodeList Path;

//Allocates memory for the grid.  
Grid::Grid(void)
{
	Map = (Vertex<int>***) malloc(sizeof(Vertex<int>*) * SIZE);
	for(int i = 0; i < SIZE; i++)
	{
		Map[i] = (Vertex<int>**) malloc(sizeof(Vertex<int>) * SIZE);
	}
}

//Frees memory reserved for members
Grid::~Grid(void)
{
	free(Map);
	free(Player);
	free(Goal);
}

//Makes Node Lists. Fills grid with Vertices.  Sets Player, Goal, and Walls on map.
void Grid::Initialize(void)
{
	Open = NodeList();
	Closed = NodeList();
	Path = NodeList();
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			Map[i][j] = new Vertex<int>(i,j);
		}
	}
	Player = new Vertex<int>(5,5);
	Goal = Map[9][5];
	Map[7][4]->Occupied = true;
	Map[7][5]->Occupied = true;
	Map[7][6]->Occupied = true;
}

//Find path of Vertices from Player to Goal and Prints the list.
void Grid::FindPath(void)
{
	SetUpSearch();
	ContinueSearch();
	MakePath();
	Path.Print();
}

//Creates the Path list once the Goal was found
void Grid::MakePath(void)
{
	//Starting with Goal, adds it and each parent into the list.
	Vertex<int> * currentNode = Goal;
	while(currentNode->Parent != nullptr)
	{
		Path.Add(currentNode);
		currentNode = currentNode->Parent;
	}
	Path.Add(currentNode);
	//Reverse the List so it does not print backwards
	Path.Reverse();
}

//Recursive Method.  Used to find shortest path to the Goal
void Grid::ContinueSearch(void)
{
	//Get lowest F Value Vertex and Close it.
	Vertex<int>* v = Open.GetLowestFValue();
	Open.Remove(v);
	Closed.Add(v);
	//Looking at all Adjacent Vertices to V.
	for(int i = -1; i < 2; i++)
	{
		for(int j = -1; j < 2; j++)
		{
			//If this Vertex is not Closed or Occupied
			if(!Closed.Contains(Map[v->X + i][v->Y + j]) && !Map[v->X + i][v->Y + j]->Occupied)
			{
				//If the Vertex is not already Open
				if(!Open.Contains(Map[v->X + i][v->Y + j]))
				{
					//Sets the Vertex's parent to V, make it Open, and calculate its F Value
					Map[v->X + i][v->Y + j]->Parent = v;
					Open.Add(Map[v->X + i][v->Y + j]);
					Map[v->X + i][v->Y + j]->Gvalue = GetTheoreticalGValue(v, Map[v->X + i][v->Y + j]);
					int xDiff = abs(Goal->X - Map[v->X + i][v->Y + j]->X);
					int yDiff = abs(Goal->Y - Map[v->X + i][v->Y + j]->Y);
					Map[v->X + i][v->Y + j]->Hvalue = 10 * (xDiff + yDiff);
					Map[v->X + i][v->Y + j]->FValue = Map[v->X + i][v->Y + j]->Gvalue + Map[v->X + i][v->Y + j]->Hvalue;
				}
				else
				{
					//If the G Value for the Vertex would be lower if V was its parent, make V its parent and update the F Value
					if(Map[v->X + i][v->Y + j]->Gvalue > GetTheoreticalGValue(v, Map[v->X + i][v->Y + j]))
					{
						Map[v->X + i][v->Y + j]->Parent = v;
						Map[v->X + i][v->Y + j]->Gvalue = GetTheoreticalGValue(v, Map[v->X + i][v->Y + j]);
						Map[v->X + i][v->Y + j]->FValue = Map[v->X + i][v->Y + j]->Gvalue + Map[v->X + i][v->Y + j]->Hvalue;
					}
				}
			}
		}
	}
	//When Goal is found, or there are no more Open Vertices
	if(Open.Contains(Goal) || Open.Size == 0)
	{
		return;
	}
	//If Goal is not found, call this Method again.
	else
	{
		ContinueSearch();
	}
}

//Takes two Vertices and calculates a theoretical G Value between them
//Returns the G Value
int Grid::GetTheoreticalGValue(Vertex<int> * parent, Vertex<int> * child)
{
	if(child->X == parent->X || child->Y == parent->Parent->Y)
		{
			return 10 + parent->Gvalue;
		}
		else
		{
			return 14 + parent->Gvalue;
		}
}

//Sets up the Open List starting from Player
void Grid::SetUpSearch()
{
	Map[Player->X][Player->Y]->Gvalue = 0;
	Open.Add(Map[Player->X][Player->Y]);
	Map[Player->X+1][Player->Y]->Parent = Map[Player->X][Player->Y];
	Open.Add(Map[Player->X+1][Player->Y]);
	Map[Player->X+1][Player->Y+1]->Parent = Map[Player->X][Player->Y];
	Open.Add(Map[Player->X+1][Player->Y+1]);
	Map[Player->X][Player->Y+1]->Parent = Map[Player->X][Player->Y];
	Open.Add(Map[Player->X][Player->Y+1]);
	Map[Player->X-1][Player->Y+1]->Parent = Map[Player->X][Player->Y];
	Open.Add(Map[Player->X-1][Player->Y+1]);
	Map[Player->X-1][Player->Y]->Parent = Map[Player->X][Player->Y];
	Open.Add(Map[Player->X-1][Player->Y]);
	Map[Player->X-1][Player->Y-1]->Parent = Map[Player->X][Player->Y];
	Open.Add(Map[Player->X-1][Player->Y-1]);
	Map[Player->X][Player->Y-1]->Parent = Map[Player->X][Player->Y];
	Open.Add(Map[Player->X][Player->Y-1]);
	Map[Player->X+1][Player->Y-1]->Parent = Map[Player->X][Player->Y];
	Open.Add(Map[Player->X+1][Player->Y-1]);
	Open.Remove(Map[Player->X][Player->Y]);
	Open.CalculateFValues(Goal);
	Closed.Add(Map[Player->X][Player->Y]);
}

void Grid::Reset()
{

}