/*
 * ListInteger.h
 *
 *  Created on: Mar 31, 2013
 *      Author: phuegler
 */

// only inlcude the header file once
#ifndef LISTINTEGER_H_
#define LISTINTEGER_H_

// class definition
class ListInteger {
	// data members
	private:
		int	Numbers[10];

	// constructors and destructor
	public:
		ListInteger();
		virtual ~ListInteger();

	// methods
	public:
		void SetItem( int Index, int Value );
		int GetItem( int Index );
};

#endif /* LISTINTEGER_H_ */
