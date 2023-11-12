#include "iostream"
#include "fstream"
#include "string"

using namespace std;

int main()
{
	int roll, marks;
	string fName, lName;

	ofstream s;
	s.open("student.txt");
	if (!s)
	{
		cout << "File not Opened";
		exit(0);
	}

	cout << "Enter Roll Number, First Name, Last Name and Marks of Students" << endl;
	while (cin >> roll >> fName >> lName >> marks)
	{
		s << roll << " " << fName << " " << lName << " " << marks << endl;
	}

	s.close();

	return 0;
}