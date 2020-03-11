
// Replace the white space with special symbol
// Demo input "we are happy"
// Demo output "we%20are%20happy"


#include <iostream>
#include <string>
#include <vector>
#include <optional>

class whiteRep {
private:
    std::string sym = "%20";
public:
    void solution(std::string& input) {
        int length = input.size();
        if (length == 0)
            return ;

        // compute the number of white space 
        int count = 0;
        for (auto i : input) {
            if (i == ' ')
                count++;
        }

        input.resize(length + count*2);
        int indexOfOriginal = length;
        int indexOfNew = length + count*2;
        while (indexOfOriginal >= 0 && indexOfOriginal < indexOfNew) {
            if (input[indexOfOriginal] == ' ') {
                input[indexOfNew--] = '0';
                input[indexOfNew--] = '2';
                input[indexOfNew--] = '%';
            } else {
                input[indexOfNew--] = input[indexOfOriginal];
            }

            --indexOfOriginal;
        }

    }
};

int main(int agrc, char** argv) {
    std::string input1 = "we are happy";
    std::string input2 = "";
    std::string input3 = "   ";

    whiteRep solve;

    solve.solution(input1);
    solve.solution(input2);
    solve.solution(input3);

    std::cout << input1 << "\n";
    std::cout << input2 << "\n";
    std::cout << input3 << std::endl;

    return 0;
}