#include <iostream>
#include <vector>

using namespace std;

int GetMaxValue(const vector<vector<int>>& grid) {
    if (grid.empty())
        return 0;
    
    int rows = grid.size();
    int cols = grid[0].size();
    // create memory efficient dynamic programming algorithm
    vector<vector<int>> result(2, vector<int>(cols + 1));


    for (int row = 0; row < rows; ++row) {
        for (int col = 1; col < cols + 1; ++col) {
            result[1][col] = max(result[1][col-1], result[0][col]) + grid[row][col-1];
        }

        result[0] = result[1];
    }

    return result[1][cols];
}

int main() {
    vector<vector<int>> grid = {{1, 10, 3, 8},
                                {12, 2, 9, 6},
                                {5, 7, 4, 11},
                                {3, 7, 16, 5}};
    cout << "Max value is " << GetMaxValue(grid) << endl;
    return 0;
}