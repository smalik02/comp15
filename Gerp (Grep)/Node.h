/*
	Name: Shehryar Malik (smalik02)
	Date: Dec. 1st. 2016
	File: Node.h
	
	This file is the definition of the Node class. The purpose
	of this class is to define the node of the trie, the main 
	data structure for indexing the elements.
	The class is used by the Trie in constructing the Trie. 

*/

#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

// Struct for storing the information for the node that is the last
// char in the word, i.e if a word is formed.
struct Line_Info{
	int number;
	int file_num;
};

class Node{
public:
	Node(); // constructor
	~Node(); // destructor

	//function for adding the Line_Info into the lines vector to store
	//info where the word occurs in the index
	void add_to_lines(Line_Info);

	//function to get the Line_Info needed for printing!
	const std::vector<Line_Info>& get_line_info();

	// function for returning the child
	Node *findChild(int c);

	bool isWord();
	void set_Word(bool);

	// function that determines if the same word was just added
	int previous_occur();

	// function to append the child to the parent
	void appendChild(Node*, int);

	void create_children();

	bool hasChild();

private:
	bool word; // if the node forms a word
	Node **children; // children nodes
	bool has_children;  // boolean if the node has children
	std::vector<Line_Info> lines; 
	// vector of Line_Info for storing where the word appears
};

#endif
