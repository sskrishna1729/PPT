#include <iostream>
#include <stack>
#include <string>

bool isValid(const std::string& s) {
    std::stack<char> parentheses;
    std::stack<char> asterisks;

    for (char ch : s) {
        if (ch == '(') {
            parentheses.push(ch);
        } else if (ch == '*') {
            asterisks.push(ch);
        } else if (ch == ')') {
            if (!parentheses.empty()) {
                parentheses.pop();
            } else if (!asterisks.empty()) {
                asterisks.pop();
            } else {
                return false;
            }
        }
    }

    while (!parentheses.empty() && !asterisks.empty()) {
        if (parentheses.top() > asterisks.top()) {
            return false;
        }
        parentheses.pop();
        asterisks.pop();
    }

    return parentheses.empty();
}

int main() {
    std::string s = "()";
    bool isValidString = isValid(s);

    if (isValidString) {
        std::cout << "The string is valid." << std::endl;
    } else {
        std::cout << "The string is not valid." << std::endl;
    }

    return 0;
}
