// Name : Shehryar Malik
// Date : Nov. 4. 2016
// sortAlgs.cpp

// Purpose: This file serves as the implementation for the SortAlgs. 
//          There are helper functions for each algorithm. There are
//          three main algorithms implemented: Insertion sort,
//          quick sort, and radix sort.

#include <iostream>
#include "sortAlgs.h"

using namespace std;

/* ======================= Helper functions ========================== */
void helper_quick_sort(vector<int> &v, int, int);
void helper_insert_sort(vector<int> &v, int);
void helper_radix_sort(vector<int> &v, int, int);
int get_Max(vector<int> &v, int);
vector<int> build_output_vector(vector<int> &v, vector<int> &sorted, 
            vector<int> &occurences, int base);
vector<int> copy_vectors(vector<int> &v, vector<int> &sorted, int size);

/* ======================== Insertion Sort =========================== */
// Purpose: To sort the input using a insertion sort algorithm
// Args   : Vector<int> by reference
// Returns: Nothing
// The algorithm is detailed in README. The function calls the helper
// function, helper_insert_sort
void insert_sort(vector<int> &v){
  helper_insert_sort(v, (int)v.size());
}

// Purpose: To sort the vecotr using insertion sort. The steps are detailed
//          in README. The function creates two sub vectors, one sorted and
//          unsorted. The idea of sub vectors is really virtual in a sense.
//          The sorted vector is part of the vector that is sorted. To begin,
//          it is the start of the vector. Then, an iterator is used to
//          go through the vector, starting at the current sorted index of
//          the vector. Then, it loops through and checks if the value is
//          less than its left neighbot. If so, it is swapped.
// Args   : int vector to be sorted, and the size of the vector 
void helper_insert_sort(vector<int> &v, int size){
  int pointer, temp;
  // start count at the second number in the list
  for (int index = 1; index < size; index++) {
    pointer = index;
    // I first had pointer > 0 check in the second part of the conditional,
    // and it caused it a valgrind error. I realized that pointer not being
    // 0 has to be checked before the vector can be checked! Cool...
    while ((pointer > 0) && (v[pointer - 1] > v[pointer])) {
      temp = v[pointer];
      v[pointer] = v[pointer - 1];
      v[pointer - 1] = temp;
      pointer--;
    }
  }
}

/* ========================= Quick Sort ============================== */
// Purpose: To sort the input using a quick sort algorithm
// Args   : Vector<int> by reference
// Returns: Nothing
// The algorithm is detailed in README. The function calls the helper
// function, helper_quick_sort
void quick_sort(vector<int> &v){
  if (v.size()!=0){
   helper_quick_sort(v, 0, (int)v.size()-1);
  }
  return;
}

// Purpose: To sort the vector using quick sort. These steps are
//          detailed in README. The function has two main pointers/indicies
//          the left index and the right index. They are used to move
//          the values around the pivot. Pivot is the value that is
//          used to subdivide the vector into smaller vectors. In my
//          function, it is the middle value. Then, the indicies are
//          moved until the left index value is no longer less than the
//          pivot, and the right index value is no longer greater than
//          the pivot. Then, the values are swaped as long as the
//          right index is greater than or equal to the left.
//          When the indicies have crossed or equal, then, the vector is
//          recursed, but with the sub vector
// Args   : int vector to be sorted, the first index and the last index.
// Returns: Nothing
void helper_quick_sort(vector<int> &v, int f_index, int l_index){
  int left_index = f_index, right_index = l_index;
  int temp;
  int pivot = v[(f_index + l_index) / 2];
  // central pivot that is going to be used to sort
  while (left_index <= right_index) { 
      while (v[left_index] < pivot) // move left_index over
          left_index++;
      while (v[right_index] > pivot) // move right_index in
          right_index--;
      if (left_index <= right_index) {
          temp = v[left_index];
          v[left_index] = v[right_index];
          v[right_index] = temp;
          left_index++; // value is moved up
          right_index--; // value is moved down (to the left)
      }
  }
  if (f_index < right_index){
      helper_quick_sort(v, f_index, right_index);
  }
  if (right_index < l_index){
      helper_quick_sort(v, left_index, l_index);
  }
}

/* ========================= Radix Sort ============================== */
// Purpose: To sort the input using a radix sort algorithm
// Args   : Vector<int> by reference
// Returns: Nothing
// The algorithm is detailed in README. The function calls the helper
// function, helper_radix_sort
void radix_sort(vector<int> &v){
  int max_value = get_Max(v, (int)v.size()); // max of the vector
  // base is the current digits place! 
  for (int base = 1; max_value/base > 0; base *= 10){
    helper_radix_sort(v, (int)v.size(), base);
  }
}

// Purpose: To sort the vector to the current digits place. The function
//          multiple different helper function. Firstly, a sorted vector
//          is created that will be used to sort to the numbers to the
//          current digits place. Then, the occurences of the digits place
//          are counted. Then, the output vector is built, and finally, 
//          the original vector is copied: sorting the vector to the 
//          current digits place.
// Args   : vector int v, size of the vector, and the current digits place,
//          base
// Returns: Nothing
void helper_radix_sort(vector<int> &v, int size, int base){
  vector<int> sorted(size); // sorted vector
  vector<int> occurences = {0,0,0,0,0,0,0,0,0,0}; 
  // determining number of occurences of a digit
  for (int count = 0; count < size; count++){
    occurences[(v[count]/base)%10]++;
  }
  // the position of the digit
  for (int position = 1; position < 10; position++){
    occurences[position] += occurences[position-1];
  }
  // building the output vector, sorting it
  sorted = build_output_vector(v, sorted, occurences, base);
  // copying it to the original vector
  v = copy_vectors(v, sorted, size);
}

// Purpose: To create a sorted vector to the current digits place
// Args   : vector int v, to be sorted vector, the occurences vector, 
//          and the current base, the digits place
// Returns: sorted vector, sorted to the current digits place
vector<int> build_output_vector(vector<int> &v, vector<int> &sorted, 
            vector<int> &occurences, int base){
  for (int i = (int)v.size() - 1; i >= 0; i--){
    sorted[occurences[ (v[i]/base)%10 ] - 1] = v[i];
    occurences[ (v[i]/base)%10 ]--;
  }
  return sorted;
}

// Purpose: To copy the sorted vector to the original vector
// Args   : vector int v, sorted vector, and size of the vector
// Returns: original vector, sorted to the current digit
vector<int> copy_vectors(vector<int> &v, vector<int> &sorted, int size){
  for (int i = 0; i < size; i++){
    v[i] = sorted[i];
  }
  return v;
}

// Purpose: To determine the max value in the vector
// Args   : vector int, and size of the vector
// Returns: max
int get_Max(vector<int> &v, int size){
  int max = v[0];
  for (int i = 1; i < size; i++)
      if (v[i] > max){
        max = v[i];
      }
  return max;
}