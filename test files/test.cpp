#include <iostream>
#include <string>
using namespace std;

size_t lastOpen, nextClose;

string getParenthesis (string expression){
 //5^(4-(3+5))
        nextClose = 0;
        lastOpen = 0;
        if(expression.find("(") != string::npos){ // finds the last "(" before the first ")", while the position of the last "(" found is 
        //less than the first ")" and the next "(" is after the first ")". if the next "(" isn't after the first ")" then this "(" position
        // is the last one and continue
            //cout << "found a (" << endl;
            cout << expression.find("(", lastOpen + 1) << " " << expression.find(")") << endl;
            cout << expression.find("(", expression.find("(") + 1) << " " <<  expression.find(")") << endl;
            while(expression.find("(", lastOpen + 1) < expression.find(")") && expression.find("(", expression.find("(") + 1) < expression.find(")") || expression.find("(", expression.find("(") + 1) == string::npos){
                lastOpen = expression.find("(", lastOpen + 1);
                //cout << lastOpen << endl;  
            }
            nextClose = expression.find(")");
            cout << "last open " << lastOpen << " next Close " << nextClose << endl;
            return expression.substr(lastOpen + 1, nextClose - lastOpen - 1);
        } else {
            return "NO";
        }
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
int main() {
    cout << getParenthesis("5^(4-(3+5))");

}