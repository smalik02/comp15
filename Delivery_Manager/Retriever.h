/*
 * By   : Shehryar Malik
 * Date : Oct. 6. 2016 
 *
 * Retriever.h
 *
 * This file is the definition of the retriever file. Retriever,
 * or also known as fetcher, is used for fetching the files for
 * the packers. The retriever class is first initiated when the 
 * program begings.
 *
 * Then, Parser reads in the input/order file, and returns one
 * order at a time in the run function (in main.cpp). That order
 * is passed into fill_retriever (function in this class). It
 * populates the sequence of the retriever, with type Order.
 *
 *
 * The retriever sequence will also be used by the TimeCalc class
 * to determine the fetch_wait_time for each package. The
 * fetch_wait_time is described in the TimeCalc.h file & README
 *
 */

#ifndef RETRIEVER_H_INCLUDED
#define RETRIEVER_H_INCLUDED

#include "Order.h"
#include "Parser.h"
#include "string2int.h"


class Retriever{
	public:
		// default constructor. It will initialize
		// the count to 0 and capacity to zero.
		Retriever();

		// destructor. Runs when the function ends or
		// delete command is used
		~Retriever();

		// void type function to fill the retriever sequence.
		// The function is called by the run function in main.cpp
		// after an order is returned by the Parser. It takes in
		// one package with type Order at a time.
		// Also, if need be, it dynamically increases the memory
		// of the sequence by calling the expand() function.
		void fill_retriever(Order package, int order_num);
		
		bool isEmpty(); // the function returns true if the sequence
						// is empty. It is used especially by the
						// RoundRobin class while it is assiging 
						// packages to the packers
		int size(); // returns the size of the retriever array
		void remove_top(); // removes the first element in the array
		Order &get_retriever(); // returns the retriever array
	private:
		int count; // variable for the size of the sequence
		int capacity; // variable for the capacity of the sequence
		Order *retriever; // Order pointer that will point to a Order
				  		  // sequence
		void expand(); // expand function increase the memory/size
			       	   // of the array
		const int INIT_CAPACITY = 5; // start with array of 5
};
#endif
