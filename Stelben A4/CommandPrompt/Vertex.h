/*---------------------------------------------------------------------------
John Stelben
Jon Runkel
10/13/2013
Vertex.h
----------------------------------------------------------------------------*/
#ifndef VERTEX_H
#define VERTEX_H


template <typename T>
class Vertex
{
public:
	//Members
	Vertex<T> * Parent;
	int Gvalue;
	int Hvalue;
	int FValue;
	T X;
	T Y;
	bool Occupied;

	//Methods
	Vertex<T>(T, T);
	~Vertex(void);
	Vertex<T>(Vertex<T>&);
	Vertex<T> operator=(Vertex<T>);
	void Print();
};
#endif
