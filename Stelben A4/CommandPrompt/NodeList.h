/*---------------------------------------------------------------------------
John Stelben
Jon Runkel
10/13/2013
NodeList.h
----------------------------------------------------------------------------*/
#ifndef NODELIST_H
#define NODELIST_H
#include "Vertex.cpp"
class NodeList
{
public:
	//Members
	//Array of Pointers to Vertex<int>
	Vertex<int> ** Nodes;
	int Size;

	//Methods
	NodeList(void);
	~NodeList(void);
	void Add(Vertex<int>*);
	void Remove(Vertex<int>*);
	void Print(void);
	void CalculateGValues(void);
	void CalculateHValues(Vertex<int>*);
	void CalculateFValues(Vertex<int>*);
	Vertex<int>* GetLowestFValue();
	bool Contains(Vertex<int>*);
	void Reverse(void);
};
#endif