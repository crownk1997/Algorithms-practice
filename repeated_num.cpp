// Find the repeated numbers in the array
// Demo input [3, 2, 3, 5, 6, 8, 7, 7]
// Demo output 3 or 7


#include <vector>
#include <iostream>
#include <optional>

class FindRepeatNum {
public:
    std::optional<int> solution(std::vector<int>& input) {
        int length = input.size();
        if (length == 0) {
            return {};
        }

        // check the invalid input
        for (int i = 0; i < length; i++) {
            if (input[i] < 0 || input[i] > length - 1) {
                return {};
            }
        }

        for (int i = 0; i < length; i++) {
            while (input[i] != i) {
                if (input[input[i]] == input[i]) {
                    return input[i];
                }

                int temp = input[i];
                input[i] = input[temp];
                input[temp] = temp;
            }
        }

        return {};
    }
};

int main(int argc, char** argv) {
    std::vector<int> input1 = {2, 3, 1, 6, 2, 5, 3};
    std::vector<int> input2 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> input3 = {};

    FindRepeatNum solve;

    std::cout << "Answer for input1 is " << solve.solution(input1).value_or(-1) << std::endl;
    std::cout << "Answer for input2 is " << solve.solution(input2).value_or(-1) << std::endl;
    std::cout << "Answer for input3 is " << solve.solution(input3).value_or(-1) << std::endl;

    return 0;
}