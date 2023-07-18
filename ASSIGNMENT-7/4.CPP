#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

std::string reverseWords(const std::string& s) {
    std::istringstream iss(s);
    std::string word;
    std::string result;

    while (iss >> word) {
        std::reverse(word.begin(), word.end());
        result += word + " ";
    }

    result.pop_back();  // Remove the extra space at the end

    return result;
}

int main() {
    std::string s = "Let's take LeetCode contest";
    std::string reversed = reverseWords(s);

    std::cout << "Reversed sentence: " << reversed << std::endl;

    return 0;
}

