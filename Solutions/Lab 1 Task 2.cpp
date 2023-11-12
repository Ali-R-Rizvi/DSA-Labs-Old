#include "iostream"
#include "string"
#include "fstream"

using namespace std;

int main()
{
	int roll;
	string fName, lName;
	float marks;

	ifstream f1;
	f1.open("student.txt");
	if (!f1)
	{
		cout << "Error, File not Opened";
		exit(1);
	}

	cout << "Roll Number\tName\t\tMarks" << endl;
	while (f1 >> roll >> fName >> lName >> marks)
	{
		cout << roll << "\t\t" << fName << " " << lName << "\t" << marks << endl;
	}

	f1.close();
	return 0;

}