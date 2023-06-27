#include <iostream>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> charCount;
    for (char c : s) {
        charCount[c]++;
    }
    for (int i = 0; i < s.length(); i++) {
        if (charCount[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    string s1 = "leetcode";
    int result1 = firstUniqChar(s1);
    cout << "Output 1: " << result1 << endl;
    string s2 = "loveleetcode";
    int result2 = firstUniqChar(s2);
    cout << "Output 2: " << result2 << endl;
    string s3 = "aabb";
    int result3 = firstUniqChar(s3);
    cout << "Output 3: " << result3 << endl;
    return 0;
}
