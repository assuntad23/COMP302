/*
 * InputOutput.cpp
 *
 *  Created on: Oct 29, 2017
 *      Author: Assunta
 */

#include "IOTest.h"


int main(int argc, char **argv) {
	//declaring instance
	IOTest Tester;
	/*
	//calling UserInput method
	Tester.UserInput();
	*/

	//calling FileStuff method
	Tester.ReadFile();
	Tester.Manipulating();
	Tester.WriteFile();
	return (0);
}




