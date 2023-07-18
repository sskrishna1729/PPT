#include <iostream>
#include <string>

bool rotateString(const std::string& s, const std::string& goal) {
    if (s.length() != goal.length()) {
        return false;
    }
    
    std::string concatenated = s + s;
    
    return concatenated.find(goal) != std::string::npos;
}

int main() {
    std::string s = "abcde";
    std::string goal = "cdeab";
    
    bool isRotated = rotateString(s, goal);

    if (isRotated) {
        std::cout << "s can become goal after some number of shifts." << std::endl;
    } else {
        std::cout << "s cannot become goal after any number of shifts." << std::endl;
    }

    return 0;
}
