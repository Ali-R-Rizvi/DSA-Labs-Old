#include "iostream"

using namespace std;

class Collection
{
	int* data, size;

public:
	Collection(int size)
	{
		this->size = size;
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = 0;
		}
	}

	Collection(int data[], int size)
	{
		this->size = size;
		this->data = new int[size];
		for (int i = 0; i < size; i++)
		{
			if (data[i] < 0)
			{
				this->data[i] = 0;
			}
			else
			{
				this->data[i] = data[i];
			}			
		}
	}

	Collection(const Collection& c)
	{
		this->size = c.size;
		this->data = new int[size];

		for (int i = 0; i < size; i++)
		{
			this->data[i] = c.data[i];
		}
	}

	~Collection()
	{
		delete[] data;
	}

	int getSize() const
	{
		return size;
	}

	void printCollection() const
	{
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}

	void getCollection()
	{
		cout << "Enter size of Array: ";
		cin >> size;

		data = new int[size];
		cout << "Enter data in collection" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "Enter [" << i + 1 << "]: ";
			cin >> data[i];
			if (data[i] < 0)
			{
				this->data[i] = 0;
			}
		}
	}

	void insertElement(int k, int i)
	{
		if (i >= 0 && i < size)
		{
			for (int j = 0; j < size; j++)
			{
				if (j == i)
				{
					if (k < 0)
					{
						data[j] = 0;
					}
					else
					{
						data[j] = k;
					}					
				}
			}
		}
		else
		{
			cout << "Index is Out of Bounds" << endl;
			exit(1);
		}
	}

	bool findElement(int key)
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] == key)
			{
				cout << "Key Exists" << endl;
				return true;
			}
		}
		return false;
	}

	Collection operator=(const Collection& c)
	{
		if (size != c.size)
		{
			delete[] data;
			size = c.size;
			data = new int[size];
			for (int i = 0; i < c.size; i++)
			{
				data[i] = c.data[i];
			}
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				data[i] = c.data[i];
			}
		}
		return *this;
	}

	Collection operator+ (const Collection& c)
	{
		
		if (c.size == size)
		{
			Collection a(*this);
			for (int i = 0; i < size; i++)
			{
				a.data[i] = c.data[i] + data[i];
			}
			return a;
		}
		else
		{
			Collection b(1);
			return b;
		}
	}

	bool operator== (Collection& c)
	{
		if (c.size == size)
		{
			for (int i = 0; i < size; i++)
			{
				if (data[i] != c.data[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	Collection c(5), c3(c);

	//c.getCollection();
	//c.printCollection();

	//Collection c1(c);
	//c1.printCollection();

	int arr[6] = { 1, 7, -5, 8, 8, 9 };
	
	Collection c2(arr, 6);
	c2.printCollection();

	cout << c2.getSize() << endl;

	c2.insertElement(5, 2);
	c2.printCollection();
	c2.findElement(9);

	c.getCollection();
	c.printCollection();

	//cout << (c + c2) << endl;
	cout << (c == c2);
	c3 = c + c2;
	c3.printCollection();

	return 0;
}