// Name: Shehryar Malik (smalik02)
// Date: Oct. 26. 2016
// StringBST.h
// Purpose: This file is the definition of the StringBST class. The file
//			serves as an abstraction for the StringBST class. The tree
//			is created using a linked list approach. Its left node has
//			values less than the root, and right has values greater.
//			The file also serves as an interface for the Alphabetizer class.

#ifndef STRINGBST_H_INCLUDED
#define STRINGBST_H_INCLUDED

class StringBST{
	public: 
		StringBST(); //constructor
		StringBST(std::string [], int); // overloaded constructor
		~StringBST(); //destructor
		bool isEmpty(); 
		void clear();
		int size();
		void print();
		void add(std::string); //adding an element into the tree
		bool remove(std::string); //removing an element from the tree
		std::string getMin(); //returning a min string in the tree
		std::string getMax(); //returning a max string in the tree
		void removeMin(); //removing the min string from the tree
		void removeMax(); //removing the max string from the tree
		bool contains(std::string); //determining if tree contains a value
	private:
		struct Tree{ // tree data structure
			std::string data;
			int num_strings;
			Tree *left;
			Tree *right;
		};
		Tree *root; // root of the tree

		/****** Helpers recursive functions for the public functions ******/

		int size_recurse(Tree*);
		void add_recurse(Tree*, Tree*, std::string);
		void print_recurse(Tree*);
		std::string getMin_recurse(Tree*);
		std::string getMax_recurse(Tree*);
		void removeMin_recurse(Tree*);
		void removeMax_recurse(Tree*);
		bool contains_recurse(Tree*, std::string);
		void clear_recurse(Tree*);
		Tree* remove_recurse(Tree*, std::string, bool&);
		Tree* getMinNode(Tree*);
};

#endif