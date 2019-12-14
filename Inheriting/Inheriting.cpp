/*
 * Inheriting.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: Assunta
 */

#include "Faculty.h"
#include "Student.h"
#include "Base.h"
#include <iostream>

int main(int argc, char **argv) {

	//Base Application;
	//Application.LogOpen();


	//had trouble creating an instance of this class, because of the pure virtual method.
	//I had to comment the method call out, because classes with 1 pure virtual method
	//are abstract classes and can't be instantiated.


	// create a teacher
	Faculty     Teacher( "Dr.", "Fred", "Flinstone", "Akeley", 345 );

	// create a student
	Student     TeachersPet( "Jane", "Doe", 60.0, 3.75 );

	// print the faculty and student
	std::cout << "Type: " << Teacher.GetType() << std::endl;
	Teacher.Print();
	std::cout << "Type: " << TeachersPet.GetType() << std::endl;
	TeachersPet.Print();

	//Application.LogClose();

	return 0;
}


