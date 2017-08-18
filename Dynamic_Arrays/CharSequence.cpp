// Shehryar Malik
// Comp15
// HW 1
// Sep. 8. 2016
//
//
#include <iostream>
#include "CharSequence.h"

using namespace std;

//constructor
CharSequence::CharSequence() {
	sequence = new char[1];
	count = 0;
	capacity = 1;
}

//overloaded constructor 
CharSequence::CharSequence(char letter) {
	sequence = new char[1];
	sequence[0] = letter;
	count = 1;
	capacity = 1;
}

//destructor --> free the memory borrowed
CharSequence::~CharSequence() {
	delete []sequence;
}

// Purpose: To determine if the sequence is empty
// Args   : None
// Returns: True if it is empty, false otherwise
bool CharSequence::isEmpty(){
	if (count == 0) {
		return true;
	} else {
		return false;
	}
}

// Purpose: To clear the sequence. It uses a similar method as expanding array
// Args   : None
// Returns: None. Updates sequence to nothing, count = 0, and capacity to 1
void CharSequence::clear(){
	char *new_sequence = new char[1];
	delete []sequence;
	sequence = new_sequence;
	count = 0;
	capacity = 1;
}

// Purpose: To return the size, count, of the array
// Args   : None
// Returns: Size of the sequence, count (number of elements)
int CharSequence::size(){
	return count;
}

// Purpose: To combine two sequences together, adding one at the end of the old
// 	    one. To do so, the size of the array being added to the old is 
// 	    determined by using the size funtion. Then, the for loop adds the
// 	    first element of the array to the end of the old one. Expands 
// 	    whenever it is needed. Count is increased by the size of the added
// 	    array
//
// Args   : Pointer to the second CharSequence struct
// Returns: Nothing.
void CharSequence::concatenate(CharSequence *second_seq){
	int sec_array_size = second_seq->size();
	// cout << "second size" << sec_array_size << endl;
	for(int i = 0; i < sec_array_size; i++){
		if(count == capacity) {
			expand();
		}
		sequence[i+count] = second_seq->elementAt(i);
	}
	count += sec_array_size;
}

// Purpose: To return the first element in the array
// Args   : None
// Returns: The first element in the array as long as count != 0
char CharSequence::first(){
	if (count == 0) { // empty array, so an error
		throw out_of_range("count is 0");
	} else {
		return (sequence[0]);
	}
}

// Purpose: To return the last element of the sequence
// Args   : None
// Returns: The last element in the array if count != 0
char CharSequence::last(){
	if (count == 0) {
		throw out_of_range("count is 0");
	} else {
		return (sequence[count-1]);
	}
}

// Purpose: To return the element at the given index
// Args   : Desired index 
// Returns: element at the desired index
char CharSequence::elementAt(int index){
	if (index >= count or index < 0){
		throw out_of_range("out of range index");
	} else {

		return sequence[index];
	} 
}

// Purpose: To print the sequence
// Args   : None
// Returns: None
void CharSequence::print(){
	cout << "[CharSequence of size " << count << " <<";
	for (int i = 0; i < count; i++) {
		cout << sequence[i];
	}
	cout << ">>]";
}

// Purpose: To insert an element in the back of the sequence
// Args   : char element to insert
// Returns: Nothing. Updates the sequence with the new element in the back
void CharSequence::insertAtBack(char insert_char){
	if (count == capacity) {
		expand();
	}
	sequence[count] = insert_char;
	count++;
}

// Purpose: To insert an element in the front. First, all elements are shifted
// 		one over. Then, the 0th index is updated with the desired 
// 		element
// Args   : char element to insert
// Returns: Nothing
void CharSequence::insertAtFront(char insert_char){
	if (count == capacity){
		expand();
	}
	for (int i = count; i > 0; i--) {
		sequence[i] = sequence[i-1];
	}
	sequence[0] = insert_char;
	count++;
}

// Purpose: To insert an element at a desiered location.
// Args   : element to insert, and the location to insert it at
// Returns: None
void CharSequence::insertAt(char insert_char, int index){
	if (index > capacity or index < 0){
		throw out_of_range("Out of Range");
	} 
	if (count == capacity) {
		expand();
	}
	if (index == 0){ // adding at front
		insertAtFront(insert_char);
	} else if (index == count){ //adding at back
		insertAtBack(insert_char);
	} else {
		for (int i = count; i > index; i--){
			sequence[i] = sequence[i-1];
		}
		sequence[index] = insert_char;
		count++;
	}
}

// Purpose: To remove an element from the front
// Args   : None
// Returns: Nothing
void CharSequence::removeFromFront(){
	if(count == 0) {
		throw string("count is zero, Can't Remove");
	}
	for (int i = 0; i < count-1; i++) {
		sequence[i] = sequence[i+1];
	}
	sequence[count-1] = '\0';
	count--;
}

// Purpose: To remove an element from the back
// Args   : None
// Returns: Nothing
void CharSequence::removeFromBack(){
	if (count == 0){
		throw string("count is zero, Can't Remove");
	}
	sequence[count-1] = '\0';
	count--;
}

// Purpose: To remove an element from the desired index
// Args   : The Index to remove the element from
// Retruns: Nothing
void CharSequence::removeFrom(int index){
	if(index >= count or index < 0){
		throw out_of_range("Out of Range Index");
	}
	if(index == 0) { //same as removing from front
		removeFromFront(); 
	} else if(index == count-1) {
		removeFromBack(); //same as removing from the back
	} else {
		for (int i = index; i < count; i++){
			sequence[i] = sequence[i+1];
		}
		count--;
	}
}

// Purpose: To replace an element in the desired index with a new element
// Args   : Int Index, and the desired element
// Returns: Nothing, just updates the sequence
void CharSequence::replace(char element, int index){
	if(index >= count or index < 0) {
		throw "you wrong";
	}
	sequence[index] = element;
}

// Purpose: To expand the array
// Args   : None
// Returns: Nothing
void CharSequence::expand() {
	char *temp_seq = new char[capacity*2];
	for (int i = 0; i < count; i++) {
		temp_seq[i] = sequence[i];
	}
	delete []sequence;
	sequence = temp_seq;
	capacity = capacity*2;
}
