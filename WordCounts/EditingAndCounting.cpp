/*
 * EditingAndCounting.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: Assunta
 */

#include "EditingAndCounting.h"
#include "IOFile.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

EditingAndCounting::EditingAndCounting() {
	// TODO Auto-generated constructor stub

}

EditingAndCounting::~EditingAndCounting() {
	// TODO Auto-generated destructor stub
}

std::map<std::string, int> EditingAndCounting::countUniqueWords(std::ifstream userInputFile){

	//declaring vector to hold strings and ints
	std::map<std::string, int> WordCounts;

	//creating variable to hold first word
	std::string word;

	//call punctuationRemover method before going through loop
	while (userInputFile>>word){
		if (ispunct(word.at(0))) {
			// Strip punctuation at beginning
			word = word.substr(1, word.length()-1);
		}
		if (ispunct(word.at(word.length()-1))) {
			// Strip punctuation at end
			word = word.substr(0, word.length()-1);
		}
		// Increment the word count
		++WordCounts[word];

	}

	return WordCounts;
}
