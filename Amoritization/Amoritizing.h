/*
 * Amoritizing.h
 *
 *  Created on: Nov 5, 2017
 *      Author: Assunta
 */

#ifndef AMORITIZING_H_
#define AMORITIZING_H_

#include <string>

class Amoritizing {
public:
	Amoritizing();
	virtual ~Amoritizing();
	double calculatePayment(double principal, double interest, int length);
	void printHeader();
	void printPaymentLine(int paymentNum, double interest, double principal, double payment, double balance);
	void SinglePayment(double principal, double interest, int length, int number);
	void TableView(double principal, double interest, int length);
};

#endif /* AMORITIZING_H_ */
