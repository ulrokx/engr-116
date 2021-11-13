#include <iostream>

int squarepath(int m, int n)
{
    if(m == 1 || n == 1)
    {
        return 1;
    } 
    else{
        return squarepath(m-1, n) + squarepath(m, n-1);
    }
}

int main()
{
    std::cout << squarepath(2,2);
}