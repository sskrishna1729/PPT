#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Find the first decreasing element from the right
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Find the smallest element in the suffix greater than nums[i]
        int j = n - 1;
        while (j > i && nums[j] <= nums[i]) {
            j--;
        }
        std::swap(nums[i], nums[j]);
    }

    // Reverse the suffix of the array
    std::reverse(nums.begin() + i + 1, nums.end());
}
