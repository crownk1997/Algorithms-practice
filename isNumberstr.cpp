#include <iostream>
#include <string>

bool scanInteger(const std::string& str, int& index);
bool isUnsignedNum(const std::string& str, int& index);
bool isNumber(const std::string& str) {
    if (str.empty())
        return false;
    
    int index = 0;
    bool isNum = scanInteger(str, index);

    if (str[index] == '.') {
        index++;
        isNum = isUnsignedNum(str, index) || isNum;
    }

    if (str[index] == 'e' || str[index] == 'E') {
        index++;
        isNum = isNum && scanInteger(str, index);
    }

    return isNum && (index == str.size());
}

bool isUnsignedNum(const std::string& str, int& index) {
    int old_index = index;
    int length = str.size();
    while (index < length && str[index] >= '0' && str[index] <= '9')
        index++;
    
    return index > old_index;
}

bool scanInteger(const std::string& str, int& index) {
    if (str[index] == '+' || str[index] == '-')
        index++;
    return isUnsignedNum(str, index);
}

int main() {
    std::string number1 = "1234.5678";
    std::string number2 = "1E10";

    std::cout << "number1 is " << isNumber(number1) << std::endl;
    std::cout << "number2 is " << isNumber(number2) << std::endl;

    return 0;
}
