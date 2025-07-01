#ifndef _StringProcessor_h
#define _StringProcessor_h
#include <string>

using namespace  std;

class StringProcessor{
    public:
    string Processor(const string& input);
    string Processor(const string& str1, const string& str2);
    string Processor(const string& input, int rep);

};


#endif