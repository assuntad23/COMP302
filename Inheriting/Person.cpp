/*
 * Person.cpp
 *
 *  Created on: Nov 10, 2017
 *      Author: Assunta
 */

#include "Person.h"
#include <string>
#include <iostream>

Person::Person(std::string NewFirstName, std::string NewLastName)
	//constructor list
	:	FirstName( NewFirstName ),
		LastName( NewLastName )
{
	LogMessages( "In PERSON constructor." );
}

Person::~Person() {
	// TODO Auto-generated destructor stub
}

// print a person's name
void Person::Print()
{
    // ouput the name
    std::cout<<"Name: "<<LastName<<", "<<FirstName<<std::endl;

    // return finshed
    return;
}
