#include "Sorter.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

Sorter::Sorter(string file)
{
	readList(file);
}

Sorter::~Sorter()
{
	delete[] numArray;
	delete[] quickArr;
	delete[] insertionArr;
	delete[] bubbleArr;
	delete[] selectionArr;
}

//======PUBLIC METHODS======
void Sorter::printList()
{
	if (arrSize == -1 || numArray == NULL) //something wrong
		cout << "Something isn't right. Make sure the inputted file has the right data formatting." << endl;
	else
		printCopyList(numArray);
}

void Sorter::quickSort()
{
	cout << "Running QuickSort..." << endl;
	//copyNumArray(quickArr);
	printCopyList(quickArr);
}

void Sorter::insertionSort()
{
	cout << "Running InsertionSort..." << endl;
	for (int j = 1; j < arrSize; j++)
	{
		double temp = insertionArr[j]; //store marked item
		int k = j-1; //where to start shifting

		//while item on left is larger, shift
		while (k > 0 && insertionArr[k-1] >= temp)
		{
			insertionArr[k+1] = insertionArr[k]; //shift right
			k--;
		}
		insertionArr[k] = temp; //place item
	}

	//printCopyList(insertionArr);
}

void Sorter::bubbleSort()
{

}

void Sorter::selectionSort()
{

}

//======PRIVATE METHODS======
void Sorter::readList(string file)
{
	ifstream inputStream;

	inputStream.open(file); //try to open file

	if (inputStream.fail())
	{
		cerr << "Error opening File." << endl;
		cerr << "Try again with the right file." << endl;
		inputStream.close();
		exit(1);
	}

	double curr;
	int counter = 0;
	while (inputStream >> curr)
	{
		if (counter == 0) //number of lines to read
		{
			arrSize = curr;
			numArray = new double[arrSize];
			quickArr = new double[arrSize];
			insertionArr = new double[arrSize];
			bubbleArr = new double[arrSize];
			selectionArr = new double[arrSize];
		}
		else //numbers to be read
		{
			if (counter > arrSize) //not >= bc line 0 doesnt count
				break;
			else //counter-1 bc else starts at counter = 1
			{
				numArray[counter-1] = curr; //add num to numArray
				quickArr[counter-1] = curr;
				insertionArr[counter-1] = curr;
				bubbleArr[counter-1] = curr;
				selectionArr[counter-1] = curr;
			}
		}
		counter++;
	}

	inputStream.close();
}

void Sorter::copyNumArray(double* newArr)
{
	newArr = new double[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		newArr[i] = numArray[i];
	}
}

void Sorter::printCopyList(double* list)
{
	cout << "===PRINTING===" << endl;
	cout << "arrSize: " << arrSize << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cout << "[" << i << "] = " << setprecision(9) << list[i] << endl;
		//std::setpricision sets decimal places to be outputted
	}
}
