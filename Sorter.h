#ifndef SORTER_H
#define SORTER_H

#include <iostream>

using namespace std;

class Sorter
{
	public:
		Sorter(string file);
		~Sorter();

		void printList();
	private:
		double* numArray; //initalized in constructor
		int arrSize = -1;

		void readList(string f);

		void quickSort();
		void insertionSort();
		void bubbleSort();
		void selectionSort();
};

#endif
