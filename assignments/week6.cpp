#include <iostream>
#include <time.h>
#include <string>
#define coolio std
void printGreeting() 
{
    srand(time(NULL));
    coolio::string greeting;
    int rand = coolio::rand()%5 + 1;
    switch(rand) {
        case 1:
        greeting = "Hope you're having a great day!";
        break;
        case 2:
        greeting = "Hi! How are you doing?";
        break;
        case 3: 
        greeting = "Glad to see you! Did you do your ENGR-116 homework yet?";
        break;
        case 4:
        greeting = "What's up? How's it going?";
        break;
        case 5:
        greeting = "Hey dude what's up?";
        break;
    }
    coolio::cout << greeting << coolio::endl;
}

void divideNumbers(float x, float y)
{
    if(y == 0)
    {
        coolio::cout << "Cannot perform division" << coolio::endl;
        return;
    }
    double theAnswer = x / y;
    coolio::cout << "The answer to " << x << "/" << y << " is " <<  theAnswer << coolio::endl;
}

int factorial(int num) {
    if(num < 0) 
    {
        return 0;
    }
    else if (num == 0)
    {
        return 1;
    }
    else 
    {
        int current, acc;
        for(current = num-1, acc = num; current; current--)
        {
            acc *= current; //practicing the dark arts
        }
        return acc;
    }
}

void fibonacci(int N) //capital N
{
    int curr = 1;
    int prev = 0;
    for(int i = 0; i < N; i++) {
        if(i == 0)
        {
            coolio::cout << prev;
        }
        else if(i == 1)
        {
            coolio::cout << ", " << curr;
        }
        else
        {
            prev = (curr += prev) - prev; 
            coolio::cout << ", " << curr;
        }
    }
}

void hanoirec(int n, char fromTower, char toTower, char otherTower)
{   
    //coolio::cout << n << coolio::endl;
    if(n == 1) // if the disk is the smallest one then move it to the destination tower
    {
        coolio::cout << "Move disk " << n << " from " << fromTower << " to " << toTower << coolio::endl;
        return;
    }
    hanoirec(n-1, fromTower, otherTower, toTower); // then you take the other disk and move it to the other tower, until you have your bottom disk
    coolio::cout << "Move disk "<< n << " from rod " << fromTower << " to rod " << toTower << coolio::endl;
    hanoirec(n-1, otherTower, toTower, fromTower); //take the bottom disk and move it to the final tower and then continue the pattern with the smallest disk but starting on the other tower
}

int main() {
    int fact = 6;
    printGreeting();
    divideNumbers(355,113);
    coolio::cout << "The factorial of " << fact << " is " << factorial(fact) << coolio::endl;
    fibonacci(10);
    coolio::cout << coolio::endl;
    hanoirec(3, 'A', 'C','B');
}