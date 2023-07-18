#include <iostream>
#include <vector>

std::vector<int> searchRange(const std::vector<int>& nums, int target) {
    int n = nums.size();

    // Initialize the start and end indices as -1
    int start = -1;
    int end = -1;

    // Perform binary search to find the starting position
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }

        if (nums[mid] == target) {
            start = mid;
        }
    }

    // Perform binary search to find the ending position
    left = 0;
    right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }

        if (nums[mid] == target) {
            end = mid;
        }
    }

    // Return the result as a vector
    if (start != -1 && end != -1) {
        return {start, end};
    } else {
        return {-1, -1};
    }
}

int main() {
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    std::vector<int> indices = searchRange(nums, target);

    std::cout << "Starting and ending positions: " << indices[0] << ", " << indices[1] << std::endl;

    return 0;
}
