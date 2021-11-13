#include <iostream>

void fizzbuzz()
{
    for(int i = 0; i < 101; i++)
    {
        if((i%3) && (i%5))
        {
            std::cout << i << std::endl;
        }
        else if((i%3) && !(i%5))
        {
            std::cout <<"Buzz" << std::endl;
        }
        else if(!(i%3) && (i%5))
        {
            std::cout <<"Fizz" << std::endl;
        }
        else{
            std::cout << "FizzBuzz" << std::endl;
        }
    }
}

int main()
{
    fizzbuzz();
    return 0;
}