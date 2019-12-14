//
// Vehicle.cpp
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// application includes
#include "Vehicle.h"

// c++ includes
//		for std::cout
#include <iostream>

// constructor
Vehicle::Vehicle( std::string NewMake, std::string NewModel )
	// use the constructor list to
	//		initialize the data members
	:	Make( NewMake ),
		Model( NewModel )
{

}

// destructor
Vehicle::~Vehicle()
{

}

// print the information
void Vehicle::Print()
{
	// print the vehicle information
	std::cout<<"Make: "<<Make<<std::endl
			 <<"Model: "<<Model<<std::endl
			 ;

	// return finished
	return;
}

// create vehicles
std::shared_ptr Vehicle::Create( std::string Type, std::string Make, std::string Model, std::string Attribute )
{
	// initialize the return value
	//		set to nullptr
	std::shared_ptr<Vehicle<	NewVehicle	=	nullptr;

	// create a boat
	if ( "Boat" == Type )
		// use reset to set the new reference
		NewVehicle.reset( new Boat( Make, Model, Attribute ) );

	// return nothing created
	return( NewVehicle );
}
