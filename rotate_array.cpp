
// binary search for rotate array
// unique element v.s. repeated elements

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class findMin {
private:
    int MinInOrder(const std::vector<T>& inputs, int index1, int index2) {
        int result = inputs[index1];
        for(int i = index1 + 1; i <= index2; i++) {
            if (result > inputs[i])
                result = inputs[i];
        }

        return result;
    }

public:
    T solution(const std::vector<T>& inputs) {
        int length = inputs.size();
        if (length == 0)
            throw std::runtime_error("Invalid input");
        
        int index1 = 0;
        int index2 = length - 1;
        int indexMid = index1;

        while (index1 < index2) {
            if (index2 - index1 == 1) {
                indexMid = index2;
                break;
            }
            indexMid = (index2 - index1) / 2 + index1;

            if (inputs[indexMid] == inputs[index1] && inputs[indexMid] == inputs[index2])
                return MinInOrder(inputs, index1, index2);

            if (inputs[indexMid] > inputs[index1])
                index1 = indexMid;
            else
                index2 = indexMid;
        }

        return inputs[indexMid];
    }
};


int main() {
    std::vector<int> inputs1 = {4, 5, 6, 7, 8, 0};
    std::vector<int> inputs2 = {1, 2, 3, 4, 5, 0, 0, 0};
    findMin<int> solve;
    std::cout << solve.solution(inputs1) << std::endl;
    std::cout << solve.solution(inputs2) << std::endl;
    return 0;

}