/*---------------------------------------------------------------------------
John Stelben
Jon Runkel
10/13/2013
NodeList.cpp
----------------------------------------------------------------------------*/
#pragma once
#include "NodeList.h"
#include <stdlib.h>

//Constructor
//Initializes the Size to 0.
NodeList::NodeList(void)
{
	Size = 0;
}

//Deconstructor
NodeList::~NodeList(void)
{

}

//Adds a Vertex to the end of the list.
void NodeList::Add(Vertex<int>* node)
{
	Size++;
	//If the List is empty, allocate memory and add first node.
	if(Size == 1)
	{
		Nodes = (Vertex<int>**) malloc(sizeof(Vertex<int>*));
		Nodes[0] = node;
	}
	else
	{
		//Create Temporary list with increased size, set List to Temporary, and add Node to empty, end slot.
		Vertex<int> ** temp = (Vertex<int>**) malloc(sizeof(Vertex<int>) * Size);
		for(int i = 0; i < Size - 1; i++)
		{
			temp[i] = Nodes[i];
		}
		temp[Size - 1] = node;
		free(Nodes);
		Nodes =  (Vertex<int>**) malloc(sizeof(Vertex<int>) * Size);
		for(int i = 0; i < Size; i++)
		{
			Nodes[i] = temp[i];
		}
		free(temp);
	}
}

//Removes desired Node from List
void NodeList::Remove(Vertex<int>* node)
{
	//Get Index of Node
	int index;
	for(int i = 0; i < Size; i++)
	{
		if(Nodes[i] == node)
		{
			index = i;
		}
	}
	//Make every value starting at Index = to the one next to it
	for(int i = index; i < Size; i++)
	{
		Nodes[i] = Nodes[i+1];
	}
	Size--;
	//Create Temporary List = to List so List's memory can be freed and reallocated.  Finally, set List = Temporary
	Vertex<int> ** temp = (Vertex<int>**) malloc(sizeof(Vertex<int>) * Size);
	for(int i = 0; i < Size; i++)
	{
		temp[i] = Nodes[i];
	}
	free(Nodes);
	Nodes =  (Vertex<int>**) malloc(sizeof(Vertex<int>) * Size);
	for(int i = 0; i < Size; i++)
	{
		Nodes[i] = temp[i];
	}
	free(temp);

}

//Print every Vertex in List
void NodeList::Print(void)
{
	for(int i = 0; i < Size; i++)
	{
		Nodes[i]->Print();
	}
}

//Checks coords of parent Vertex, if it's diagonal add 14 to the G Value, else add 10.
//Value are taken from A* guide
//http://www.policyalmanac.org/games/aStarTutorial.htm
void NodeList::CalculateGValues(void)
{
	for(int i = 0; i < Size; i++)
	{
		if(Nodes[i]->X == Nodes[i]->Parent->X || Nodes[i]->Y == Nodes[i]->Parent->Y)
		{
			Nodes[i]->Gvalue = 10 + Nodes[i]->Parent->Gvalue;
		}
		else
		{
			Nodes[i]->Gvalue = 14 + Nodes[i]->Parent->Gvalue;
		}
	}
}

//Calculate H Values by multiplying location difference with Goal by 10.
void NodeList::CalculateHValues(Vertex<int> * node)
{
	for(int i = 0; i < Size; i++)
	{

		int xDiff = abs(node->X - Nodes[i]->X);
		int yDiff = abs(node->Y - Nodes[i]->Y);
		Nodes[i]->Hvalue = 10 * (xDiff + yDiff);
	}
}

//Calculate F Values by adding G Values and H Values for each Vertex
void NodeList::CalculateFValues(Vertex<int> * node)
{
	CalculateGValues();
	CalculateHValues(node);
	for(int i = 0; i < Size; i++)
	{
		if(Nodes[i]->FValue == 0)
		{
			Nodes[i]->FValue = Nodes[i]->Gvalue + Nodes[i]->Hvalue;
		}
	}
}

//Find the Vertex with the lowest F Value
//Return the pointer to this Vertex
Vertex<int>* NodeList::GetLowestFValue()
{
	int low = Nodes[Size - 1]->FValue;
	int lowIndex = Size - 1;
	for(int i = Size - 1; i > -1; i--)
	{
		if(Nodes[i]->FValue < low)
		{
			lowIndex = i;
			low = Nodes[i]->FValue;
		}
	}
	return Nodes[lowIndex];
}

//Check if the List contains the Vertex
//Returns true or false
bool NodeList::Contains(Vertex<int> * node)
{
	for(int i = 0; i < Size; i++)
	{
		if(Nodes[i] == node)
		{
			return true;
		}
	}
	return false;
}

//Reverses the Nodes in the List
//Used so it can print the opposite way.
void NodeList::Reverse(void)
{
	Vertex<int> ** temp = (Vertex<int>**) malloc(sizeof(Vertex<int>) * Size);
	for(int i = 0; i < Size; i++)
	{
		temp[i] = Nodes[Size - 1 - i];
	}
	free(Nodes);
	Nodes =  (Vertex<int>**) malloc(sizeof(Vertex<int>) * Size);
	for(int i = 0; i < Size; i++)
	{
		Nodes[i] = temp[i];
	}
	free(temp);
}
