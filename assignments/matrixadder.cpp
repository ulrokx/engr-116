#include <iostream>

int main () {
    int A[3][3], B[3][3], C[3][3];

    std::cout << "a matrix:" << std::endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << "element at row: " << i + 1 << ", col: " << j + 1 << std::endl;
            std::cin >> A[i][j];
        }
    }
    std::cout << "Starting B matrix" << std::endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << "element at row: " << i + 1 << ", col: " << j + 1 << std::endl;
            std::cin >> B[i][j];
        }
    }
    std::cout << "added matrix" << std::endl;
    for(int i = 0; i < 3; i++) {
        std::cout << " | ";
        for(int j = 0; j < 3; j++) {
            std::cout << A[i][j] + B[i][j] << " ";
        }
        std::cout << "| " << std::endl;
    }
    std::cout << "subtracted matrix" << std::endl;
    for(int i = 0; i < 3; i++) {
        std::cout << " | ";
        for(int j = 0; j < 3; j++) {
            std::cout << A[i][j] - B[i][j] << " ";
        }
        std::cout << "| " << std::endl;
    }

}