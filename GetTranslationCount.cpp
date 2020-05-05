#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GetTranslationCount(const string& number);
int GetTranslationCount(int number) {
    if (number < 0)
        return 0;
    
    string numberInString = to_string(number);
    return GetTranslationCount(numberInString);
}

int GetTranslationCount(const string& number) {
    int length = number.length();
    vector<int> counts(length);
    int count = 0;

    for (int i = length - 1; i >= 0; --i) {
        count = 0;
        if (i < length - 1)
            count = counts[i+1];
        else 
            count = 1;
        
        if (i < length - 1) {
            int digit1 = number[i] - '0';
            int digit2 = number[i+1] - '0';
            int converted = digit1 * 10 + digit2;
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

int main() {
    int number = 12258;
    cout << GetTranslationCount(number) << endl;
    return 0;
}