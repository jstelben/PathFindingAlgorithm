/*---------------------------------------------------------------------------
John Stelben
Jon Runkel
10/13/2013
Grid.h
----------------------------------------------------------------------------*/
#ifndef GRID_H
#define GRID_H
#include "Vertex.cpp"

//Size of the grid.  Set it to 30 for the console window.
#define SIZE 30

class Grid
{
public:
	//Members
	Vertex<int>*** Map;
	Vertex<int> * Player;
	Vertex<int> * Goal;

	//Methods
	Grid(void);
	~Grid(void);
	void Initialize(void);
	void FindPath(void);
	void SetUpSearch(void);
	void ContinueSearch(void);
	void MakePath(void);
	int GetTheoreticalGValue(Vertex<int>*, Vertex<int>*);
	void Reset();
};
#endif
