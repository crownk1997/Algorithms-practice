#include <iostream>
#include <string>

bool increment(std::string& number) {
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = number.size();
    for (int i = nLength - 1; i >= 0; i--) {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1)
            nSum++;
        
        if (nSum >= 10) {
            if (i == 0)
                isOverflow = true;
            else {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        } else {
            number[i] = '0' + nSum;
            break;
        }
    }

    return isOverflow;
}

void printNumber(const std::string& number) {
    bool isBeginning0 = true;
    int nLength = number.size();

    for (int i = 0; i < nLength; i++) {
        if (isBeginning0 && number[i] != '0')
            isBeginning0 = false;
        
        if (!isBeginning0) {
            std::cout << number[i] << "\n";
        }
    }
}

void printToMaxOfDigits(int n) {
    if (n <= 0)
        return;
    
    std::string number(n, '0');

    while (!increment(number)) {
        printNumber(number);
    }
}

void printToMaxDigitsRecursive(std::string& number, int index) {
    if (index == number.size() - 1) {
        printNumber(number);
        return;
    }

    for (int i = 0; i < 10; i++) {
        number[index + 1] = i + '0';
        printToMaxDigitsRecursive(number, index + 1);
    }
}

void printToMaxOfDigitsRecur(int n) {
    if (n <= 0)
        return;
    
    std::string number(n, '0');

    for (int i = 0; i < 10; i++) {
        number[0] = '0' + i;
        printToMaxDigitsRecursive(number, 0);
    }
}

int main() {
    int n = 1;

    printToMaxOfDigits(n);
    std::cout << std::endl;

    printToMaxOfDigitsRecur(n);
    std::cout << std::endl;

    return 0;
}