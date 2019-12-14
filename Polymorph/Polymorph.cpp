/*
 * Polymorph.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: Assunta
 */

#include "Automobile.h"
#include "Bicycle.h"
#include "Vehicle.h"
#include "Boat.h"
#include <iostream>
#include <memory>

int main(int argc, char **argv) {

	 Vehicle	*MyVehicle	=	new Automobile( "Chevy", "Impala", "Sedan" );

	 MyVehicle->Print();
	 std::cout<<std::endl;

	 delete MyVehicle;

	 Automobile	MyOtherCar( "Ford", "F-150", "Truck" );
	 Vehicle		Test = MyOtherCar;

	 Test.Print();
	 std::cout<<std::endl;

	 std::shared_ptr	MyThirdCar( new Automobile( "Madza", "Miata", "Roadster" ) );

	 MyThirdCar.Print();


	return (0);
}


