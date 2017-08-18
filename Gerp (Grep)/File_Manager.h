// Name: Shehryar Malik (smalik02)
// Date: Dec. 2. 2016

// Name: File_Manager.h
// Purpose: This file is the definition of the File_Manager class.
//			This class is responsible for traversing through the FSTree
//			and get the file paths. This class is used by the user
//			to traverse the directory, by calling the traverse_directory
//			function. 
//			The file needs the header file of Gerp.h because it needs to
//			call the parse_file function in Gerp, so the index can be
//			created!
//


#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include "Gerp.h"
#include "FSTree.h"

class File_Manager{
public:
	File_Manager(); // constructor
	~File_Manager(); // destructor
	void traverse_directory(Gerp &g, char *argv[]);
private:
	void add(Gerp &g, DirNode *root, std::string full_path);
};
#endif