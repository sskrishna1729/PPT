#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> findDuplicates(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    std::vector<int> duplicates;
    
    for (const auto& num : nums) {
        if (seen.count(num) > 0) {
            duplicates.push_back(num);
        }
        seen.insert(num);
    }
    
    return duplicates;
}

int main() {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> duplicates = findDuplicates(nums);

    std::cout << "Duplicates: ";
    for (const auto& num : duplicates) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}


