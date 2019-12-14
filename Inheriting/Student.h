/*
 * Student.h
 *
 *  Created on: Apr 6, 2013
 *      Author: phuegler
 */

#ifndef STUDENT_H_
#define STUDENT_H_


#include "Person.h"

// student class : indicates inheritance
class Student: public Person {
	// data members
	private:
		double	CreditsEarned;
		double	GPA;

	// constructors and destructor
	public:
		Student( std::string NewFirstName, std::string NewLastName, double CreditsEarned, double GPA );
		virtual ~Student();
		virtual std::string GetType();

	// methods
	public:
		void Print();
};

#endif /* STUDENT_H_ */
