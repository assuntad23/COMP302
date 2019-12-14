/*
 * Base.h
 *
 *  Created on: Nov 10, 2017
 *      Author: Assunta
 */

#ifndef BASE_H_
#define BASE_H_
#include <string>
#include <fstream>
#include <iostream>

class Base {
public:
	Base();
	virtual ~Base();
	void LogMessages( std::string Message );
	//the pure virtual method prevents me from instantiating the class
	virtual std::string GetType() = 0;
	void LogOpen();
	void LogClose();
private:
	static std::ofstream    LogFile;
};

#endif /* BASE_H_ */
