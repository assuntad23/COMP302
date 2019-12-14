//
// Bicycle.h
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// only include the definition once
#ifndef BICYCLE_H_
#define BICYCLE_H_

// application includes
#include "Vehicle.h"

// class definition
//		inherit from vehicle
class Bicycle : public Vehicle
{
	// data members
	protected:
		// gearing type
		//		10-speed, cruiser, etc.
		std::string		Gearing;

	// constructors and destructors
	public:
		// constructor
		Bicycle( std::string NewMake, std::string NewModel, std::string NewGearing );

		// destructor
		virtual ~Bicycle();

		// public methods
		public:
			// print the bike information
			void Print();
};

#endif /* BICYCLE_H_ */
