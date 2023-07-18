#include <iostream>
#include <vector>

int compress(std::vector<char>& chars) {
    int n = chars.size();
    int index = 0; // index to track the position of the compressed characters in the modified array

    for (int i = 0; i < n; ++i) {
        char currentChar = chars[i];
        int count = 1; // count of consecutive repeating characters

        // Count the number of consecutive repeating characters
        while (i + 1 < n && chars[i + 1] == currentChar) {
            ++count;
            ++i;
        }

        // Modify the array with the compressed characters
        chars[index++] = currentChar;

        // If the count is greater than 1, append the count as characters
        if (count > 1) {
            std::string countStr = std::to_string(count);
            for (char ch : countStr) {
                chars[index++] = ch;
            }
        }
    }

    return index; // return the new length of the modified array
}

int main() {
    std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    int newLength = compress(chars);

    std::cout << "New length of the array: " << newLength << std::endl;
    std::cout << "Modified array: ";
    for (int i = 0; i < newLength; ++i) {
        std::cout << chars[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
