#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* nextNode;
    Node* prevNode;

    Node(int val) : value(val), nextNode(nullptr), prevNode(nullptr) {}
};

class linkedList {
private:
    Node* first;
    Node* last;

public:
    linkedList() : first(nullptr), last(nullptr) {}

    void traverseForward() {
        Node* temp = first;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->nextNode;
        }
        cout << endl;
    }

    void traverseBackward() {
        if (last == nullptr) {
            cout << "The list is empty" << endl;
            return;
        }

        Node* temp = last;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->prevNode;
        }
        cout << endl;
    }

    int fetchValue(int position) {
        if (position < 0) {
            cout << "Position cannot be negative." << endl;
            return 0;
        }

        Node* temp = first;
        int index = 0;

        while (temp != nullptr) {
            if (index == position) {
                return temp->value;
            }
            temp = temp->nextNode;
            index++;
        }

        cout << "Position out of bounds." << endl;
        return 0;
    }

    void removeHead() {
        if (first == nullptr) {
            cout << "The list is empty, nothing to remove!" << endl;
            return;
        }

        Node* temp = first;

        if (first == last) {
            first = last = nullptr;
        } else {
            first = first->nextNode;
            first->prevNode = nullptr;
        }

        delete temp;
        cout << "First element removed." << endl;
    }

    void insert(int num) {
        Node* newNode = new Node(num);

        if (last == nullptr) {
            first = last = newNode;
        } else {
            last->nextNode = newNode;
            newNode->prevNode = last;
            last = newNode;
        }
    }
};

int main() {
    linkedList output;
    output.insert(5);
    output.insert(46);
    output.insert(76);
    output.insert(21);
    output.insert(3);

    cout << "Forward traversal: ";
    output.traverseForward();
    cout << "Backward traversal: ";
    output.traverseBackward();

    cout << "Value at position 4: ";
    cout<<output.fetchValue(4)<<endl;

    output.removeHead();
    cout << "Updated list: ";
    output.traverseForward();
    
    output.insert(45);
    cout << "Updated list: ";
    output.traverseForward();

    return 0;
}