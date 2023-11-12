#include "iostream"

using namespace std;

const int MAX_SIZE = 5;

template <class T>
class Stack
{
private:
	T* data;
	int top;
	//	const int MAX_SIZE;

public:
	Stack()
	{
		data = new T[MAX_SIZE];
		top = -1;
	}

	~Stack()
	{
		delete[] data;
	}

	void push(const T newItem)
	{
		if (top != MAX_SIZE - 1)
		{
			data[++top] = newItem;
		}
		else
		{
			cerr << "Stack Overflow" << endl;
		}
	}

	void pop()
	{
		if (top != -1)
		{
			top--;
		}
		else
		{
			cerr << "Stack Underflow" << endl;
		}
	}

	void clear()
	{
		top = -1;
	}

	T getTop() const
	{
		if (top != -1)
		{
			return data[top];
		}
		else
		{
			cerr << "Stack Underflow" << endl;
		}
		return -1;
	}

	bool isEmpty() const
	{
		return top == -1;
	}

	bool isFull() const
	{
		return top == MAX_SIZE - 1;
	}

	void showStructure() const
	{
		cout << "top -->  " << data[top] << endl;
		for (int i = top - 1; i > -1; i--)
		{
			cout << "\t " << data[i] << endl;
		}
		cout << "-----------------" << endl;
	}

};

int main()
{
	Stack<float> s;

	s.push(5.0);
	s.push(6.5);
	s.showStructure();

	s.push(-3.0);
	s.push(-8.0);
	s.showStructure();

	s.pop();
	s.pop();
	s.showStructure();

	return 0;
}
