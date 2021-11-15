#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main () {
    string cipher;
    transform(cipher.begin(), cipher.end(), cipher.begin(), tolower);
    string lower = cipher;
    transform(cipher.begin(), cipher.end(), cipher.begin(), toupper);
    string upper = cipher;
}