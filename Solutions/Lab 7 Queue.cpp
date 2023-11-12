#include "iostream"

using namespace std;

const int MAX_SIZE = 5;

template <class T>
class Queue
{
private:
	T* data;
	int front;
	int rear;

public:
	Queue()
	{
		data = new T[MAX_SIZE];
		int rear = front = -1;
	}

	~Queue()
	{
		delete[] data;
	}

	void enQueue(T newItem)
	{
		if (!isFull())
		{
			if (front == -1)
			{
				front = 0;
			}
			rear = (rear + 1) % MAX_SIZE;
			data[rear] = newItem;
		}
		else
		{
			cerr << "Queue is Full" << endl;
		}
	}

	void deQueue()
	{
		if (!isEmpty())
		{
			if (rear == front)
			{
				rear = front = -1;
			}
			else
			{
				front = (front + 1) % MAX_SIZE;
			}
		}
		else
		{
			cerr << "Queue is Empty" << endl;
		}
	}

	void clear()
	{
		front = rear = -1;
	}

	T getFront() const
	{
		if (!isEmpty())
		{
			return data[front];
		}
		else
		{
			cerr << "Queue is Empty" << endl;
		}
	}

	T getRear() const
	{
		if (!isEmpty())
		{
			return data[rear];
		}
		else
		{
			cerr << "Queue is Empty" << endl;
		}
	}

	bool isEmpty()
	{
		return front == -1;
	}

	bool isFull()
	{
		return ((rear + 1) % MAX_SIZE == front);
	}

	void showStructure() const
	{
		cout << "front -->  " << data[front + 1] << endl;
		for (int i = front + 2; i < rear; i++)
		{
			cout << "  \t   " << data[i] << endl;
		}
		cout << "  \t   " << data[rear] << "   <-- rear" << endl;
		cout << "--------------------------" << endl;
	}

};

int main()
{
	Queue<float> q;

	q.enQueue(5.0);
	q.enQueue(6.5);
	q.showStructure();

	q.enQueue(-3.0);
	q.enQueue(-8.0);
	q.showStructure();

	q.deQueue();
	q.deQueue();
	q.showStructure();

	return 0;
}