/*
 * Overloading.cpp
 *
 *  Created on: Nov 7, 2017
 *      Author: adesanto
 */

#include "Matrix1.h"
#include <iostream>

int main(int argc, char **argv) {

	//using constructor with 2 ints
	Matrix example(5,5);

	example.Print();

	//array to populate matrix below
	int     Array[12] = { 1, 2, 3, 4 , 21, 22, 23, 24, 7, 6, 5, 4 };

	//using constructor with 3 ints
	Matrix secondExample(3,4,Array);
	//printin matrix
	secondExample.Print();
	//printing just row 2
	secondExample.Print(2);

	//new line to separate from multiplication
	std::cout<<std::endl;

	//using scalar multiplication method
	Matrix	Matrix1 = secondExample.ScalarMultiplication( 3 );
	Matrix1.Print();


	//multiplying matrix by 4.5
	Matrix  Matrix2 = 4.5 * secondExample;
	Matrix2.Print();

	//multiplying by 10.1
	Matrix  Matrix3 = secondExample * 10.1;
	Matrix3.Print();


	return 0;
}

