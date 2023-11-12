#include "iostream"
#include "fstream"
#include "stack"

using namespace std;

bool delimetersOK(const string& exp) 
{
    stack<char> s;
    for (int i = 0; i < exp.length(); i++) 
	{
        if (exp[i] == '(' || exp[i] == '[') 
		{
            s.push(exp[i]);
        }
        if (exp[i] == ')' || exp[i] == ']') 
		{
            if (s.top() == '(' && exp[i] == ')') 
			{
                s.pop();
            }
            else if (s.top() == '[' && exp[i] == ']') 
			{
                s.pop();
            }
        }        
    }
    
    if (s.empty()) 
	{
        return true;
    }
    
    return false;
}

int main() {
    fstream file;
    file.open("input.txt",ios::in);
    
	string line;
    getline(file, line);
    string line2;
    
	int i = 1;
    
	while(!file.eof()) 
	{
        getline(file,line2);
        if (delimetersOK(line2)) 
		{
            cout << "Valid" << endl;
        }
        else 
		{
            cout << "Invalid" << endl;
        }
    }
    return 0;
}
