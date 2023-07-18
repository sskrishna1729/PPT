#include <iostream>
#include <unordered_map>

bool isIsomorphic(const std::string& s, const std::string& t) {
    int n = s.length();
    std::unordered_map<char, char> sMap, tMap;

    for (int i = 0; i < n; ++i) {
        char sChar = s[i];
        char tChar = t[i];

        if (sMap.count(sChar)) {
            if (sMap[sChar] != tChar) {
                return false;
            }
        } else {
            sMap[sChar] = tChar;
        }

        if (tMap.count(tChar)) {
            if (tMap[tChar] != sChar) {
                return false;
            }
        } else {
            tMap[tChar] = sChar;
        }
    }

    return true;
}

int main() {
    std::string s = "egg";
    std::string t = "add";

    bool isomorphic = isIsomorphic(s, t);

    if (isomorphic) {
        std::cout << "Strings are isomorphic." << std::endl;
    } else {
        std::cout << "Strings are not isomorphic." << std::endl;
    }

    return 0;
}
