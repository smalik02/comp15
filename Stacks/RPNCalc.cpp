// RPNCalc.cpp
//
// Shehryar Malik
// Sep. 25. 2016
// HW3
//
// This file implements the RPNCalc class. It uses functions to read in the
// user input and add or take off data from the stack created by the 
// DoubleStack class
//
//
// This file also utilizes functions and ideas given to us by the TA's

#include <iostream>
#include "RPNCalc.h"
#include <cstdio>
#include <fstream>

using namespace std;

// constructor
RPNCalc::RPNCalc(){
	run_true = true;
	input = "";
	in_file = false;
//	stack = new DoubleStack;
}

// destructor
RPNCalc::~RPNCalc(){
	
}

// Purpose: To take in the input from the user in order to perform the 
// 		calculations. 
// Args   : None
// Returns: Nothing
void RPNCalc::run() {
	ifstream null_fs;
	while (run_true){
		cin >> input;
		read_input(input, null_fs);
		//cout << "back in run" << endl;
	}
}

// Purpose: To convert a string into a double if it is a number. Code was
// 		provided by Comp15 TA's
// Args   : string s to convert to double and a pointer to a double variable
// 		where the converted double will be stored
// Returns: True if the string was converted to a double, false otherwise
bool RPNCalc::got_double(string s, double *resultp){
	return sscanf(s.c_str(), "%lf", resultp) == 1;
}

// Purpose: To perfom the corresponding operation based upon the user input
// Args   : string input consisting of the operation (+, /, *, -)
// Returns: Nothing
void RPNCalc::operations(string input){
	double num1 = stack.pop(); // first number for the operation
	double num2 = stack.pop(); // second number
	if (input == "-"){
		output = num2 - num1;
	} else if (input == "+") {
		output = num2 + num1;
	} else if (input == "/") {
		output = num2/num1;
	} else if (input == "*"){
		output = num2*num1;
	}
	stack.push(output); // result is added to the stack
}

// Purpose: To print the top number on the stack
// Args   : None
// Returns: Nothing, just prints the top item in the stack
void RPNCalc::print_first(){
	double num = stack.top();
	cout << num << endl;
}

// Purpose: To read in the file containing the data and add it to the stack
// Args   : string name of the file
// Returns: Nothing
// Credit also goes to the TA's for providing with the code. The code was
// modified a little bit to fit this programs desired taks
void RPNCalc::read_in_file(string input){
	string filename = input;
	in_file = true;
	ifstream fs; // ifstream object to open and close the file
	//cout << filename << endl;
	fs.open(filename); // file is opened
	if (not fs.is_open()) { // if file couldnt be opened
		cerr << "Unable to read " << filename << endl;
		in_file = false;
		return;
	}
	copy_strings_from(fs); // the content is copied from the fs object
	fs.close(); // file is closed
	//copy_strings_from(cin); this was in the sample code; however, it
		// is not needed as it cin the input after the file was
		// closed. That task is handled by run.
}

// Purpose: To copy the strings from the file. The function calls the read
// 		input function,  which takes in the input and determines
// 		what taks to perform. 
// Args   : istream address of the file object
// Returns: Nothing
void RPNCalc::copy_strings_from(istream &file){
	string s;
	for (file >> s; not file.eof() and run_true; file >> s){
		read_input(s, file);
		//cout << "in copy " << s;
	}	
}

// Purpose: To read the input from the user and analyze it
// Args   : The string user input
// Returns: Nothing
void RPNCalc::read_input(string s, istream &fs) {
	double pointer = 0;
	if (s == "+" or s == "-" or s == "/" or s == "*"){
		operations(s);
	} else if (s == "p" or s == "P"){
		print_first();
	} else if (s == "c" or s == "C"){
		stack.clear();
	} else if (got_double(s, &pointer)) {
		stack.push(pointer);
	} else if (s == "f" or s == "F"){
		if (in_file){
			fs >> s; 
		} else {
			cin >> s; // read in the file name now
		}
		read_in_file(s);
		in_file = false;
	} else if (s == "q" or s == "Q"){
		//cout << "got q" << endl;
		run_true = false;
		in_file = false;
		return;
	} else {
		cerr << s << ": unimplemented" << endl;
	}
}
