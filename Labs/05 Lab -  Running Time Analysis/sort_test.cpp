#include "iostream"
#include "fstream"
#include "ctime"

using namespace std;

//Add necessary instructions to count the Number of Key Comparsisons and Data Movements
//You are NOT Allowed to add any input/output instructions in sorting algorithms 

//Bubble Sort
void bubbleSort(int a[], int size)
{
	int key = 0, dm = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				dm++;	
			}
			key++;	
		}
	}
	cout << "Key Comparison = " << key << "\tData Movements = " << dm << endl;
}

//Selection Sort
void selectionSort(int a[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;

		for (int j = i + 1; j < size; j++)
		{
			if (a[min] > a[j])
				min = j;
		}

		swap(a[i], a[min]);
	}
}

//Insertion Sort
void insertionSort(int a[], int size)
{
	int j = 0;

	for (int i = 0; i < size - 1; i++)
	{
		j = i + 1;

		while (j > 0 && a[j] < a[j - 1])
		{
			swap(a[j], a[j - 1]);
			j--;
		}
	}
}

int main()
{
	int d[500], total;
	//Read the data from file here
	ifstream f;
	///D:\\University\\Data Structures and Algorithm\\Lab\\05 Lab -  Running Time Analysis\\//
	f.open("Data Files\\in500a.txt");
	if(f.is_open())
	{
		while(!f.eof())
		{
			//for(int i = 1; i == f.eof(); i++)
			f >> total;
			for(int i = 0; i < 500; i++)
			{
				f >> d[i];
			}
		}
		cout << "Total = " << total << endl;
	}
	else
	{
		cout << "File not Opened" << endl;
		exit(0);
	}

	clock_t startTime = clock();

	//Make a call to sorting algorithm. DO NOT perform any other operation here 
	bubbleSort(d, 500);
	
	clock_t endTime = clock();
	double elapse = ((double)endTime - (double)startTime) / CLOCKS_PER_SEC;
	cout << "The operation took " << elapse << " seconds";

	//Add any other instructions here, if required


	return 0;
}
