/*
 * Basics.cpp
 *
 *  Created on: Nov 2, 2017
 *      Author: adesanto
 */

#include "Basics.h"
#include <string>
#include "List.h"
#include <vector>
#include <iostream>
#include <map>
#include <cstdlib>

Basics::Basics() {
	// TODO Auto-generated constructor stub

}

Basics::~Basics() {
	// TODO Auto-generated destructor stub
}

void Basics::TemplateExample(){

	//declaring list
	List<int>          IntegerList;
	List<std::string>  StringList;


	//setting item values
	IntegerList.SetItem( 1, -4 );
	IntegerList.SetItem( 2, 45 );
	StringList.SetItem( 4, "Hello" );
	StringList.SetItem( 5, "World" );

	//testing get item method
	std::cout<<"Integer 1: "<<IntegerList.GetItem(1)<<std::endl
	         <<"Integer 2: "<<IntegerList.GetItem(2)<<std::endl;

}

void Basics::STLExample(){
	//adding items to vector
	std::cout<<"Add some items"<<std::endl;
	for( int i=0; i<10; i++ )
	    IntVector.push_back( i + 3 );

	//printing out contents
	std::cout<<"Current vector contents"<<std::endl;
	for( unsigned int i=0; i<IntVector.size(); i++ )
	    std::cout<<"   "<<i<<" - "<<IntVector[i]<<std::endl;

	//adding more items
	std::cout<<"Adding 5 more items"<<std::endl;
	for( int i=10; i<15; i++ )
	    IntVector.push_back( i + 3 );

	//printing them out
	std::cout<<"Printing out all contents"<<std::endl;
	for( unsigned int i=0; i<IntVector.size(); i++ )
	    std::cout<<"   "<<i<<" - "<<IntVector[i]<<std::endl;

	//creating map
	std::map<std::string,std::string>       MyMap;

	//inserting items into map
	MyMap.insert( std::pair<std::string,std::string> ( "Hello", "World" ) );
	MyMap.insert( std::pair<std::string,std::string> ( "Elvis", "Lives" ) );

	//giving keys should print out values (World and Lives)
	std::cout<<"Hello: "<<MyMap["Hello"]<<std::endl;
	std::cout<<"Elvis: "<<MyMap["Elvis"]<<std::endl;

}


void Basics::IteratorExample(){
	//declaring iterator
	std::vector<int>::iterator     Current;

	//declaring iterators for beginning and end of vector
	std::vector<int>::iterator     Beginning   =   IntVector.begin();
	std::vector<int>::iterator     End         =   IntVector.end();

	//using a for loop to loop through elements
	std::cout<<"Current contents of the vector using iterators"<<std::endl;
	for( Current=Beginning; Current<End; Current++ )
	    std::cout<<"   "<<Current-Beginning<<" - "<<(*Current)<<std::endl;

	//inserting two elements
	IntVector.insert( IntVector.begin() + 3, 33 );
	IntVector.insert( IntVector.begin() + 9, 33 );

	//erasing two elements
	IntVector.erase( IntVector.begin() + 5 );
	IntVector.erase( IntVector.begin() + 5 );

	//need to redeclare beginning and ending of vectors since new elements were added
	Beginning   =   IntVector.begin();
	End         =   IntVector.end();

	//reprinting
	std::cout<<"Printing contents of vector after adding & removing elements"<<std::endl;
	for( Current=Beginning; Current<End; Current++ )
		    std::cout<<"   "<<Current-Beginning<<" - "<<(*Current)<<std::endl;

}

double Basics::GetRandom(){
	// return a random number
    //      between 0 and 10
    return( 100.0 * std::rand() / RAND_MAX );
}

void Basics::NewFeatures(){
	//getting two random numbers
	//since we used auto we don't need to change variable type here
	auto r1 = GetRandom();
	std::cout<<r1<<std::endl;
	auto r2 = GetRandom();
	std::cout<<r2<<std::endl;

	//creating vector & initializing it
	std::vector<double>     Numbers = { 14.5, 15.9, 16.3, 17.3, 18.8, 19.0 };

	std::cout<<"Printing Original Vectors"<<std::endl;
	//looping through and printing. Using auto instead of double
	for( auto Number : Numbers ){
		std::cout<<Number<<std::endl;
	}

	//adding random numbers to vector
	//using ampersand here too, because it wasn't working without it
	for( auto &Number : Numbers )
	    Number += GetRandom();

	std::cout<<"Printing Vectors + Random Numbers"<<std::endl;
	//need to use ampersand (pointer) otherwise number won't change
	for( auto &Number : Numbers ) {
		std::cout<<Number<<std::endl;
	}

}
