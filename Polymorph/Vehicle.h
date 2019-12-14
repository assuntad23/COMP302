//
// Vehicle.h
//
//	Copyright (c) 2017 Peter A. Huegler
//
//		See LICENSE for more information
//

// only include the definition once
#ifndef VEHICLE_H_
#define VEHICLE_H_

// c++ library includes
//		for std::string
#include <string>
#include <memory>

// class definition
class Vehicle
{
	// data members
	protected:
		// make and model
		std::string		Make;
		std::string		Model;

	// constructors and destructors
	public:
		// constructor
		Vehicle( std::string NewMake, std::string NewModel );

		// destructor
		virtual ~Vehicle();

	// public methods
	public:
		// print the information
		virtual void	Print();
		//
		static std::shared_ptr<Vehicle>	Create( std::string Type, std::string Model, std::string Make, std::string Attribute );

};

#endif /* VEHICLE_H_ */
