#include <iostream>

using namespace std;

int main () {
    int array[10], sum, min, max;
    
    for(int i = 0; i< 10; i++) {
        cout << "Enter number " << i + 1 << endl;
        cin >> array[i];
    }
    min = array[0];
    max = array[0];
    for(int i = 0; i < 10; i++){
        sum += array[i];
        min = array[i] < min ? min = array[i] : min;
        max = array[i] > max ? max = array[i] : max;
    }
    printf("Sum is %d, minimum is %d, maximum is %d", sum, min, max);
}