#include <iostream>
#include <cmath>

using namespace std;

int beginNumber(int digits); 
int countOfIntegers(int digits) {
    if (digits == 1)
        return 10;
    
    int count = (int) std::pow(10, digits-1);
    return 9 * count;
}

int digitAtIndex(int index, int digits) {
    int number = beginNumber(digits) + index / digits;
    int indexFromRight = digits - index % digits;
    for (int i = 1; i < indexFromRight; i++)
        number /= 10;
    
    return number % 10;
}

int beginNumber(int digits) {
    if (digits == 1)
        return 0;
    
    return (int)std::pow(10, digits-1);
}

int digitAtIndex(int index) {
    if (index < 0)
        return -1;
    
    int digits = 1;
    while (true) {
        int numbers = countOfIntegers(digits);
        if (index < numbers * digits)
            return digitAtIndex(index, digits);
        
        index -= digits * numbers;
        digits++;
    }

    return -1;
}

int main() {
    cout << digitAtIndex(1001) << endl;

    return 0;
}