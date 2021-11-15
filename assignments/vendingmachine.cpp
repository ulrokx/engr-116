#include <iostream>
#include <sys/stat.h>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <experimental/filesystem>
using namespace std;

struct VendingItem {
    string name;
    int initStock;
    int stock;
    double price;
    VendingItem(string itemname, int starting, double setPrice) {
    name = itemname;
    initStock = starting;
    stock = initStock;
    price = setPrice;
    }
};

class VendingMachine {
    public:
    VendingMachine();
    VendingMachine(vector<VendingItem>& initItems);
    void addItem(VendingItem& item);
    void menu();
    void dispense(int index);
    void handleMoney(int index);
    void adminPanel();
    void restockAll();
    void auth();
    void createPassword();

    private:
    ifstream ifs;
    ofstream ofs;
    string filename;
    vector<VendingItem> items;
    double revenue;
};

VendingMachine::VendingMachine(vector<VendingItem>& initItems) {
    items = initItems;
    filename = "authpass.txt";
}

void VendingMachine::addItem(VendingItem& item) {
    items.push_back(item);
    cout << "Added " << item.name << " to the machine with an initial stock of " << item.initStock << " and a price of " << item.price << endl;
}

void VendingMachine::menu() {
    cout << "This is a vending machine. To attempt to dispense an item type the code corresponding to the item." << endl;
    int idx = 0;
    double response = -1;
    for(auto item: items) {
        cout << idx++ << ": " << item.name << endl;
    }
    cout << "99: Admin Functions" << endl;
    while(response >= items.size() || response < 0) {
        if(response == 99) {
            auth();
            return;
        }
        cin >> response;
    }
    if (response == 99) {
        auth();
    }
    if(items[(int)response].stock == 0) {
        cout << "Sorry, this item is out of stock. Call the admin to restock the machine." << endl;
        return;
    } 
    handleMoney((int)response);
    
}

void VendingMachine::handleMoney(int index) {
    double itemPrice = items[index].price;
    string itemName = items[index].name;
    int itemAmt = items[index].stock;
    cout << "Item " << index << ": " << itemName << " costs $" << itemPrice << "." << endl;
    cout << "How will you be paying? Enter amount to tender." << endl;
    double response = -1;
    while(response < 0) {
        cin >> response;
    }
    if(response < itemPrice) {
        cout << "Insufficient funds! " << endl;
        return;
    }
    else {
        cout << "Paid with $" << response << endl;
        cout << "Change given: $" << response - itemPrice << endl;
        dispense(index);
    }

}

void VendingMachine::dispense(int index) {
    cout << "Dispensing item..." << endl;
    items[index].stock--;
    revenue += items[index].price;
}

void VendingMachine::restockAll() {
    for(auto& item : items) {
        item.stock = item.initStock;
    }
    cout << "Restocked all items!" << endl;
}

void VendingMachine::adminPanel() {
    cout << "--Admin Panel--" << endl;
    cout << "0: Restock all items." << endl;
    cout << "1: See item counts" << endl;
    cout << "2: See revenue" << endl;
    cout << "3: Change password" << endl;
    cout << "4: Exit to menu" << endl;
    int response = -1;
    while(response < 0 || response > 4) {
        cin >> response;
    }
    switch(response) {
        case 0:
        restockAll();
        break;

        case 1:
        for(auto item: items) {
            cout << "Item: " << item.name << " | " << "Stock: " << item.stock << endl;
        }
        break;

        case 2:
        cout << "$"<< revenue << endl;
        break;

        case 3:
        createPassword();
        break;

        case 4:
        return;
    }
}

void VendingMachine::createPassword() {
    string newPass;
    cout << "Enter new password:" << endl;
    cin >> newPass;
    ofs.open(filename, ios::trunc);
    ofs << newPass << endl;
    ofs.close();
    cout << "Password created" << endl;
    return;
}

void VendingMachine::auth() {
    ifs.open(filename);
    if(!ifs.good()) {
        ifs.close();
        createPassword();
    }
    else {
        ifs.close();
        cout << "Enter admin password: ";
        string userPass;
        cin >> userPass;
        ifs.open(filename);
        string line;
        if(getline(ifs, line)) {
            cout <<"file good" << endl;
        }
        else {
            cout <<"error" << endl;
        }
        if(line == userPass) {
            cout << "Successfully authenticated. Launching admin panel." << endl;
            ifs.close();
            adminPanel();
        }
        else {
            cout << "Incorrect password. " << endl;
            ifs.close();
            return;
        }
    }
}

int main () {
    vector<VendingItem> items =  {
        VendingItem("Lays Classic", 15, 1.25), 
        VendingItem("Fritos", 2, 1.25),
        VendingItem("Haribo", 10, 2.25),
        VendingItem("KitKat", 10, 1.5),
        VendingItem("Hershey's", 10, 1.5),
        VendingItem("Snickers", 10, 1.5)};
    VendingMachine machine(items); // init vending machine with items ^^
    while(true) {
    machine.menu();
    }

}