#include <vector>
#include <iostream>

void print(const std::vector<int>& array) {
    for (auto i : array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void swap(T& var1, T& var2) {
    T temp = var1;
    var1 = var2;
    var2 = temp;
}

void sortOddEven(std::vector<int>& array) {
    int index_for = 0;
    int index_back = array.size()-1;

    while (index_for < index_back) {
        while (array[index_for] % 2 == 0)
            index_for++;
        
        while (array[index_back] % 2 != 0)
            index_back--;
        
        if (index_for < index_back)
            swap(array[index_for], array[index_back]);
    }
}

int main() {
    std::vector<int> array = {1, 2, 4, 5, 6, 7, 9, 0, 3, 5, 4, 6, 3};
    print(array);
    sortOddEven(array);
    print(array);
    return 0;
}