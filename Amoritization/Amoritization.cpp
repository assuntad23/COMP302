/*
 * Amoritization.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: Assunta
 */

#include "Amoritizing.h"
#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char **argv) {
	//creating instance

	Amoritizing myLoan;

	//declaring variables
	double principal;
	double interest;
	int length;
	int option;
	int number;
	//taking user input for principal
	std::cout << "Enter the principal:";
	std::cin >> principal;
	if (principal <= 0) {
		std::cout<<"Principal must be greater than 0";
		return 1;
	}

	//taking the user input for interest
	std::cout << "Enter the interest (in decimal format):";
	std::cin >> interest;
	interest = interest * 100.0;


	//making sure interest is valid
	if (interest > 100){
		std::cout<<"Interest cannot be greater than 100";
		return 1;
	}
	else if (interest < 0){
		std::cout<<"Interest cannot be less than 100";
		return 1;
	}

	//taking user interest for years
	std::cout << "Enter the length in years:";
	std::cin >> length;
	if (length <= 0) {
		std::cout<<"Length of loan must be greater than 0";
		return 1;
	}

	//taking user interest for option
	std::cout << "Enter a 1 for a table; 2 for a single payment:";
	std::cin >> option;

	if (option == 1){
		myLoan.TableView(principal, interest, length);
	}
	else if (option ==2){
		std::cout << "Enter the payment number:";
		std::cin >> number;
		myLoan.SinglePayment(principal,interest,length,number);

	}
	else{
		std::cout<<"You have entered and invalid option.";
		return 1;
	}

	return 0;
}

