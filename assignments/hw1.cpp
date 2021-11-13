#include <iostream>
using namespace std;

int main(){
    system("Color 0A");
    cout << "Hello World!" << endl;
    printf("This is another way to print text! \n");
    cout << "This is line 3." << endl;
    cout << "This is line 4." << endl;
    system("echo This is line 5, another way to print text");
    return 0;
}
