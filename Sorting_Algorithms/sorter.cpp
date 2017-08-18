// Name : Shehryar Malik
// Date : Nov. 4. 2016
// Sorter.cpp

// Purpose: This file serves as the interface for the algorithms.
//          The main function analyzes the arguments, and determines
//          which alogirthm to run, if any. Furthermore, the file
//          handles the printing for the program. 

#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>
#include <fstream>
#include <string>
#include "sortAlgs.h"

using namespace std;

//================ Helper Function Declarations =================//

void check_args(int argc, vector<string> args);
void interactive(vector<int> &v);
int string2int(string s);
void file_input(vector<int> &v, string);
void file_save(vector<int> &v, int argc, vector<string> args);
void console_print(vector<int> &v);
vector<string> initialize_args(int, char *argv[]);


// Purpose: Main function to read in the arguments and determine
//          which algorithm to run, if any. To make it easier,
//          I initialized a string vector of the args. 
int main(int argc, char *argv[]){
    vector<string> args = initialize_args(argc, argv);
    check_args(argc, args);
    vector<int> v;
    if (argc == 3){
        interactive(v);
    } else {
        file_input(v, args[2]);
    }
    if (args[0] == "-s1"){
        insert_sort(v);
    } else if (args[0] == "-s2"){
        quick_sort(v);
    } else if (args[0] == "-s3"){
        radix_sort(v);
    } 
    if (args[1] == "--print"){
        console_print(v);
    } else if (args[1] == "--save"){
        file_save(v, argc, args);
    }
    return 0;
}

// Purpose: To determine if the arguments passed in are correct. If not,
//          then the function will exit with a cerr. 
// Args   : int argc, number of args, and vector<string> args, arguments
//          passed in
// Returns: Nothing, but exits the prgram if the args are not valid.
void check_args(int argc, vector<string> args){
    if (argc < 3 || argc > 4 || (args[0] != "-s1" && args[0] != "-s2" &&
        args[0] != "-s3") || (args[1] != "--print" && args[1] != "--save")){
        cerr << "Usage: sorter sortAlgs outputMode [filename]\n";
        cerr << "           where: sortAlgs is -s1, -s2, or -s3\n";
        cerr << "           and    outputMode is --print or --save\n";
        exit(1);
    }
}

// Purpose: To initialize the argument vevtor from the argv array. It 
//          allows me to easily compare strings together, without
//          having to cast it as strings specifically.
// Args   : int argc, number of arguments, and the char pointer argv
// Returns: The string vector created
vector<string> initialize_args(int argc, char *argv[]){
    vector<string> args;
    for (int i = 0; i < argc-1; i++){
        args.push_back(argv[i+1]);
    }
    return args;
}

// Purpose: To create the vector from console input.
// Args   : string vector by reference
// Returns: Nothing
void interactive(vector<int> &v){
    string input;
    while (cin >> input){
        //cout << data << endl;
        v.push_back(string2int(input));
    }
}

// Purpose: To create the vector from file input.
// Args   : string vector by reference, and string filename
// Returns: Nothing
void file_input(vector<int> &v, string filename){
    ifstream fs;
    fs.open(filename);
    if (not fs.is_open()) { // if file couldnt be opened
        cerr << "Unable to read " << filename;
        return;
    }
    string s;
    for (fs >> s; not fs.eof(); fs >> s){
        //cout << s << " ";
        v.push_back(string2int(s));
    }
    fs.close();
}

// Purpose: To print the sorted output on the console
// Args   : string vector by reference
// Returns: Nothing
void console_print(vector<int> &v){
    for (int i = 0; i < (int)v.size(); i++){
        cout << v[i] << endl;
    }
}

// Purpose: To save the output in a file
// Args   : string vector by reference, int number of args, and
//          vector<string> of args
// Returns: Nothing
void file_save(vector<int> &v, int argc, vector<string> args){
    ofstream fs;
    string name;
    if (argc == 3){
        name = "cin";
    } else {
        name = args[2];
    }
    //string num_sorted = to_string((int)v.size());
    if (args[0] == "-s1"){
        name += "_1";
    } else if (args[0] == "-s2"){
        name += "_2";
    } else if (args[0] == "-s3"){
        name += "_3";
    }
    name += "_";
    //cout << (int)v.size() << endl;
    name += to_string((int)v.size());
    fs.open(name+"_sorted.txt");
    for (int i = 0; i < (int)v.size(); i++){
        fs << v[i] << endl;
    }
    fs.close();
}

// Purpose: To convert between string to int
// Args   : string s
// Returns: Int value converted from string
int string2int(string s)
{
    stringstream ss(s);
    int result;
    ss >> result;
    if (ss.fail())
        throw(runtime_error("string2int: non-numeric value: " + s));

    return result;
}