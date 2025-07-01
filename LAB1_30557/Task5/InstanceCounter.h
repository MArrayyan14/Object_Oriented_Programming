#ifndef _InstanceCounter_h
#define _InstanceCounter_h

class InstanceCounter {

    public:
    int getCount() const;
    InstanceCounter();

    private:
    static int counter ;

};

int InstanceCounter :: counter = 0; 

#endif