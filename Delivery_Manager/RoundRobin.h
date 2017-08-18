/*
 *  By:   Shehryar Malik (smalik02)
 *  Date: Oct. 5. 2016
 *
 *  This file is the definition for the RoundRobin class. 
 *
 *  I broke down the three different methods of packaging into each class
 *  because it would allow me to modularize the code. Also, since each
 *  mode is different, it will allow me to create class specific variables.
 *
 *  RoundRobin mode means that retriever assigns the package to ever packer
 *  one at a time, until the orders run out. 
 *  
 *  RoundRobin function robin_assign_order is the main function in the class.
 *  It takes int number of packers, the retriever class, and 
 *  the array of packers w/ type Orderqueue. The function is going to assign
 *  order using while loop & a for loop nested inside of it.
 *  The while loop will have the main condition that will check if the
 *  retriever is empty. It will run the while loop as long as it is not empty.
 *  It will loop through the array of packers and assign each packer an order
 *  in order, using the enqueue function. 
 *
 *  In addition, we will have a conditional that will check within the for 
 *  loop if the retriever array is empty because it is possible that there
 *  arent enough packages to assign to each packer, so the loop will have 
 *  to be broken.
 *
 *
 */

#ifndef ROUNDROBIN_H_INCLUDED
#define ROUNDROBIN_H_INCLUDED

#include "Order.h"
#include "Orderqueue.h"
#include "Retriever.h"


class RoundRobin{
	public:
		RoundRobin();
		~RoundRobin();

		// As described above, assign order assigns orders to the
		// packers in order. The function takes in array of packers
		// with type Order and the retriever class. The function is
		// called in main by run function if the packing mode is RoundRobin.
		void assign_order(Retriever &r, Orderqueue *packers[],
				int);
	private:
		Orderqueue packer; // instance of the Orderqueue packers
		Retriever r;
};

#endif
