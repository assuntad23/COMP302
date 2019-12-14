//
// Boat.h
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// only include the definition once
#ifndef BOAT_H_
#define BOAT_H_

// application includes
#include "Vehicle.h"

// class definition
//		inherits from Vehicle
class Boat : public Vehicle
{
	// data members
	private:
		// motor type - inboard, outboard
		std::string		Motor;

	// constructors and destructors
	public:
		// constructor
		Boat( std::string NewMake, std::string NewModel, std::string NewMotor );

		// destructor
		virtual ~Boat();


		// public methods
		public:
			// print the boat information
			void Print();
};

#endif /* BOAT_H_ */
