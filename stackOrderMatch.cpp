#include <stack>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
bool ifStackOrder(const vector<T>& order1, const vector<T>& order2) {
    if (order1.empty() || order2.empty() || order1.size() != order2.size())
        return false;

    bool ifPossible = false;
    int length1 = order1.size();
    int length2 = order2.size();
    int index1 = 0;
    int index2 = 0;

    stack<T> stackData;
    while (index2 < length2) {
        while (stackData.empty() || stackData.top() != order2[index2]) {
            if (index1 == length1)
                break;

            stackData.push(order1[index1]);
            index1++;
        }

        if (stackData.top() != order2[index2])
            break;
        
        stackData.pop();
        index2++;
    }

    if (stackData.empty() && index2 == length2)
        ifPossible = true;
    return ifPossible;
}

int main() {
    vector<int> order1 = {1,2,3,4,5};
    vector<int> order2 = {4,5,3,2,1};
    cout << ifStackOrder<int>(order1, order2) << endl;

    return 0;
}