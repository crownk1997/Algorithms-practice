#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool hasPathCore(const vector<vector<char>>& matrix, int row, int col, 
                const string& str, int& pathLength, vector<bool>& visited);
bool hasPath(const vector<vector<char>>& matrix, const string& str) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (rows < 1 || cols < 1 || str.empty())
        return false;
    
    vector<bool> visited(rows*cols, 0);

    int pathLength = 0;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (hasPathCore(matrix, row, col, str, pathLength, visited))
                return true;
        }
    }

    return false;
}

bool hasPathCore(const vector<vector<char>>& matrix, int row, int col, 
                const string& str, int& pathLength, vector<bool>& visited) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if(str[pathLength] == '\0')
        return true;

    bool hasPath = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row][col] == str[pathLength] && !visited[row * cols + col]) {
        pathLength++;

        visited[row * cols + col] = true;

        hasPath = hasPathCore(matrix, row, col - 1, str, pathLength, visited) 
                || hasPathCore(matrix, row - 1, col, str, pathLength, visited)
                || hasPathCore(matrix, row, col + 1, str, pathLength, visited)
                || hasPathCore(matrix, row + 1, col, str, pathLength, visited);
        
        if (!hasPath) {
            pathLength--;
            visited[row * cols + col] = false;
        }
    }

    return hasPath;
}


int main() {
    vector<vector<char>> matrix;
    vector<char> row1 = {'a', 'b', 't', 'g'};
    vector<char> row2 = {'c', 'f', 'c', 's'};
    vector<char> row3 = {'j', 'd', 'e', 'h'};

    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);

    string str = "bfce";

    bool found = hasPath(matrix, str);
    if (found)
        cout << "Found !" << endl;
    
    return 0;
}