#include <iostream>
using namespace std;

class Queue {
    private:
        int start, end, size;
        int* elements;

        void expand(){
            int newSize = size * 2;
            int* newElements = new int[newSize];
            for (int i = 0; i < size; i++){
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
            size = newSize;

            cout << "Queue expanded to capacity: " << size << endl;
        }
    
    public:
        Queue(int cap = 4){
            start = end = -1;
            size = cap;
            elements = new int[size];
        }

        ~Queue() {
            delete[] elements;
        }

        void enqueue(int value) {
            if (end == size - 1) { 
                cout << "Overflow, queue is full" << endl;
                expand();
                return;
            }

            if (start == -1 && end == -1) { 
                start = end = 0;
            } else {
                end++;
            }

            elements[end] = value;
            cout << "Enqueued: " << value << endl;
        }

        void dequeue() {
            if (start == -1 && end == -1) {  
                cout << "Underflow, queue is empty" << endl;
                return;
            }

            cout << "Dequeued: " << elements[start] << endl;

            if (start == end) {  
                start = end = -1;  
            } else {
                start++;  
            }
        }

        void display() {
            if (start == -1 && end == -1) {
                cout << "Queue is empty" << endl;
                return;
            }

            cout << "Queue: ";
            for (int i = start; i <= end; i++) {
                cout << elements[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    Queue que;

    que.enqueue(10);
    que.enqueue(20);
    que.enqueue(30);
    que.enqueue(40);
    que.enqueue(50);
    
    que.display();

    que.enqueue(60); 

    que.dequeue();
    que.display();

    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.dequeue();  

    que.display();

    return 0;
}
        
/*
Q. Analyze the complexity of enqueue and dequeue operations.
Ans. The time complexity for the enqueue and dequeue operations is O(1) as 
no matter how big or small the queue size is, it will only take one cycle to
add or delete the data, meaning the operation time remains constant. However, there is an exception when 
resizing the queue during the enqueue operation. When the queue is full, the complexity becomes O(n)
as the queue is resized and all elements from the existing array are copied to the new dynamic array.
*/
