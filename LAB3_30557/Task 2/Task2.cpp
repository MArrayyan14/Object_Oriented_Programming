#include <iostream>
using namespace std;

class Node {
public:
    string link;
    Node* nextPage;
    
    Node(string link) : link(link), nextPage(nullptr) {}
};

class BrowserHistory {
private:
    Node* firstPage;
    Node* lastPage;
    Node* currentPage;

public:
    BrowserHistory() : firstPage(nullptr), lastPage(nullptr), currentPage(nullptr) {}

    void visitPage(string link) {
        Node* newPage = new Node(link);
        if (firstPage == nullptr) {
            firstPage = lastPage = currentPage = newPage;
        } else {
            lastPage->nextPage = newPage;
            lastPage = newPage;
            currentPage = newPage;
        }
    }

    void goBack() {
        if (currentPage == nullptr || currentPage == firstPage) {
            return;
        }
        Node* temp = firstPage;
        while (temp->nextPage != currentPage) {
            temp = temp->nextPage;
        }
        currentPage = temp;
        cout << "Current page after going back: " << currentPage->link << endl;
    }

    void displayHistory() {
        Node* temp = firstPage;
        while (temp != nullptr) {
            if (temp == currentPage)
                cout << "[CURRENT] ";
            cout << temp->link << endl;
            temp = temp->nextPage;
        }
    }

    ~BrowserHistory() {
        Node* temp = firstPage;
        while (temp != nullptr) {
            Node* next = temp->nextPage;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    BrowserHistory history;
    history.visitPage("https://google.com");
    history.visitPage("https://example.com");
    history.visitPage("https://webpage.com");

    cout << "Browsing History:" << endl;
    history.displayHistory();

    history.goBack();
    cout << endl;
    
    cout << "Browsing History after going back:" << endl;
    history.displayHistory();
    
    return 0;
}
