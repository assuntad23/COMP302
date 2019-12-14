/*
 * ListDouble.cpp
 *
 *  Created on: Mar 31, 2013
 *      Author: phuegler
 */

// application includes
#include "ListDouble.h"

// c++ library includes
//		for runtime_error exception
#include <stdexcept>

// constructor
ListDouble::ListDouble()
{

}

// destructor
ListDouble::~ListDouble()
{

}

// set an item
void ListDouble::SetItem( int Index, double Value )
{
	// check for a valid index
	if (( Index < 0 ) || ( Index > 9 ))
		// throw an exception
		throw( std::runtime_error( "Invalid index used - must be between 0 and 9" ));

	// set the item
	Numbers[Index]	=	Value;

	// return finished
	return;
}

// get an item
double ListDouble::GetItem( int Index )
{
	// check for a valid index
	if ( Index > 9 )
		// throw an error
		throw( "Index Error" );

	// return the item
	return( Numbers[Index] );
}

