#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
0-12 spades
13-25 hearts
26-38 clubs
39-51 diamonds
0 ace
10 jack
11 queen
12 king
*/
class Deck {
    public:
    Deck() {
        vector<int> cards;
        for(int i = 0; i < 52 ; i++) {
            cards[i] = i;
        }
    }
    string draw() {
        string card;
        int index = rand() % cards.size();
        int suit = index / 4;
        int number = index%13;
        cards.erase(cards.begin()+index);
        switch(suit) {
            case 0:
                card = "S";
                break;
            case 1:
                card = "H";
                break;
            case 2:
                card = "C";
                break;
            case 3:
                card = "D";
                break;
        }
        switch(number) {
            case 10:
                card = "J" + card;
                break;
            case 11:
                card = "K" + card;
                break;
            case 12:
                card = "Q" + card;
                break;
            default:
                card = to_string(number) + card;
                break;
        }

        return card;
    }

};
int main () {
    Deck test;
    cout << test.draw();
}