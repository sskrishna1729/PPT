#include <iostream>
#include <string>

std::string reverseStr(const std::string& s, int k) {
    std::string reversed = s;
    int n = s.length();
    
    for (int i = 0; i < n; i += 2 * k) {
        int left = i;
        int right = std::min(i + k - 1, n - 1);
        
        while (left < right) {
            std::swap(reversed[left], reversed[right]);
            ++left;
            --right;
        }
    }
    
    return reversed;
}

int main() {
    std::string s = "abcdefg";
    int k = 2;
    
    std::string reversed = reverseStr(s, k);

    std::cout << "Reversed string: " << reversed << std::endl;

    return 0;
}

