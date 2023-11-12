#include "iostream"
#include "stdlib.h"
#include "string"

using namespace std;

class Student
{
	friend class StudentList;

private:
	int id;
	string name;
	float cgpa;
	Student* next;

public:
	Student(int id, string name, float cgpa, Student* next)
	{
		this->id = id;
		this->name = name;
		this->cgpa = cgpa;
		this->next = next;
	}

	void studentDetails()
	{
		cout << "Displaying details" << endl;
		cout << "ID\tName\tCGPA" << endl;
		cout << id << "\t" << name << "\t" << cgpa << endl;
	}
};

class StudentList {
private:
	Student* head;
	Student* cursor;

public:
	StudentList()
	{
		head = cursor = NULL;
	}

	~StudentList()
	{
		delete head;
		delete cursor;
	}

	void insert(const Student* newStd) 
	{
		if (head == NULL)
		{
			head = new Student(newStd->id, newStd->name, newStd->cgpa, newStd->next);
			cursor = head;
		}
		else
		{
			cursor->next = new Student(newStd->id, newStd->name, newStd->cgpa, newStd->next);
			cursor = cursor->next;
		}
	}

	void remove(int id)
	{
		if (head == NULL)
		{
			cout << "List is Empty" << endl;
		}
		else
		{
			Student* temp;
			temp = cursor;
			if (cursor->id == id)
			{
				cursor = cursor->next;
				delete temp;
			}
			else if (cursor->next == NULL && cursor->id == id)
			{
				delete temp;
				cursor = head;
			}
		}
	}

	void search(float cgpa) const
	{
		if (head == NULL)
		{
			cout << "Empty List" << endl;
		}
		else
		{
			Student* temp;
			temp = head;
			while (temp->next != NULL)
			{
				if (temp->cgpa == cgpa)
				{
					//Display Details
					temp->studentDetails();
				}
				temp = temp->next;
			}
			cout << "Not Found" << endl;
		}
	}

	bool isEmpty()
	{
		return head == NULL;
	}

	void gotoBeginning()
	{
		cursor = head;
	}

	void gotoEnd()
	{
		if (head == NULL)
		{
			cout << "list is Empty" << endl;
		}
		else
		{
			while (head->next != NULL)
			{
				head = head->next;
			}
			cursor = head;
		}
	}

	bool gotoNext()
	{
		if (cursor->next != NULL)
		{
			cursor = cursor->next;
			return true;
		}
		return false;
	}

	bool gotoPrior()
	{
		Student* pre;
		pre = head;
		if (cursor == head)
		{
			return false;
		}
		else
		{
			while (head->next != cursor)
			{
				head = head->next;
				pre = head;
			}
			cursor = pre;
			return true;
		}
	}

	Student getCursor()
	{
		if (head == NULL)
		{
			cout << "list is Empty" << endl;
		}
		else
		{
			//display information
			cursor->studentDetails();
		}
	}

	void showStructure() const
	{
		if (head == NULL)
		{
			cout << "list is Empty" << endl;
		}
		else
		{
			Student* temp = head;
			do
			{
				temp->studentDetails();
				temp = temp->next;
			} while (temp->next != NULL);
		}
	}
};

int main()
{
	Student std(1, "ABC", 2.4, NULL);

	std.studentDetails();

	return 0;
}