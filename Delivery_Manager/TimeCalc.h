/*
 * By   : Shehryar Malik
 * Date : Oct. 6. 2016
 *
 * This file is the definition of the TimeCalc class. The class
 * is used to calculate different components of the total_time 
 * for each Order. 
 *
 * The total_time is broken down into four different components:
 * fetch_wait_time (time waiting in the retriever)
 * fetch_time (time it takes the retriever to get the package to packers)
 * pack_wait_time (time it waits in the packer's queue)
 * pack_time (time it takes to pack)
 *
 *
 *
 */

#ifndef TIMECALC_H_INCLUDED
#define TIMECALC_H_INCLUDED

#include "Order.h"
#include "Retriever.h"
#include "Orderqueue.h"

class TimeCalc{
public:
	TimeCalc();
	~TimeCalc();

	/* fetch_wait_time is equal to the total fetch time 
 	 * minus the arrival time. Also, if total fetch time
 	 * is less than the arrival time, then total fetch time
 	 * will be updated to the arrival time to keep it consistent.
 	 * For that case also, the fetch_wait_time will be zero.
 	 */ 
	void fetch_wait_time(Order *retriever, int);

	/*
 	 * pack wait time is equal to the total time of the previous
 	 * package minus the start time of this package. Start time is
 	 * equal to the time when the package arrives to the packer.
 	 * Start time is equal to fetch wait time + arrival time + 
 	 * fetch time.
 	 */ 
	void pack_wait_time(Orderqueue *packers[], int);
	void pwt(Orderqueue *packers[], int);
private:
	int total_fetch_time; // time the fetcher has been fetching for
						  // totally
	Orderqueue packer; // instance of the Orderqueue class
	Retriever r; 	   // instance of the retriever class
	int prev_start;    // previous package's start time (for packing)
	int prev_packd;    // previous package's pack duration
	int prev_pwt;      // previous package's pack_wait_time
	int prev_print;    // previous package's print time (time it will exit
					   // the packer array in the print function in main.cpp)
	Order temp;
};
#endif
