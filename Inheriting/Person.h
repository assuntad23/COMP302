/*
 * Person.h
 *
 *  Created on: Nov 10, 2017
 *      Author: Assunta
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include "Base.h"

class Person : public Base{
public:
	Person(std::string NewFirstName, std::string NewLastName);
	virtual ~Person();
	void Print();
protected:
    std::string  FirstName;
    std::string  LastName;
};

#endif /* PERSON_H_ */
