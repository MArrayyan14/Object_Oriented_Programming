#include <iostream>
#include <vector>
using namespace std;

int countHeightMismatches(vector<int>& studentHeights) {
    vector<int> frequency(101, 0);
    for (int height : studentHeights) frequency[height]++;
    
    vector<int> sortedHeights;
    for (int i = 1; i <= 100; ++i) {
        while (frequency[i]--) sortedHeights.push_back(i);
    }
    
    int mismatchCount = 0;
    for (int i = 0; i < studentHeights.size(); ++i) {
        if (studentHeights[i] != sortedHeights[i]) mismatchCount++;
    }
    return mismatchCount;
}

int main() {
    vector<int> studentHeights = {1, 1, 4, 2, 1, 3};
    
    cout << "Input: heights = ";
    for (int height : studentHeights) {
        cout << height << " ";
    }
    cout << endl;

    int result = countHeightMismatches(studentHeights);
    cout << "Output: " << result << endl;

    return 0;
}
