#include <iostream>
using namespace std;

class MemoryResource{

    public:
    MemoryResource(){
        cout<<"MemoryResource base allocated"<<endl;
    }
    ~MemoryResource(){
        cout<<"MemoryResource base freed"<<endl;
    }

};

class NetworkBuffer : public MemoryResource{
    
    public:
    NetworkBuffer(){
        cout<<"NetworkBuffer derived allocated"<<endl;
    }
    ~NetworkBuffer(){
        cout<<"NetworkBuffer derived freed"<<endl;
    }

};

int main(){

    {NetworkBuffer n;}

    return 0;
}

/*

Q. Why does the MemoryResource constructor run before the NetworkBuffer constructor?

A. When an object of a derived class is created, the base class’s constructor is executed first, followed by the derived class’s constructor
since, the derived class inherits the attributes of the base class this order makes sure that the base object is properly made before moving 
on to the inherited object. 
This order is reversed when a destructor is called. 

*/