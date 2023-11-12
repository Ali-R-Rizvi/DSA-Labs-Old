#include "iostream"
#include "fstream"

using namespace std;

//complete the implementation of eraseObject function
void eraseObject (int** ar, int r, int c, int i, int j)
{
	if (i >= 0 && i < r && j >= 0 && j < c)
	{
		for (int x = 0; x < r; x++)
		{
			for (int y = 0; y < c; y++)
			{
				if (x == i && y == j)
				{
					ar[x][y] = 0;
					if (ar[x][y - 1] == 1)
					{
						return eraseObject(ar, r, c, i, j - 1);
					}
					else if (ar[x][y + 1] == 1)
					{
						return eraseObject(ar, r, c, i, j + 1);
					}
					else if (ar[x + 1][y] == 1)
					{
						return eraseObject(ar, r, c, i + 1, j);
					}
					//else if (ar[x - 1][y] == 1)
					//{
					//	return eraseObject(ar, r, c, i - 1, j);
					//}
					
				}
			}
		}
	}
	

}

int main(void)
{
	//opening file
	ifstream inf("input.txt");

	if(!inf)
	{
		cout << "Failed to open a file" << endl;
		exit(0);
	}

	int ROWS, COLS, p_x, p_y;
		
	inf >> ROWS >> COLS;	//rading size of image from file
	inf >> p_x >> p_y;		//reading coordinates of the pixel from file
	
	//array of pointers
	int **ar = new int*[ROWS];

	//each location has COLS size int array
	for(int i = 0; i < ROWS; i++)
	{
		ar[i] = new int[COLS];
	}

	//reading image data from file into ar
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			inf >> ar[i][j];
		}
	}

	//closing file
	inf.close();

	//making call to eraseObject function
	eraseObject (ar, ROWS, COLS, p_x, p_y);
	
	//displaying image data after processing
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
	
	//freeing all the allocated memory
	for(int i = 0; i < ROWS; i++)
	{
		delete[] ar[i];
	}
	delete[] ar;
	
	return 0;
}
