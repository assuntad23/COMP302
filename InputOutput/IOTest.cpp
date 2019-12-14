/*
 * IOTest.cpp
 *
 *  Created on: Oct 29, 2017
 *      Author: Assunta
 */

#include "IOTest.h"
#include <iostream>
#include <fstream>
#include <iomanip>

IOTest::IOTest() {
	// TODO Auto-generated constructor stub

}

IOTest::~IOTest() {
	// TODO Auto-generated destructor stub
}

// test input and output
void IOTest::UserInput()
{
	int UserNumber;
	//output message
	std::cout<<"Enter a number:";
	//input number
	std::cin>>UserNumber;


	std::cout<<"The user entered ";
	std::cout<<UserNumber<<std::endl;

    // return finished
    return;
}

void IOTest::ReadFile(){
	// open the file for reading
	std::ifstream     InFile( "TestFile.txt" );
	// declaring variables
	int RowCount;
	int ColumnCount;

	// reading row count and column count
	InFile>>RowCount;
	InFile>>ColumnCount;

	//for loop adds new line after each row
	for (int i = 0; i < RowCount; i++) {
		// for loop prints number in file and a tab
		for (int i = 0; i < ColumnCount; i++){
			float numbers;
			InFile>>numbers;
			std::cout<<std::setw(15)<<std::fixed<<std::setprecision(7)<<(float)numbers;
		}
		std::cout<<""<<std::endl;

	}
	// closing file
	InFile.close();
}

void IOTest::Manipulating(){
	// declare and initialize some variables
	float   Float1 = 3.14159265;
	int     Integer1 = 42;

	// output the variables
	//setw sets # of characters; setprecision sets # after decimal place
	std::cout<<std::setw(15)<<std::fixed<<std::setprecision(7)<<Float1;
	std::cout<<std::setw(15)<<std::fixed<<std::setprecision(7)<<(float)Integer1;
	std::cout<<std::endl;
	//std::left sets left just; std::right sets right just
	std::cout<<std::setw(10)<<std::left<<"***"<<std::endl;
	std::cout<<std::setw(10)<<std::right<<"***"<<std::endl;

}

void IOTest::WriteFile(){
	//Creating & Opening File
	std::ofstream    OutFile( "OutputFile.txt" );

	//writing message
	OutFile<<"Now is the time for all good men to come to the aid of their country."<<std::endl;

	//writing message with value
	float   MyValue = 1.61803398875;
	OutFile<<"The golden ratio is about: "
	       <<std::setw(10)<<std::fixed<<std::setprecision(4)<<MyValue
	       <<std::endl
	       ;

	//closing file
	OutFile.close();
}
