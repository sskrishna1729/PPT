#include <iostream>
#include <string>

bool buddyStrings(const std::string& s, const std::string& goal) {
    int n = s.length();
    int m = goal.length();

    // If the lengths of the strings are not equal, they cannot be made equal by swapping
    if (n != m) {
        return false;
    }

    // If both strings are equal, check if there are at least two identical characters to swap
    if (s == goal) {
        int count[26] = {0}; // Frequency array for characters

        for (char ch : s) {
            if (++count[ch - 'a'] >= 2) {
                return true;
            }
        }

        return false;
    }

    int firstIndex = -1; // Index of the first character that is different
    int secondIndex = -1; // Index of the second character that is different

    // Find the indices of the differing characters
    for (int i = 0; i < n; ++i) {
        if (s[i] != goal[i]) {
            if (firstIndex == -1) {
                firstIndex = i;
            } else if (secondIndex == -1) {
                secondIndex = i;
            } else {
                return false; // More than two differing characters
            }
        }
    }

    // Check if swapping the characters at the two indices makes the strings equal
    return (secondIndex != -1 && s[firstIndex] == goal[secondIndex] && s[secondIndex] == goal[firstIndex]);
}

int main() {
    std::string s = "ab";
    std::string goal = "ba";

    bool canSwap = buddyStrings(s, goal);

    std::cout << "Can swap two letters: " << std::boolalpha << canSwap << std::endl;

    return 0;
}
