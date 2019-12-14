/*
 * EditingAndCounting.h
 *
 *  Created on: Nov 12, 2017
 *      Author: Assunta
 */

#ifndef EDITINGANDCOUNTING_H_
#define EDITINGANDCOUNTING_H_
#include <map>
#include <string>


class EditingAndCounting {
public:
	EditingAndCounting();
	virtual ~EditingAndCounting();
	std::map<std::string, int> countUniqueWords(std::ifstream userInputFile);
};


#endif /* EDITINGANDCOUNTING_H_ */
