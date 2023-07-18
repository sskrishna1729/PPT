#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sortedSquares(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n);
    int left = 0, right = n - 1;
    
    for (int i = n - 1; i >= 0; --i) {
        if (std::abs(nums[left]) > std::abs(nums[right])) {
            result[i] = nums[left] * nums[left];
            ++left;
        } else {
            result[i] = nums[right] * nums[right];
            --right;
        }
    }
    
    return result;
}

int main() {
    std::vector<int> nums = {-4, -1, 0, 3, 10};
    std::vector<int> squaredSorted = sortedSquares(nums);

    std::cout << "Squared Sorted Array: ";
    for (const auto& num : squaredSorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
