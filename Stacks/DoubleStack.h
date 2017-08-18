// DoubleStack.h
// 
// Shehryar Malik
// Sep 23 2016
// HW3
//
// This file defines the DoubleStack Class functions. The class utilizes lists
// to make a stack struct
//

#ifndef DoubleStack_H_INCLUDED
#define DoubleStack_H_INCLUDED

class DoubleStack{
	struct Node{
		double data;
		Node *next;
	};
	public: 
		DoubleStack(); // constructor
		DoubleStack(double number[], int size); //overloaded
		~DoubleStack(); // destrcutor
		bool isEmpty(); //if list is empty or not
		void clear(); //to make the list empty
		int size(); //size of the list in the stack
		double top(); //returns the first element in the stack
		double pop(); //removes the first element and returns it
		void push(double); //add an element in the stack

	private:
		Node *head;
		int count;
};

#endif
