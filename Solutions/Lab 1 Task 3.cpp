#include "iostream"
#include "string"
#include "fstream"

using namespace std;

int main()
{
	string str;

	ifstream f;
	f.open("input.txt");
	if (!f)
	{
		cout << "Error" << endl;
		exit(1);
	}

	while (!f.eof())
	{
		getline(f, str);
		cout << str << endl;
	}

	f.close();
	return 0;
}