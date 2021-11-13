#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class calculatorMain{
    public:
    const string ops[6] = {"^","","*","/","-","+"}; // change this to change the order of ops, does them in groups of 2
    size_t o = 0;
    size_t lastNeg = 0;
    size_t opIndexTemp, searchIter, opIndex, opIndexP, nextClose;
    string beforeSign, afterSign, outManip;
    int lastOpen;
    float base, exponent, operationOutput;
    bool searchAgain = 0;
    void iniVars() {
        o=0; // resets the operator index to 0 each time program is done again
        lastNeg = 0;
        opIndexTemp = 0;
        searchIter = 0;
        beforeSign = "";
        afterSign = "";
        outManip = "";
        operationOutput = 0;
        searchAgain = 0;
    }
    string getParenthesis (string expression){
        lastOpen = -1;
        if(expression.find("(") != string::npos){
            while(expression.find("(",lastOpen + 1) < expression.find(")") && expression.find("(", lastOpen + 1) != string::npos) {
                lastOpen = expression.find("(", lastOpen+1);
            }
            nextClose = expression.find(")");
            return expression.substr(lastOpen + 1, nextClose - lastOpen - 1);
        } else {
            return "NO";
        }
    }
    void getBandA(string expression, size_t operatorIndex) {
        afterSign = "";
        beforeSign = "";
        searchIter = 1;
        while (isdigit(expression[operatorIndex+searchIter]) == true || expression[operatorIndex+searchIter] == '.' || expression[operatorIndex+searchIter] == '-') {
            if(expression[operatorIndex+searchIter] == '-' && isdigit(expression[operatorIndex+(searchIter-1)]) == true) {
                break; //if there is a - and the thing before it is not a symbol, its a subtract
            }
            afterSign += expression[operatorIndex+searchIter]; // if not then continue as usual
            searchIter++;
        }
        searchIter = 1; // must be a digit or a decimal or a subtract to have the opportunity to be added to beforeSign, afterSign
        while (isdigit(expression[operatorIndex-searchIter]) == true || expression[operatorIndex-searchIter] == '.' || expression[operatorIndex-searchIter] == '-' ) { 
            if(expression[operatorIndex-searchIter] == '-' && isdigit(expression[operatorIndex-(searchIter+1)]) == true) {
                break; //similar, if there is a - and the thing before it is not a symbol, its a subtract
            }
            beforeSign = expression[operatorIndex-searchIter] + beforeSign;
            searchIter++;
        }
    }
    string doOperator(char operatorType) { // converts string before and after sign to float to do math
        if(operatorType == '+') {
            operationOutput = stof(afterSign)+stof(beforeSign);
        } else if(operatorType == '-') {
            operationOutput = stof(beforeSign)-stof(afterSign);
        } else if(operatorType == '*') {
            operationOutput = stof(beforeSign)*stof(afterSign);
        } else if(operatorType == '/') {
            operationOutput = stof(beforeSign)/stof(afterSign);
        } else if(operatorType == '^') {
            operationOutput = pow(stof(beforeSign), stof(afterSign));
        }
        outManip = to_string(operationOutput);
        while (outManip[outManip.length()-1] == '0' && outManip.find('.') != string::npos){
            outManip.erase(outManip.length()-1);
            if(outManip[outManip.length()-1] == '.') {
                outManip.erase(outManip.length()-1);
                break; //tldr floats suck booty, just goes and removes trailing zeros and the decimal point if it gets there then breaks
            }
        }
        return outManip;
    }
    string replaceWith(string toReplace, string expression, size_t opIndex){ //think about removing this or combining with parenthesis one
        return expression.replace(opIndex - beforeSign.length(), beforeSign.length()+afterSign.length()+1, toReplace);
    } 
    size_t getOpIndex(string expression) {
        o = 0;
        do { // going to test if the next operator we're looking for (either ^, * or /, - or +) is not a negative
            opIndexTemp = expression.find_first_of(ops[o]+ops[o+1], lastNeg);
        if (opIndexTemp == string::npos && o==0) { //if it cant find a ^ goes to * and /
            o=2;
            searchAgain = true;
            continue;
        } else if (opIndexTemp == string::npos && o==2) { //no / * goes to - +
            o = 4;
            searchAgain = true;
            continue; 
        }  else if(opIndexTemp == string::npos && o==4) { // no + or - all ops done return -1
            return -1;
        } else if(expression[opIndexTemp] == '-' && isdigit(expression[opIndexTemp-1]) == false) { // if the operator is infront of a digit then its a negative so 
            searchAgain = true;
            lastNeg = opIndexTemp + 1;
            continue; // first - thats not a negative, saves index
        } 
        searchAgain = false; // if its not a negative then it is an operator !
        lastNeg = 0;
        } while(searchAgain == true);
        return opIndexTemp;
    }
    string doTheMath(string expression) { 
        opIndex = getOpIndex(expression);
        getBandA(expression, opIndex);
        return replaceWith(doOperator(expression[opIndex]), expression, opIndex);
    }
    string replaceParenthesis(string expressionP, string expression) {
        expression.replace(lastOpen, (nextClose-lastOpen+1), expressionP);
        if (isdigit(expression[lastOpen-1]) == true || expression[lastOpen-1] == ')') {
            expression = expression.insert(lastOpen,1 , '*');
        }
        return expression;
}
    };
int main () {
    calculatorMain calc;
    string expression, expressionP;
    char response;
    bool goAgain = true;
    cout << "this is richard ricky kirk's pemdas calculator!\n"
        "it can do the four operators, negative numbers, decimals, and returns everything in decimals\n"
        "also has support for parenthesis and will assume multiplication if no operator before initial parenthesis\n"
        "try negatives to start the expression, decimals to start the expression, and pemdas goes mult/div l-r,\n"
        "add/sub l-r. //just need to add exponents now"    << endl;
    while (goAgain == true){
    cout << "enter expression" << endl;
    cin >> expression;
    if(expression.find_first_not_of("1234567890+-/*.()^") !=string::npos) return -1;
    while(calc.getParenthesis(expression) != "NO") {
        expressionP = calc.getParenthesis(expression);
        while(calc.getOpIndex(expressionP) != -1) {
            expressionP = calc.doTheMath(expressionP);
        }
        expression = calc.replaceParenthesis(expressionP, expression);
    }
    while(calc.getOpIndex(expression) != -1) {
        expression = calc.doTheMath(expression);
    }
    cout << expression << endl;
    cout << "use again? y/n";
    cin >> response;
    if(response == 'y') {
        calc.iniVars();
        expression = "";
        goAgain = true;
    } else {
        goAgain = false;
    }
    }
    return 0;
}