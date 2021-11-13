#include<iostream>
#include<string>
#include<vector>
//maybe more input check tests, a better way to do input check tests then while? or that is the only way.
using namespace std;
class inputChecking {
    public:
    bool ifEqualWhole(float hw, float midterm, float final){ //sees if the floats add up to 100
        if(hw + midterm + final != 1){
            cout << "Weights don't add up to 100%, enter weights again" << endl;
            return false;
        }
        return true;
    }
    float convertToDec(string input){ //sees if they entered a percentage, decimal, or just a number and converts it to a float
        if(input.find("%") != string::npos) { 
            input = input.erase(input.find("%"));
            return (stof(input))/100;
        }
        else if(input.find(".") == string::npos){
            return (stof(input))/100;
        }
        else {
            return (stof(input));
        }
    }
};
class interfaceMain {
    public: 
    int count[3];
    string weightString[3];
    vector<float> gradeHw;
    vector<float> gradeMidterm;
    vector<float> gradeFinal;
    float calcGrade = 0;
    void menu() {
        cout << "This is Richard Kirk's ENGR-116 grade calculator" << endl;
        cout << "Below you will enter the amount of homeworks, midterms, " << endl;
        cout << "and final grades you wish to be calculated with." << endl;
        cout << "You will then enter the weighting for each of the catagories." << endl;
    }
    void gatherCounts() {
        cout << "Enter the number of homework assignments to be included in the calculation:" << endl;
        cin >> count[0];
        cout << "Enter the number of midterm grades to be included in the calculation:" << endl;
        cin >> count[1];
        cout << "Enter the number of final grades to be inluded in the calculation:" << endl;
        cin >> count[2];
    }
    void gatherWeights() {
        cout << "Enter the weight of homework assignments for the course:" << endl;
        cin >> weightString[0];
        cout << "Enter the weight of midterm grades for the course:" << endl;
        cin >> weightString[1];
        cout << "Enter the weight of final grades for the course:" << endl;
        cin >> weightString[2];
    }
    void gatherGrade(int typeIndex, int index) { //wish i only had to use one switch functions, maybe make a pointer that changes which vector it points too
        static string type;
        static float userInput;
        switch(typeIndex){
        case 0:
        type = "homework ";
        break;
        case 1:
        type = "midterm ";
        break;
        case 2:
        type = "final ";
        break;
        } 
        cout << "Enter " << type << "grade " << index+1 << ":" << endl;
        cin >> userInput;
        switch(typeIndex){
        case 0:
        gradeHw.push_back(userInput);
        break;
        case 1:
        gradeMidterm.push_back(userInput);
        break;
        case 2:
        gradeFinal.push_back(userInput);
        break;
        }
        }
    float calculateGrade(float weight[]) { //same with this, a way to point to the correct vector per assignment type help
        for(int i = 0; i < gradeHw.size(); i++){
            calcGrade = calcGrade + weight[0]/gradeHw.size()*gradeHw[i];
        }
        for(int i = 0; i < gradeMidterm.size(); i++){
            calcGrade = calcGrade + weight[1]/gradeMidterm.size()*gradeMidterm[i];
        }
        for(int i = 0; i < gradeFinal.size(); i++){
            calcGrade = calcGrade + weight[2]/gradeFinal.size()*gradeFinal[i];
        }
    return calcGrade;
    }
    void printGrade(float grade) {
        if(grade >= 90){
            cout << "Congratulations! Your grade is " << grade << ". You got an A for this course." << endl;
        } else if(grade >= 80){
            cout << "Great job! Your grade is " << grade << ". You got a B for this course." << endl;
        } else if(grade >=70){
            cout << "Good work. Your grade is " << grade << ". You got a C for this course." << endl;
        } else{
            cout << "Uh oh. Your grade is " << grade << ". You got a D for this course." << endl;
        }
    }
    
    };

int main(){
    interfaceMain calc;
    inputChecking inputs;
    float toAdd;
    float weight[3];
    calc.menu();
    calc.gatherCounts(); // and maybe a way to put all of these inside my classes?
    do{ //do gather the weights, if the weights converted to a decimal does not add up to 1 then ask for weights again
        calc.gatherWeights();
    } while (inputs.ifEqualWhole(inputs.convertToDec(calc.weightString[0]),inputs.convertToDec(calc.weightString[1]),inputs.convertToDec(calc.weightString[2])) == false);
    for(int i = 0; i != 3; i++) { //convery the three strings to decimal if they add up to 100
        weight[i] = inputs.convertToDec(calc.weightString[i]);
    }
    for(int type = 0; type < 3; type++){
        for(int i = 0; i < calc.count[type]; i++){
            calc.gatherGrade(type, i);
            }
    }
    calc.printGrade(calc.calculateGrade(weight));
    return 0;
}
