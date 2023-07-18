#include <iostream>
#include <vector>

int searchInsert(const std::vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // Found the target, return the index
        } else if (nums[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    // Target not found, return the index where it would be inserted
    return left;
}

int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    int index = searchInsert(nums, target);

    std::cout << "Insertion index: " << index << std::endl;

    return 0;
}
