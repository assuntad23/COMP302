/*
 * Amoritizing.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: Assunta
 */

#include "Amoritizing.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

Amoritizing::Amoritizing() {
	// TODO Auto-generated constructor stub

}

Amoritizing::~Amoritizing() {
	// TODO Auto-generated destructor stub
}

double Amoritizing::calculatePayment(double principal, double interest,
		int length) {
	double payment;
	double monthlyInterest = interest / (12.0 * 100.0);
	int numMonths = length * 12;

	payment = principal
			* (monthlyInterest
					/ (1.0 - std::pow((1.0 + monthlyInterest), -numMonths)));

	return payment;

}

void Amoritizing::printHeader() {
	std::cout << std::setw(15) << "Payment Number";
	std::cout << std::setw(15) << "Interest";
	std::cout << std::setw(15) << "Principal";
	std::cout << std::setw(15) << "Payment";
	std::cout << std::setw(15) << "Balance";
	std::cout<<std::endl;
}

void Amoritizing::printPaymentLine(int paymentNum, double interest, double principal, double payment, double balance) {
	std::cout << std::setw(15) << paymentNum;
	std::cout << std::setw(15) << std::fixed << std::setprecision(2)
			<< interest;
	std::cout << std::setw(15) << principal;
	std::cout << std::setw(15) << payment;
	std::cout << std::setw(15) << balance;
	std::cout<<std::endl;
}

void Amoritizing::SinglePayment(double principal, double interest, int length,
		int number) {
	int i = 1;
	double payment = calculatePayment(principal, interest, length);
	printHeader();
	while (principal > 0) {

		double monthlyInterest = interest / (12.0 * 100.0);
		double currentMonthlyI = principal * monthlyInterest;
		double currentMonthlyP = payment - currentMonthlyI;
		double currentBalance = principal - currentMonthlyP;

		if (i == number) {
			printPaymentLine(i, currentMonthlyI, currentMonthlyP, payment, currentBalance);
		};

		principal = currentBalance;

		i++;

	};

}
void Amoritizing::TableView(double principal, double interest, int length) {
	int i = 1;
	double payment = calculatePayment(principal, interest, length);
	printHeader();
	while (principal > 0) {

		double monthlyInterest = interest / (12.0 * 100.0);
		double currentMonthlyI = principal * monthlyInterest;
		double currentMonthlyP = payment - currentMonthlyI;
		double currentBalance = principal - currentMonthlyP;

		if (currentBalance >= 0) {
			printPaymentLine(i, currentMonthlyI, currentMonthlyP, payment, currentBalance);
		}

		principal = currentBalance;

		i++;

	};
}

