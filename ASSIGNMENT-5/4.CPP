#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::vector<int>> findDisjointArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::vector<std::vector<int>> answer(2);
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());

    for (const auto& num : nums1) {
        if (set2.find(num) == set2.end()) {
            answer[0].push_back(num);
        }
    }

    for (const auto& num : nums2) {
        if (set1.find(num) == set1.end()) {
            answer[1].push_back(num);
        }
    }

    return answer;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {2, 4, 6};

    std::vector<std::vector<int>> answer = findDisjointArrays(nums1, nums2);

    std::cout << "Distinct integers in nums1 not present in nums2: ";
    for (const auto& num : answer[0]) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Distinct integers in nums2 not present in nums1: ";
    for (const auto& num : answer[1]) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
