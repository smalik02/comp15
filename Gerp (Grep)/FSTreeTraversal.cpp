// Name: Shehryar Malik (smalik02)
// Date: Nov 18th. 2016
// Purpose: To build a File Search Tree from a give directory
//
// This program serves as a testing phase for determining if the tree
// built is correct or not. Also, it allows us to traverse through the
// tree, which will be important when indexing for the project.

#include <iostream>
#include "FSTree.h"

using namespace std;

// Helper Functions
void traverse_tree(char *argv[]);
void print_dir_node(DirNode *root, string);

// main function to determine if there are correct number of arguments
int main(int argc, char *argv[]){
	if (argc > 2){
		cerr << "Usage:  gerp directory\n";
		cerr << "            where:  directory is a valid directory";
		exit(EXIT_FAILURE);
	}
	traverse_tree(argv);
}

// Purpose : To traverse the tree and print the full directory paths
//			 for each file. It calls a helper recursive function to do so
// Args    : char pointer to the array of inputed arguments
// Returns : Nothing
void traverse_tree(char *argv[]){
	FSTree tree(argv[1]);
	DirNode *root = tree.getRoot();
	print_dir_node(root, "../");
}

// Purpose : To traverse the tree and print the full directory paths
//			 for each file. 
// Args    : DirNode root pointer, and string full_path of the parents
// Returns : Nothing
void print_dir_node(DirNode *root, string full_path){
	if (root->isEmpty()){
		//cout << root->getName() << endl;
		return;
	}
	full_path += root->getName() + "/";
	for (int i = 0; i < root->numFiles(); i++){
		cout << full_path << root->getFile(i) << endl;
	}
	for (int i = 0; i < root->numSubDirs(); i++){
		print_dir_node(root->getSubDir(i), full_path);
	}
}