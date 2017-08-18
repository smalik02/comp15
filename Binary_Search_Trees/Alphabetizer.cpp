//
// Name: Shehryar Malik (smalik02)
// Date: Oct. 26. 2016
// Alphabetizer.cpp
// Purpose: This file is the implementation of the Alphabetizer class.
//			This class has two main run functions that create a BST using
//			the StringBST class based upon console input mode or file stream
//			input. This class is used by the main.cpp, which decides
//			which mode of input to run.

#include <iostream>
#include "StringBST.h"
#include "Alphabetizer.h"
#include <fstream>

using namespace std;

// Constructor
Alphabetizer::Alphabetizer(){
	input = "";
}

// Destructor
Alphabetizer::~Alphabetizer(){

}

// Purpose: This function reads in input from the command line and
//			creates a BST from user input. It then calls the print
//			function to print the tree in either front or reverse
//			mode, again depending on the user input.
// Args   : None
// Returns: Nothing
void Alphabetizer::run(){
	string order = "";
	cin >> order;
	if (order != "r" && order != "f"){
		cerr << "Order: f or r";
		exit(1);
	}
	while(cin >> input){
		tree.add(input);
	}
	print("cin", order);
}

// Purpose: This function reads in input from filestream and
//			creates a BST from file input. It then calls the print
//			function to print the tree in either front or reverse
//			mode, again depending on the user input.
// Args   : String order for printing the tree (front or reverse),
//			and filename to read the inputs from
// Returns: Nothing
void Alphabetizer::run(string filename, string order){
	ifstream ifs; // input filestream object created
	ifs.open(filename);
	if (not ifs.is_open()) { // if file couldnt be opened
		cerr << "Unable to read " << filename;
		return;
	}
	string s;
	for (ifs >> s; not ifs.eof(); ifs >> s){
		//cout << s << " ";
		tree.add(s);
	}
	ifs.close();
	print(filename, order);
}

// Purpose: This function prints the tree in either the front or
//			reverse mode. 
// Args   : String 
// Returns: Nothing
void Alphabetizer::print(string input_mode, string order){
	cout << "[ " << input_mode << ", " << order << " : ";
	if (order == "f"){
		while(!tree.isEmpty()){
			cout << tree.getMin();
			if (tree.size() == 1){
				cout << " ";
			} else {
				cout << ", ";
			}
			tree.removeMin();
		}
	} else {
		while (!tree.isEmpty()){
			cout << tree.getMax();
			if (tree.size() == 1){
				cout << " ";
			} else {
				cout << ", ";
			}
			tree.removeMax();
		}
	}
	cout << "]"; 
}