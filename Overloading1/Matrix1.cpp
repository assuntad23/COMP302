/*
 * Matrix.cpp
 *
 *  Created on: Nov 7, 2017
 *      Author: adesanto
 */

#include "Matrix1.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

// constructor
Matrix::Matrix(int NewRowCount, int NewColumnCount)
// c++ way of initializing data members
//		by calling their constructors
:
		RowCount(NewRowCount), ColumnCount(NewColumnCount) {
	// resize the vectors and initialize to zeros
	Data.resize(RowCount, std::vector<double>(ColumnCount, 0.0));
}

Matrix::~Matrix() {
	// TODO Auto-generated destructor stub
}

// print the matrix
void Matrix::Print() {
	for (std::vector<double> Row : Data) {
		for (double Element : Row)
			std::cout << std::setw(10) << Element;
		std::cout << std::endl;
	}

	return;
}

//matrix that take data as an argument
Matrix::Matrix(int NewRowCount, int NewColumnCount, int NewData[])
// c++ way of initializing data members
//		by calling their constructors
:
		RowCount(NewRowCount), ColumnCount(NewColumnCount) {
	// resize the vectors and initialize to zeros
	Data.resize(RowCount, std::vector<double>(ColumnCount, 0.0));
	int k = 0;
	//loop to initialize data
	for (int i = 0; i < RowCount; i++)
		for (int j = 0; j < ColumnCount; j++) {
			Data[i][j] = NewData[k];
			k++;
		}
}

//overloading print with an int argument
void Matrix::Print(int Row) {
	//making sure row falls within bounds
	if (Row >= RowCount) {
		throw std::runtime_error("Row does not exist!");
	} else if (Row < 0) {
		throw std::runtime_error("Can't have negative rows!");
	}

	//looping through elements in row and printing them
	for (double Element : Data[Row])
		std::cout << std::setw(10) << Element;

}

// scalar multiplication
Matrix Matrix::ScalarMultiplication( double Scalar ) const
{
	// this method doesn't change the existing
	//		matrix. it creates a new one to
	//		store the results. the new matrix
	//		is returned from the method.

	// create a new matrix to
	//		hold the product
	Matrix	Product( RowCount, ColumnCount );

	// update the product matrix
	//		with the scalar multiplication
	//		results
	for (int i=0; i<RowCount; i++ )
		for( int j=0; j<ColumnCount; j++ )
			Product.Data[i][j] = Scalar * Data[i][j];

	// return
	return( Product );
}

//method Dr. Huegler provided to override the *operator
Matrix operator * ( const double &LHS, const Matrix &RHS )
{
	return( RHS.ScalarMultiplication( LHS ) );
}

//this method mirrors the method above, but switches the two arguments so that the override will work commutatively
Matrix operator * (const Matrix &RHS, const double &LHS )
{
	return( RHS.ScalarMultiplication( LHS ) );
}
