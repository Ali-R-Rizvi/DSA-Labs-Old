#include "iostream"
#include "fstream"
#include "string"

using namespace std;

class Student
{
	friend class StudentBST;

private:
	int stdID;
	string name;
	float fee;
	Student* left;
	Student* right;

public:
	Student(int stdID, string name, float fee, Student* left, Student* right)
	{
		this->stdID = stdID;
		this->name = name;
		this->fee = fee;
		this->left = left;
		this->right = right;
	}

	void display()
	{
		cout << stdID << "\t" << name << "\t" << fee << endl;
	}
};

class StudentBST
{
private:
	Student* root;

	void inOrder(Student* p)
	{
		if (p != NULL)
		{
			inOrder(p->left);
			p->display();
			inOrder(p->right);
		}
	}

	void preOrder(Student* p)
	{
		if (p != NULL)
		{
			p->display();
			inOrder(p->left);
			inOrder(p->right);
		}
	}

	void postOrder(Student* p)
	{
		if (p != NULL)
		{
			inOrder(p->left);
			inOrder(p->right);
			p->display();
		}
	}

	void destroy(Student* p)
	{
		if (p != NULL)
		{
			destroy(p->left);
			destroy(p->right);
			delete p;
		}
	}

public:
	StudentBST()
	{
		root = NULL;
	}

	~StudentBST()
	{
		destroy(root);
		root = NULL;
	}

	bool insert(int stdID, string name, float balance)
	{
		Student* temp = new Student(stdID, name, balance, NULL, NULL);
		Student* cur = root;
		Student* pre = NULL;
		
		while (cur != NULL)
		{
			pre = cur;
			if (temp->stdID == cur->stdID)
				return false;
			else if (temp->stdID < cur->stdID)
				cur = cur->left;
			else
				cur = cur->right;
		}

		if (pre == NULL)
		{
			root = temp;
			return true;
		}
		else if (pre->stdID < temp->stdID)
		{
			pre->right = temp;
			return true;
		}
		else 
		{
			pre->left = temp;
			return true;
		}
	}

	bool search(int stdID)
	{
		Student* temp = root;

		while (temp != NULL)
		{
			if (stdID == temp->stdID)
			{
				temp->display();
				return true;
			}
			else if (stdID < temp->stdID)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		cout << "Not Found" << endl;
		return false;
	}

	void inOrder()
	{
		inOrder(root);
		cout << endl;
	}

	void preOrder()
	{
		preOrder(root);
		cout << endl;
	}

	void postOrder()
	{
		postOrder(root);
		cout << endl;
	}
};

int main()
{
	fstream f;
	f.open("input.txt", ios::in);

	int stdID;
	string name; 
	float fee;

	StudentBST s;
	while (!f.eof())
	{
		f >> stdID >> name >> fee;
		s.insert(stdID, name, fee);
	}
	f.close();

	s.search(3);
	cout << endl;

	s.postOrder();

	return 0;
}