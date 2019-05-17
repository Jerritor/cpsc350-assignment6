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
		void quickSort();
		void insertionSort();
		void bubbleSort();
		void selectionSort();
	private:
		//original unsorted array
		double* numArray; //initalized in constructor

		double* quickArr;
		double* insertionArr;
		double* bubbleArr;
		double* selectionArr;

		int arrSize = -1;

		void readList(string f);
		void copyNumArray(double* newArr);
		void printCopyList(double* list);
};

#endif
