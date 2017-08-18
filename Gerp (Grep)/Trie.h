/*
	Name: Shehryar Malik (smalik02)
	Date: Dec. 1st. 2016
	File: Trie.h
	
	This file is the definition of the Trie class. The purpose
	of this class is to build the trie, the main data structure used
	to index the words in the files. The trie class is used by the
	Gerp class when adding a word or searching for the word.

	The main functions are the add and the search functions.

*/

#ifndef TRIE_H
#define TRIE_H

#include "Node.h"
#include <vector>
#include <string>

class Trie{
public:
	Trie();
	~Trie();
	void add(std::string word, int file_index, int line);
	const std::vector<Line_Info>& search(std::string word, bool&);
private:
	// a dummy empty vector that is returned if the word was not found
	const std::vector<Line_Info> empty_none_found;
	Node *root;
};
#endif