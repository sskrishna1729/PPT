#include <iostream>
#include <string>
#include <stack>

bool backspaceCompare(const std::string& s, const std::string& t) {
    std::stack<char> stackS, stackT;

    for (char ch : s) {
        if (ch != '#') {
            stackS.push(ch);
        } else if (!stackS.empty()) {
            stackS.pop();
        }
    }

    for (char ch : t) {
        if (ch != '#') {
            stackT.push(ch);
        } else if (!stackT.empty()) {
            stackT.pop();
        }
    }

    return stackS == stackT;
}

int main() {
    std::string s = "ab#c";
    std::string t = "ad#c";

    bool isEqual = backspaceCompare(s, t);

    if (isEqual) {
        std::cout << "The strings are equal after typing into empty text editors." << std::endl;
    } else {
        std::cout << "The strings are not equal after typing into empty text editors." << std::endl;
    }

    return 0;
}
