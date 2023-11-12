#include "iostream"
#include "fstream"
#include "string"

using namespace std;

int main()
{
	int roll, marks;
	string fName, lName;

	ifstream s;
	s.open("student.txt");
	if (!s)
	{
		cout << "Error File not Opened" << endl;
		exit(0);
	}

	cout << "Roll No.\tName\t\tMarks" << endl;
	while (s >> roll >> fName >> lName >> marks)
	{
		cout << roll << "\t\t" << fName << " " << lName << "\t" << marks << endl;
	}

	s.close();

	return 0;
}