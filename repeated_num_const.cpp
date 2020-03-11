// Find the repeated number without modifying the array
// Demo input [3, 2, 3, 5, 6, 8, 7, 7]
// Demo output 3 or 7

#include <iostream>
#include <optional>
#include <vector>

class FindRepeatNum {
private:
    int countRange(const std::vector<int>& input, int start, int end) {
        int length = input.size();
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (input[i] >= start && input[i] <= end)
                count++;
        }

        return count;
    }

public: 
    std::optional<int> solution(const std::vector<int>& input) {
        int length = input.size();
        if (length == 0)
            return {};
        
        // check the invalid input
        for (int i = 0; i < length; i++) {
            if (input[i] < 0 || input[i] > length - 1) {
                return {};
            }
        }
        
        int start = 1;
        int end = length - 1;
        
        while (end >= start) {
            int middle = ((end - start) >> 1) + start;

            int count = countRange(input, start, middle);

            if (end == start) {
                if (count > 1)
                    return start;
                else 
                    return {};
            }

            if (count > (end - middle + 1)) {
                end = middle;
            } else {
                start = middle + 1;
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