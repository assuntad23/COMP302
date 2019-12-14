/*
 * Student.cpp
 *
 *  Created on: Apr 6, 2013
 *      Author: phuegler
 */

// application includes
#include "Student.h"

// c++ library includes
//		for std::cout
#include <iostream>


// constructor
Student::Student( std::string NewFirstName, std::string NewLastName, double NewCreditsEarned, double NewGPA )
	// using parent class for first and last name variables
	:	Person( NewFirstName, NewLastName ),
		CreditsEarned( NewCreditsEarned ),
		GPA( NewGPA )
{
	LogMessages( "In STUDENT constructor." );
}


// destructor
Student::~Student()
{

}

// print method
void Student::Print()
{
    // print the name
    Person::Print();
    std::cout<<"   Credits Earned: "<<CreditsEarned<<std::endl;
    std::cout<<"   GPA: "<<GPA<<std::endl;

    // return finished
    return;
}

std::string Student::GetType()
{
    // return student
    return( "Student" );
}
