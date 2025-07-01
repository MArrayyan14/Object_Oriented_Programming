#include "StringProcessor.h"
#include <iostream>
#include <string>

using namespace  std;

string StringProcessor::Processor(const string& input){
    string str;
    for(int i=input.length(); i>=0; i--){
        str += input[i]; 
    }
    return str;
}

string StringProcessor::Processor(const string& str1, const string& str2){
    string nstr;
    nstr = str1 + " " + str2;
    return nstr;
}

string StringProcessor::Processor(const string& input, int rep){
    string repstr;
    for(int i = 0; i<rep; i++){
        repstr += input;
    }
    return repstr;
}