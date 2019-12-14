//
// Automobile.h
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// only include the definition once
#ifndef AUTOMOBILE_H_
#define AUTOMOBILE_H_

// application includes
#include "Vehicle.h"

// class definition
//		inherits from Vehicle
class Automobile : public Vehicle
{
	// data members
	private:
		// style - sedan, roadster, suv, etc.
		std::string		Style;

	// constructors and destructors
	public:
		// constructor
		Automobile( std::string NewMake, std::string NewModel, std::string NewStyle );

		// destructor
		virtual ~Automobile();

	// public methods
	public:
		// print the car information
		void Print();
};

#endif /* AUTOMOBILE_H_ */
