#include <iostream>
#include <vector>

using namespace std;

int findMaxIndex(vector<vector<int>> &matrix, int col, int top, int bottom) {
    if (top == bottom) return top;

    int midRow = (top + bottom) / 2; 

    int current = matrix[midRow][col];
    int above = (midRow > 0) ? matrix[midRow - 1][col] : -1;
    int below = (midRow < matrix.size() - 1) ? matrix[midRow + 1][col] : -1;

    if (current >= above && current >= below) {
        return midRow;
    }

    if (midRow > 0 && above > current) {
        return findMaxIndex(matrix, col, top, midRow - 1);
    }
    return findMaxIndex(matrix, col, midRow + 1, bottom);
}

int find2DPeak(vector<vector<int>> &matrix, int leftCol, int rightCol) {
    if (leftCol > rightCol) return -1;

    int midCol = (leftCol + rightCol) / 2;
    int maxRow = findMaxIndex(matrix, midCol, 0, matrix.size() - 1);

    int current = matrix[maxRow][midCol];
    int left = (midCol > 0) ? matrix[maxRow][midCol - 1] : -1;
    int right = (midCol < matrix[0].size() - 1) ? matrix[maxRow][midCol + 1] : -1;

    if (current >= left && current >= right) {
        return current;
    }

    if (left > current) {
        return find2DPeak(matrix, leftCol, midCol - 1);
    }

    return find2DPeak(matrix, midCol + 1, rightCol);
}

int find2DPeak(vector<vector<int>> &matrix) {
    return find2DPeak(matrix, 0, matrix[0].size() - 1);
}

int main() {
    vector<vector<int>> matrix = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 40, 32}
    };

    cout << "2D Peak: " << find2DPeak(matrix) << endl;
    return 0;
}
