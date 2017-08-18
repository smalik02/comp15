/*
	Name: Shehryar Malik (smalik02)
	Date: Dec. 1st. 2016
	File: Gerp.cpp
	
	This file is the implementation of the Gerp class. The purpose
	of this class is to handle the parsing of the file and searching
	the tree. This file does not necessarily do the searching or adding
	the word in the trie. It calls the Trie add and search functions to
	do so. This class is used by the user to perform a search, by calling
	the search function.

	The parse_file function is called by the File_Manager class. The
	function calls the Trie add function. The function creates a 
	vector of vectors of strings that holds all of the lines
	from the files. This allows me to use less memory as the lines
	themselves will not be stored numerous times in the trie.

	The search function is called by the user in main to perform a
	search. The function takes in a search mode (regular or insensitive)
	when searching. The function also calls the Trie search function
	to search the trie, which will return the line numbers and file name
	for the word, if found. The foudn information is used to parse through
	the vector of vectors of strings (file_lines) and print the respective
	information.

*/



#include "Gerp.h"
#include <iostream>
#include "Trie.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void read_line(string line, int line_number);

// constructor
Gerp::Gerp(){

}
// destructor
Gerp::~Gerp(){

}

// Purpose: To convert the string to lowercase. The function
//			parses through each of the chars and converts them
//			to lowercase.
// Args   : string word to convert to lowercase
// Returns: converted string
string Gerp::lower_string(string word)
{
	string new_string = "";
	for(unsigned index = 0; index < word.length(); ++index) {
		new_string += tolower(word[index]);
	}
	return new_string;
}

// Purpose: To parse the given the file. The function first pushes the
//			file_name to the file_names vector. Then, it creates the
//			fstream to parse the file line by line. Then, the line is
//			pushed onto the lines vector. Then, a input string stream is
//			created to parse the line word by word. The word is then
//			added to both the case sensitive (regular) and insensitive
//			word (but first lowercased for the later case). Once at the
//			end of the file, the lines vector is added is file_lines
//			vector of vector of strings. 

// Args   : string filename
// Returns: Nothing
void Gerp::parse_file(string file_name){
	file_names.push_back(file_name);
	ifstream fs;
	string line = "";
	int line_number = 0;
	int file_index = find_file_index(file_name);
	//cout << "before the loop " << c << endl;
	fs.open(file_name);
	while (getline(fs, line)){
	  	// cerr << "reading a line " << endl;
		// Reading line by line
		file_line.push_back(line);
		line_number++; // line number in the file
		read_line(line, line_number, file_index);
	}
	files_lines.push_back(file_line);
	// added the lines in this file to the vector will lines of all of
	// the files
	file_line.clear(); // clear the vector of lines for just one file
	fs.close();
}

// Purpose: To parse a line in a given file. The function is called by
//			the Gerps parse_file function once its gets one line.
// Args   : By reference, the line to parse, the int line_number in file,
//			and the int file_index
// Returns: Nothing
void Gerp::read_line(string &line, int &line_number, int &file_index){
	istringstream ss(line);
	string word;
		while (ss >> word){ 
			// Reading word by word and adding to the Trie
			tree.add(word, file_index, line_number);	
			tree_insensitive.add(lower_string(word),file_index,line_number);
		}
}

// Purpose: To search the trie for the given word and the given search mode.
//			The function creates an instance of vector of Line_Info that
//			will be used to store/copy the line numbers and the file names
//			of where the word occurs once it is returned from the trie
//			search function.
//			If found, a helper function, find_file_index, is used
//			to find the index of where the file lines are in the
//			file_lines vector of vectors.
//			It then calls the helper print function that prints
//			the information.
//
// Args   : string word to search, and the search mode
// Returns: Nothing
void Gerp::search(string word, string mode){
	bool found = false; // boolean to determine if the word was found
	if (mode == "regular"){
		searched = tree.search(word, found);
	} else {
		searched = tree_insensitive.search(lower_string(word), found);
	}
	// searched the Trie!!
	// If the word was found, going to print the information...almost over
	if (found){
		print(searched);
		found = false;
	} else {
		cout << word << " Not Found. Try with @insensitive or @i."<< endl;
	}
}

// Purpose: A helper function that determines the index of the file in
//			the file_lines vector. It has to iterate through every instance
//			of the file_name in the searched vector and compare it with
//			the file_names vector to determine the index.
// Args   : vector of Line_Info searched
// Returns: vector<int> of the file indicies
int Gerp::find_file_index(string &file_name){
	int file_index = 0;
		for (int k = 0; k < (int)file_names.size(); k++){
			// comparing it with every element in the 
			if (file_names[k] != file_name){
				file_index++;
			} else {
				return file_index;
			}
		}
	return file_index;
}

// Purpose: To print the output
// Args   : vector<Line_Info> of the searched info
// Returns: Nothing!
void Gerp::print(const vector<Line_Info>& searched){
	int file_num = 0, line_num = 0, prev_file_num = 0, prev_line_num = 0;
	for (int occur = 0; occur < (int)searched.size(); occur++){
		file_num = searched[occur].file_num;
		line_num = searched[occur].number;
		if ((file_num == prev_file_num) && (line_num == prev_line_num)){
			goto a;
		}
		cout << file_names[file_num]<< ":" << line_num;
		cout << ": ";
		cout << files_lines.at(file_num).at(line_num-1);
		cout << endl;
		a:
		prev_line_num = line_num;
		prev_file_num = file_num;
	}
}