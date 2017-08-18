/*
 * Orderqueue.h
 * By:    Shehryar Malik (smalik02)
 *
 * Date:  Oct. 5. 2016
 *
 *
 * This file is the definition of the class Orderqueue.
 * The file defines the functions for creating and handling
 * queues. The public functions include enqueue, which is adding
 * to a queue, dequeue, which is removing from the queue once the
 * task is done. Also, we have the default constructors and 
 * destructors for the class.
 *
 * The data structure being used is a linked list. It is not
 * a double linked list because we are really only concerned with
 * the front and the back of the list while in the queue. The interface
 * only allows interactions with the enqueue and the dequeue functions. 
 * enqueue function adds at the back of the list, and dequeue removes from
 * the front.
 *
 * This file/class has the Order header file included. Order is a struct,
 * given to us, that has int values for different times, and an 
 * identification. Since we are going to be adding Orders to the queue,
 * the queue has to have the Order type, and therefore, the struct definition
 * is included in this class.
 *
 * This class is going to be heavily used by the main.cpp file because we are
 * going to add and remove order from the queue using this class. Moreover,
 * it serves as the main data structure class. The retriver will use this 
 * class often as well. It will call the enqueue function once it has fetched
 * the order. 
 *
 *
 */


#ifndef ORDER_QUEUE_H_INCLUDED
#define ORDER_QUEUE_H_INCLUDED

#include "Order.h"

class Orderqueue
{
public:
	struct Node{
		Order package;
		Node *next;
		Node *previous;
	}
	// the linked list struct which the queue is based on
	// It has a previous node pointer, a next node pointer, and the order
	// package itself.


       	Orderqueue();
 //	OrderQueue(int size); Not needed because never created with already
 //				order to go
        ~Orderqueue();

       	Order dequeue(); // function responsible for removing an order
			// from the queue once the time left for packing has
			// elapsed

        void enqueue(Order element); // function used to add to the back of
				     // the queue

private:
	Node *head; // Node pointer to the head
	Node *tail; // Node pointer to the end of the list, makes it easier
		    // to enqueue
       	Order package; // an instance of the Order package
	int size;   // size of the queue, which will be most useful for 
		    // fewst_item mode in the main.cpp file 
	void clear(); // function to delete the created memory/free the
		      // asked memory by making the list empty
};
#endif
