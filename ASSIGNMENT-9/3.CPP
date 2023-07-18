#include <iostream>
#include <vector>

int findPeakElement(const std::vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Check if the mid element is greater than its neighbors
        if (nums[mid] > nums[mid + 1]) {
            right = mid; // Search in the left half
        } else {
            left = mid + 1; // Search in the right half
        }
    }

    // Return the index of the peak element
    return left;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 1};

    int peakIndex = findPeakElement(nums);

    std::cout << "Peak element index: " << peakIndex << std::endl;

    return 0;
}
