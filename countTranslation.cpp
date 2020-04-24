#include <iostream>
#include <vector>
#include <string>

using namespace std;

int CountTranslation(const string& numStr) {
    int length = numStr.length();
    vector<int> counts(length);
    int count = 0;

    for (int i = length - 1; i >= 0; i--) {
        count = 0;
        if (i < length - 1)
            count = counts[i+1];
        else
            count = 1;
        
        if (i < length - 1) {
            int number1 = numStr[i] - '0';
            int number2 = numStr[i+1] - '0';
            int converted = number1 * 10 + number2;
            if (converted >= 10 && converted <= 25) {
                if (i < length - 2)
                    count += counts[i+2];
                else
                    count += 1;
            } 
        }
        counts[i] = count;
    }

    return counts[0];
}

int CountTranslation(int number) {
    if (number < 0)
        return 0;
    
    string numStr = to_string(number);
    return CountTranslation(numStr);
}

int main() {
    int number = 1234215;
    cout << CountTranslation(number) << endl;

    return 0;
}