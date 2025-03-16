#include <iostream>
#include <vector>

using namespace std;

int findMin(int startIndex, int stopIndex, const vector<int> &vectorInput) {
    if (startIndex == stopIndex) {
        return vectorInput[startIndex];
    }

    int middle = (startIndex + stopIndex) / 2;

    int leftMin = findMin(startIndex, middle, vectorInput);
    int rightMin = findMin(middle + 1, stopIndex, vectorInput);

    return min(leftMin, rightMin);
}

int main() {
    vector<int> vec = {1, 4, 2, 3, 5, 7, 9, 10, 2};
    int minVal = findMin(0, vec.size() - 1, vec);
    cout << "Minimum value: " << minVal << endl;
    return 0;
}
