/*
 FewestItems.cpp

 By   : Shehryar Malik
 Date : Oct 12. 2016

 Purpose : This file is the implementation of the FewestItems class.
 			The constructor sets the min to a very high starting value.
 			It also sets the index to zero.
 			The destructor is empty empty because nothing needs to be
 			actively deleted as no memory was allocated for a new variable

 			The main function is the assign_package function. To determine
 			which packer has the fewest items we will use the int min, which
 			will be set to zero when the function is called, to determine 
 			the current min and iterate through the packer array and call 
 			the size function.
*/

#include "Order.h"
#include "Orderqueue.h"
#include "Retriever.h"
#include "FewestItems.h"
#include "TimeCalc.h"

using namespace std;

FewestItems::FewestItems(){
	min = 999999;
	index = 0;
}

// Destructor : Empty has no memory was allocated using new
FewestItems::~FewestItems(){
	
}

// Purpose : Purpose of this function is to assign orders. In this mode,
// 			 it will assign orders based on the fewest items
//
//Design  : Since nothing is being dequeued until it prints at the end, 
//			the size of the Orderqueue does not change. Therefore, the 
//			items_not_done function in Orderqueue is used. The start_time
//			of the package to be added is compared with all of the Orders
//			in the packer queue to determine if those packages wouuld be
//			done if I had dequeued. The final count is returned as an int,
//			and assigned to min. Values are compared across all packages
//			to determine the package with fewest items.
//
// Args   : Retriever class by reference, pointer to Orderqueue type array,
//			int number of packers, and TimeCalc class by reference. 
// Returns : Nothing
void FewestItems::assign_package(Retriever &r, Orderqueue *packers[],
				int num_packers, TimeCalc &t){
	Order *retriever = &(r.get_retriever());
	while(!r.isEmpty()){
		for (int i = 0; i < num_packers; i++){
			t.pack_wait_time(packers, num_packers);
			if (min > packers[i]->items_not_done(retriever[0].
				start_time)) {
				min = packers[i]->items_not_done(retriever[0].
					start_time);
				index = i;
			}	
		}
	//	cout << "min " << min << "index " << index << endl;
		packers[index]->enqueue(retriever[0]);
		r.remove_top(); // remove the Order that was just added
		min = 999999;
	}
}
