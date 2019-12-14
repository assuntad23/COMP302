/*
 * WordCounts.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: Assunta
 */
#include <map>
#include <string>
#include "IOFile.h"
#include "EditingAndCounting.h"
#include <fstream>

int main(int argc, char **argv) {

	//creating instances of each class
	IOFile newFile;
	EditingAndCounting changingFile;

	//checks if a file exists and opens it for reading,
	// then counts the words in the file
	std::map<std::string, int> V = changingFile.countUniqueWords(newFile.OpeningForReading());

	// Writes the word count to a new file
	newFile.OpeningAndWriting(V);

	return 0;
}


