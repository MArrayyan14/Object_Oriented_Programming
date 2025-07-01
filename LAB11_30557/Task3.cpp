#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class RadixStringSorter {
public:
    void sortAscending(vector<string>& words);
    void sortDescending(vector<string>& words);
    void sortByPosition(vector<string>& words, int index);
private:
    void countingSort(vector<string>& items, int index, bool isAscending);
};

void RadixStringSorter::countingSort(vector<string>& items, int index, bool isAscending) {
    vector<vector<string>> buckets(256);
    for (const auto& word : items) {
        char character = index < word.size() ? word[index] : 0;
        buckets[(int)character].push_back(word);
    }
    items.clear();
    if (isAscending) {
        for (int i = 0; i < 256; ++i) {
            for (auto& word : buckets[i]) items.push_back(word);
        }
    } else {
        for (int i = 255; i >= 0; --i) {
            for (auto& word : buckets[i]) items.push_back(word);
        }
    }
}

void RadixStringSorter::sortAscending(vector<string>& words) {
    size_t maxLength = 0;
    for (const auto& word : words) maxLength = max(maxLength, word.size());
    for (int index = maxLength - 1; index >= 0; --index) {
        countingSort(words, index, true);
    }
}

void RadixStringSorter::sortDescending(vector<string>& words) {
    size_t maxLength = 0;
    for (const auto& word : words) maxLength = max(maxLength, word.size());
    for (int index = maxLength - 1; index >= 0; --index) {
        countingSort(words, index, false);
    }
}

void RadixStringSorter::sortByPosition(vector<string>& words, int index) {
    countingSort(words, index, true);
}

int main() {
    vector<string> fruits = {"banana", "Apple", "apple", "Banana", "grape", "apricot"};

    RadixStringSorter sorter;

    vector<string> sortedAsc = fruits;
    sorter.sortAscending(sortedAsc);
    cout << "Ascending:\n";
    for (const auto& word : sortedAsc) cout << word << endl;

    vector<string> sortedDesc = fruits;
    sorter.sortDescending(sortedDesc);
    cout << "\nDescending:\n";
    for (const auto& word : sortedDesc) cout << word << endl;

    vector<string> sortedByChar = fruits;
    sorter.sortByPosition(sortedByChar, 1);
    cout << "\nSorted by 2nd character:\n";
    for (const auto& word : sortedByChar) cout << word << endl;

    return 0;
}
