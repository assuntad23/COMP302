/*
 * Preprocessor.c
 *
 *  Created on: Sep 21, 2017
 *      Author: Assunta
 */

#include <stdio.h>
// this works like a constant. It will set the value of PI to 3.14159265 everywhere it is used in the program.
#define PI 3.14159265
//defining the macro here will make it easier to use the formula.  It's like a mini-function
#define AreaCircle( r ) ( PI * r * r )
#define Debug

int main(int argc, char **argv) {


	//computing the area of a circle
	int     Radius;

	printf( "Enter a radius: " );
	scanf( "%d", &Radius );

	//if Debug is defined above, it will run this code.
	#ifdef Debug
    	printf( "The radius entered was %d\n", Radius );
	#endif


	//using the macros here cleans up the code.
	double Area = AreaCircle(Radius);

	printf( "\nThe Area is: %f\n", Area );


	return (0);
}

