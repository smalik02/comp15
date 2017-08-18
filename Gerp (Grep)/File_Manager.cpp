// Name: Shehryar Malik (smalik02)
// Date: Dec. 2. 2016

// Name: File_Manager.cpp
// Purpose: This file is the implementation of the File_Manager class.
//			This class is responsible for traversing through the FSTree
//			and get the file paths. The file traversing the tree, and
//			passes the file's directory to Gerp class's parse_file()
//			function.
//
//			I guess the class could be called traverse_FSTree!

#include <iostream>
#include "FSTree.h"
#include "File_Manager.h"
#include "Gerp.h"

using namespace std;

// constructor
File_Manager::File_Manager(){

}

// destructor
File_Manager::~File_Manager(){

}

// Purpose : To traverse the file tree and to read the files.
//			 It calls a helper recursive function to do so
// Args    : Gerp class instance to call the parse_file function and
//			 char pointer to the array of inputed arguments
// Returns : Nothing
void File_Manager::traverse_directory(Gerp &g, char *argv[]){
	//cout << argv[1] << endl;
	FSTree tree(argv[1]);
	DirNode *root = tree.getRoot();
	//cout << "got the tree root in file manager" << endl;
	add(g, root, argv[1]);
}

// Purpose : To traverse the tree and print the full directory paths
//			 for each file. 
// Args    : DirNode root pointer, and string full_path of the parents
// Returns : Nothing
void File_Manager::add(Gerp &g, DirNode *root, string full_path){
	if (root->isEmpty()){
		//cout << root->getName() << endl;
		return;
	}	
	full_path += "/";
	// iteratring through the files and calling the Gerp's parse_file
	// function!
	// recurse it on the sub-directories
	for (int i = 0; i < root->numSubDirs(); i++){
		//cout << "recursing the add function in file manager" << endl;
		add(g,root->getSubDir(i), full_path + root->getSubDir(i)->getName());
	}
	//cout << "done" << endl;
	for (int i = 0; i < root->numFiles(); i++){
		//cout << "bout to read files in file manager" << endl;
		string file_path = full_path + root->getFile(i);
		//cout << file_path << endl;
		g.parse_file(file_path);
		//cout << full_path << root->getFile(i) << endl;
	}
}