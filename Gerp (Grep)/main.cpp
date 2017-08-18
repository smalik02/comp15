// Name: Shehryar Malik (smalik02)
// Date: Dec. 2. 2016

// File: main.cpp
// Purpose: This files serves as the user side of the program. The file
//			checks if the arguments are valid. The main also creates
//			an instance of the File_Manager and Gerp. It passes in the 
//			directory to index to the File_Manager. Gerp is used for
//			searching the word.
//			The main also cins all of the Query and prints out the
//			appropriate dialogue for the user!

#include <iostream>
#include "Gerp.h"
#include "File_Manager.h"

int main(int argc, char *argv[]){
	if (argc > 2){
		std::cerr << "Usage:  gerp directory\n";
		std::cerr << "            where:  directory is a valid directory";
		exit(EXIT_FAILURE);
	}
	File_Manager f;
	Gerp g;
	//std::cout << argv[1] << std::endl;
	f.traverse_directory(g, argv);
	std::cout << "Query? ";
	std::string input, mode;
	while (std::cin >> input){
		if (input == "@i" || input == "@insensitive"){
			mode = "insensitive";
			std::cin >> input;
		} else if (input == "@q" || input == "@quit"){
			std::cout << "\n";
			std::cout << "Goodbye! Thank you and have a nice day.\n";
			return 0;
		} else {
			mode = "regular";
		}
		g.search(input, mode);
		std::cout << "Query? ";
	}
	std::cout << "\nGoodbye! Thank you and have a nice day.\n";
	return 0;
}