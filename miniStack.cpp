#include <iostream>
#include <stack>
#include <limits>

using namespace std;

template <typename T>
class MiniStack {
private:
    stack<T> main_stack;
    stack<T> aux_stack;

    T minvalue = numeric_limits<T>::max();

public:
    void addElem(T elem) {
        main_stack.push(elem);
        if (elem < minvalue) {
            minvalue = elem;
        }
        aux_stack.push(elem);
    }

    T popElem() {
        try {
            T temp = main_stack.pop();
            aux_stack.pop();
            return temp;
        } 
        catch (...) {
            cout << "Exception occured when pop stack element" << endl;
        }
    }

    T getMin() {
        try {
            T temp = aux_stack.top();
            return temp;
        }
        catch (...) {
            cout << "Exception occured when you are trying to get minimum value" << endl;
        }
    }
};

int main() {
    MiniStack<int> test_stack;
    test_stack.addElem(10);
    test_stack.addElem(5);
    test_stack.addElem(170);
    test_stack.addElem(1);
    cout << test_stack.getMin() << endl;
    return 0;
}