//
// Bicycle.cpp
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// application includes
#include "Bicycle.h"

// c++ library includes
//		for std::cout
#include <iostream>

// constructor
Bicycle::Bicycle( std::string NewMake, std::string NewModel, std::string NewGearing )
// use the constructor list to
//		initialize the parent class and
//		data members
	: Vehicle( NewMake, NewModel ),
	  Gearing( NewGearing )
{

}

// destructor
Bicycle::~Bicycle()
{

}

// print the bike information
void Bicycle::Print()
{
	// output the make and model
	Vehicle::Print();

	// output the gearing
	std::cout<<"Gearing: "<<Gearing<<std::endl;

	// return finished
	return;
}

