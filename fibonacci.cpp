#include <vector>
#include <iostream>

long long Fibonacci(unsigned n) {
    int result[2] = {0, 1};

    if (n < 2)
        return result[n];
    
    long long fibonacci_one = 1;
    long long fibonacci_two = 0;
    long long fibN = 0;
    for (unsigned int i = 2; i <= n; i++) {
        fibN = fibonacci_one + fibonacci_two;

        fibonacci_two = fibonacci_one;
        fibonacci_one = fibN; 
    }

    return fibN;
}

int main() {
    unsigned int n = 30;
    std::cout << "Fibonacci 30th element is " << Fibonacci(n) << std::endl;

    return 0;
}