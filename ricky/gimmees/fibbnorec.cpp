#include <iostream>

int main () {
    unsigned long long t, a, b, m;
    a = 0;
    b = 1;
    std::cin >> t;
    std::cout << a << std::endl;
    for(int i = 1; i<t; i++) {
        m = a + b;
        a = b;
        b = m;
        std::cout << a << std::endl;
    }
}