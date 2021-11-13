#include <iostream>

unsigned long fact(unsigned long n) {
    if (n<=1) {
        return 1;
    } else {
        return n*fact(n-1);
    }
}
int main () {
    unsigned long limit;
    std::cin >> limit;
    std::cout << fact(limit);
    return 0;
}