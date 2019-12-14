/*
 * List.h
 *
 *  Created on: Nov 2, 2017
 *      Author: adesanto
 */

#ifndef LIST_H_
#define LIST_H_
#include <iostream>

template< class T > class List
{
	//T is a data type
    private:
        T Items[10];
    public:
        //method to set item
        void SetItem( int Index, T Value )
        {
            if (( Index < 0 ) || ( Index > 9 ))
                throw( std::runtime_error( "Invalid index used - must be between 0 and 9" ));

            Items[Index]	=	Value;

            return;
        }
        //method to get item
        T GetItem(int Index){
        	if (( Index < 0 ) || ( Index > 9 ))
        	                throw( std::runtime_error( "Invalid index used - must be between 0 and 9" ));

        	T Value = Items[Index];

        	return (Value);
        }

};




#endif /* LIST_H_ */
