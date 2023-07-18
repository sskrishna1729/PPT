#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> findOriginalArray(const std::vector<int>& changed) {
    int n = changed.size();
    if (n % 2 != 0) {
        return {};  // Return an empty array if the length is odd
    }

    std::unordered_map<int, int> freq;
    for (const auto& num : changed) {
        ++freq[num];
    }

    std::vector<int> original;
    for (const auto& num : changed) {
        if (freq[num] > 0 && freq[2 * num] > 0) {
            --freq[num];
            --freq[2 * num];
            original.push_back(num);
        }
    }

    if (original.size() == n / 2) {
        return original;
    } else {
        return {};  // Return an empty array if the changed array is not a doubled array
    }
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
