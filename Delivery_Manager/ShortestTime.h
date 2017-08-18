/*
 * By   : Shehryar Malik
 * Date : Oct. 6. 2016
 *
 * ShortestTime.h
 *
 * This file is the definition of the ShortestTime class. The class is
 * used to assign packages based on the shortest time for packaging all
 * the packages in the queue for the packers. The class is used by
 * the main.cpp in run function as it will be called to assign 
 * packages. 
 *
 * The assign_package function is the main function because it assigns
 * the packages to the packers. To determine which packer has the shortest
 * time, we will use the int min, which will be set to a high value to start
 * the loop, to determine the current min and iterate through the
 * packers. To access the packers queue, the function will check the last
 * element in the queue using last_element function. It will return a copy
 * of the last element, which the Order last_package will get, because
 * structs are copied when they are passed or returned. 
 * 
 *
 *
 */

#ifndef SHORTESTTIME_H_INCLUDED
#define SHORTESTTIME_H_INCLUDED

#include "Order.h"
#include "Orderqueue.h"
#include "Retriever.h"
#include "TimeCalc.h"

class ShortestTime{

public:
	ShortestTime();
	~ShortestTime();

	// function to assign packages based on the shortest pack time
	// among the packers. It takes in the reference to the retriever class
	// It also takes in Orderqueue array of packers, int number of packers,
	// and reference to the TimeCalc class.
	// The reason for taking in reference to the Retriever and TimeCalc
	// class is because it will allow me to modify the arrays as need be
	// and have those changes show up in the main function. 
	// It is first going to iterate through and determine the shortest
	// time. Then it will assign the package. It will end once the 
	// retriever is empty (calling isEmpty function)
	void assign_package(Retriever &r, Orderqueue *packers[], 
			int, TimeCalc &t);
	
private:
	Orderqueue packer; // instance of the packer class
	int min; // min variable for the shortest time
	Retriever r; // instance of the Retriever clas
	int index; // index of the packer for inserting the order to
	TimeCalc t; // instance of the TimeCalc class
	Order last_package; // instance of the last package struct
						// it will be used by the assign function when it
						// calls the last_element function from the Orderqueue
						// class.
};
#endif
