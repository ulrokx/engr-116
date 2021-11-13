#include<iostream>
using namespace std;
    template<typename First, typename ... T>
    bool is_in(First &&first, T && ... t)
{
    return ((first == t) || ...);
}

int main()
{
    int finalScore;

    cout << "What is your final score" << endl;
    cin >> finalScore;
    if(finalScore >90) {
        cout << "Congrats! You get an A \n";
    }

    cout << "Goodbye";


}