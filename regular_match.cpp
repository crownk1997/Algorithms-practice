#include <iostream>
#include <string>


bool matchCore(const std::string& str, const std::string& pattern, int index_s, int index_p);
bool match(const std::string& str, const std::string& pattern) {
    if (str.empty() && pattern.empty())
        return true;
    
    if (str.empty() || pattern.empty())
        return false;
    
    return matchCore(str, pattern, 0, 0);
}

bool matchCore(const std::string& str, const std::string& pattern, int index_s, int index_p) {

    if (index_s == str.length() && index_p == pattern.length())
        return true;
    
    if (index_s != str.length() && index_p == pattern.length())
        return false;

    if (pattern[index_p+1] == '*') {
        if (pattern[index_p] == str[index_s] || pattern[index_p] == '.') {
            return matchCore(str, pattern, index_s+1, index_p+2) ||
                    matchCore(str, pattern, index_s+1, index_p) ||
                    matchCore(str, pattern, index_s, index_p+2);
        } else {
            return matchCore(str, pattern, index_s, index_p+2);
        }
    }

    if (str[index_s] == pattern[index_p] || pattern[index_p] == '.')
        return matchCore(str, pattern, index_s+1, index_p+1);
}

int main() {
    std::string str = "abcaba";
    std::string pattern = "abca*";
    bool result = match(str, pattern);
    std::cout << result << std::endl;

    return 0;
}