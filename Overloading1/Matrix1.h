/*
 * Matrix.h
 *
 *  Created on: Nov 7, 2017
 *      Author: adesanto
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include <vector>

class Matrix {
public:
	Matrix( int NewRowCount, int NewColumnCount);
	virtual ~Matrix();
	void Print();
	Matrix( int NewRowCount, int NewColumnCount, int NewData[] );
	void Print(int Row);
	Matrix ScalarMultiplication(double Scalar) const;
private:
	int RowCount;
	int ColumnCount;
	std::vector<std::vector<double>> Data;
};
//need to put this here to overload the * operator
Matrix operator * ( const double &LHS, const Matrix &RHS );
Matrix operator * (const Matrix &RHS, const double &LHS);

#endif /* MATRIX_H_ */
