#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class PocketMoney {

    public:
    static float amount;
    static bool headerPrinted;
    PocketMoney(const string& source, float Received){
        this->source = source;
        this->Received = Received;
        amount += Received;
        display_wallet();
    }
    void display_wallet(){
        if (!headerPrinted) {
            cout << left << setw(20) << "Source"<< right << setw(10) << "Received"<< right << setw(10) << "Total" << endl;
            headerPrinted = true;
        }
        cout << left << setw(20) << source << right << setw(10) << Received << right << setw(10) << amount << endl;
    }

    private:
    string source;
    float Received;

};

float PocketMoney :: amount = 0;
bool PocketMoney::headerPrinted = false;

int main(){
    
    PocketMoney pm1("Father",200);
    PocketMoney pm2("Brother",60);

    return 0;
}