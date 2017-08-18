/*
 * By   : Shehryar Malik
 * Date : Oct. 6. 2016
 *
 * RoundRobin.cpp
 *
 * This file is the implementation of the RoundRobin class. The class is
 * used to assign packages in order (one by one to each packer)
 * The class is used by the main.cpp in run function as it will be 
 * called to assign packages. 
 * The assign_package function is the main function because it assigns
 * the packages to the packers. 
 *
 */

#include "Order.h"
#include "Orderqueue.h"
#include "Retriever.h"
#include "RoundRobin.h"

using namespace std;
// constructor 
RoundRobin::RoundRobin(){
	
}

// Destructor: empty has nothing specific was created using new
RoundRobin::~RoundRobin(){

}

// Purpose : Purpose of this function is to assign orders. In this mode,
// 			 it will assign orders in order
//
//Design   : Function has a while loop that checks if the retriever array
//			 is empty, meaning all the orders are assigned. Then it goes
//			 one by one to each packer and assigns the package. The assigned
//			 packaged is removed from the retriever array. Whith in the for
//			 loop, is is also checked if the retriever arrary becmae empty 
//			 after assiging the last package
//
// Args    : Retriever class by reference, pointer to Orderqueue type array,
//			 & int number of packers
// Returns : Nothing
void RoundRobin::assign_order(Retriever &r, Orderqueue *packers[],
				int num_packers){

//	cout << "packers " << num_packers << endl;
	Order *retriever = &(r.get_retriever()); // get the array of order
	while (!r.isEmpty()){
		//cout << "before packing" << endl;
		for (int i = 0; i < num_packers; i++){
			packers[i]->enqueue(retriever[0]); // added to the queue
			if (r.isEmpty()){ // if retriever is empty
				return;
			}
			r.remove_top(); // remove the Order that was just added
	//		cout << "added" << endl;
		}
	}
}
