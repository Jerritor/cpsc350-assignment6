#ifndef SORTER_H
#define SORTER_H

#include <iostream>

using namespace std;

class Sorter
{
	public:
		Sorter(string file);
	private:
		double* numArray; //initalized in constructor
		int arrSize;

		void readList(string f);
		void printList();

		void quickSort();
		void insertionSort();
		void bubbleSort();
		void selectionSort();
};

#endif
