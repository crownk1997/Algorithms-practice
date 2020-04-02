#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printMatrixInCycle(const vector<vector<T>> matrix, int start);

template <typename T>
void printMatrixClockWise(const vector<vector<T>> matrix) {
    if (matrix.empty())
        return;
    
    int start = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();

    while (cols > start*2 && rows > start*2) {
        printMatrixInCycle(matrix, start);

        start++;
    }
}

template <typename T>
void printMatrixInCycle(const vector<vector<T>> matrix, int start) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int endX = cols - 1 - start;
    int endY = rows - 1 - start;

    for (int i = start; i <= endX; i++) {
        cout << matrix[start][i] << " ";
    }

    if (start < endY) {
        for (int i = start + 1; i <= endY; i++) {
            cout << matrix[i][endX] << " ";
        }

        if (start < endX && start < endY) {
            for (int i = endX - 1; i >- start; i--) {
                cout << matrix[endY][i] << " ";
            }
        }
        
        if (start < endX && start < endY - 1) {
            for (int i = endY - 1; i >= start + 1; i--) {
                cout << matrix[i][start] << " ";
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1,2,3,4,5},
                                  {6,7,8,9,10},
                                  {11,12,13,14,15}};
    
    printMatrixClockWise(matrix);

    cout << endl;

    return 0;
}