#include "Sorter.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <chrono>

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
	time_t startTime, endTime;
	time(&startTime); //mark start time

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

	time(&endTime); //mark end time

	//printCopyList(insertionArr);
	//cout << "startTime: " << startTime << endl;
	//cout << "endTime: " << endTime << endl;
	cout << "Elapsed: " << difftime(endTime, startTime) << " secs." << endl;
}

void Sorter::bubbleSort()
{
	cout << "Running BubbleSort..." << endl;
	time_t startTime, endTime;
	time(&startTime); //mark start time

	int num1, num2;
	for(int i = 0; i < arrSize; i++)
	{
		for(int j = 0; j < arrSize-1; j++)
		{
			if (bubbleArr[j] > bubbleArr[j+1])
			{
				double tmp = bubbleArr[j]; //hold smaller val
				bubbleArr[j] = bubbleArr[j+1]; //swap values
				bubbleArr[j+1] = tmp; //set [j+1] to bigger val
			}
		}
	}

	time(&endTime); //mark end time

	//printCopyList(bubbleArr);
	//cout << "startTime: " << startTime << endl;
	//cout << "endTime: " << endTime << endl;
	cout << "Elapsed: " << difftime(endTime, startTime) << " secs." << endl;
}

void Sorter::selectionSort()
{
	cout << "Running SelectionSort..." << endl;
	time_t startTime, endTime;
	time(&startTime); //mark start time

	int minIndex;
	for(int i = 0; i < arrSize; i++)
	{
		//find minimum element index
		minIndex = i;
		for(int j = i+1; j < arrSize+1; j++)
			if (selectionArr[j] < selectionArr[minIndex])
				minIndex = j;

		//swap min element with selectionArr[i]
		double tmp = selectionArr[minIndex]; //hold smaller val
		selectionArr[minIndex] = selectionArr[i]; //swap values
		selectionArr[i] = tmp; //set [i] to bigger val
	}

	time(&endTime); //mark end time
	//printCopyList(selectionArr);
	cout << "Elapsed: " << difftime(endTime, startTime) << " secs." << endl;
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
		cout << "[" << i << "] = " << setprecision(2) << fixed << list[i] << endl;
		//std::setpricision sets decimal places to be outputted
	}
}
