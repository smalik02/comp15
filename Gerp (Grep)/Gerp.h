/*
	Name: Shehryar Malik (smalik02)
	Date: Dec. 1st. 2016
	File: Gerp.h
	
	This file is the definition of the Gerp class. The purpose
	of this class is to handle the parsing of the file and searching
	the tree. This file does not necessarily do the searching or adding
	the word in the trie. It calls the Trie add and search functions to
	do so. This class is used by the user to perform a search, by calling
	the search function.

*/

#ifndef GERP_H
#define GERP_H

#include <vector>
#include <string>
#include "Trie.h"

class Gerp{
public:
	Gerp();
	~Gerp();
	void parse_file(std::string);
	void search(std::string, std::string);
private:
	// structure for holding all of the lines in the file
	std::vector<std::vector<std::string>> files_lines;

	// structure for storing the names of the files, in order
	// to find the index
	std::vector<std::string> file_names;

	// instances of the Tries (both search modes)
	Trie tree;
	Trie tree_insensitive;

	// function for finding the index of the file_name
	int find_file_index(std::string&);

	// function for printing the searched info
	void print(const std::vector<Line_Info>&);

	// function for converting the string to lower_case
	std::string lower_string(std::string);

	// helper function for parsing the line. It calls the
	// Trie's add function to add the word
	void read_line(std::string&, int&, int&);

	// vector of Line_Info that will store the queried
	// words line number and file index
	std::vector<Line_Info> searched;

	// vector for storing line in the file
	std::vector<std::string> file_line;
};

#endif