/*
 *
 *  COMP 15 HW 2 Cheshire ConCATenation - Time to linked up in hur
 *
 *  CharLinkedList.cpp
 *  Complete CharLinkedList Class Implementation
 *  Modified By (UTLN): smalik02
 *           On       : 09.20.16
 *
 *  Purpose: To implement the class defined by the CharLinkedList.h
 *  		The functions implement different types of taks for linked 
 *  		lists, such as concatenate, add, remove, replace, etc.
 */


#include <iostream>
#include "CharLinkedList.h"

using namespace std;

// constructor 
CharLinkedList::CharLinkedList(){
	head = NULL;
	count = 0;
	previous = NULL;
	tail = NULL;
}

// overloaded constructor
CharLinkedList::CharLinkedList(char element){
	count = 0;
	head = NULL;
	previous = NULL;
	tail = NULL;
	insertAtFront(element);	
}

// destructor
//
CharLinkedList::~CharLinkedList(){
	clear();
}
// Purpose: To determine if the CharLinkedList is empty
// Args   : None
// Returns: True if its empty, false otherwise
bool CharLinkedList::isEmpty(){
	if (count == 0) {
		return true;
	} else {
		return false;
	}
}

// Purpose: To clear the list, make it empty
// Args   : None
// Returns: Nothing
void CharLinkedList::clear(){
	Node *iterator = head;
	while(iterator != NULL){
		head = head->next;
	//	cout << "in while";
		delete iterator;
		iterator = head;
	}
	count = 0;
	previous = NULL;
	head = NULL;
}

// Purpose: To determine the size of the CharLinkedList
// Args   : None
// Returns: Int size of the CharLinkedList
int CharLinkedList::size(){
	return count;
}

// Purpose: To determine the first element in the CharLinkedList
// Args   : None
// Returns: The char element in the first node; if empty, throws an exception
char CharLinkedList::first(){
	if (head == NULL){
		throw invalid_argument("Empty");
	}
	return head->data;
}

// Purpose: To determine the last element in the CharLinkedList
// Args   : None
// Returns: The char element in the last node; if empty, throws an exception
char CharLinkedList::last(){
	if (head == NULL){
		throw invalid_argument("empty list");
	} else {
		return tail->data;
	}
}

// Purpose: To determine the element at the given index
// Args   : int index to find the element at
// Returns: The char element at the given index
char CharLinkedList::elementAt(int index){
	if (index >= count or index < 0 or head == NULL){
		throw out_of_range("Out of Range Index");
	}
	Node *iterator = head;
	int index_count = 0; // counter to match the given index
	while(index_count != index){
		iterator = iterator->next;
		index_count++;
	}
	return iterator->data;
}

// Purpose: To print the elements in the linkedlist
// Args   : None
// Returns: Nothing, prints the elements
void CharLinkedList::print(){
	string print_sequence = ""; // sequence to be printed
	Node *iterator = head;
	while(iterator != NULL){
		print_sequence += iterator->data;
		iterator = iterator->next;
	}
	cout << "[CharLinkedList of size " << count << " <<"
		<< print_sequence << ">>]";
}

// Purpose: To insert a new node at the back of the linked list
// Args   : Element to be added in the data part of the node
// Returns: Nothing
void CharLinkedList::insertAtBack(char element){
	if (count == 0) {
		insertAtFront(element);
		return;
	}
	Node *insert_node = new Node;
	insert_node->data = element;
	insert_node->next = NULL;
	insert_node->previous = tail; // link the new node to the list by tail
	tail->next = insert_node;
	tail = insert_node; // move tail to the new last node
	count++;
}

// Purpose: To insert a new node at the start of the linked list
// Args   : Element to be added in the new node
// Returns: Nothing
void CharLinkedList::insertAtFront(char element){
	Node *insert_node = new Node;
	insert_node->data = element;
	//insert_node->next = head;
	//cout << "before conditional" << endl;
	insert_node->previous = NULL;
	if(count == 0){ // adding into an empty list
		insert_node->next = head;
		head = insert_node; //head was NULL initially, now to new node
		tail = insert_node; //tail was NULL, now points to new node
	//	cout << "in if == 0" << endl;
	} else {
		insert_node->next = head;
		head->previous = insert_node;
		head = insert_node; // head updated to new front
	}
	count++;
}

// Purpose: To insert a new node with an element at the given index
// Args   : Element to be added in the new node, along with index to add node
// Returns: Nothing
void CharLinkedList::insertAt(char element, int index){
	int index_count = 0; // index count to find given index in the list
	Node *insert_node = new Node; //new node created
	insert_node->data = element;
	Node *iterator = head;
	if (index > count or index < 0) {
		throw out_of_range("Out of Range");
	} else if (index == 0){
		insertAtFront(element); // inserting at front
	} else if (index == count){
		insertAtBack(element); // inserting at back
	} else {
		while(index_count != index-1){
			iterator = iterator->next;
			index_count++;
		}
	insert_node->next = iterator->next; // link node to the next node
	iterator->next->previous = insert_node; // link next node's previous
						// with new node
	insert_node->previous = iterator; //new node linked with previous node
	iterator->next = insert_node; // previous node linked with new node
	count++;
	}
}

// Purpose: To remove a node from the front
// Args   : None
// Returns: Nothing
void CharLinkedList::removeFromFront(){
	if (count == 0) { // empty list, so cant remove
		throw invalid_argument("empty list");
	} else if (count == 1){ //one node list
		clear(); //removing one means cant change the previous
			//so, you have to just delete the whole node
		return;
	}
	Node *iterator = head;
	head = iterator->next;
	delete iterator;
	head->previous = NULL; //previous is now the front, so points to NULL
	count--;
}

// Purpose: To remove a node from the end of the list
// Args   : None
// Returns: Nothing, just removes a node
void CharLinkedList::removeFromBack(){
	if (count == 0) { // empty list, so cant remove
		throw invalid_argument("empty list");
	} else if (count == 1){
		clear(); // similar to remove from front, if one node list,
			// have to delete the whole list
		return;
	}
	Node *iterator = tail;
	tail = tail->previous;
	delete iterator;
	tail->next = NULL;
	count--;
}

// Purpose: To remove a node from the given index
// Args   : Int index to remove a node from
// Returns: Nothing
void CharLinkedList::removeFrom(int index){
	if (index >= count or index < 0){
		throw out_of_range("Out of Range Index");
	} else if (index == 0){ // similar to remove from Front
		removeFromFront();
	} else if (index == count-1){ // similar to remove from back
		removeFromBack();
	} else {
		Node *iterator  = head;
		int index_count = 0; // counter to find the index position
		while(index_count != index){
			iterator = iterator->next;
			index_count++;
		}
		iterator->previous->next = iterator->next;
		// links previous node to the next node
		iterator->next->previous = iterator->previous;
		// links next node to the previous node
		delete iterator; // removes the current node at the index
		count--;
	}
}

// Purpose: To replace an element in the index number node
// Args   : Index for the node, and the element to replace with
// Returns: Nothing
void CharLinkedList::replace(char element, int index){
	if (index >= count or index < 0){
		throw out_of_range("Out of Range Index");
	} else {
		Node *iterator = head;
		int index_count = 0; // counter to find the index position
		while(index_count != index){
			iterator = iterator->next;
			index_count++;
		}
		iterator->data = element;
	}
}

// Purpose: To link two lists together
// Args   : pointer to a second list's class
// Returns: Nothing
void CharLinkedList::concatenate(CharLinkedList *second_list){
	//Node *iterator = head;
	if (second_list->head == NULL) {
		return;
	} 
	Node *point_second = NULL;
	//cout << "point created" << endl;
	point_second = copy(second_list->head, tail); //pointer to copied node
	//cout << "second_list copied" << endl;
	if (count == 0) { //first list is empty
		head = point_second; //first list's head points to the copied
		point_second->previous = NULL;
		count += second_list->size();
		tail = head;
		while(tail->next != NULL){
			tail = tail->next;
		}
		return;
	}
	tail->next = point_second; //link the main list with the copied node
	//cout << "node at tail connected to the second_list" << endl;
	tail = point_second; // move tail over
	//cout << "tail moved to second_list" << endl;
	while(tail->next != NULL){ // in order to move the tail to the end
		tail = tail->next;
	}
	count += second_list->size();
}

// Purpose: To insert a new element in alphabetical order
// Args   : char element to insert
// Retunrs: Nothing
void CharLinkedList::insertInOrder(char element){
	Node *iterator = head;
	if (iterator == NULL) { //if empty, then same as insert at front
		insertAtFront(element);
		return;
	}
	int index_count = 0; // counter for how far the counter goes (index)
	while(iterator != NULL){
		if(iterator->data < element){ //element is higher in alphabet
			iterator = iterator->next;
			index_count++; //index increased
		} else { // insert element was less than the next element
			break; // no need to increment the counter
		}
	}
	if (index_count == 0){ //element was less than the next element
		insertAtFront(element);
	} else if (index_count == count){ //iterated through the end
		insertAtBack(element);
	} else {
		insertAt(element, index_count); //insert at the index
	}
}

// Purpose: To copy the node to be inserted in the concatenate function
// 		The function performs the task recursively 
// Args   : Pointer to the second_list to insert, and pointer to the previous
// 		node in order to link the new node both ways
// Returns: A pointer to the new copied node
CharLinkedList::Node *CharLinkedList::copy(Node *second_list, Node *previous_node){
	if(second_list == NULL) { // if list is empty, return the null pointer
		return second_list;
	}
	Node *new_list = new Node; // new node created
	new_list->data = second_list->data; // get new_node data
	new_list->previous = previous_node; // previous points to last node
		// in the start, it will be the tail of the main list
	new_list->next = copy(second_list->next, new_list);
		// new node's next points to the rest of the list, which is
		// performed recursively. the pointer to the node being copied
		// is passed, along with the pointer to the current node which
		// serves as the previous for the next node to be added
	return new_list; // return the pointer to the copied node
}
