/*
 * Fibonacci.c
 *
 *  Created on: Sep 17, 2017
 *      Author: Assunta
 */

#include <stdio.h>

int BuildFibonacci(){

	//setting up file to Output to
	FILE *FibonacciNumbers;
	FibonacciNumbers = fopen( "FibonacciNumbers.txt", "w" );
	// Ensure file was opened for writing
	if ( NULL == FibonacciNumbers )
	{
	    printf( "File not opened\n" );
	    return( 1 );
	}

	//taking user input for numberOfNumbers
	printf( "How many Fibonacci Numbers do you want? \n" );
	int numberOfNumbers;
	scanf( "%d", &numberOfNumbers );
	//controlling for anything less than 1
	while (numberOfNumbers < 1){
		printf( "How many Fibonacci Numbers do you want? \n" );
		scanf( "%d", &numberOfNumbers );
	}

	//taking user input for perLine
	printf( "How many per line? \n" );
	int perLine;
	scanf( "%d", &perLine );
	//controlling for anything less than 1
	while( perLine < 1){
		printf( "How many per line? \n" );
		scanf( "%d", &perLine );
	}

	//setting variables needed for fibonacci sequence
	int first = 0;
	int second = 1;
	int fibo;
	//for loop to loop through fibonacci sequence
	//starting on i = 1, so that modular division works below
	//numberOfNumbers needs to have one added to it because I'm starting on i=1
	for (int i = 1; i < (numberOfNumbers+1); i++) {
		//printing 0 is a special case
		if (i == 1)
			fprintf (FibonacciNumbers, "%d\t", first);
		//printing the first 1 is a special case
		else if (i == 2){
			fprintf(FibonacciNumbers, "%d\t", second);
			//modular division to ensure a new line is printed when the user requests it
			if (i%perLine == 0)
				fprintf (FibonacciNumbers, "\n");
		} else{
			//adding numbers
			fibo = first + second;

			//printing result
			fprintf (FibonacciNumbers, "%d\t", fibo);

			//swapping values
			first = second;
			second = fibo;
			//modular division to ensure a new line is printed when the user requests it
			if (i%perLine == 0)
				fprintf (FibonacciNumbers, "\n");
		}
	}

	fclose(FibonacciNumbers);

	return (0);
}


int main(int argc, char **argv) {

	return BuildFibonacci();

}
