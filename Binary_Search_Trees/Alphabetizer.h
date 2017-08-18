// Name: Shehryar Malik (smalik02)
// Date: Oct. 26. 2016
// Alphabetizer.h
// Purpose: This file is the definition of the Alphabetizer class. The file
//			serves as an abstraction for the Alphabetizer class. The program
//			includes the StringBST.h, the interface of the Binary Search Tree
//			class and has an instance of the class.


#ifndef ALPHABETIZER_H_INCLUDED
#define ALPHABETIZER_H_INCLUDED
#include "StringBST.h"

class Alphabetizer{
public:
	Alphabetizer(); // constructor
	~Alphabetizer(); // destructor
	void run(); // run function for console input
	void run(std::string, std::string); // run function for file input stream
private:
	std::string input; // variable for console input data
	StringBST tree; // instance of the StringBST class
	void print(std::string, std::string); // print function
};
#endif