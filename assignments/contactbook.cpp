#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AddressBook
{
private:
    ofstream ofs;
    ifstream ifs;
    string filename;
    uint32_t entries;

public:
    AddressBook();
    void add();
    void search();
    void display();
    void Sdelete();
};

AddressBook::AddressBook()
{
    filename = "addressbook.txt";
}

void AddressBook::add()
{
    string first, last, phone, email, address;
    cout << "First name of new contact:" << endl;
    cin >> first;
    cout << "Last name of new contact:" << endl;
    cin >> last;
    cout << "Phone number of new contact:" << endl;
    cin >> phone;
    cout << "Email address of new contact:" << endl;
    cin >> email;
    ofs.open(filename, ios::app);
    ofs << first << endl
        << last << endl
        << phone << endl
        << email << endl;
    ofs.close();
}

void AddressBook::search()
{
    string query, line;
    bool found = false;
    stringstream foundResults;
    int numFound = 0;
    cout << "Enter first name of contact you would like to find the details of:" << endl;
    cin >> query;
    ifs.open(filename);
    while (getline(ifs, line))
    {
        if (line.find(query) != string::npos)
        {
            numFound++;
            foundResults << "First Name: " << line << endl;
            getline(ifs, line);
            foundResults << "Last Name: " << line << endl;
            getline(ifs, line);
            foundResults << "Phone Number: " << line << endl;
            getline(ifs, line);
            foundResults << "Email: " << line << endl << endl;
        }
    }
    if (numFound == 0)
    {
        cout << "Found no results. Did you make a typo?" << endl
             << endl;
        return;
    }
    cout << "Found " << numFound << " results:" << endl;
    cout << foundResults.str();
    ifs.close();
}

void AddressBook::display()
{
    cout << "Printing entire address book:" << endl;
    string first, last, phone, email;
    ifs.open(filename);
    int count = 0;
    while (getline(ifs, first))
    {
        count++;
        cout << "First Name: " << first << endl;
        getline(ifs, last);
        cout << "Last Name: " << last << endl;
        getline(ifs, phone);
        cout << "Phone Number: " << phone << endl;
        getline(ifs, email);
        cout << "Email: " << email << endl << endl;

    }
    if(count ==0) {
        cout << "Book is empty!" << endl;
    }
    ifs.close();
}

void AddressBook::Sdelete()
{
    int lineIndex = 0;
    string query, line;
    stringstream foundResults;
    int found = 0;
    vector<int> toDelete;
    cout << "Enter name you would like to find delete from your address book:" << endl;
    cin >> query;
    ifs.open(filename);
    while (getline(ifs, line))
    {
        lineIndex++;
        if (line.find(query) != string::npos)
        {
            found++;
            toDelete.push_back(lineIndex);
            foundResults << "Result " << found << endl;
            foundResults << "First Name: " << line << endl;
            getline(ifs, line);
            foundResults << "Last Name: " << line << endl;
            getline(ifs, line);
            foundResults << "Phone Number: " << line << endl;
            getline(ifs, line);
            foundResults << "Email: " << line << endl << endl;
        }
    }
    cout << "Found " << found << " results." << endl;
    if(found > 0) {
        cout << foundResults.str();
    }
    else {
        return;
    }
    string boole;
    while(!(boole == "y" || boole == "n")) {
    cout << "Would you like to delete a result? (y/n)" << endl;
    cin >> boole;
    }
    if(boole == "n") {
        ifs.close();
        return;
    }
    int response = -1;
    while(response < 1 || response > found) {
    cout << "Which result would you like to delete?" << endl;
        cin >> response;
    }
    response--;
    ifs.clear();
    ifs.seekg(0);
    ofs.open("tempaddbook.txt");
    int lineOut = 1;
    while(getline(ifs,line)) {
        if(lineOut == toDelete[response]) {
            getline(ifs,line);
            getline(ifs,line);
            getline(ifs,line);
            cout << "Deleted entry." << endl;
            continue;
        }
        lineOut++;
        ofs << line << endl;
    }
    ifs.close();
    ofs.close();
    remove(filename.c_str());
    rename("tempaddbook.txt", filename.c_str());
}

int main()
{
    AddressBook book;
    bool quit = false;
    while (!quit)
    {
        cout << "What would you like to do\n0: Add new contact\n1: Search for contact\n2: Display all contacts\n3: Delete a contact\n4: Quit" << endl;
        int response;
        cin >> response;
        switch (response)
        {
        case 0:
            book.add();
            break;
        case 1:
            book.search();
            break;
        case 2:
            book.display();
            break;
        case 3:
        book.Sdelete();
        break;
        case 4:
            quit = true;
            break;
        default:
            cout << "Enter a number 0 - 4 :)" << endl;
        }
    }
    cout << "Thanks for using my addressbook!" << endl;
}