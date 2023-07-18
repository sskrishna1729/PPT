#include <iostream>
#include <string>
#include <stack>

std::string decodeString(const std::string& s) {
    std::stack<int> countStack; // Stack to store the repeat counts
    std::stack<std::string> strStack; // Stack to store the decoded strings
    std::string currentString; // Current decoded string
    int currentCount = 0; // Current repeat count

    for (char ch : s) {
        if (isdigit(ch)) {
            currentCount = currentCount * 10 + (ch - '0');
        } else if (isalpha(ch)) {
            currentString += ch;
        } else if (ch == '[') {
            countStack.push(currentCount);
            strStack.push(currentString);
            currentCount = 0;
            currentString.clear();
        } else if (ch == ']') {
            int repeatCount = countStack.top();
            countStack.pop();
            std::string repeatedString;
            for (int i = 0; i < repeatCount; ++i) {
                repeatedString += currentString;
            }
            currentString = strStack.top() + repeatedString;
            strStack.pop();
        }
    }

    return currentString;
}

int main() {
    std::string s = "3[a]2[bc]";

    std::string decodedString = decodeString(s);

    std::cout << "Decoded string: " << decodedString << std::endl;

    return 0;
}
