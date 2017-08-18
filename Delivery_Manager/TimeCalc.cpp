/*
 * By   : Shehryar Malik
 * Date : Oct. 6. 2016
 *
 * This file is the implementation of the TimeCalc class. The class
 * is used to calculate different components of the total_time 
 * for each Order. 
 *
 * The total_time is broken down into four different components:
 * fetch_wait_time (time waiting in the retriever)
 * fetch_time (time it takes the retriever to get the package to packers)
 * pack_wait_time (time it waits in the packer's queue)
 * pack_time (time it takes to pack)
 *
 */

#include "Order.h"
#include "Retriever.h"
#include "Orderqueue.h"
#include "TimeCalc.h"
#include <iostream>

using namespace std;

// constructor : sets the private int variables to zero
TimeCalc::TimeCalc(){
	total_fetch_time = 0;
	prev_start = 0;
	prev_packd = 0; 
	prev_pwt = 0; 
	prev_print = 0;
}

// destructor : Nothing as no new memory was allocated
TimeCalc::~TimeCalc(){

}

// Purpose : To determine the fetch_wait_time.
// Args    : Order retriver pointer, and int total orders in the array
// Returns : Nothing
void TimeCalc::fetch_wait_time(Order *retriever, int total_orders){
	for (int i = 0; i < total_orders; i++){
		if (retriever[i].arrival_timestamp >= total_fetch_time){
			total_fetch_time = retriever[i].arrival_timestamp + 
					retriever[i].fetch_duration; // update total fetch time
			retriever[i].fetch_wait_time = 0; 
			// didnt have to wait as the order came in after fetcher was done
		} else {
			// order came in while fetcher was busy
			retriever[i].fetch_wait_time = total_fetch_time -
					retriever[i].arrival_timestamp;
			total_fetch_time += retriever[i].fetch_duration;
			// update the total fetch time wih the orders durations
		}
		retriever[i].start_time = retriever[i].fetch_duration +
 			retriever[i].arrival_timestamp + 
			retriever[i].fetch_wait_time;
		// start_time i.e. time it gets to the packer
	} 
}

// Purpose : To determine the pack_wait_time of the packers in the packer
//			 queue. 
// Design  : The function is broken down into two different parts, if
//				the Order is the first item in the queue, or not. If it is,
//				then the pack_wait_time is automatically 0. If not, 
//				the the time depends upon the previous Order's print
//				time and the start time of the current package. If
//				p_wait_time (prev_print - start of the current) is less than
//				zero, that means that it was given to the packer when the
//				was technically empty. If not, then the difference is the
//				pack_wait_time, which is done by pwt (to make functions under
//				30 lines)
//				Also, the packages are dequeued and then enqueued again
//				because the Order information is the only thing that
//				needs to be updated, and the queue is still used by
//				the print function in main to print in order. Threfore, by
//				dequeueing and enqueueing, the order of the queue is preserved
// Args    : Orderqueue type pointer to array of packers, and int num
//				of packers
// Retunrs : Nothing
void TimeCalc::pack_wait_time(Orderqueue *packers[], int num_packers){
	for (int i = 0; i < num_packers; i++){
		for (int a = 0; a < packers[i]->count(); a++) {
			if (a == 0){ // first order in the array
				temp = packers[i]->dequeue(); // get the order
				temp.pack_wait_time = 0; // no wait time 
				temp.total_time = temp.fetch_duration + temp.pack_duration +
					temp.fetch_wait_time; // total_time is calculated
				prev_start = temp.start_time; 
				prev_packd = temp.pack_duration;
				prev_pwt = temp.pack_wait_time;
				prev_print = prev_packd + prev_start;
				temp.print = prev_print; // store the print time, needed for
										 // print function in main.cpp
				packers[i]->enqueue(temp); // added back to the queue
			} else {
				pwt(packers, i);
			}
		}
	}
}

// Purpose : To determine the pack wait time if the order being checked
//				isnt the first item in the list. It is called by
//				pack_wait_time function
// Args    : Orderqueue type pointer to array of packers and the index
//				of the packer array to dequeue the order from
// Returns : Nothing
void TimeCalc::pwt(Orderqueue *packers[], int i){
	temp = packers[i]->dequeue(); // dequeue the top Order
	int p_wait_time = prev_print - temp.start_time; //determine pack_wait_time
	if (p_wait_time < 0){
		temp.pack_wait_time = 0; // Order arrived when the packer was empty
	} else {
		temp.pack_wait_time = p_wait_time;
	}
	temp.total_time = temp.fetch_wait_time + temp.fetch_duration +
	temp.pack_duration + temp.pack_wait_time;
	prev_start = temp.start_time;
	prev_packd = temp.pack_duration;
	prev_pwt = temp.pack_wait_time;
	prev_print = prev_start + prev_packd + prev_pwt;
	temp.print = prev_print; // store the print time
	packers[i]->enqueue(temp); // added back to the queue
}