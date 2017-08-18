/*
 * Order.h
 * Written by: Max Bernstein and Erica Schwartz
 * Fall 2016
 *
 * Defines an Order struct that holds the data for a Nozama order
 *
 * Modified By: Shehryar Malik
 * Date       : Oct. 6. 2016
 * Comments: This the data structure for the orders we recieve. Each order
 * 		has a unique ID, arrival_timestamp (time it arrives in the
 * 		order log), fetch_duration(time it takes for the retriever
 * 		to get the package to the packer), pack_duration (the time
 * 		it takes for the packer to pack the package). As of now,
 * 		I am not using fetch_time_left and pack_time_left.
 * 		I added 3 new variables: fetch_wait_time, pack_wait_time,
 * 		and total_time. fetch_wait_time is the time the package
 * 		is waiting in the retriever's array while the current package
 * 		is being fetched (or delivered to the packers). 
 * 		pack_wait_time is the time the package has to wait in the
 * 		queue of the packer while the first/current item is being
 * 		packed.
 * 		total_time is the time the package was in the warehouse.
 * 		It is comprised of the following:
 * 		fetch_duration + fetch_wait_time + pack_wait_time + 
 * 		pack_duration.
 *
 *
 */

#ifndef ORDER_H
#define ORDER_H

struct Order {
        int id;
        int arrival_timestamp;  /* aka "arrival time" */
        int fetch_duration;     /* aka "fetch time"   */
        int pack_duration;      /* aka "pack time"    */
        int fetch_time_left;
        int pack_time_left;
	int fetch_wait_time;
	int pack_wait_time;
	int total_time;
	int start_time;
	int print;
};

#endif
