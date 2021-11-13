#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
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
        << email << endl
        << address << endl;
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
        if (line == query)
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
    while (getline(ifs, first))
    {
        cout << "First Name: " << first << endl;
        getline(ifs, last);
        cout << "Last Name: " << last << endl;
        getline(ifs, phone);
        cout << "Phone Number: " << phone << endl;
        getline(ifs, email);
        cout << "Email: " << email << endl;
    }
    ifs.close();
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
        // case 3:
        // book.del();
        // break;
        case 4:
            quit = true;
            break;
        default:
            cout << "Enter a number 0 - 4 :)" << endl;
        }
    }
}