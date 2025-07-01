#include <iostream>
using namespace std;

class Cache{

    private:
    int* arr;
    int capacity;
    int currentItems;

    public:
    Cache(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        currentItems = 0;
    }
    void printCache(){
        for(int i = 0; i < currentItems; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int getCapacity() const { 
        return capacity; 
    }
    int getCurrentItems() const { 
        return currentItems; 
    }
    void setCurrentItems(int value) { 
        currentItems = value; 
    }
    int* getArray() { 
        return arr; 
    }
    ~Cache(){
        delete[] arr;
    }

};

class FIFOCache : public Cache{
    public:
    FIFOCache(int cap) : Cache(cap) {}

    void addItem(int item){
        if(getCurrentItems() < getCapacity()){
            getArray()[getCurrentItems()] = item;
            setCurrentItems(getCurrentItems() + 1);
        } else {
            for(int i = 1; i < getCapacity(); i++){
                getArray()[i-1] = getArray()[i];
            }
            getArray()[getCapacity()-1] = item;
        }
    }
};

class LRUCache : public Cache {
    public:
        LRUCache(int cap) : Cache(cap) {}
    
        void addItem(int item) {
            int* arr = getArray();
            int current = getCurrentItems();
    
            for (int i = 0; i < current; i++) {
                if (arr[i] == item) {
                    for (int j = i; j < current - 1; j++) {
                        arr[j] = arr[j + 1];
                    }
                    arr[current - 1] = item;
                    return;
                }
            }
    
            if (current < getCapacity()) {
                arr[current] = item;
                setCurrentItems(current + 1);
            } else {
                for (int i = 1; i < getCapacity(); i++) {
                    arr[i - 1] = arr[i];
                }
                arr[getCapacity() - 1] = item;
            }
        }
    };
    
    int main() {
        cout << "FIFO Cache: ";
        FIFOCache f(3);
        f.addItem(1);
        f.addItem(2);
        f.addItem(3);
        f.addItem(4);
        f.printCache();
    
        cout << "LRU Cache: ";
        LRUCache l(3);
        l.addItem(1);
        l.addItem(2);
        l.addItem(3);
        l.addItem(2);
        l.addItem(4);
        l.printCache();
    
        return 0;
    }
    