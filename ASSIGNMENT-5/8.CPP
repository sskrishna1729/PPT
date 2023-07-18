#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> findOriginalArray(const std::vector<int>& changed) {
    int n = changed.size();
    if (n % 2 != 0) {
        return {};  // Return an empty array if the length is odd
    }

    std::unordered_set<int> seen;
    std::vector<int> original;

    for (const auto& num : changed) {
        if (num % 2 != 0) {
            return {};  // Return an empty array if num is not even
        }

        int half = num / 2;
        if (seen.count(half) > 0) {
            original.push_back(half);
            seen.erase(half);
        } else {
            seen.insert(num);
        }
    }

    return original;
}

int main() {
    std::vector<int> changed = {1, 3, 4, 2, 6, 8};
    std::vector<int> original = findOriginalArray(changed);

    std::cout << "Original array: ";
    for (const auto& num : original) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
