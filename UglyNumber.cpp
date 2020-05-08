#include <iostream>
#include <vector>

int GetUglyNumber_Solution2(int index) {
    if (index <= 0)
        return 0;
    
    int vector<int> pUglyNumbers(index);
    pUglyNumbers[0] = 1;
    int nextUglyIndex = 1;
    int multiply2Index = 0;
    int multiply3Index = 0;
    int multiply5Index = 0;

    while (nextUglyIndex < index) {
        int min = min({pUglyNumbers[multiply2Index]*2,
                       pUglyNumbers[multiply3Index]*3,
                       pUglyNumbers[multiply5Index]*5});
        pUglyNumbers[nextUglyIndex] = min;

        while (pUglyNumbers[multiply2Index]*2 <= pUglyNumbers[nextUglyIndex])
            ++multiply2Index;
        while (pUglyNumbers[multiply3Index]*3 <= pUglyNumbers[nextUglyIndex])
            ++multiply3Index; 
        while (pUglyNumbers[multiply5Index]*5 <= pUglyNumbers[nextUglyIndex])
            ++multiply5Index;
    }

    return pUglyNumbers[nextUglyIndex - 1];
}

int main() {
    return 0;
}