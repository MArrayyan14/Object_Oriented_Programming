#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template <typename T>
class Sorter {
public:
    void insertionSort(vector<T>& items, function<bool(const T&, const T&)> compare) {
        for (size_t i = 1; i < items.size(); i++) {
            T currentItem = items[i];
            int previousIndex = i - 1;

            while (previousIndex >= 0 && compare(items[previousIndex], currentItem)) {
                items[previousIndex + 1] = items[previousIndex];
                previousIndex--;
            }
            items[previousIndex + 1] = currentItem;
        }
    }
};

struct Student {
    string fullName;
    double gradePointAvg;

    Student(string name, double gpa) : fullName(name), gradePointAvg(gpa) {}

    void show() const {
        cout << fullName << " (GPA: " << gradePointAvg << ")" << endl;
    }
};

bool sortByName(const Student& a, const Student& b) {
    return a.fullName > b.fullName;  
}

bool sortByGPA(const Student& a, const Student& b) {
    return a.gradePointAvg < b.gradePointAvg;  
}

int main() {
    vector<Student> classList = {
        {"Alice Johnson", 3.5},
        {"Bob Smith", 3.8},
        {"Charlie Brown", 3.2},
        {"David Wilson", 3.9},
        {"Eve Davis", 2.5},
        {"Frank Miller", 3.0},
        {"Grace Lee", 3.7},
        {"Hannah Kim", 2.8},
        {"Isaac Newton", 3.1},
        {"Jack Daniels", 2.4},
        {"Kathy Bates", 3.6},
        {"Liam Neeson", 2.1},
        {"Mia Farrow", 3.4},
        {"Noah Centineo", 2.6},
        {"Olivia Wilde", 3.3},
        {"Paul Rudd", 2.7},
        {"Quinn Fabray", 3.0},
        {"Rachel Green", 3.5},
        {"Sam Winchester", 2.9},
        {"Tina Fey", 3.8},
        {"Uma Thurman", 2.0},
        {"Zaid Tariq", 3.9},
        {"Ali Habib", 2.2},
        {"Alice Wonder", 1.3},
        {"Alice Wonderland", 2.79}
    };

    Sorter<Student> sorter;

    cout << "Sorting by Name:\n";
    sorter.insertionSort(classList, sortByName);
    for (const auto& student : classList) student.show();

    cout << "\nSorting by GPA:\n";
    sorter.insertionSort(classList, sortByGPA);
    for (const auto& student : classList) student.show();

    return 0;
}
