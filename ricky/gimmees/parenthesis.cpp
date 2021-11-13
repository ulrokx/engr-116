#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> lisp;
        lisp.empty();
        for(char i:s) {
			cout << i << endl; 
            if(i == ')') {
                if(lisp.top() == '(') {
                    lisp.pop();
					continue;
                }
                else {
                    return false;
                }
            }
            if(i == ']') {
                if(lisp.top() == '[') {
                    lisp.pop();
					continue;
                }
                else {
                    return false;
                }
            }
            if(i == '}') {
                if(lisp.top() == '{') {
                    lisp.pop();
					continue;
                }
                else {
                    return false;
                }
            }
            lisp.push(i);
			cout << lisp.top() << endl;
        }
        return true;
        
    }
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.isValid("([])");
}