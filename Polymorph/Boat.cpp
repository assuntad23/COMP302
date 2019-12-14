//
// Boat.cpp
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// application includes
#include "Boat.h"

// c++ library includes
//		for std::cout
#include <iostream>

// constructor
Boat::Boat( std::string NewMake, std::string NewModel, std::string NewMotor )
// use the constructor list to
//		initialize the parent class and
//		data members
	: Vehicle( NewMake, NewModel ),
	  Motor( NewMotor )
{

}

// destructor
Boat::~Boat()
{

}

// print the boat information
void Boat::Print()
{
	// output the make and model
	Vehicle::Print();

	// output the motor
	std::cout<<"Motor: "<<Motor<<std::endl;

	// return finished
	return;
}

