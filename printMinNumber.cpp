#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compare(const string& strNumber1, const string& strNumber2) {
    string strNew1 = strNumber1 + strNumber2;
    string strNew2 = strNumber2 + strNumber1;

    return strNew1 < strNew2;
}

void PrintMinNumber(const vector<int>& numbers) {
    if (numbers.empty())
        return;
    
    int length = numbers.size();
    // convert int array to string array
    vector<string> strNumbers;
    for (auto i : numbers) {
        strNumbers.push_back(to_string(i));
    }

    sort(strNumbers.begin(), strNumbers.end(), compare);
    string result = "";
    for (auto i : strNumbers)
        result += i;
    
    cout << "Final result is " << result << endl;
}

int main() {
    vector<int> numbers = {3, 321, 32, 45};
    PrintMinNumber(numbers);

    return 0;
}