/*
	Name: Shehryar Malik (smalik02)
	Date: Dec. 1st. 2016
	File: Trie.cpp
	
	This file is the implementation of the Trie class. The purpose
	of this class is to build the trie, the main data structure used
	to index the words in the files. The trie class is used by the
	Gerp class when adding a word or searching for the word.

	The main functions are the add and the search functions.

*/


#include "Trie.h"
#include <iostream>
#include "Node.h"
#include <vector>
#include <locale>


using namespace std;

void recurse_delete(Node *node);

// Constructor
Trie::Trie(){
	root = new Node;
	root->create_children();
}

// Destructor (Calls a recursive function to delete every node)
Trie::~Trie(){
	recurse_delete(root);
}

// Purpose: To delete every node in the trie recursively
// Args   : Node pointer to start the delete from
// Returns: Nothing
void recurse_delete(Node *node){
	if (node == NULL){
		return;
	}
	if (node->hasChild()){
		for (int i = 0; i < 96; i++){
			// i + 32 since the ASCII values are moved 32 down in findChild
			recurse_delete(node->findChild(i+32));
		}
	}
	delete node;
	node = NULL;
	return;
}

// Purpose: To add a word to the trie. The function is called
//			by Gerp class after having read a word. The function
//			checks if the child already exits. If it does, then it
//			just moves the temp node to the child, and updates the
//			lines vector containing the line number and file name info
//			If the child does not exit, then a new node is created.
// Args   : string word to add, string file name, and the line number
//			for the word
// Returns: Nothing
void Trie::add(string word, int file_index, int line){
	Node *temp = root;
	//cout << "starting loop \n";
	for (int i = 0; i < (int)word.length(); i++){
		if (!temp->hasChild()){
			temp->create_children();
		}
		if (temp->findChild(word[i]) != NULL){
			temp = temp->findChild(word[i]);
			//cout << "temp moved to the already child" << endl;
		} else {
		    Node *new_node = new Node;
			temp->appendChild(new_node, word[i]);
			//cerr << "appended " << word[i] << endl;
			temp = new_node;
		}
	}
	//	cout<< " creating the line_info for the word" << endl;
	Line_Info new_line;
	new_line.file_num = file_index;
	new_line.number = line;
	temp->add_to_lines(new_line);
	temp->set_Word(true);
	//cout << temp->isWord() << endl;
}

// Purpose: To search a word in the trie. The function is called by
//			the Gerp class that searches for the word asked by the
//			if the children match up with the chars of the word.
//			If so, then it sets found to true and returns the 
//			lines vector of type Line_Info. If not, an empty vector
//			is returned.
// Args   : string word to add, string file name, and the line number
//			for the word
// Returns: Nothing
const vector<Line_Info>& Trie::search(string word, bool &found){
	Node *temp = root;
	// cout << word << " " << word.length() << endl;
	// traversing thorugh the trie to find the word
	for (unsigned i = 0; i < word.length(); i++){
		if (temp->findChild(word[i]) != NULL){
			temp = temp->findChild(word[i]);
		} else {
			return empty_none_found;
		}
	}
	if (temp->isWord()){ // word was found
		found = true;
		// return the appropriate Line_Info for printing
		return temp->get_line_info();
	}
		return empty_none_found;
}
