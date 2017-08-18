// Shehryar Malik
// Comp15
// HW 1
// Sep. 8. 2016
//
// Test file for the CharSequence Class. 
// The purpose of this file is to test different functions of the CharSequence Class.
//
//
#include <iostream>
#include "CharSequence.h"

using namespace std;

int main(){
	CharSequence charSequence;
	charSequence.isEmpty(); //to make sure it is intialzed as empty.
	charSequence.print(); //nothing should be printed;
	charSequence.insertAtFront('a'); //add in the front
	charSequence.clear(); //clear the array
	charSequence.print(); //nothing should be printed
	
	charSequence.insertAtFront('c');
	charSequence.insertAtBack('t');
	charSequence.insertAt('a',1);
	charSequence.size(); //should be 3
	charSequence.print(); //should be cat with the msg
	
	CharSequence charSequence2('t');
	charSequence2.insertAtBack('a');
	charSequence2.insertAtBack('c');
	charSequence.concatenate(&charSequence2); //combine two sequences
	charSequence.print(); //cattac should be printed
	
	charSequence.removeFromFront(); //should become attac
	charSequence.removeFromBack(); //becomes atta
	cout <<	charSequence.size();
//	charSequence.removeFrom(4); //should throw an exception -- core dumped
	charSequence.removeFrom(3);
	charSequence.print(); //should print att

	charSequence.replace('t', 0);
	charSequence.print(); //should print ttt

	charSequence.clear();
	charSequence.insertAtFront('a');
	charSequence.insertAtBack('b');
	charSequence.insertAt('c', 2);
	charSequence.insertAtBack('d');
	charSequence.print();
	charSequence.removeFrom(1);
	charSequence.print();
}
