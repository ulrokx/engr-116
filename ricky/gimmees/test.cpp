#include <iostream>
#include <sstream>
using namespace std;

int main() {
    stringstream out;
    out << "hello" << endl << "hi";
    cout << out.str();
    return 0;
}