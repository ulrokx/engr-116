#include <iostream>
#include <fstream>

using namespace std;

int main () {
    string name, phone;
    ofstream writer;
    cout << "what is your name" << endl;
    cin >> name;
    cout << "what is your phone number" << endl;
    cin >> phone;

    writer.open("phonebook.txt", ios::app);
    writer << name << " " << phone<< endl;
    writer.close();
    

    string line;
    ifstream reader;

    reader.open("phonebook.txt");
    while(getline(reader,line))
    {
        cout << line << endl;
    }

    reader.close();



}