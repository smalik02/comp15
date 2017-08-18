/*
 ShortestTime.cpp

 By   : Shehryar Malik
 Date : Oct 12. 2016

 Purpose : This file is the implementation of the ShortestTime class,
 			which adds the packages based on the shortest packaging
 			time of all the current packages in the packer queues/
 			The constructor sets the min to a very high starting value.
 			It also sets the index to zero.
 			The destructor is empty empty because nothing needs to be
 			actively deleted as no memory was allocated for a new variable

 			The main function is the assign_package function. To determine
 			which packer has the shortest time, the print_time of the last
 			item is compared among all of the packers.
 			print time is used because it tells at what time the package
 			is going to exit the queue and be shipped.
*/

#include "Order.h"
#include "Orderqueue.h"
#include "ShortestTime.h"
#include "TimeCalc.h"

using namespace std;

// constructor
ShortestTime::ShortestTime(){
	min = 999999;
	index = 0;
}

// Destructor is empty as nothing is created with new
ShortestTime::~ShortestTime(){

}

// Purpose : Purpose of this function is to assign orders. In this mode,
// 			 it will assign orders based on the shortest time. 
//
//Design  :  Function will be called before the time.pack_wait_time is run in
//			 in main.cpp, print time is not known. Therefore, the function
//			 is called for every package in the for loop. It does lead
//			 to a little bit of inefficiency; however, I guess this is one
//			 of downsides in using a math approach. Then, the values are
//			 compared using the print times. 
//			 Also, for loop is broken down into two parts, if packer
//			 is empty. If it is, then it is enqueued as the print time
//			 will be zero.
//
// Args   : Retriever class by reference, pointer to Orderqueue type array,
//			int number of packers, and TimeCalc class by reference. 
// Returns : Nothing
void ShortestTime::assign_package(Retriever &r, Orderqueue *packers[],
				int num_packers, TimeCalc &t){
	Order *retriever = &(r.get_retriever()); // copy of the retriever array
	bool added = false; // bool for if the added was when array was empty
	while (!r.isEmpty()){	
		for (int i = 0; i < num_packers; i++){
			t.pack_wait_time(packers, num_packers);
			if (packers[i]->items_not_done(retriever[0].start_time) == 0){
				packers[i]->enqueue(retriever[0]);
				min = 99999;
				r.remove_top(); // remove the Order that was just added
				added = true; 
			} else {
				last_package = packers[i]->last_element();
				if (min > last_package.print){
					min  = last_package.print;
					index = i;
				}
				added = false;
			}
		}
		if (!added){
			packers[index]->enqueue(retriever[0]);
			r.remove_top(); // remove the Order that was just added
			min = 999999;
		}
		if (r.isEmpty()){ // if retriever has run out of orders, done
			return;
		}
	}
}

