#include <iostream>

int countBinaryOne(int number) {
    int count = 0;

    while (number) {
        if (number & 1)
            count++;
        number = number >> 1;
    }

    return count;
}

int main() {
    int number = 9;

    std::cout << "Number of one is " << countBinaryOne(number) << std::endl;

    return 0;
}