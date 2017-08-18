// Name: Shehryar Malik (smalik02)
// Date: Oct. 26. 2016
// AlphaTesting.cpp
// 
// Purpose: This file is tests the AlphaTesting class. It is broken down
//			into different sub-test functions. It is very simple because
//			one there are not many test cases, and second, all the 
//			interactions occur at the console input level. It is explained
//			more in README in the testing section.

#include <iostream>
#include "Alphabetizer.h"

using namespace std;

void run_test1();
void run_test2(string order, string filename);

int main(int argc, char *argv[]){
	if (argc == 1){
		run_test1();
	} else if (argc == 3){
		string order(argv[1]);
		string filename = argv[2];
		if (order != "f" && order != "r"){
			cerr << "Usage : alphabetizer [order filename]";
			return 1;
		}
		run_test2(filename, order);
	} else {
		cerr << "Usage : alphabetizer [order filename]";
		return 1;
	}
}

void run_test1(){
	Alphabetizer a;
	a.run();
}

void run_test2(string filename, string order){
	Alphabetizer a;
	a.run(filename, order);
}
