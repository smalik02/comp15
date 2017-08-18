/*
	Name: Shehryar Malik (smalik02)
	Date: Dec. 1st. 2016
	File: Node.cpp
	
	This file is the implementation of the Node class. The purpose
	of this class is to define the node of the trie, the main 
	data structure for indexing the elements.
	The class is used by the Trie in constructing the Trie. 

	The class has a Line_Info stuct that stores the int line number and
	the int file index. It is used to store one instance of when the word
	appears.
	It also has a vector of Line_Infos, lines, that stores all of the
	occurances of the word in the index!

*/

#include <iostream>
#include "Node.h"
using namespace std;

// constructor
// It initializes the children to NULL
Node::Node(){
	word = false;
	has_children = false;
}

// destructor ... Nothing!
Node::~Node(){
	if (hasChild()){
		delete [] children;
	}
}

// Purpose: To find the child of the node, using the ASCII value
//			of the int-32 (as trie is concerned with ASCII values
//			between 32 and 126)
// Args   : Int index
// Returns: Pointer to the Node of the child
Node* Node::findChild(int c){
	if (children[c-32] == NULL){
		return NULL;
	} else {
		return children[c-32];
	}
}

// Purpose: To determine if the node is the word(i.e. it forms a word)
// Args   : None
// Returns: boolean true if it is
bool Node::isWord(){
	if (word){
		return true;
	}
	return false;
}

// Purpose: To set the boolean value of the word to true or fasle
// Args   : boolean value to set the word to
// Returns: Nothing
void Node::set_Word(bool is_word){
	word = is_word;
}

// Purpose: To add the Line_Info of the word to the collection of
// 			Line_Infos, the lines vector
// Args   : Line_Info to add to the lines
// Returns: Nothing
void Node::add_to_lines(Line_Info info){
	lines.push_back(info);
//	cout << "line info size " << sizeof(lines) << endl;
}

// Purpose: To get the lines vector needed for printing the information
//			The lines vector is passed as a const because I do not want
//			the user to be able to change and modify the vector. The 
//			vector is needed for printing. 
// Args   : Nothing
// Returns: Const reference to the lines vector of Line_Info
const vector<Line_Info>& Node::get_line_info(){
	return lines;
}

// Purpose: To determine if the word appears on the same line
// Args   : None
// Returns: the int last line number in the lines vector
int Node::previous_occur(){
	int last_number = lines.at((int)lines.size()-1).number;
	//cout << "last number " << last_number << endl;
	return last_number;
}

// Purpose: To add the node to the parents children
// Args   : children's node, and the index of the child
// Returns: Nothing
void Node::appendChild(Node *node, int index){
	children[index-32] = node;
}

// Purpose: To create and initialize the children for the node
// Args   : None
// Returns: Nothing
void Node::create_children(){
	// allocate the memory
	children = new Node*[96];
	//	cout << "Node created " << endl;
	for (int i = 0; i < 96; i++){
		children[i] = NULL;
	}
	// node has children is set to true!
	has_children = true;
}

// Purpose: To determine if the node has a child
// Args   : None
// Returns: boolean value, true if it has a child
bool Node::hasChild(){
//	cerr << "has children: " << has_children << endl;
	return has_children;
}