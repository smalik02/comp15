
/*
 *
 *  COMP 15 HW 2 Cheshire ConCATenation - Time to linked up in hur
 *
 *  CharLinkedList.cpp
 *  Complete CharLinkedList Class Header and Declaration
 *  Modified By (UTLN):
 *           On       :
 *
 */
#ifndef CharLinkedList_H_INCLUDED
#define CharLinkedList_H_INCLUDED


class CharLinkedList {

	struct Node{
        	char data;
        	Node *next;
        	Node *previous;
	};
	public:
		CharLinkedList(); // constructor
		CharLinkedList(char); // overloaded constructor
		~CharLinkedList(); // destructor
		bool isEmpty();
		void clear(); // makes the linked list empty
		int size(); // returns the size of the linked list
		char first(); // returns the first element in the linked list
		char last(); // returns the last element in the linked list
		char elementAt(int); // returns element at given index
		void print(); // prints the elements
		void insertAtBack(char); // inserts a node at the back
		void insertAtFront(char); // inserts a node at the front
		void insertAt(char,int);
		void removeFromBack(); // removes a node from the back
		void removeFromFront(); // removes a node form the front
		void removeFrom(int); // removes from the desired location
		void replace(char, int); // replaces an element at given index
		void concatenate(CharLinkedList *second_list); // links two lists
		void insertInOrder(char);
			// inserts element in aplhabetical order
	
	private:
		Node *head;
		Node *tail;
		int count;
		Node *previous;
		Node *copy(Node *second_list, Node *previous_node);
};
#endif
