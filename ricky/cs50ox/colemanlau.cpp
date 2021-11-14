#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int main () {
    string input;
    getline(std::cin, input);
    cout << input << endl;
    int letters = 0, sentences = 0, words = 1;
string abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string symbols = ".!?";

    double lpw, spw;
    for (char c : input) {
        if(abc.find(c) != string::npos) {
            letters++;
        }
        else if(symbols.find(c) != string::npos) {
            sentences++;
        }
        else if(c == ' ') {
            words++;
        }
    }
    cout << "letters:" << letters << " sentences:" << sentences << " words: " << words << endl;
    double conversion = (float)100/words;
    cout << "conversion:" << conversion << endl;
    lpw = letters * conversion;
    cout << "lpw: " << lpw << endl;
    spw = sentences*conversion;
    cout << "spw: " << spw << endl;
    double metric = (.0588*lpw) - (.296*spw) - (15.8);
    if (metric >=16) {
        cout << "16+";
    }
    else {
        cout << round(metric);
    }
    return 0;

}