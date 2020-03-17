#include <iostream>
#include <vector>

using namespace std;

int movingCountCore(int threshold, int rows, int cols, int row, int col, vector<bool>& visited);
bool check(int threshold, int rows, int cols, int row, int col, const vector<bool>& visited);
int getDigitSum(int number);

int movingCount(int threshold, int rows, int cols) {
    if (threshold < 0 || rows <= 0 || cols <= 0)
        return 0;
    
    vector<bool> visited(rows*cols, 0);

    int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

    return count;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, vector<bool>& visited) {
    int count = 0;
    if (check(threshold, rows, cols, row, col, visited)) {
        visited[row*cols+col] = true;

        count = 1 + movingCountCore(threshold, rows, cols, row + 1, col, visited) +
                movingCountCore(threshold, rows, cols, row, col + 1, visited) +
                movingCountCore(threshold, rows, cols, row - 1, col, visited) +
                movingCountCore(threshold, rows, cols, row, col - 1, visited);
    }

    return count;
}

bool check(int threshold, int rows, int cols, int row, int col, const vector<bool>& visited) {
    if (row >= 0 && row < rows && col >= 0 && col < cols && getDigitSum(row) + getDigitSum(col) <= threshold &&
    !visited[row*cols+col]) {
        return true;
    }

    return false;
}

int getDigitSum(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

int main() {
    int threshold = 18;
    int rows = 20;
    int cols = 20;
    int count = movingCount(threshold, rows, cols);
    std::cout << "Found " << count << std::endl;

    return 0;
}