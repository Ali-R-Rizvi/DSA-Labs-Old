#include "iostream"
#include "string"
#include "fstream"

using namespace std;

class Book
{
	friend class BookList;

private:
	int id;
	string title;
	float price;
	Book* next;
	Book* pre;

public:
	Book(int id, string title, float price, Book* next, Book* pre)
	{
		this->id = id;
		this->title = title;
		this->price = price;
		this->next = next;
		this->pre = pre;
	}
	void bookDetails()
	{
		cout << id << endl << title << endl << price << endl << endl;
	}
};

class BookList
{
private:
	Book* head;
	Book* cursor;
	Book* last;

public:
	BookList()
	{
		head = cursor = last = NULL;
	}

	~BookList()
	{
		if (head != NULL)
		{
			Book* temp = head;
			while (head)
			{
				head = temp->next;
				//delete temp->next;
				delete temp->pre;
				delete temp;
				temp = head;
			}
		}
	}

	void insert(const Book& newItem)
	{
		Book* temp;
		temp = new Book(newItem.id, newItem.title, newItem.price, newItem.next, newItem.pre);

		if (head == NULL)
		{
			head = cursor = last = temp;
		}
		else
		{
			temp->pre = cursor;
			cursor->next = temp;
			cursor = cursor->next;
			last = cursor;
		}
	}
	//}void insert(const Book& newItem)
	//{
	//	if (head == NULL)
	//	{
	//		Book* temp;
	//		temp = new Book(newItem.id, newItem.title, newItem.price, newItem.next, newItem.pre);
	//		head = temp;
	//		head->next = head->pre = NULL;
	//		cursor = head;
	//		//cursor = head = last;
	//		//head->pre = head->next = NULL;
	//	}
	//	else
	//	{
	//		Book* temp;
	//		temp = new Book(newItem.id, newItem.title, newItem.price, newItem.next, newItem.pre);
	//		cursor->next = temp;
	//		temp->pre = cursor;
	//		cursor = temp;
	//	}
	//}

	void remove()
	{
		if (head == NULL)
		{
			cout << "list Empty" << endl;
		}
		else
		{
			if (cursor->next == NULL)
			{
				Book* temp = cursor;
				cursor->pre->next = NULL;
				cursor = head;
				cursor->next = head->next;
				delete temp;
			}
			else
			{
				Book* temp = cursor;
				cursor = cursor->next;
				cursor->pre = temp->pre;
				delete temp;
			}
		}
	}

	void search(string title)
	{
		if (head == NULL)
		{
			cout << "list Empty" << endl;
		}
		else
		{
			Book* temp = head;
			while (temp != NULL)
			{
				if (temp->title == title)
				{
					temp->bookDetails();
				}
				temp = temp->next;
			}
		}
	}

	void replace(const Book& newItem)
	{
		if (head == NULL)
		{
			cout << "list Empty" << endl;
		}
		else
		{
			cursor->id = newItem.id;
			cursor->title = newItem.title;
			cursor->price = newItem.price;
		}
	}

	bool isEmpty()
	{
		return head == NULL;
	}

	void gotoBeginning()
	{
		if (head == NULL)
		{
			cout << "list Empty" << endl;
		}
		else
		{
			Book* temp = cursor;
			cursor->pre->next = temp->next;
			cursor->next->pre = temp->pre;
			cursor = head;
			//cursor->pre = NULL;
			//cursor->next = head->next;
		}
	}

	void gotoEnd()
	{
		if (head == NULL)
		{
			cout << "list Empty" << endl;
		}
		else
		{
			Book* temp = cursor;
			cursor->pre->next = temp->next;
			cursor->next->pre = temp->pre;
			cursor = last;
		}
	}

	bool gotoNext()
	{
		if (head == NULL)
		{
			cout << "list Empty" << endl;
		}
		else
		{
			if (cursor->next != NULL)
			{
				Book* temp = cursor;
				cursor = cursor->next;
				temp->pre = cursor;
				cursor->pre = temp->pre;

				return true;
			}
			return false;
		}
	}

	bool gotoPrior()
	{
		if (head == NULL)
		{
			cout << "list Empty" << endl;
		}
		else
		{
			if (cursor->pre != NULL)
			{
				Book* temp = cursor;
				cursor = cursor->pre;
				temp->next->pre = cursor;
				cursor->next = temp->next;

				return true;
			}
			return false;
		}
	}

	Book getCursor()
	{
		if (head == NULL)
		{
			cout << "list Empty" << endl;
		}
		else
		{
			return *cursor;
		}
	}

	void showStructureForward() const
	{
		if (head == NULL)
		{
			cout << "list Empty" << endl;
		}
		else
		{
			Book* temp = head;
			while (temp != NULL)
			{
				cout << temp->id << endl << temp->title << endl << temp->price << endl << endl;
				temp = temp->next;
			}
		}
	}

	void showStructureReverse() const
	{
		if (head == NULL)
		{
			cout << "list Empty" << endl;
		}
		else
		{
			Book* temp = last;
			while (temp != NULL)
			{
				cout << temp->id << endl << temp->title << endl << temp->price << endl << endl;
				temp = temp->pre;
			}
		}
	}

};


int main()
{
	//fstream f;
	//f.open("input.txt", ios::in);
	//if (!f)
	//{
	//	cerr << "Not Fourd" << endl;
	//	exit(0);
	//}
	//else
	//{
	//	int id;
	//	string title;
	//	float price;
	//	while (!f.eof())
	//	{
	//		f >> id >> title >> price;
	//		Book b1(id, title, price, NULL, NULL);
	//		BookList b;
	//		b.insert(b1);
	//		//b.getCursor();
	//		b.showStructureForward();
	//		//b.showStructureReverse();
	//	}
	//}
	//f.close();

	Book b(1, "C++", 200.1, NULL, NULL);

	BookList b1;
	b1.insert(b);

	//b.bookDetails();
	b1.showStructureForward();
	//b1.remove();

	return 0;
}