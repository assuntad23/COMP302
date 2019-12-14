/*
 * Faculty.cpp
 *
 *  Created on: Apr 6, 2013
 *      Author: phuegler
 */

// including header file
#include "Faculty.h"

//for output
#include <iostream>


// constructor
Faculty::Faculty( std::string NewSalutation, std::string NewFirstName, std::string NewLastName, std::string NewOfficeBuilding, int NewOfficeNumber )
	// initialize using a constructor list
	:	Salutation( NewSalutation ),
		// using parent class for first and last name variables
		Person( NewFirstName, NewLastName ),
		OfficeBuilding( NewOfficeBuilding ),
		OfficeNumber( NewOfficeNumber )
{
	LogMessages( "In FACULTY constructor." );
}

// destructor
Faculty::~Faculty()
{

}

// print method
void Faculty::Print()
{
	// ouput the name
	std::cout<<"Name: "<<Salutation<<" "<<LastName<<", "<<FirstName<<std::endl;
	std::cout<<"   Office: "<<OfficeNumber<<" "<<OfficeBuilding<<std::endl;

	// return finished
	return;
}

std::string Faculty::GetType()
{
    // return student
    return( "Faculty" );
}
