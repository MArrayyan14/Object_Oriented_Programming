#include <iostream>
#include "InstanceCounter.h"

using namespace std;

int main(){
    InstanceCounter o1;
    InstanceCounter o2;
    cout<<o2.getCount();
}