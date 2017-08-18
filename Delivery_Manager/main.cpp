/*

main.cpp

Name   : Shehryar Malik (smalik02)
Date   : Oct. 12. 2016

Purpose: This file includes the implementation of the whole program.
		 main.cpp runs the program by calling the run function.
		 The function executes the prorgam one task at a time:
		 fill the retriever array, determine fetch_wait_time, 
		 pack the packers, determine the pack_wait_time, and print
		 the final information in the file.

		 The process is detailed in the README file.
*/

/* ========================= Header Files =============================== */
#include <iostream>
#include <fstream>
#include "string2int.h"
#include "Order.h"
#include "Parser.h"
#include "Orderqueue.h"
#include "RoundRobin.h"
#include "ShortestTime.h"
#include "FewestItems.h"
#include "TimeCalc.h"
#include "Retriever.h"


using namespace std;
/* ===================== Function Declarations ========================= */
void run(string, int, string); 
void print(Orderqueue *packers[], int, int);
Orderqueue **update_packers(Orderqueue *packers[], int&, int);
void sort_times(int total_times[], int first_index, int last_index);
int average_times(int total_times[], int num_packages);
void setup_array (int total_times[], int num_packages);

/* ========================== Implementation ========================== */
int main(int argc, char** argv){
	if (argc > 4) {
			throw logic_error("Too many arguments");
	}
	string filename = argv[1];
	// convert the string arg into int for number of packer
	int num_packers = string2int(argv[2]);
	string pack_mode = argv[3];

	// run the program
	run(filename, num_packers, pack_mode);
	return 0;
}

// Purpose : As stated above, the purpose of the run to execute the program
//			 step by step
// Args    : Takes in three arguments: name of the file to read in the order
//			 from, number of packers, and the pack_mode for packing the orders
// Returns : Nothing
void run(string filename, int num_packers, string pack_mode){
	Parser p(filename); // parser instance with the filename
	Retriever r; // Retriever instance
	TimeCalc t; // TimeCalc instance
	Orderqueue *packers[num_packers]; // array of packers
	for (int i = 0; i < num_packers; i++){
		packers[i] = new Orderqueue();
	}
	int num_packages = 0; // strat with zero packages
	while (!p.is_done()){
		Order package = p.read_order();
		// fill the retriever array one by one
		r.fill_retriever(package, num_packages);
		num_packages++;
	}
	Order *retriever = &(r.get_retriever()); // get the retriever array
	t.fetch_wait_time(retriever, num_packages); // calculates fetch_wait_time
	if (pack_mode == "ROUND_ROBIN"){
		RoundRobin rr;
		rr.assign_order(r, packers, num_packers);
		t.pack_wait_time(packers, num_packers); // calculates pack_wait_time
	} else if (pack_mode == "FEWEST_ITEMS"){
		FewestItems fi;
		fi.assign_package(r, packers, num_packers, t);
	} else if (pack_mode == "SHORTEST_TIME"){
		ShortestTime st;
		st.assign_package(r, packers, num_packers, t);
	}
	t.pack_wait_time(packers, num_packers);
	print(packers, num_packers, num_packages); // print the packages
}


// Purpose : To print the packages in order of shipping time
// Args    : It takes in Orderqueue type pointer to an array of packers, int
// 			 num of packers, and int num of packages
// Returns : Nothing
void print(Orderqueue *packers[], int num_packers, int num_packages){
	int index = 0; // index of packer that had the min print time
	int min = 9999999; // min to compare the different print times
	Order temp; // Order variable that is going to get the value of dequeued 
	int total_times[num_packages]; // array of total_times for the packages
	setup_array(total_times, num_packages); // initialize values to zero
	for (int i = 0; i < num_packages; i++){
		for (int p = 0; p < num_packers; p++){
			if(min > packers[p]->top_total_time()){
				min = packers[p]->top_total_time();
				index = p;
			}
		}
		min = 999999; // reset min
		temp = packers[index]->dequeue(); // dequeue from index(th) packer
		total_times[i] = temp.total_time;
		cout << "<Order("<<temp.id<<") arrival_timestamp = "
			<< temp.arrival_timestamp << " fetch_duration = "
			<< temp.fetch_duration << " pack_duration = " <<
			temp.pack_duration << " total_time = " << temp.total_time <<">\n";
		packers = update_packers(packers, num_packers, index);
	}
	sort_times(total_times, 0, num_packages-1); // sort the array of times
	int global_min = total_times[0]; // min is first element of sorted array
	int global_max = total_times[num_packages-1]; // max is the last
	int average = average_times(total_times, num_packages); // calculate avg
	cout << "min elapsed time " << global_min << " minutes" << endl;
	cout << "max elapsed time " << global_max << " minutes" << endl;
	cout << "mean elapsed time " << average << " minutes" << endl;
	cout << num_packages << " orders processed" << endl;
}


// Purpose : The purpose of this function is to update the packers array if
//			packers are empty. To do so, the function will check if the
//			count of packers is == 0 (i.e. Empty). If so, it will
//			update the array (remove that packer) based upon
//			what index was used to dequeue from the packers array in the
//			print function
// Args    : Orderqueue type pointer to array of packers, int reference
//			to the num_packers, and the index.
// Returns : Pointer to an Orderqueue array (i.e. pointers) of packers
Orderqueue** update_packers(Orderqueue *packers[], int &num_packers,
							 int index){
	//cout << "packers at start " << num_packers << endl;
	if (packers[index]->count() == 0){
	//cout << "in new function" << endl;
		if (index == 0) {
			for (int a = 0; a < num_packers-1; a++){
				packers[a] = packers[a+1];
			}
			num_packers--;
		} else if (index == num_packers-1){
			num_packers--;
	//		cout << "in num_packers-1 " << num_packers << endl;
		} else {
			for (int a = index; a < num_packers-1; a++){
				packers[a] = packers[a+1];
			}
			num_packers--;
	//		cout << "after for loop " << num_packers << endl;
		}
	}
	return packers;
}

// Purpose : To initialize the array to zeros
// Args    : int total_times array and number of packages
// Returns : Nothing
void setup_array (int total_times[], int num_packages){
	for (int i = 0; i < num_packages; i++){
		total_times[i] = 0;
	}
}
// Purpose : To sort the array of total times using a Quick Sort algorithm
// 			The algorithm is described in README
// Args    : int array of total times, the first index of the array and the
//			 last. The indices are going to be changed as the function is
//			 recurssed. 
// Returns : Nothing
void sort_times(int total_times[], int first_index, int last_index) {
      int i = first_index, j = last_index;
      int tmp;
      int pivot = total_times[(first_index + last_index) / 2];
      // central that is going to be used to sort
       while (i <= j) { // as long as the two ends arent the same
            while (total_times[i] < pivot) // move first_index (left) over
                  i++;
            while (total_times[j] > pivot) // move last_index (right) in
                  j--;
            if (i <= j) { // if they are the same or i is less than j
                  // moves items less than the pivot to the left and greater
            	  // to the right
                  tmp = total_times[i];
                  total_times[i] = total_times[j];
                  total_times[j] = tmp;
                  i++; // value is moved up
                  j--; // value is moved down (to the left)
            }
      }
      if (first_index < j){
            sort_times(total_times, first_index, j);
      }
      if (i < last_index){
            sort_times(total_times, i, last_index);
      }
}

// Purpose : To calculate the average of the total times
// Args    : int array of total times and number of packages
// Returns : int average
int average_times(int total_times[], int num_packages){
	int sum = 0;
	for (int i = 0; i < num_packages; i++){
		sum += total_times[i];
	}
	return sum/num_packages;
}