#include <iostream> 


int gcd(int a, int b) {
    int c;

    while (b) {
       c = a % b;
       a = b;
       b = c;        
    }

    std::cout << a << std::endl;

    return a;
}
