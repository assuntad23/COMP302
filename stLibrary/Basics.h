/*
 * Basics.h
 *
 *  Created on: Nov 2, 2017
 *      Author: adesanto
 */

#ifndef BASICS_H_
#define BASICS_H_
#include <vector>

class Basics {
public:
	Basics();
	virtual ~Basics();
	void TemplateExample();
	void STLExample();
	void IteratorExample();
	void NewFeatures();
private:
    std::vector<int>IntVector;
    double GetRandom();
};
#endif /* BASICS_H_ */
