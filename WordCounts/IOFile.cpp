/*
 * IOFile.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: Assunta
 */

#include "IOFile.h"
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>


IOFile::IOFile() {
	// TODO Auto-generated constructor stub

}

IOFile::~IOFile() {
	// TODO Auto-generated destructor stub
}

std::ifstream IOFile::OpeningForReading(){

	//declaring variable to hold file name
	std::string userInput;
	//ask user for file name
	std::cout<<"Enter file name with .txt extension";
	//inputting string into userInput
	std::cin>>userInput;

	// open the file for reading
	try{
		std::ifstream     userInputFile( userInput );
		return userInputFile;
	}
	catch (const std::ifstream::failure& e) {
		std::runtime_error   MyException( "Error opening file" );
		throw( MyException );
	}

}

void IOFile::OpeningAndWriting(std::map<std::string,int> WordCounts){
	//Creating & Opening File
	try{
		// Open a file to write the word count to
		std::ofstream    WordCountFile( "WordCount.txt" );
		// Iterate through the map and write each count
		for (auto elem : WordCounts){
			WordCountFile << std::setw(20) << elem.first << ": " << elem.second << std::endl;
		}

		WordCountFile.close();

	} catch (const std::ifstream::failure& e) {
		std::runtime_error   MyException( "Error opening file" );
		throw( MyException );
	}

}


