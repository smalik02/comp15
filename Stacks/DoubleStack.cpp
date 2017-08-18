// DoubleStack.cpp
//
// Shehryar Malik
// Sep. 25. 2016
// HW3
// 
// This file implements the DoubleStack.h class. The file creates a double
// Stack to store the information from the user for the calculator. 
// It has functions such as clear, pop, push, top, etc. 
//
//

#include <iostream>
#include "DoubleStack.h"

using namespace std;

// constructor 
DoubleStack::DoubleStack(){
	head = NULL;
	count = 0;
	//cout << "constructor " << count << endl;
}

// overloaded constructor
// It takes a double array and the size of the array. The function takes
// in the information in reverse to fill in the list data structre for the
// stack
DoubleStack::DoubleStack(double array[], int size){
	head = NULL;
	count = 0;
	for (int i = 0; i < size ; i++){
		push(array[i]);
	}
}

// destructor
// Calls the clear function to delete the node
DoubleStack::~DoubleStack(){
	clear();
}
// Purpose: To determine if the stack is empty
// Args   : Nothing
// Returns: True if the stack is empty, and false otherwise
bool DoubleStack::isEmpty(){
	if (count == 0){
		return true;
	} 
		return false;
}

// Purpose: To clear the stack
// Args   : Nothing
// Returns: Nothing
void DoubleStack::clear(){
	Node *iterator = head;
	//cout << "count: " << count << endl;
	while(count != 0){
		//cout << "again" << endl;
		head = head->next;
		//cout << "before delete" << endl;
		delete iterator;
		//cout << "after delete" << endl;
		iterator = head;
		//cout << "problem?" << endl;
		count--;
	}
	count = 0;
	//cout << "out of the loop" << endl;
	head = NULL;	
}

// Purpose: To determine the size of the stack
// Args   : Nothing
// Returns: The int size of the stack (count)
int DoubleStack::size(){
	return count;
}

// Purpose: To determine the first item in the stack
// Args   : None
// Returns: a double vale, the first item in the stack
double DoubleStack::top(){
	if (count == 0){ // empty stack
		throw runtime_error("empty_stack");
	}
	return head->data;
}

// Purpose: To take off the first item in the stack
// Args   : None
// Returns: a double value, the first item in the stack
double DoubleStack::pop(){
	if (count == 0){
		throw runtime_error("empty_stack");
	}
	Node *temp = head;
	head = head->next; // head is moved to the next
	double num = temp->data; // value to be returned
	delete temp; // remove the node
	count--; // size is decreased
	return num; // return the first item in the stack
}

// Purpose: To add a double value in the stack
// Args   : The double value to be added
// Returns: Nothing
void DoubleStack::push(double num){
	Node *new_node = new Node; // node to be added
	new_node->data = num;
	new_node->next = head; // connected to the list
	head = new_node; // new front
	count++; // size is increased
	//cout << count << endl;
}
