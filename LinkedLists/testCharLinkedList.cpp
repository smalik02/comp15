/*
 *
 *  COMP 15 HW 2 Cheshire ConCATenation - Time to linked up in hur
 *
 *  testCharLinkedList.cpp
 *  Testing File for your sequence CharLinkedList class
 *  Modified By (UTLN): Shehryar Malik
 *           On       : Sep. 22. 16
 *
 *
 * Purpose: To test the program to determine if it works. The file 
 * 		uses some functions from the provide tests, yet they
 * 		are modified a little bit to make sure they were working
 */

#include <iostream>
#include "CharLinkedList.h"

void sample_test1();
void remove_test();
void last_test();
void empty_test();
void insert();
void concatenate_test();

using namespace std;
int main()
{
	CharLinkedList *list = new CharLinkedList;
	//list->print(); // print nothing
	list->insertAtFront('a');
	//list->print(); // a
	list->insertAtBack('c');
	//list->print(); // ac
	list->insertAt('b',1);
//	cout << list->last() << endl; // print c
//	cout << list->first() << endl; // print a
//	cout << list->elementAt(1) << endl; // print b
	CharLinkedList *list2 = new CharLinkedList('a');
//	cout << "new list created " << endl; test
//	list2->insertAtBack('d'); // should be ad
	list2->removeFromFront(); // should be just d
	list->concatenate(list2); // should be just abc
//	list2->removeFromBack(); // should throw an exception
//	list2->insertAt('c', 1); // should throw an exception
	list->removeFromBack();	// should print ab
//	list->insertAt('x',3); // should throw an exception
	list->insertAt('x',2); // should print abx
	list->insertInOrder('t'); // should be abtx
	list2->insertInOrder('e');
	list->replace('d', 1);
//	list->replace(4,'e'); // should throw an exception
//	list2->removeFrom(1); // should throw an exception
//	list2->removeFrom(0); // should be an empty linked list
//	list2->removeFromBack(); // should be empty
	list2->insertInOrder('f');
	list->print();
	list2->print();
	//sample_test1();
	list->~CharLinkedList();
//	list2->~CharLinkedList();
	remove_test();
	//last_test();
	//empty_test();
	//insert();
	concatenate_test();
}

// Following functions were taken from the provide tests and they were 
// modified for a little bit
// Therefore, credit goes to Comp15 TA's

void empty_test(){
	std::cout << "Testing isEmpty" << std::endl;
	CharLinkedList *sequencetest = new CharLinkedList('e'); // non empty
	bool testempty1 = sequencetest->isEmpty();
	CharLinkedList *sequencetest2 = new CharLinkedList(); // empty
	bool testempty2 = sequencetest2->isEmpty();
	if(testempty1 == false & testempty2 == true){
		std::cout << "isEmpty test successful" << std::endl;
	}
       // delete sequencetest;
       // delete sequencetest2;
       sequencetest->~CharLinkedList();
	sequencetest2->~CharLinkedList();
}

void last_test(){
	std::cout << "Testing last" << std::endl;
	CharLinkedList *listtest = new CharLinkedList('e'); // non empty
	CharLinkedList *listtest2 = new CharLinkedList(); // empty
	char first = listtest->last();
	bool threw_exception = false;
	cout << "here" << endl;
	try{
		cout << listtest2->last() << endl;
	}
	catch(...){
		threw_exception = true;
	}
	if(first == 'e' & threw_exception==true){
		std::cout << "last test successful" << std::endl;
	}
        delete listtest;
        delete listtest2;
}

void remove_test(){

	CharLinkedList *list = new CharLinkedList('a');
    	std::cout<<"Testing Insert Remove Replace"<<std::endl;
    	list->removeFromFront();
    	try
    	{
        	list->removeFromBack();
    	} 
    	catch(...)
    	{ 
        	std::cout<<"Caught Remove Index Out Of Bounds"<<std::endl;
    	}
    	list->print(); std::cout<<std::endl;
    	try
    	{
        	list->removeFrom(1);
    	}
    	catch(...)
    	{
        	std::cout<<"Caught Remove Index Out Of Bounds"<<std::endl;
    	}
    	list->insertAtFront('a');
    	list->insertAtBack('b');
    	list->insertAt('c',2);
    	list->insertAtBack('d');
    	list->print(); std::cout<<std::endl;
    	list->removeFrom(1);
    	list->print(); std::cout<<std::endl;
   	list->replace('9',2);
   	list->print(); std::cout<<std::endl;
   	try
    	{
        	list->replace('a',4);    
    	}
    	catch(...)
    	{
        	std::cout<<"Caught Replace Index Out Of Bounds"<<std::endl;
    	}
    	std::cout<<"Insert Remove Replace Test Completed"<<std::endl;
    	delete list;
}

void insert()
{
    std::cout<<"Testing Insert Functions"<<std::endl;
    CharLinkedList *list = new CharLinkedList('b');
    list->print(); std::cout<<std::endl;
    list->insertAtBack('c');
    list->print(); std::cout<<std::endl;
    list->insertAtFront('d');
    list->print(); std::cout<<std::endl;
    list->insertAt('q',3);
    list->print(); std::cout<<std::endl;
    list->insertAtFront('e');
    list->print(); std::cout<<std::endl;
    list->insertAtBack('1');
    list->print(); std::cout<<std::endl;
    list->insertAt('A',1);
    list->print(); std::cout<<std::endl;
    try
    {
        list->insertAt('6',140);
    }
    catch(...)
    {
        std::cout<<"Caught Insert Index Out Of Bounds"<<std::endl;
    }
    std::cout<<"Insert Tests Completed"<<std::endl;
    delete list;
}


// test function from provide
void  sample_test1(){
    	CharLinkedList *list = new CharLinkedList;
   	 if(list->isEmpty()) {
        	std::cout<<"Default object isEmpty..."<<std::endl;
    	}
    	if(list->size() == 0){
        	std::cout<<"Default object is size zero..."<<std::endl;
    	}
    	list->insertAtFront('a');
    	if(!list->isEmpty()) {
        	std::cout<<"Adding an element makes default object not empty..."<<std::endl;
    	}
    	bool sizeRight = true;
    	for(int x = 2 ; x < 100; x++){
        	list->insertAtFront('b');
        	if(list->size() != x){
            		sizeRight = false;
        	}
        	if(list->isEmpty()){
            		sizeRight = false;
        	} 
    	}
    	if(sizeRight){
        std::cout<<"Size Tests Completed"<<std::endl;
    	}
	delete list;
    
}

void concatenate_test()
{
    std::cout<<"Starting Concatenation Test"<<std::endl;
    CharLinkedList *list1 = new CharLinkedList;
    CharLinkedList *list2 = new CharLinkedList;
    list1->print(); std::cout<<std::endl;
    list1->concatenate(list2);
    list1->print(); std::cout<<std::endl;
    list2->insertAtFront('f');
    list1->concatenate(list2);
    list1->print(); std::cout<<std::endl;
    delete list2;
    CharLinkedList *list3 = new CharLinkedList('d');
    list1->concatenate(list3);
    list1->print(); std::cout<<std::endl;
    list1->concatenate(list3);
    list1->print(); std::cout<<std::endl;
    CharLinkedList *list4 = new CharLinkedList;
    list1->concatenate(list4);
    list1->print(); std::cout<<std::endl;
    list1->concatenate(list1);
    list1->print(); std::cout<<std::endl;
    std::cout<<"Concatenation Test Completed"<<std::endl;
    delete list1;
    delete list3;
    delete list4;
}
