// Name: Shehryar Malik (smalik02)
// Date: Oct. 26. 2016
// BSTTesting.cpp
// 
// Purpose: This file is tests the StringBST class. It is broken down
//			into different sub-test functions

#include <iostream>
#include "StringBST.h"

using namespace std;

void test1();
void test_remove();
void test_contains();
void test_min_max();

int main(){
	test1();
	test_remove();
	test_contains();
	test_min_max();
	return 0;
}

void test1(){
	StringBST a;
	cout << a.isEmpty() << endl;
	a.clear(); // test clear..shouldnt do anything
	cout << a.size() << endl;
	a.add("d");
	a.add("e");
	a.add("a");
	cout << a.isEmpty() << endl;
	a.print();
	cout << a.getMin() << endl;
	cout << a.getMax() << endl;
	cout << a.size() << endl;
	string input[] = {"sd", "we", "aw", "tfg", "uj","zz", "we", "aw"};
	StringBST b(input, 8);
	cout << b.isEmpty() << endl;
	b.print();
	cout << b.getMin() << endl;
	cout << b.getMax() << endl;
	b.removeMin();
	b.print();
	b.removeMax();
	b.print();
	cout << a.contains("a") << endl;
	cout << b.contains("jjj") << endl;
	a.clear();
}

void test_remove(){
	string input[] = {"sd", "we", "aw", "tfg", "uj","zz", "we", "aw"};
	StringBST a(input, 8);
	cout << a.size() << endl;
	a.print();
	a.remove("aw"); // base test where number of string is greater than 1
	a.print();
	a.remove("aw");
	//cout << "deleted aw twice " << endl;
	cout << a.size() << endl;
	a.print();
	a.remove("uj");
	a.print();
	a.remove("sd"); // root with only child left
	a.print();
	a.add("aa"); 
	a.print();
	a.remove("we"); // removing a root with two childs
	a.print();
	a.remove("we"); //leftmost node in the right subtree will become the root
	a.print();
}

void test_contains(){
	StringBST a;
	a.print(); // should be []
	cout << a.size() << endl;
	cout << a.contains("a") << endl; // empty tree so it should be 0
	a.add("d");
	cout << a.contains("d") << endl; // should be 1
	a.add("e");
	a.add("a");
	a.add("ahhh");
	a.add("zzz");
	a.add("yyy");
	a.add("zzzzzzzz");
	cout << a.contains("ed") << endl; // should be 0
	cout << a.contains("yyy") << endl; // should be 1
	a.clear();
}

void test_min_max(){
	string input[] = {"Fgh","BOB","Ron","Mac","Ann", "Ann", "Tom","Cat"};
	StringBST a(input, 8);
	cout << a.getMax() << endl; // should be Tom
	cout << a.getMin() << endl; // Ann
	a.remove("Ann");
	cout << a.getMin() << endl; // Ann
	a.remove("BOB"); 
	a.print();
	cout << a.getMin() << endl; // should still be Ann
	a.removeMin(); // Ann is gone
	cout << a.getMin() << endl; // should be Cat now
	a.removeMax(); // Tom is gone
	cout << a.getMax() << endl; // shoul dbe Ron now
	a.removeMax();
	cout << a.getMax() << endl; // should be Mac now
	a.removeMin(); 
	cout << a.getMin() << endl; // should be Fgh
	a.print();
	cout << endl;
	a.removeMin();
	a.removeMax();
	cout << a.getMax() << endl; // exception thrown
}