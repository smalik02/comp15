// Name: Shehryar Malik (smalik02)
// Date: Oct 26. 2016
// StringBST.cpp
// Purpose: This file is the implementation of the StringBST class.
//			This serves as the implementation of the whole
//			program as this class is being used by the Alphabetizer
//			class, which is being used by main or any other user.
//			The program creates a Binary Search Tree and defines functions
//			such as contains, remove, getMin, print, etc. All of the
//			functions, except for isEmpty & Overloaded costructor are done
//			recursively.

#include <iostream>
#include "StringBST.h"

using namespace std;

// constructor
StringBST::StringBST(){
	root = NULL;
}

// overloaded constructor
// It calls the add function to recursively create the tree
StringBST::StringBST(string input[], int size){
	root = NULL;
	for (int i = 0; i < size; i++){
		//cout << "in overloaded" << "input: " << input[i] << endl;
		add(input[i]);
		//cout << "added" << endl;
	}
}

// destructor
// It calls the clear function
StringBST::~StringBST(){
	clear();
}

// Purpose: To clear the tree and make it an empty NULL tree
//			It calls a helper clear_recurse function to recursively
//			delete the tree
// Args   : None
// Returns: Nothing
void StringBST::clear(){
	if (root != NULL){
		clear_recurse(root);
		root = NULL;
	}	
}

// Purpose: To recursively clear the tree. It iterates its left and right
//			node until it reaches null for both (meaning its the node is
//			a leaf) and then deletes it.
// Args   : Takes in a pointer to a node, the root of the tree specifically
// Returns: Nothing
void StringBST::clear_recurse(Tree *node){
	if (node == NULL){
		return;
	}
	clear_recurse(node->left); //iterate to the left
	clear_recurse(node->right); //iterate to the right
	delete node; //delete the node
	node = NULL;
}

// Purpose: To determine if the tree is empty or not. If the root is NULL,
//			then it is empty.
// Args   : None
// Returns: bool value; true if empty
bool StringBST::isEmpty(){
	if (root == NULL){
		return true;
	}
	return false;
}

// Purpose: To determine the size of the tree. It calss a helper size_recurse
//			function to do so. 
// Args   : None
// Returns: int size of the tree
int StringBST::size(){
	if (root == NULL){
		return 0;
	}
	return size_recurse(root);
}

// Purpose: To determine the size of the tree recursively. If the root is
//			null, then it returns 0, the base case. Then, the count is
//			set to the num_strings of the current node + the num_strings
//			of all the nodes on the left, and all of the nodes on the right.
//			Finally, after all the iterations, it returns the count.
// Args   : Tree root pointer.
// Returns: The int size of the size
int StringBST::size_recurse(Tree *root){
	if (root == NULL){ // base case
		return 0;
	}
	int count = 0;
	//current size + rest
	count = root->num_strings + size_recurse(root->left); 
	count += size_recurse(root->right);
	return count;
}

// Purpose: To add a new string in the tree recursively. It calls a helper
//			recursively function, add_recurse.
// Args   : string input to add
// Returns: Nothing
void StringBST::add(string input){
	if (root == NULL){
		root = new Tree;
		root->data = input;
		root->num_strings = 1;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	add_recurse(root, root, input);
}

// Purpose: To add a string into the tree recursively. The algorithm is
//			detailed in the Algorithms section in README
// Args   : Tree node pointer, parent pointer, and string input to add
// Returns: Nothing
void StringBST::add_recurse(Tree *node, Tree *parent, string input){
	if (node == NULL){ // base case
		Tree *new_node = new Tree;
		new_node->data = input;
		new_node->num_strings = 1;
		new_node->left = NULL;
		new_node->right = NULL;
		if (parent->data > new_node->data){ //added to left parent node
			parent->left = new_node;
		} else {
			parent->right = new_node; //added to the right parent node
		}
		return;
	}
	if (node->data == input){ // if the string already exists, size increased
		node->num_strings += 1;
	} else if (node->data > input){
		//if value being added is less than the current node, recurse through
		//left subtree
		add_recurse(node->left, node, input);
	} else {
		//else recurse through right subtree
		add_recurse(node->right, node, input);
	}
}

// Purpose: To print the tree. It calls a helper recursive function
// Args   : None
// Returns: Nothing
void StringBST::print(){
	print_recurse(root);
	//cout << endl;
}

// Purpose: To print the tree recursively. 
// Args   : Take a pointer to a node to start printing from
// Retruns: Nothing
void StringBST::print_recurse(Tree *node){
	if (node == NULL){
		cout << "[]"; // empty node print
		return;
	}
	cout << "[";
	print_recurse(node->left);
	cout << " " << node->data << " " << node->num_strings << " ";
	print_recurse(node->right);
	cout << "]";
}

// Purpose: To remove a string input from a tree recursively. It calls a
//			helper function when the tree is not empty
// Args   : string input to remove
// Returns: True if an instance of the string was removed
bool StringBST::remove(string input){
	if (root == NULL){
		return false;
	}
	bool deleted = false;
	root = remove_recurse(root, input, deleted);
	return deleted;
}

// Purpose: To remove a string from the tree recursively. The algorithm is
//			explained in README
// Args   : Tree pointer to a node, string input to remove, and boolean
//			value by reference for determining if a value was removed
// Retruns: Tree pointer to the root of the tree
StringBST::Tree* StringBST::remove_recurse(Tree *node, string input,
											bool &deleted){
	if (node == NULL){
		deleted = false;
		return node;
	}
	if (node->data > input){ // traverse to the left of the tree
		node->left = remove_recurse(node->left, input, deleted);
	} else if (node->data < input){ //traverse to the right
		node->right = remove_recurse(node->right, input, deleted);
	} else if (node->data == input){ //node to be removed
		deleted = true;
		if (node->num_strings > 1){ //more than one instance
			node->num_strings -= 1;
			return node;
		} else if (node->left == NULL){ //if it has none or one child
			Tree *temp = node->right;
			delete node;
			return temp;
		} else if (node->right == NULL){ //none or one child
			Tree *temp = node->left;
			delete node;
			return temp;
		}
		Tree *temp = getMinNode(node->right);
		node->data = temp->data; //copy the data from the min node over
		node->num_strings = temp->num_strings;
		node->right = remove_recurse(node->right, temp->data, deleted);
	}
	return node;
} 

// Purpose: To get the pointer to the node of min value from the given
//			node's pointer recursively
// Args   : Tree pointer to a node 
// Returns: Tree pointer to the min node
StringBST::Tree* StringBST::getMinNode(Tree *node){
	if (node->left == NULL){
		return node;
	}
	return getMinNode(node->left);
}

// Purpose: To get the minimum string in the tree recursively. It calls
//			a helper function to do so.
// Args   : None
// Retruns: Min string in the tree
string StringBST::getMin (){
	if (root == NULL){
		throw runtime_error("getMin:empty_tree");
	}
	return getMin_recurse(root);
}

// Purpose: To find the min string in the tree recursively. It iterates to
//			the leftmost node in the tree, and returns the data.
// Args   : Tree pointer to the node/root
// Returns: Min string
string StringBST::getMin_recurse(Tree *node){
	if (node->left == NULL){
		return node->data;
	}
	return getMin_recurse(node->left);
}

// Purpose: To get the maximum string in the tree recursively. It calls
//			a helper function to do so.
// Args   : None
// Retruns: Max string in the tree
string StringBST::getMax(){
	if (root == NULL){
		throw runtime_error("getMax:empty_tree");
	}
	return getMax_recurse(root);
}

// Purpose: To find the max string in the tree recursively. It iterates to
//			the rightmost node in the tree, and returns the data.
// Args   : Tree pointer to the node/root
// Returns: Max string
string StringBST::getMax_recurse(Tree *node){
	if (node->right == NULL){
		return node->data;
	}
	return getMax_recurse(node->right);
}

// Purpose: To remove the min node from the tree recursively. It calls a
//			helper function, removeMin_recurse
// Args   : None
// Returns: Nothing
void StringBST::removeMin(){
	removeMin_recurse(root);
}

// Purpose: To remove a min node from the tree. Base case is if tree is
//			empty, in which case it returns nothing.
//			It could calls the remove function and gives the getMin string.
//			Without using remove
//			Since its min, it will always iterate through the left child
//			of the node. If the left child of the node is NULL, then,
//			the node is min value. But, there are few cases within that.
//			If the num of strings is greater than 1, then one instance
//			is just removed by decrementing the num_strings.
//			If the node to be removed is same as the parent, then the parent
//			or the root in that case, will get the right child as the current
//			will be deleted. Also, if the right child of the node being 
//			deleted is not empty, then parent's left will get that child.
//			And finally, the node is deleted.
// Args   : The tree pointer to the current node and one to the parent
// Returns: Nothin
void StringBST::removeMin_recurse(Tree *node){
	if (node == NULL) return;
	/*if (node->left == NULL){
		if (node->num_strings == 1) {
			if (node == parent){
				root = node->right;
				delete node;
				if (root != NULL) root->left = NULL;
				return;
			}
			if (node->right != NULL){
				parent->left = node->right;
				delete node;
				return;
			}
			delete node;
			parent->left = NULL;
			return;
		}
		node->num_strings -= 1;
		return;
	}*/
	bool deleted = false;
	root = remove_recurse(root, getMin(), deleted);
}

// Purpose: To remove the max node from the tree recursively. It calls a
//			helper function, removeMax_recurse
// Args   : None
// Returns: Nothing
void StringBST::removeMax(){
	removeMax_recurse(root);
}

// Purpose: To remove a max node from the tree. Base case is if tree is
//			empty, in which case it returns nothing. It calls remove
//			function and give the getMax string. 
//			If not using remove:
//			Since its max, it will always iterate through the right child
//			of the node. If the right child of the node is NULL, then,
//			the node is max value. But, there are few cases within that.
//			If the num of strings is greater than 1, then one instance
//			is just removed by decrementing the num_strings.
//			If the node to be removed is same as the parent, then the parent
//			or the root in that case, will get the left child as the current
//			will be deleted. Also, if the left child of the node being 
//			deleted is not empty, then parent's right will get that child.
//			And finally, the node is deleted.
// Args   : The tree pointer to the current node and one to the parent
// Returns: Nothing
void StringBST::removeMax_recurse(Tree *node){
	if (node == NULL){
		return;
	}
	/*if (node->right == NULL){
		if (node->num_strings == 1){
			if (node == parent){
				root = node->left;
				delete node;
				if (root != NULL) root->right = NULL;
				return;
			}
			if (node->left != NULL){
				parent->right = node->left;
				delete node;
				return;
			}
			delete node;
			parent->right = NULL;
			return;	
		}
		node->num_strings -= 1;
		return;
	}*/
	bool deleted = false;
	root = remove_recurse(root, getMax(), deleted);
}

// Purpose: To determine if the string input is in the tree.
// Args   : String input to find
// Retruns: Bool value, true if it finds the string
bool StringBST::contains(string input){
	return contains_recurse(root, input);
}

// Purpose: To determine if the string is in the tree recursively.
//			Base Case: If the tree is empty, return false.
//			If the current node's data is equal to the string,
//			return true. 
//			If not, then recurse to left if the input is less than
//			the current node's data, and right otherwise.
// Args   : Tree node pointer, and the string to find
// Returns: True if it find the value, false otherwise
bool StringBST::contains_recurse(Tree *node, string input){
	if (node == NULL){
		return false;
	}
	if (node->data == input){
		return true;
	}
	if (node->data > input){
		return contains_recurse(node->left, input);
	} else {
		return contains_recurse(node->right, input);
	}
}




