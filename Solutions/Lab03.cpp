#include "iostream"

using namespace std;

struct Point3D
{
	float x, y, z;
};

class PointList
{
	Point3D* a;
	int maxSize, curSize, cursor;

public:
	PointList(int maxSize)
	{
		curSize = 0;
		cursor = -1;
		this->maxSize = maxSize;
		a = new Point3D[maxSize];

		for (int i = 0; i < maxSize; i++)
		{
			a[i].x = a[i].y = a[i].z = 0;
		}		
	}

	~PointList()
	{
		delete[] a;
	}

	bool isEmpty()
	{
		if (curSize == 0)
		{
			return true;
		}
		return false;
	}

	bool isFull()
	{
		if (curSize == maxSize)
		{
			return true;
		}
		return false;
	}

	void insert(Point3D newPoint)
	{
		if (curSize != 0 && curSize < maxSize)
		{
			a[curSize] = newPoint;
			cursor = curSize;
			++curSize;
		}
		else if(curSize == 0)
		{
			a[0] = newPoint;
			++curSize;
		}
		else
		{
			cout << "List is Already Full" << endl;
		}
	}

	void showStructure()
	{
		if (curSize == 0)
		{
			cout << "Empty List" << endl;
		}
		else
		{
			for (int i = 0; i < curSize; i++)
			{
				cout << "Point " << i + 1 << ": " << a[i].x << ", " << a[i].y << ", " << a[i].z << endl;
			}
		}
	}

	Point3D getCursor()
	{
		if (curSize != 0)
		{
			cout << a[cursor].x << ", " << a[cursor].y << ", " << a[cursor].z << endl;
			return a[cursor];
		}
		else
		{
			cout << "Empty List: ERROR" << endl;
			Point3D o;
			o.x = o.y = o.z = -1;

			cout << o.x << ", " << o.y << ", " << o.z << endl;
			return o;
		}
	}

	void gotoBeginning()
	{
		if (curSize != 0)
		{
			cursor = 0;	
		}			
	}

	void gotoEnd()
	{
		if (curSize != 0)
		{
			cursor = curSize - 1;
		}
	}

	bool gotoNext()
	{
		if (curSize != 0)
		{
			if (cursor < curSize - 1)
			{
				++cursor;
				return true;
			}
			return false;
		}
	}

	bool gotoPrior()
	{
		if (curSize != 0)
		{
			if (cursor != 0)
			{
				--cursor;
				return true;
			}
			return false;
		}
	}

	void clear()
	{
		curSize = 0;
		cursor = -1;
	}
	
	bool replace(Point3D newPoint)
	{
		if (curSize != 0)
		{
			a[cursor] = newPoint;

			return true;
		}
		return false;
	}

	void remove()
	{
		if (curSize != 0)
		{
			if (cursor != curSize)
			{
				a[cursor] = a[curSize - 1];
				--curSize;
			}
			else if (cursor == curSize - 1)
			{
				--curSize;
				cursor = 0;
 			}
		}

	}

};

int main()
{
	PointList list(5);
	Point3D p, q, r, s, t;
	p.x = r.y = 2.8;
	p.y = s.z = 3.7;
	p.z = r.x = 8.2;

	q.x = s.y = 4.6;
	q.y = s.x = 2.8;
	q.z = r.z = 1.9;

	t.x = 7.3; t.y = 4.6; t.z = 9.1;

	cout << "List is Empty? " << list.isEmpty() << endl;
	
	list.insert(p);
	list.insert(q);
	
	cout << "List is Full? " << list.isFull() << endl;

	list.insert(r);
	list.insert(s);
	list.insert(t);
		
	cout << "--- Displaying List ---" << endl;
	list.showStructure();

	cout << "Now List is FULL? " << list.isFull() << endl;

	list.getCursor();

	list.gotoBeginning();
	list.getCursor();

	list.gotoEnd();
	list.getCursor();

	cout << "NEXT? " << list.gotoNext() << endl;
	cout << "PRIOR? " << list.gotoPrior() << endl;
	list.gotoPrior();

	list.getCursor();

	PointList eList(2);
	eList.insert(p);
	eList.insert(t);

	eList.showStructure();
	eList.clear();
	cout << "Cleared? " << eList.isEmpty() << endl;

	Point3D n;
	n.x = n.y = n.z = 5.5;

	cout << "Replace Successful? " << list.replace(n) << endl;

	list.showStructure();

	cout << "GO to Prior" << endl;
	list.gotoPrior();
	list.remove();
	list.showStructure();

	cout << "go to end" << endl;
	list.gotoEnd();
	list.remove();
	list.showStructure();

	cout << "Checking if the cursor is at beginning" << endl;
	list.getCursor();

	return 0;
}
