#include <iostream>
#include <cstdlib>
#include <string>
int main () {
    bool running = true;
    std::string resp;

    int n, t;
    std::cout << "enter range" << std::endl;
    std::cin >> n;
    std::cout << "enter tries" << std::endl;
    std::cin >> t;
    int values[n];
    while(running) {
    for (int i = 0; i < n; i++) {
        values[i] = 0;
    }
    for (int j = 0; j < t; j++) {
        values[std::rand() % n] += 1;
    }
    for (int k = 0; k < n; k++) {
        std::printf("%d: %-12d\n", k, values[k]);
    }
    std::cout << "again? (y/n" << std::endl;
    std::cin >> resp;
    running = (resp == "y") ? true : false;
    }
}