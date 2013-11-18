/*---------------------------------------------------------------------------
John Stelben
Jon Runkel
10/13/2013
Vertex.cpp
----------------------------------------------------------------------------*/
#pragma once
#include "Vertex.h"
#include <iostream>

//Makes Vertex with given X and Y values
template <typename T>
Vertex<T>::Vertex(T X1, T Y1)
{
	X = X1;
	Y = Y1;
	Occupied = false;
	Parent = nullptr;
	Gvalue = 0;
	Hvalue = 0;
	FValue = 0;
}

//Deconstructor
template <typename T>
Vertex<T>::~Vertex(void)
{
}

//Copy Constructor
template <typename T>
Vertex<T>::Vertex(Vertex<T> &v)
{
	X = v.X;
	Y = v.Y;
	Occupied = v.Occupied;
}

//Copy Assignment Operator
template <typename T>
Vertex<T> Vertex<T>::operator=(Vertex<T> v)
{
	Vertex nv(v);
	return nv;
}

//Prints Vertex's X and Y values.
template <typename T>
void Vertex<T>::Print()
{
	std::cout << "X: " << X << " Y: " << Y << std::endl;
}