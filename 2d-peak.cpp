#include <iostream>
#include <vector>

using namespace std;

int findMaxIndex(vector<vector<int>> &matrix, int col) {
    int maxIndex = 0;
    for (int i = 1; i < matrix.size(); i++) {
        if (matrix[i][col] > matrix[maxIndex][col]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int find2DPeak(vector<vector<int>> &matrix, int leftCol, int rightCol) {
    if (leftCol > rightCol) return -1;

    int midCol = (leftCol + rightCol) / 2;
    int maxRow = findMaxIndex(matrix, midCol);

    int current = matrix[maxRow][midCol];
    int left = (midCol > 0) ? matrix[maxRow][midCol - 1] : -1;
    int right = (midCol < matrix[0].size() - 1) ? matrix[maxRow][midCol + 1] : -1;

    if (current >= left && current >= right) {
        return current;
    }

    if (left > current) {
        return find2DPeak(matrix, leftCol, midCol - 1);
    } else {
        return find2DPeak(matrix, midCol + 1, rightCol); 
    }
}

int find2DPeak(vector<vector<int>> &matrix) {
    return find2DPeak(matrix, 0, matrix[0].size() - 1);
}

int main() {
    vector<vector<int>> matrix = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    cout << "2D Peak: " << find2DPeak(matrix) << endl;
    return 0;
}
