/*
 * By   : Shehryar Malik
 * Date : Oct. 6. 2016
 *
 * Retriever.cpp
 *
 * This file is the implementation of the Retriever class. The class is
 * 	used to create the retriver array that holds the orders before they
 *  are sent to the packers by run in main.cpp. The array is also 
 *  dynamic array. 
 *
 */

#include "Order.h"
#include "Orderqueue.h"
#include "Retriever.h"

using namespace std;

// constructor
Retriever::Retriever(){
	count = 0;
	capacity = INIT_CAPACITY;
	retriever = new Order[INIT_CAPACITY];
}

// destructor
Retriever::~Retriever(){
	delete []retriever;
}

// Purpose : To fill the retriever arrays with the Order package read
//			 from parser. 
// Args    : Order package to be added, and int order number
void Retriever::fill_retriever(Order package, int order_num){
	if (order_num >= capacity){
		expand();
	}
	retriever[order_num] = package;
	count++;
	//cout << "AT " <<retriever[order_num].arrival_timestamp << endl;
}

// Purpose : To determine if the retriever array is empty
// Args    : None
// Returns : Nothing
bool Retriever::isEmpty(){
	//cout << count << endl;
	if (count == 0){
		return true;
	}
	return false;
}

// Purpose : To determine the size of the array
// Args    : None
// Returns : Nothing
int Retriever::size(){
	return count;
}

// Purpose : To remove the top element from the array
// Args    : None
// Returns : Nothing
void Retriever::remove_top(){
	for (int i = 0; i < count-1; i++){
		retriever[i] = retriever[i+1];
	}
	count--;
}


// Purpose : To expand the retriever array
// Args    : None
// Returns : Nothing
void Retriever::expand(){
	Order *temp = new Order[capacity*2];
	for (int i = 0; i < count; i++){
		temp[i] = retriever[i];
	}
	delete []retriever;
	retriever = temp;
	capacity = capacity*2;
}

// Purpose : To return reference to the retriever array.
//			 It is used by run in main, as the array is passed to assign
//			 functions of different packing modes
// Args    : None
// Returns : Nothing
Order &Retriever::get_retriever(){
	return *retriever;
}
