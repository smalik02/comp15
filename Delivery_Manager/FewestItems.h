/*
 * By   : Shehryar Malik
 * Date : Oct. 6. 2016
 *
 * FewestItems.h
 *
 * This file is the implementation of the FewestItems class. The class is
 * used to assign packages based on the fewest number of packages in the
 * queue for the packers. The class is used by the main.cpp in run 
 * function as it will be called to assign packages. 
 *
 * The assign_package function is the main function because it assigns
 * the packages to the packers. To determine which packer has the fewest
 * items we will use the int min, which will be set to zero when the 
 * function is called, to determine the current min and iterate through the
 * packer array and call the size function.
 *
 *
 */

#ifndef FEWESTITEMS_H_INCLUDED
#define FEWESTITEMS_H_INCLUDED

#include "Order.h"
#include "Orderqueue.h"
#include "Retriever.h"
#include "TimeCalc.h"

class FewestItems{
	public:
		FewestItems(); // default constructor
		~FewestItems(); // destructor
		// assign_package is used for assigning the packers the
		// packages based on the fewest items. The function is going
		// to loop through the array of packers, Orderqueue packers
		// (passed in as arg), and determine the min.
		void assign_package(Retriever &retriever, Orderqueue *packers[]
					, int, TimeCalc &t);
	
	private:	
		Orderqueue packer; // instance of the Orderqueue packer class
		int min; // number of items in the queued when a package is
				 // is being added
		int index; // index for the packer with the min num of orders
		Retriever r;
		TimeCalc t;
};
#endif
