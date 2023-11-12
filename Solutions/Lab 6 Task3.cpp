#include "iostream"
#include "fstream"
#include "cstring"
#include "string"

using namespace std;

int occurences(const char *t, const char *w);
bool subStr(const char* t, int occurence, const char* w);

int main()
{
    string line, word;

    ifstream f("input3.txt");

    f >> word;
    f.ignore();
    
    int i = 1;
    while (!f.eof())
	{
        getline(f, line);
        cout << "Line "<< i++ << ": " << occurences(line.c_str(), word.c_str()) << endl;
    }
}

int occurences(const char *t, const char *w)
{
    int count = 0;

    for (int i = 0, length = strlen(t); i < length; i++)
        {
        	if (tolower(t[i]) == tolower(w[0]))
             {
			 if (subStr(t, i, w))
             	{
			    	count++;
				}
			}
		}
		

    return count;
}

bool subStr(const char* t, int occurence, const char* w)
{
    for (int i = 0, length = strlen(w); i < length; i++)
    {
    	if (t[occurence] != 0 && tolower(t[occurence++]) != tolower(w[i]))
            {
            	return false;	
			}
	}       
    return true;
}
