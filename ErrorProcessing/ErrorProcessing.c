/*
 * ErrorProcessing.c
 *
 *  Created on: Sep 21, 2017
 *      Author: Assunta
 */

#include <stdio.h>
//this will allow the program access to the error code numbers
#include <errno.h>
//we need to include this in order to use strerror
#include <string.h>

int main(int argc, char **argv) {

	//this loop loops through error numbers and messages and prints the first 50 of them to the console.
	for (int i = 1; i <= 50; i ++){
		printf ("Error Number %d : %s\n", i, strerror( i ));
	}

	//test Opening a file for reading
	FILE *TestFile;
	TestFile = fopen( "/etc/shadow.txt", "w" );
	//the file does not exist, so it should print an error and return the error number
	if ( NULL == TestFile )
	{
		printf( "File not opened - error: %d\n", errno );
		//this converts the error number to a string which identifies what went wrong without having to look it up.
		printf( "%s\n", strerror( errno ) );
	    return( 1 );
	}

	return (0);
}

