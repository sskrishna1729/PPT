#include <iostream>
#include <vector>
#include <algorithm>

int minProductSum(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    int n = nums1.size();
    
    std::vector<int> sortedNums1 = nums1;
    std::sort(sortedNums1.begin(), sortedNums1.end());
    
    std::vector<int> sortedNums2 = nums2;
    std::sort(sortedNums2.begin(), sortedNums2.end(), std::greater<int>());
    
    int minProductSum = 0;
    for (int i = 0; i < n; ++i) {
        minProductSum += sortedNums1[i] * sortedNums2[i];
    }
    
    return minProductSum;
}

int main() {
    std::vector<int> nums1 = {5, 3, 4, 2};
    std::vector<int> nums2 = {4, 2, 2, 5};
    int minProduct = minProductSum(nums1, nums2);

    std::cout << "Minimum product sum: " << minProduct << std::endl;

    return 0;
}
