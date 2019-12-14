/*
 * Base.cpp
 *
 *  Created on: Nov 10, 2017
 *      Author: Assunta
 */

#include "Base.h"
#include <string>
#include <chrono>
#include <iostream>
#include <iomanip>

std::ofstream Base::LogFile;

Base::Base() {
	// TODO Auto-generated constructor stub

}

Base::~Base() {
	// TODO Auto-generated destructor stub
}

// open the log file
void Base::LogOpen()
{
    // open the log file
    if ( !LogFile.is_open() )
        LogFile.open( "LogFile.txt" );

    // return finished
    return;
}

// close the log file
void Base::LogClose()
{
    // close the file
    if ( LogFile.is_open() )
        LogFile.close();

    // return finished
    return;
}

// log messages
void Base::LogMessages( std::string Message )
{


    // get the current and local date/time
    //      this uses the C++11 chrono library
    //      this is how to get time in C++
    auto        CurrentTime =   std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
    struct tm   LocalTime;
    //      localtime_r is a thread safe version
    //          of local time
    localtime_r( &CurrentTime, &LocalTime );

    // build the time stamp
    std::stringstream   Timestamp;
    //      std::put_time is a C++11 addition
    //          used to format time
    Timestamp<<std::put_time( &LocalTime, "[%Y-%m-%d %H:%M:%S]" );

    // output the message
    std::cout<<Timestamp.str()<<" "<<Message<<std::endl;

    if ( LogFile.is_open() )
    	    LogFile<<Timestamp.str()<<" "<<Message<<std::endl<<std::flush;

    // return finished
    return;
}
