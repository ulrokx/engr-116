#include <iostream>
#include <cstring>
class prime {
    public:
    void sieve(int n) {
    bool primes[n+1];
    memset(primes, true, sizeof(primes));

    for (int p = 2; p*p <=n; p++) {
        if (primes[p] == true) {
            for (int i = p*p; i<=n; i+=p) {
                primes[i] = false;
            }
        }
    }
    for (int i = 2; i<=n; i++) {
        if (primes[i] == true) {
            std::cout << i << " ";
        }
    }
    }
    bool checkIf(int n) {
        for(int i=2; i * i <= n; i++) {
            if(n%i==0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int max;
    std::cin >> max;
    prime primes;
    primes.sieve(max);
    std::cout << std::endl << primes.checkIf(max) << std::endl;

}