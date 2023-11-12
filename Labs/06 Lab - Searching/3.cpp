#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int count_occurences(const char *text, const char *word);
bool sub_str(const char* text, int occurence_index, const char* word);

int main(){

    string line, word;

    ifstream input_file("input3.txt");

    input_file >> word;
    input_file.ignore();
    
    int i = 1;
    while (!input_file.eof()){
        getline(input_file, line);
        cout << "Line "<< i++ << ": " << count_occurences(line.c_str(), word.c_str()) << endl;
    }
}

// Count occurences of a substring in some text, case insensitive
int count_occurences(const char *text, const char *word){
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
        if (tolower(text[i]) == tolower(word[0]))
            if (sub_str(text, i, word))
                count++;

    return count;
}

// Determines whether a string at a particular index is a substring or not, case insensitive
bool sub_str(const char* text, int occurence_index, const char* word){
    for (int i = 0, len = strlen(word); i < len; i++)
        if (text[occurence_index] != 0 && tolower(text[occurence_index++]) != tolower(word[i]))
            return false;
    return true;
}
