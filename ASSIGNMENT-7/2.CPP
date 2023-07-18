#include <iostream>
#include <unordered_map>

bool isStrobogrammatic(const std::string& num) {
    std::unordered_map<char, char> strobogrammaticMap{
        {'0', '0'},
        {'1', '1'},
        {'6', '9'},
        {'8', '8'},
        {'9', '6'}
    };

    int left = 0;
    int right = num.length() - 1;

    while (left <= right) {
        char leftChar = num[left];
        char rightChar = num[right];

        if (strobogrammaticMap.count(leftChar) && strobogrammaticMap.count(rightChar)) {
            if (strobogrammaticMap[leftChar] != rightChar) {
                return false;
            }
        } else {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}

int main() {
    std::string num = "69";
    bool isStrobogrammaticNum = isStrobogrammatic(num);

    if (isStrobogrammaticNum) {
        std::cout << "The number is a strobogrammatic number." << std::endl;
    } else {
        std::cout << "The number is not a strobogrammatic number." << std::endl;
    }

    return 0;
}
