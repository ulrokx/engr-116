//I pledge my honor that I have abided by the Stevens Honor System
#include<iostream>
#include<math.h>
using namespace std;
#define PI 3.14159265 // put pi here don't know how to do it better

int main()
{
    //define whether to restart the calculator outside of the while loop
    bool contans = false;
    printf("This is Richard Kirk ENGR-116 Week 2 calculator/string concatenator\n"
            "Type into the terminal to answer the prompts\n"
            "All angles will be given by you and returned to you in degrees\n"
            "Pi is approximated to eight digits after the decimal\n");
    do {
        //define everything for the calculator
    float angle, hypo, adj, opp;
    int calc;
    string contquest;
    cout << "Enter 0 for right angle triangle calculator or 1 for basic calculator:"<< endl;
    cin >> calc;
    switch(calc) {
    case 0:
        int tfunction;
        cout << "0 - Find the components given angle and hypotenuse" << endl;
        cout << "1 - Find the other component and hypotenuse given angle and component" << endl;
        cout << "2 - Find the adjacent angle and opposite angle given both components" << endl;
        cin >> tfunction;
        switch(tfunction) {
            case 0:

            cout << "Enter angle in degrees" << endl;
            cin >> angle;
            cout << "Enter hypotenuse" << endl;
            cin >> hypo;
            adj = hypo * cos(angle*PI/180);
            opp = hypo * sin(angle*PI/180);
            cout << "The adjacent component is " << adj << endl;
            cout << "The opposite component is " << opp << endl;
            break;
            case 1:

            cout << "Enter angle adjacent to component in degrees" << endl;
            cin >> angle;
            cout << "Enter component adjacent to angle";
            cin >> adj;
            opp = adj * tan(angle*PI/180);
            hypo = adj / cos(angle*PI/180);
            cout << "The opposite component is " << opp << endl;
            cout << "The hypotenuse is " << hypo << endl;
            break;

            case 2:

            cout << "Enter first component" << endl;
            cin >> adj;
            cout << "Enter second component" << endl;
            cin >> opp;
            hypo = hypot(adj, opp);
            angle = atan(opp/adj)*180/PI;
            cout << "The angle adjacent to the first component is " << angle << endl;
            cout << "The angle adjacent to the second component is " << 90-angle << endl;
            cout << "The hypotenuse is " << hypo << endl;
            break;
        }
        break;
    case 1:
        string type;
        while(true) {
        cout << "Type variable type: (string, int, or float)" << endl;
        cin >> type;
        if(type == "string" || "int" || "float") {
            break;
        } else{
            cout << "Try Again" << endl;
        }
        }
        if(type == "string") {

            string string1, string2;

            cout << "You selected string." <<  endl;
            cout << "Enter the first string:" <<  endl;
            cin >> string1;
            cout << "Enter the second string:" << endl;
            cin >> string2;
            cout << "This is your concatenated string:" << endl;
            string newString = string1 + " " + string2;
            cout << newString << endl;
    }   else if(type == "int") {

            int int1, int2;

            cout << "You selected integer." << endl;
            cout << "Enter the first integer" << endl;
            cin >> int1;
            cout << "Enter the second integer" << endl;
            cin >> int2;
            cout << "Basic math:" << endl;
            cout << "Sum:" << int1 + int2 << endl;
            cout << "Difference:" << int1 - int2 << endl;
            cout << "Product:" << int1 * int2 << endl;
            cout << "Dividend:" << int1 / int2 << endl;
            cout << "Power:" << pow(int1, int2) << endl;
        } else if(type == "float") {

            float float1, float2;

            cout << "You selected float." << endl;
            cout << "Enter the first float" << endl;
            cin >> float1;
            cout << "Enter the second float" << endl;
            cin >> float2;
            cout << "Basic math:" << endl;
            cout << "Sum:" << float1 + float2 << endl;
            cout << "Difference:" << float1 - float2 << endl;
            cout << "Product:" << float1 * float2 << endl;
            cout << "Dividend:" << float1 / float2 << endl;
            cout << "Power:" << pow(float1, float2) << endl;
        }
        break; // won't let me do default case after this idk why
    }
    cout << "Would you like to use the calculator again? (yes, no)" << endl;
    cin >> contquest;;
    if(contquest == "yes") {
        contans = true;
    } else if(contquest == "no") {
        contans = false;
        cout << "You said that you did not want to continue using the calculator. Thank you! Exiting now." << endl;
    } else{
        contans = false;
        cout << "Unrecognized response, so exiting now. Thank you!" << endl;
    }        
} while (contans == true);
return 0;
}   
