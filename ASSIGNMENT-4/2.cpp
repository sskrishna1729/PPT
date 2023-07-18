#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<std::vector<int>> findDistinctElements(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());
    std::vector<int> notInNums2;
    std::vector<int> notInNums1;

    for (int num : nums1) {
        if (set2.find(num) == set2.end()) {
            notInNums2.push_back(num);
        }
    }

    for (int num : nums2) {
        if (set1.find(num) == set1.end()) {
            notInNums1.push_back(num);
        }
    }

    return {notInNums1, notInNums2};
}

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {2, 4, 6};

    std::vector<std::vector<int>> result = findDistinctElements(nums1, nums2);

    std::cout << "Distinct elements in nums1 but not in nums2: ";
    for (int num : result[0]) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Distinct elements in nums2 but not in nums1: ";
    for (int num : result[1]) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
