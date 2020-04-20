#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool CheckMoreThanHalf(const vector<int>& array, int result) {
    int length = array.size();
    int times = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] == result)
            times++;
    }

    bool isMoreThanHalf = true;
    if (times * 2 <= length) {
        isMoreThanHalf = false;
    }

    return isMoreThanHalf;
}

int partition(vector<int>& array, int start, int end) {
    int pivot = (end - start) >> 1 + start;
    swap(array[pivot], array[end]);

    int small = start - 1;
    for (int i = start; i < end; i++) {
        if (array[i] < array[end]) {
            small++;
            if (small != i)
                swap(array[i], array[small]);
        }
    }

    small++;
    swap(array[small], array[end]);

    return small;
}

int MoreThanHalfNum(vector<int>& array) {
    if (array.empty())
        return 0;

    int length = array.size();
    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = partition(array, start, end);
    while (index != middle) {
        if (index > middle) {
            end = index - 1;
            index = partition(array, start, end);
        } else {
            start = index + 1;
            index = partition(array, start, end);
        }
    }

    int result = array[middle];
    if (!CheckMoreThanHalf(array, result))
        result = 0;
    
    return result;
}

int main() {
    vector<int> array = {1, 2, 3, 2, 2, 2, 2, 9, 8, 2};
    cout << "The numer more than half is " << MoreThanHalfNum(array) << endl;

    return 0;
}