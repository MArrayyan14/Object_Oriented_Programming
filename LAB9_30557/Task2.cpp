#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BalancedBraces {
public:
    bool operator()(const string& expression) const {
        int counter = 0;
        for (char ch : expression) {
            if (ch == '{') {
                ++counter;
            } else if (ch == '}') {
                if (counter == 0) {
                    return false;
                }
                --counter;
            }
        }
        return counter == 0;
    }
};

int main() {
    vector<string> expressions = {
        "{x + y} * {a - b}",
        "{{x}}",
        "{x + y",
        "x + y}",
        "{ { } { }"
    };

    BalancedBraces checker;

    for_each(expressions.begin(), expressions.end(), [&](const string& expr) {
        cout << "Expression: \"" << expr << "\" is "
             << (checker(expr) ? "Balanced" : "Unbalanced") << endl;
    });

    return 0;
}