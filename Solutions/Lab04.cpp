#include "iostream"

using namespace std;

class Matrix
{
	int* p, rows, cols;

public:
	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;

		p = new int[rows * cols];

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				*(p + i * cols + j) = 0;
			}
		}
	}

	~Matrix()
	{
		delete[] p;
	}

	int get(int i, int j)
	{
		if ((i >= 0 && i < rows) && (j >= 0 && j < cols))
		{
			return *(p + i * cols + j);
		}
		else
		{
			cout << "Row or Column is out of bounds" << endl;
		}
	}

	void set(int i, int j, int v)
	{
		if ((i >= 0 && i < rows) && (j >= 0 && j < cols))
		{
			*(p + i * cols + j)  = v;
		}
		else
		{
			cout << "Row or Column is out of bounds" << endl;
		}
	}

	void print()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << *(p + i * cols + j) << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	void transpose()
	{
		int* t;
		t = new int[rows * cols];
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				*(t + j * rows + i) = *(p + i * cols + j);
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				*(p + i * cols + j) = *(t + i * cols + j);
			}
		}
		delete[] t;
	}
		
	void printSubMatrix(int r1, int r2, int c1, int c2)
	{
		if (r1 >= 0 && r1 < rows && r2 >= 0 && r2 < rows && c1 >= 0 && c1 < cols && c2 >= 0 && c2 < cols)
		{
			for (int i = r1; i <= r2; i++)
			{
				for (int j = c1; j <= c2; j++)
				{
					cout << *(p + i * cols + j) << " ";
				}
				cout << endl;
			}
			cout << endl;

		}
		else
		{
			cout << "Incorrect SubMatrix dimensions" << endl;
		}
	}

	void makeEmpty(int n)
	{
		if (n < rows && n < cols)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					*(p + i * cols + j) = 0;
					*(p + j * rows + i) = 0;
				}
			}
		}
		else
		{
			cout << "Value exceeds Row or Column Size. No Changes will be made." << endl;
		}
	}

	//void add(Matrix first, Matrix second)
	//{
	//	if ((first.rows == second.rows) && (first.cols == second.cols))
	//	{
	//		this->rows = first.rows;
	//		this->cols = first.cols;
	//		for (int i = 0; i < rows; i++)
	//		{
	//			for (int j = 0; j < cols; j++)
	//			{
	//				this->p[i * cols + j] = first.p[i * cols + j] + second.p[i * cols + j];
	//			}
	//		}
	//	}
	//	else
	//	{
	//		cout << "ERROR: Rows and Columns of Matrices are not Equal" << endl;
	//	}
	//}

	void add(Matrix first, Matrix second)
	{
		if ((first.rows == second.rows) && (first.cols == second.cols))
		{
			this->rows = first.rows;
			this->cols = second.cols;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					this->p[i * cols + j] = first.p[i * cols + j] + second.p[i * cols + j];

					//*(p + i * cols + j) = *(first.p + i * cols + j) + *(second.p + i * cols + j);
				}
			}
		}
		else
		{
			cout << "ERROR! Rows and Columns are not Equal." << endl;
		}
	}

};

int main()
{
	Matrix m(5, 5);

	m.set(2, 1, 4);
	m.set(0, 0, 1);
	m.set(3, 1, 2);
	m.set(0, 2, 3);
	m.set(1, 0, 3);
	m.set(4, 1, 6);
	m.set(1, 2, 2);
	m.set(2, 0, 2);
	m.set(3, 2, 6);
	m.set(4, 4, 7);

	cout << m.get(2, 2) << endl;
	cout << m.get(2, 1) << endl;
	m.print();

	m.transpose();
	cout << endl << endl;
	m.print();

	cout << endl << endl;
	m.printSubMatrix(1, 3, 2, 3);

	m.makeEmpty(1);
	m.print();

	Matrix n(5, 5), s(5, 5);
	n.set(0, 0, 1);
	n.set(0, 3, 9);
	n.set(0, 4, 2);
	n.set(1, 1, 4);
	n.set(1, 0, 1);
	n.set(2, 1, 1);
	n.set(2, 2, 2);
	n.set(3, 0, 2);
	n.set(3, 1, 3);
	n.set(3, 2, 6);
	n.set(4, 0, 2);
	n.set(4, 2, 3);
	n.set(4, 4, 1);

	cout << "N = " << endl;
	n.print();

	cout << "M = " << endl;
	m.print();

	s.print();
	//cout << "S = " << endl;
	//s.add(m, m);
	////s.print();

	return 0;
}