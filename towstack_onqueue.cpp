#include <stack>
#include <vector>
#include <iostream>
#include <stdexcept>

template <typename T> class CQueue {
private:
    std::stack<T> stack_input;
    std::stack<T> stack_output;
    int numElements;

public:
    CQueue() {
        numElements = 0;
    }

    void appendTail(const T& node);
    T deleteHead();
    int getNumElement() const {return numElements;}
};

template <typename T> 
void CQueue<T>::appendTail(const T& node) {
    stack_input.push(node);
    numElements++;
}

template <typename T>
T CQueue<T>::deleteHead() {
    if (!stack_output.empty()) {
        T top = stack_output.top();
        stack_output.pop();
        return top;
    } else if (stack_input.size() != 0){
        while (stack_input.size() > 0) {
            T& data = stack_input.top();
            stack_input.pop();
            stack_output.push(data);
        }
    } else {
        throw new std::runtime_error("queue is empty");
    }

    T top = stack_output.top();
    stack_output.pop();
    numElements--;
    return top;
}

int main(int argc, char** argv) {
    std::vector<int> inputs = {1,2,3,4,5};
    CQueue<int> queue;
    for (auto &i : inputs) {
        queue.appendTail(i);
    }

    int totalElements = queue.getNumElement();
    while (totalElements != 0) {
        int head = queue.deleteHead();
        std::cout << head << " ";
        totalElements--;
    }
    std::cout << std::endl;

    return 0;
}