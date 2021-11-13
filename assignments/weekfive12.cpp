#include <iostream>

using namespace std;

int main () {
    int array[10], sum, min, max, A[3][3], B[3][3], C[3][3];
    cout << "program 1" << endl;
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
    printf("Sum is %d, minimum is %d, maximum is %d\n", sum, min, max);
    cout << "program 2" << endl;

    std::cout << "Starting A matrix" << std::endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << "Another element at row: " << i + 1 << ", col: " << j + 1 << std::endl;
            std::cin >> A[i][j];
        }
    }
    std::cout << "Starting B matrix" << std::endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << "Another element at row: " << i + 1 << ", col: " << j + 1 << std::endl;
            std::cin >> B[i][j];
        }
    }

    for(int i = 0; i < 3; i++) {
        std::cout << " | ";
        for(int j = 0; j < 3; j++) {
            std::cout << A[i][j] - B[i][j] << " ";
        }
        std::cout << "| " << std::endl;
    }
}
