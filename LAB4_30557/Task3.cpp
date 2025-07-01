#include <iostream>
using namespace std;

class TextEditor {
private:
    int* undoBuffer;
    int* redoBuffer;
    int undoCapacity;
    int redoCapacity;
    int undoCount;
    int redoCount;

    void expandUndoBuffer() {
        int newCapacity = undoCapacity * 2;
        int* newUndoBuffer = new int[newCapacity];
        for (int i = 0; i < undoCount; ++i) {
            newUndoBuffer[i] = undoBuffer[i];
        }
        undoCapacity = newCapacity;
        delete[] undoBuffer;
        undoBuffer = newUndoBuffer;
    }

    void expandRedoBuffer() {
        int newCapacity = redoCapacity * 2;
        int* newRedoBuffer = new int[newCapacity];
        for (int i = 0; i < redoCount; ++i) {
            newRedoBuffer[i] = redoBuffer[i];
        }
        redoCapacity = newCapacity;
        delete[] redoBuffer;
        redoBuffer = newRedoBuffer;
    }

public:
    TextEditor(int initialCapacity = 2) {
        undoCapacity = initialCapacity;
        redoCapacity = initialCapacity;
        undoBuffer = new int[undoCapacity];
        redoBuffer = new int[redoCapacity];
        undoCount = 0;
        redoCount = 0;
    }

    ~TextEditor() {
        delete[] undoBuffer;
        delete[] redoBuffer;
    }

    void insertText(int text) {
        if (undoCount == undoCapacity) expandUndoBuffer();
        undoBuffer[undoCount++] = text;
    }

    void deleteText() {
        if (undoCount == 0) {
            cout << "Nothing to delete." << endl;
            return;
        }

        int removedValue = undoBuffer[--undoCount]; 
        cout << "Deleted value from the undo buffer: " << removedValue << endl;
    }

    void undo() {
        if (undoCount > 0) {
            int action = undoBuffer[--undoCount];
            if (redoCount == redoCapacity) expandRedoBuffer();
            redoBuffer[redoCount++] = action;
        }
    }

    void redo() {
        if (redoCount > 0) {
            int action = redoBuffer[--redoCount];
            if (undoCount == undoCapacity) expandUndoBuffer();
            undoBuffer[undoCount++] = action;
        }
    }

    void display() {
        cout << "Undo Buffer: ";
        for (int i = 0; i < undoCount; ++i) {
            cout << undoBuffer[i] << " ";
        }
        cout << endl;

        cout << "Redo Buffer: ";
        for (int i = 0; i < redoCount; ++i) {
            cout << redoBuffer[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    TextEditor editor;
    editor.insertText(1);
    editor.insertText(2);
    editor.insertText(3);
    editor.display();

    cout << "Popping from the undo buffer and pushing into redo buffer:" << endl;
    editor.undo();
    editor.display();

    cout << "Popping from the redo buffer and pushing into undo buffer" << endl;
    editor.redo();
    editor.display();

    editor.deleteText();
    editor.display();

    return 0;
} 

/*
The time complexity for each function is O(1) as the function only loops once every time, but there is 
an exception when the resize function is called, which increases the time complexity to O(n) as it 
loops for n times in the resize function.
*/