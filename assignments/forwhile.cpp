#include<iostream>
#include<climits>

using namespace std;
int thisInt, minInt, maxInt, sum, i;
void setMinMax(int i, int thisInt) {
    if(i == 0) {
        maxInt = thisInt;
        minInt = thisInt;
    } else if(thisInt > maxInt) {
        maxInt = thisInt;
    } else if(thisInt < minInt) {
        minInt = thisInt;
    } 
        sum += thisInt;
}
int main() {
    for(int i = 0; i < 10; i++) {
        cout << "input integer " << i+1 << endl;
        cin >> thisInt;
        setMinMax(i, thisInt);
    }
    printf("The sum is %d, the minimum is %d, and the maximum is %d\n", sum, minInt, maxInt);
    i=0;
    sum=0;
    while(true){
        cout << "input integer (-1 to stop) " << i+1 << endl;
        cin >> thisInt;
        if(thisInt == -1) {
            break;
        }
        setMinMax(i, thisInt);
        i++;
    }
    printf("The sum is %d, the minimum is %d, and the maximum is %d", sum, minInt, maxInt);
}