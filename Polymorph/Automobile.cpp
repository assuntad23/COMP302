//
// Automobile.cpp
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// application includes
#include "Automobile.h"

// c++ library includes
//		for std::cout
#include <iostream>

// constructor
Automobile::Automobile( std::string NewMake, std::string NewModel, std::string NewStyle )
// use the constructor list to
//		initialize the parent class and
//		data members
	: Vehicle( NewMake, NewModel ),
	  Style( NewStyle )
{

}

// destructor
Automobile::~Automobile()
{

}

// print the car information
void Automobile::Print()
{
	// output the make and model
	Vehicle::Print();

	// output the style
	std::cout<<"Style: "<<Style<<std::endl;

	// return finished
	return;
}

