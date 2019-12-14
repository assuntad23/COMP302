/*
 * Variables.c
 *
 *  Created on: Sep 12, 2017
 *      Author: adesanto
 */

#include <stdlib.h>
#include <stdio.h>

void ArrayWork() {

	//creating an array with 25 integers
	int a[25];

	//finding out what the highest random number could be
	int max = RAND_MAX;
	printf("%d\n", max);

	//seeding the random number, changing this will change the numbers generated
	srand(7);

	//filling the array with "random" numbers
	for (int i = 0; i < 25; i++) {
		//set random number range below 10
		a[i] = rand() * 10.0 / RAND_MAX;
		printf("%d\n", a[i]);
	}

	return;
}

void ComplexDT(){

	//the structure below has three ints
	//it records a 3D point
	typedef struct
	{
	    int     x;
	    int     y;
	    int     z;
	} Point;

	//Could also be declared as testPoint.x = 1; testPoint.y = 9; etc.
	//doing it in one line is more effective and the more modern way to declare
	Point testPoint = {1,9,-4};

	//printing coordinates of testPoint
	printf( "The coordinates of the point are (%d,%d,%d)\n", testPoint.x, testPoint.y, testPoint.z );

	return;
}

void TypeCasting (){

	int     Total   =   112;
	int     Count   =   15;
	//without type casting one of the above variables as a double,
	//C will return calculated average as an Integer (7.000) which is incorrect.
	double  Average = (double) Total/Count;

	//printing the average
	printf ("The average is %f", Average);

	return;
}

int main(int argc, char **argv) {

	//calling the three functions defined above.
	ArrayWork();
	ComplexDT();
	TypeCasting();

	return (0);
}
