/*Sorting.cpp : Defines the entry point for the console application.
						10			1.000		1000.000		1.000.000.000
----------------------------------------------------------------------------
INSERTION SORT	|0.0040074/10000 |0.0040096	 |				 |
MERGE SORT		|0.0710505/10000 |0.0010001	 |				 |					
QUICK SORT	    |0.0290235/10000 |0.0010012	 |1.27491		 |
RADIX SORT		|				 |			 |				 |
----------------------------------------------------------------------------
i did not find any solution for the 1000 000 value and its related to the memory of my computer if i want to solve the problem
i should use an external storage
*/

#include "Timer.h"
#include "RandomNumberGenerator.h"
#include "SortingAlgorithms.h"
#include <iostream>

/**
*/
int main(int argc, char argv[])
{
	int n=1000000;
    Timer tmr;

	RandomNumberGenerator rng(n);
	rng.generate();
	double time = tmr.elapsed();
	//std::cout << time << std::endl;
	//rng.display();

	tmr.reset();
	for (int i = 0; i < 10000; i++){
		SortingAlgorithms::InsertionSort(rng.getData() ,rng.getSize());
	    //rng.display();	
	}
	time = tmr.elapsed();
	std::cout << time << std::endl;

	std::cin.get();

}

