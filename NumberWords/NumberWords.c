/*
 * NumberWords.c
 *
 *  Created on: Sep 24, 2017
 *      Author: Assunta
 */

#include <stdio.h>
#include <string.h>

float InputNumber(){

	float userInput;

	//takes input from user for numbers between 0 and 999.99
	printf( "How much do you want to write the check for? \n" );
	scanf( "%f", &userInput );

	//anything less than 0 or greater than 999.99 should be controlled for
	while (userInput < 0){
		printf ("Number is negative. If they owe you money, ask them for a check!\n");
		printf( "How much do you want to write the check for? \n" );
		scanf( "%f", &userInput );
	}
	while (userInput >= 999.99){
		printf ("Check is for 1000 dollars or more. You will have to go to the bank for that.\n");
		printf( "How much do you want to write the check for? \n" );
		scanf( "%f", &userInput );
	}

	return userInput;
}

void ConvertToWords(float userInput){

	//these variables are used below
	int ones = ((int)userInput % 10);
	int hundreds = ((int)userInput / 100);

	//declaring arrays to hold number words
	//0-9 are ones places, but 10-19 are special cases. I've chosen to store them all in the firstPlace array to make it easier
	//the hundreds places are covered here as well (1-9 hundred)
	char *firstPlace[20] = {
			"Zero","One","Two","Three","Four",
			"Five","Six","Seven","Eight","Nine",
			"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
			"Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	//because firstPlace covers up to twenty, I only need to account for twenty-ninety.
	char *secondPlace[8] = { "Twenty", "Thirty", "Forty", "Fifty",
			"Sixty", "Seventy", "Eighty", "Ninety"};

	//this is the String I'm storing the finalNumber in. I will concatenate onto this in the if statements below.
	char finalNumber[120] = "";

	// 0 dollars is a special case
	if ((int)userInput == 0){
		sprintf(finalNumber, "Zero");
	} else {

		//if the number is greater than 100, it will concatenate that number and the word hundred onto finalNumber.
		//hundreds is at the beginning of this method. It is defined as (userInput/100)
		if (userInput >= 100) {
			sprintf (finalNumber, "%s", firstPlace[hundreds]);
			strcat (finalNumber, " Hundred ");
		}

		//the remainder is necessary to properly calculate what is left over after removing the hundreds place.
		int remainder = (int)userInput % 100;


		//1-19 are special cases
		if (remainder < 20){
			//creating an array to hold the ones place input
			char addingOnes[20];
			//if the remainder is less than 0, we do not need to state it
			if (remainder > 0){
				//turning them into a string
				sprintf(addingOnes, "%s", firstPlace[(int)userInput%100]);
				//concatenating the ones place to the finalNumber
				strcat(finalNumber, addingOnes);
			}
		} else {
			//to find out the tens place, we have to divide the remainder by 10
			int tens = (remainder / 10);
			//creating an array to hold the tens place input
			char addingTens[20];
			//turning them into a string
			sprintf(addingTens, "%s", secondPlace[tens-2]);
			//concatenating the tens place to the finalNumber
			strcat (finalNumber, addingTens);
			if ((remainder % 10) != 0){
				strcat (finalNumber, "-");
				//creating an array to hold the ones place input
				char addingOnes[20];
				sprintf(addingOnes, "%s", firstPlace[ones]);
				strcat (finalNumber, addingOnes);
			}
		}
	}

	// I had to use this hack to account for the rounding errors.
	char userInputAsStr[10] = "";
	sprintf(userInputAsStr, "%.2f", userInput);
	char cents[3];
	cents[0] = userInputAsStr[strlen(userInputAsStr)-2];
	cents[1] = userInputAsStr[strlen(userInputAsStr)-1];


	//concatenating dollars and cents/100
	strcat(finalNumber, " Dollars and ");
	strcat(finalNumber, cents);
	strcat(finalNumber, "/100");
	//printing finalNumber
	printf (finalNumber);


	return;
}


int main(int argc, char **argv) {

	float userInput = InputNumber();

	ConvertToWords(userInput);

	return (0);
}
