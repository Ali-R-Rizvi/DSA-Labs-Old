#include "iostream"
#include "fstream"
#include "string"

using namespace std;

int main()
{
	int roll;
	string fName, lName;
	float marks;

	ofstream f1;
	f1.open("student.txt");
	if (!f1)
	{
		cout << "File not Opened" << endl;
		exit(1);
	}

	cout << "Enter Roll Number, First Name, Last Name and Marks of Students" << endl;
		///*do
		//{
		//	cin >> roll >> fName >> lName >> marks;
		//	f1 << roll << " " << fName << " " << lName << " " << marks << endl;
		//
		//} while (roll != -999);*/

	while (cin >> roll >> fName >> lName >> marks)
	{
		if (roll == -999)
		{
			exit(1);
		}
		f1 << roll << " " << fName << " " << lName << " " << marks << endl;

	}
	
	f1.close();
	return 0;
}