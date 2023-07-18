#include <iostream>
#include <vector>
#include <unordered_map>

int majorityElement(const std::vector<int>& nums) {
    int n = nums.size();
    std::unordered_map<int, int> count;

    // Count the occurrences of each element
    for (int num : nums) {
        count[num]++;
    }

    // Find the element with the majority count
    for (auto& pair : count) {
        if (pair.second > n / 2) {
            return pair.first;
        }
    }

    // Majority element not found
    return -1;
}

int main() {
    std::vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};

    int majority = majorityElement(nums);

    if (majority != -1) {
        std::cout << "Majority element: " << majority << std::endl;
    } else {
        std::cout << "No majority element found" << std::endl;
    }

    return 0;
}
