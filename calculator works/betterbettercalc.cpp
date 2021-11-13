#include<iostream>
#include<string>

using namespace std;

class calculatorMain{
    public:
    const string ops[4] = {"*","/","+","-"};
    size_t o = 0;
    size_t lastNeg = 0;
    size_t opIndexTemp;
    size_t searchIter;
    string beforeSign, afterSign, outManip;
    size_t opIndex;
    size_t opIndexP;
    size_t nextClose, lastOpen;
    int lastOpenSize;
    float operationOutput;
    bool isNeg = 0;
    void iniVars() {
        o=0;
        lastNeg = 0;
        opIndexTemp = 0;
        searchIter = 0;
        beforeSign = "";
        afterSign = "";
        outManip = "";
        operationOutput = 0;
        isNeg = 0;
    }
    string getParenthesis (string expression){

        nextClose = 0;
        lastOpen = 0;
        if(expression.find("(") != string::npos){ // finds the last "(" before the first ")", while the position of the last "(" found is 
        //less than the first ")" and the next "(" is after the first ")". if the next "(" isn't after the first ")" then this "(" position
        // is the last one and continue
            //cout << "found a (" << endl;
            //cout << expression.find("(", lastOpen + 1) << " " << expression.find(")") << endl;
            while(expression.find("(", lastOpen + 1) < expression.find(")") && expression.find("(", expression.find("(") + 1) > expression.find(")")){
                lastOpen = expression.find("(", lastOpen + 1);
                //cout << lastOpen << endl;
            }
            nextClose = expression.find(")");
            lastOpenSize = lastOpen;
            //cout << "last open " << lastOpen << " next Close " << nextClose << endl;
            return expression.substr(lastOpen + 1, nextClose - lastOpen - 1);
        } else {
            return "NO";
        }
    }
    void getBandA(string expression, size_t operatorIndex) {
        afterSign = "";
        beforeSign = "";
        searchIter = 1;
        //cout << "in getBand A " << endl;
        while (isdigit(expression[operatorIndex+searchIter]) == true || expression[operatorIndex+searchIter] == '.' || expression[operatorIndex+searchIter] == '-') {
            //cout << "searchIter " << searchIter << endl;
            if(expression[operatorIndex+searchIter] == '-' && isdigit(expression[operatorIndex+(searchIter-1)]) == true) {
                break; //if there is a - and the thing before it is not a symbol, its a subtract
            }
            afterSign += expression[operatorIndex+searchIter]; // if not then continue as usual
            searchIter++;
        }
        //cout << "after sign " << afterSign << endl;
        searchIter = 1;
        while (isdigit(expression[operatorIndex-searchIter]) == true || expression[operatorIndex-searchIter] == '.' || expression[operatorIndex-searchIter] == '-' ) { 
            if(expression[operatorIndex-searchIter] == '-' && isdigit(expression[operatorIndex-(searchIter+1)]) == true) {
                break; 
            }
            beforeSign = expression[operatorIndex-searchIter] + beforeSign;
            searchIter++;
        }
        //cout << beforeSign << " " << afterSign << endl;
    }
    string doOperator(char operatorType) {
        if(operatorType == '+') {
            operationOutput = stof(afterSign)+stof(beforeSign);
        } else if(operatorType == '-') {
            operationOutput = stof(beforeSign)-stof(afterSign);
        } else if(operatorType == '*') {
            operationOutput = stof(beforeSign)*stof(afterSign);
        } else if(operatorType == '/') {
            operationOutput = stof(beforeSign)/stof(afterSign);
        }
        outManip = to_string(operationOutput);
        while (outManip[outManip.length()-1] == '0' && outManip.find('.') != string::npos){
            outManip.erase(outManip.length()-1);
            if(outManip[outManip.length()-1] == '.') {
                outManip.erase(outManip.length()-1);
                break; //tldr floats suck booty
            }
        }
        //cout << "outmanip " << outManip << endl;
        return outManip;
        
    }
    string replaceWith(string toReplace, string expression, size_t opIndex){ 
        return expression.replace(opIndex - beforeSign.length(), beforeSign.length()+afterSign.length()+1, toReplace);
    }
    size_t getOpIndex(string expression) {
        do {
            //cout << "o = " << o << endl;
            //cout << "expression = " << expression << endl;
            opIndexTemp = expression.find_first_of(ops[o]+ops[o+1], lastNeg);
            //cout << "preopindextemp " << opIndexTemp << endl;
        if (opIndexTemp == string::npos && o==0) {
            o = 2;
            //cout << "setting o to 2" << endl;
            isNeg = true;
            continue; 
        }  else if(opIndexTemp == string::npos && o==2) {
            return -1;
        } else if(expression[opIndexTemp] == '-' && isdigit(expression[opIndexTemp-1]) == false) {
            isNeg = true;
            lastNeg = opIndexTemp+1;
            continue; // first not negative sign
        }
        isNeg = false;
        lastNeg = 0;
        } while(isNeg == true);
        return opIndexTemp;
    }
    string doTheMath(string expression) {
        opIndex = getOpIndex(expression);
        //cout << "opindex " << opIndex << endl;
        getBandA(expression, opIndex);
        return replaceWith(doOperator(expression[opIndex]), expression, opIndex);
    }
    string replaceParenthesis(string expressionP, string expression) {
        //cout << "expressionP " << expressionP << " expression " << expression << endl;
        //cout << "gets here  last Open is " << lastOpen << " next close is " <<nextClose << endl;
        expression.replace(lastOpen, (nextClose-lastOpen+1), expressionP);
        if (isdigit(expression[lastOpen-1]) == true) {
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
    cout << "this is richard ricky kirk's mdas calculator!\n"
        "it can do the four operators, negative numbers, decimals, and returns everything in decimals\n"
        "also has support for parenthesis and will assume multiplication if no operator before initial parenthesis\n"
        "try negatives to start the expression, decimals to start the expression, and pemdas goes mult/div l-r,\n"
        "add/sub l-r. //just need to add exponents now"    << endl;
    while (goAgain == true){
    cout << "enter expression" << endl;
    cin >> expression;
    if(expression.find_first_not_of("1234567890+-/*.()") !=string::npos) return -1;
    while(calc.getParenthesis(expression) != "NO") {
        expressionP = calc.getParenthesis(expression);
        //cout << "after ini " <<calc.lastOpen << endl;
        while(calc.getOpIndex(expressionP) != -1) {
            expressionP = calc.doTheMath(expressionP);
            //cout << "expression P " << expressionP << endl;
        }
        //cout << calc.lastOpen << endl;
        //cout << "before replace " << expressionP << " " << expression << endl;
        expression = calc.replaceParenthesis(expressionP, expression);
    }
    calc.o = 0;
    //cout << "expression post P " << expression << endl;
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