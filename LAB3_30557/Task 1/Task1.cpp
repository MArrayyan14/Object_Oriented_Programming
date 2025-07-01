#include "StringProcessor.h"
#include <iostream>
#include <string>

using namespace  std;

int main(){

    StringProcessor s1;
    cout<<s1.Processor("hello")<<endl;
    cout<<s1.Processor("hello","world")<<endl;
    cout<<s1.Processor("he",3);


    return 0;
}