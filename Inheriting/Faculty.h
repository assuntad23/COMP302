/*
 * Faculty.h
 *
 *  Created on: Apr 6, 2013
 *      Author: phuegler
 */

#ifndef FACULTY_H_
#define FACULTY_H_


#include "Person.h"

// faculty class
class Faculty: public Person {
	// data members
	private:
		std::string		Salutation;
		std::string		OfficeBuilding;
		int		OfficeNumber;

	// constructors and destructor
	public:
		Faculty( std::string NewSalutation, std::string NewFirstName, std::string NewLastName, std::string NewOfficeBuilding, int NewOfficeNumber );
		virtual ~Faculty();
		virtual std::string GetType();

	// methods
	public:
		void Print();
};

#endif /* FACULTY_H_ */
