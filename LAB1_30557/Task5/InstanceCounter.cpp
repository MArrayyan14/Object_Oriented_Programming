#include <iostream>
#include "InstanceCounter.h"

using namespace std;

InstanceCounter :: InstanceCounter(){
    counter += 1;
}

int InstanceCounter :: getCount() const {
    return counter;
}

