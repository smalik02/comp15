// RPNCalc.h
// Shehryar Malik
// HW3
//
// The file defines the functions for the RPNCalc class.
//

#ifndef RPNCalc_H_INCLUDED
#define RPNCalc_H_INCLUDED

#include "DoubleStack.h"
#include <fstream>

class RPNCalc {
	public:
		RPNCalc(); //default constructor
		~RPNCalc(); //destructor
		void run(); //main operation function
	private:
		bool run_true; // for determining how long to run
		std::string input; // user input
		bool got_double(std::string s, double *resultp);
			// to determine if the string can be converted into
			// a double

		void operations(std::string);
			// function to perform (+, -, /, *) operations

		void print_first(); // print the first element in the stack
		double output; // output from the operations
		void read_in_file(std::string); // function to read in file
		void copy_strings_from(std::istream &infile);
			// function to copy the data from the file

		void read_input(std::string s, std::istream &fs);
			// function to read the user input and interpret it

		DoubleStack stack; // an instance of the stack
		bool in_file; // bool to see if input should be read from the
			// file
};

#endif
