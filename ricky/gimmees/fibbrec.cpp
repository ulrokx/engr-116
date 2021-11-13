#include <iostream>


unsigned long fib(int i) {
    if(i == 0) {
        return 0;
    } else if (i == 1) {
        return 1;
    } else {
        const int temp = fib(i-1) + fib(i-2);
        std::cout << temp << std::endl;
        return fib(i-1) + fib(i-2);
    }
}
int main () {
    int n;
    std::cout << "Enter the index" << std::endl;
    std::cin >> n;
    std::cout << fib(n) << std::endl;
    
}