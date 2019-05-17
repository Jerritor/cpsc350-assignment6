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
}

//======PUBLIC METHODS======
void Sorter::printList()
{
	if (arrSize == -1 || numArray == NULL) //something wrong
	{
		cout << "Something isn't right. Make sure the inputted file has the right data formatting." << endl;
	}
	else
	{
		cout << "===PRINTING===" << endl;
		cout << "arrSize: " << arrSize << endl;
		for (int i = 0; i < arrSize; i++)
		{
			cout << "[" << i << "] = " << setprecision(9) << numArray[i] << endl;
			//std::setpricision sets decimal places to be outputted
		}
	}
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
		}
		else //numbers to be read
		{
			if (counter > arrSize) //not >= bc line 0 doesnt count
				break;
			else //counter-1 bc else starts at counter = 1
				numArray[counter-1] = curr; //add num to numArray
		}
		counter++;
	}

	inputStream.close();
}

void Sorter::quickSort()
{

}

void Sorter::insertionSort()
{

}

void Sorter::bubbleSort()
{

}

void Sorter::selectionSort()
{

}
