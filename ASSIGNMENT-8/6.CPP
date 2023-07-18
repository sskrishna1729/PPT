#include <iostream>
#include <string>
#include <vector>

std::vector<int> findAnagrams(const std::string& s, const std::string& p) {
    std::vector<int> result;
    int sLen = s.length();
    int pLen = p.length();

    if (sLen < pLen) {
        return result;
    }

    std::vector<int> sFreq(26, 0); // Frequency array for characters in s
    std::vector<int> pFreq(26, 0); // Frequency array for characters in p

    // Calculate the frequency of characters in p
    for (char ch : p) {
        pFreq[ch - 'a']++;
    }

    // Initialize the sliding window
    for (int i = 0; i < pLen; ++i) {
        sFreq[s[i] - 'a']++;
    }

    // Slide the window through s
    for (int i = pLen; i <= sLen; ++i) {
        // Compare the frequency arrays of the current window and p
        if (sFreq == pFreq) {
            result.push_back(i - pLen); // Add the start index of an anagram
        }

        // Update the frequency arrays for the next window
        if (i < sLen) {
            sFreq[s[i] - 'a']++;
            sFreq[s[i - pLen] - 'a']--;
        }
    }

    return result;
}

int main() {
    std::string s = "cbaebabacd";
    std::string p = "abc";

    std::vector<int> indices = findAnagrams(s, p);

    std::cout << "Start indices of anagrams: ";
    for (int index : indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}
