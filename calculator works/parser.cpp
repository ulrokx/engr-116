#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class calculateParse {
    public:
    string afterSign, beforeSign;
    float operationOutput;
    string simpAnswerStr, outManip;
    size_t parseToIndex(string expression, string operatorType) {
        return expression.find_first_of(operatorType);
    }
    void getBandA(string expression, size_t operatorIndex) {
        afterSign = "";
        beforeSign = "";
        size_t searchIndex = 1;
        while (isdigit(expression[operatorIndex+searchIndex]) == true || expression[operatorIndex+searchIndex] == '.' || expression[operatorIndex+searchIndex] == '-') {
            if(expression[operatorIndex+searchIndex] == '-' && isdigit(expression[operatorIndex+(searchIndex+1)]) == false){
                    continue;
                }
            if(expression[operatorIndex+searchIndex] == '-' && isdigit(expression[operatorIndex+(searchIndex+1)]) == true) {
                break;
            }
            afterSign += expression[operatorIndex+searchIndex];
            searchIndex++;
        }
        searchIndex = 1;
        while (isdigit(expression[operatorIndex-searchIndex]) == true || expression[operatorIndex-searchIndex] == '.' || expression[operatorIndex-searchIndex] == '-' ) { 
            if(expression[operatorIndex-searchIndex] == '-' && isdigit(expression[operatorIndex-(searchIndex+1)]) == false){
                continue;
            }
            if(expression[operatorIndex-searchIndex] == '-' && isdigit(expression[operatorIndex-(searchIndex+1)]) == true) {
                break;
            }
            beforeSign = expression[operatorIndex-searchIndex] + beforeSign;
            searchIndex++;
        }
        cout << beforeSign << " " << afterSign << endl;
    }
    string doOperator(string operatorType) {
        cout << "operator index" << 
        if(operatorType == "+") {
            operationOutput = stof(afterSign)+stof(beforeSign);
        } else if(operatorType == "-") {
            operationOutput = stof(beforeSign)-stof(afterSign);
        } else if(operatorType == "*") {
            operationOutput = stof(beforeSign)*stof(afterSign);
        } else if(operatorType == "/") {
            operationOutput = stof(beforeSign)/stof(afterSign);
        }
        outManip = to_string(operationOutput);
        while (outManip[outManip.length()-1] == '0' && outManip.find('.') != string::npos){
            outManip.erase(outManip.length()-1);
            if(outManip[outManip.length()-1] == '.') {
                outManip.erase(outManip.length()-1);
                break;
            }
        }
        cout << "output manip" << outManip << endl;
        return outManip;
        
    }
    string replaceAnswer(string expression, size_t operatorIndex, string simpAnswer) {
        cout << "expresseion before" << expression << endl;
        cout << "operator index before, beforeSign, afterSign, simpAnswer" << operatorIndex << " " << beforeSign << " "<< afterSign << " "<< simpAnswer << endl;
        return expression.replace(operatorIndex-beforeSign.length(), beforeSign.length()+afterSign.length()+1, simpAnswer);
    }
}; 
int main() {
    string expression, response;
    bool goAgain;
    string operators[4] = {"/", "*", "+", "-"};
    int o = 0;
    cout << "this is richard kirk's calculator - supports the four operators, negatives, and decimals" << endl;
    do {
    cout << "enter your expression to be evaluated below" << endl;
    cin >> expression;
    calculateParse calc;
    while (o < 3){
        while(expression.find_first_of(operators[o] + operators[o+1]) != string::npos){
            calc.getBandA(expression, calc.parseToIndex(expression, operators[o] + operators[o+1]));
            expression = calc.replaceAnswer(expression, calc.parseToIndex(expression, operators[o]), calc.doOperator(operators[o]));
            cout << "output " << expression << endl;
        } o = o+2;
    }
        cout << "output  going to subtract" << expression << endl;
        while(expression.find(operators[o]) != string::npos){
            if(calc.parseToIndex(expression, operators[o]) == 0 && expression.find(operators[o], 1) == string::npos) {
                break;
            } else {
                calc.getBandA(expression, calc.parseToIndex(expression, operators[o]));
                expression = calc.replaceAnswer(expression, calc.parseToIndex(expression, operators[o]), calc.doOperator(operators[o]));
            cout << "output subtract " << expression << endl;
            }
        }
    
    cout << expression << endl;
    cout << "use again? (y/n)" << endl;
    cin >> response;
    if(response == "y") {
        goAgain = true;
        expression = "";
        o = 0;

    } else {
        goAgain = false;
    }
    } while(goAgain == true);
}
