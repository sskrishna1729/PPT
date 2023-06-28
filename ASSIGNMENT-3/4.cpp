#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int index = searchInsert(nums, target);
    std::cout << index << std::endl; // Output: 2

    return 0;
}
