// Shehryar Malik
// Comp15
// HW 1
// Sep. 8. 2016
//
// Class Implementation File
//

#ifndef CharSequence_H_INCLUDED
#define CharSequence_H_INCLUDED

class CharSequence
{
	public:
		CharSequence(); //the main constructor with no parameters
		CharSequence(char letter); //the overloaded constructor
		~CharSequence(); //the destructor 

		bool isEmpty();
		
		void clear();

		int size();

		void concatenate(CharSequence *second_seq);

		char first();

		char last();

		char elementAt(int index);

		void print();

		void insertAtBack(char insert_char);

		void insertAtFront(char insert_char);

		void insertAt(char insert_char, int index);

		void removeFromBack();

		void removeFromFront();

		void removeFrom(int index);

		void replace(char element, int index);

	private:
		char *sequence;
		int count;
		int capacity;
		void expand();

};
#endif

