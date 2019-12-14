/*
 * ListDouble.h
 *
 *  Created on: Mar 31, 2013
 *      Author: phuegler
 */

// only include the header file once
#ifndef LISTDOUBLE_H_
#define LISTDOUBLE_H_

// class definition
class ListDouble {
	// data members
	private:
		double	Numbers[10];

	// constructors and destructor
	public:
		ListDouble();
		virtual ~ListDouble();

	// methods
	public:
		void SetItem( int Index, double Value );
		double GetItem( int Index );
};

#endif /* LISTDOUBLE_H_ */
