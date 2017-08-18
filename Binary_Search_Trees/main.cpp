// Name: Shehryar Malik
// Date: Oct. 27. 2016
// main.cpp
// Purpose: To interface with the alphabetizer class. This class serves
//			as a user interface class. It determines if there are correct
//			number and types of arguments and calls the corresponding
//			run function from the alphabetizer class.

#include <iostream>
#include "Alphabetizer.h"

using namespace std;

int main(int argc, char *argv[]){
	Alphabetizer a;
	if (argc == 1){
		a.run();
	} else if (argc == 3){
		string order = argv[1];
		string filename = argv[2];
		if (order != "f" && order != "r"){
			cerr << "Usage : alphabetizer [order filename]";
			return 1;
		}
		a.run(filename, order);
	} else {
		cerr << "Usage : alphabetizer [order filename]";
		return 1;
	}
}