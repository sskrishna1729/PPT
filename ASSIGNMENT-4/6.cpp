#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sortedSquares(const std::vector<int>& nums) {
    std::vector<int> result(nums.size());
    int left = 0;
    int right = nums.size() - 1;

    for (int i = nums.size() - 1; i >= 0; --i) {
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

    std::vector<int> result = sortedSquares(nums);

    std::cout << "Sorted squares: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
