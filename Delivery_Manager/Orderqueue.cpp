/*
 * By   : Shehryar Malik
 * Date : Oct. 6. 2016
 *
 * OrderQueue.cpp
 *
 * This file is the implementation of the OrderQueue.h class.
 * It defines the functions such as dequeue and enqueue (main
 * functions used by main.cpp)
 * 
 * These functions are used mostly by the three structs
 * (RoundRobin, ShortestTime, and FewestItems) function
 * assign_pacakage.
 *
 * Each packer is going to be an instance of this class.
 *
 */

#include <iostream>
#include "Order.h"
#include "OrderQueue.h"

using namespace std;

// constructor
Orderqueue::Orderqueue(){
	head = NULL;
	tail = NULL;
	size = 0;
}

// destructor
Orderqueue::~Ordequeue(){
	clear(); // makes the queue empty
}

// Purpose: To remove the first item from the list.
// Args   : None
// Returns: The item that was removed from the queue, with type Order.
Order Orderqueue::dequeue(){
	if (head == NULL){
		cout << "empty queue" << endl;
		return;
	} else if (size == 1){
		clear();
	}
	Node *temp = head; // temp iterator
	head = head->next;
	head->previous = NULL;
	Order storage = temp->package; // Order type to return
	delete temp;
	size--;
	return storage;
}

// Purpose: To add a new item to the end of the queue
// Args   : Order type data
// Returns: Nothing
void Orderqueue::enqueue(Order data){
	Node *new_Node = new Node; // new node created
	new_Node->package = data;  // gets the data
	if(size == 0){ // if empty list
		head = new_Node; // head points
		head->previous = NULL; // previous is NULL
	} else {
		tail->next = new_Node; // the last item points to this new Node
		new_Node->previous = tail; // link the new Node to the list
	}
	tail = new_Node; // tail is updated
	new_Node->next = NULL; // next points NULL as it is the end
	
}


// Purpose: To empty the OrderQueue
// Args   : None
// Returns: Nothing
void Orderqueue::clear(){
	Node *iterator = head;
	while(iterator != NULL){
		head = head->next;
		delete iterator;
		iterator = head;
	}
	count = 0;
	previous = NULL;
	head = NULL;
}

