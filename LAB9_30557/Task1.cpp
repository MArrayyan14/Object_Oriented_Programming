#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

class Element {
    public:
    string name;
    string symbol;
    int AN;
};

class ElementSorter {
public:
    bool operator()(Element& a,Element& b) {
        if (a.AN == b.AN) {
            return a.name < b.name;
        }else{
            return a.AN < b.AN;
        }
    }
};

class NameFilter {
public:
    bool operator()(Element& a) {
        bool status = a.name.length() > 5;
        return status;
    }
};

string UpperCase(string& s) {
    string newstring = s;
    transform(newstring.begin(), newstring.end(), newstring.begin(), ::toupper);
    return newstring;
}

int main(){
       
        vector<Element> elements = {
            {"Hydrogen", "H", 1},
            {"Helium", "He", 2},
            {"Lithium", "Li", 3},
            {"Beryllium", "Be", 4},
            {"Boron", "B", 5},
            {"Carbon", "C", 6},
            {"Nitrogen", "N", 7},
            {"Oxygen", "O", 8},
            {"Fluorine", "F", 9},
            {"Neon", "Ne", 10}
        };

        int min;
        cout << "Enter minimum atomic number to include: ";
        cin >> min;
    
        vector<Element> MyElements;
        copy_if(elements.begin(), elements.end(), back_inserter(MyElements), 
            [min](Element& e) {
                return e.AN >= min;
            });

        sort(MyElements.begin(), MyElements.end(), ElementSorter());   
        
        cout<<"SORTED ELEMENTS"<<endl;
        for(int i = 0; i<MyElements.size(); i++){
            cout<<"NAME: "<<MyElements[i].name<<", SYMBOL:" <<MyElements[i].symbol<<" ,ATOMIC NUMBER: " <<MyElements[i].AN<<endl;
        }
        int longName = count_if(MyElements.begin(), MyElements.end(), NameFilter());
        cout << "Number of elements with names longer than 5 characters: " << longName<<endl;



        vector<string> upperSymbols;

        transform(MyElements.begin(), MyElements.end(), back_inserter(upperSymbols),
        []( Element& e) {
            string upper = e.symbol;
            transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
            return upper;
        });

        cout<<"UPPER CASE SYMBOLS:"<<endl;
        for(int i = 0; i<upperSymbols.size(); i++){
            cout<<upperSymbols[i]<<endl;
        }

}