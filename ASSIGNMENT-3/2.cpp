#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    std::vector<std::vector<int>> result;

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue; // Skip duplicate values in the outer loop
        }

        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue; // Skip duplicate values in the second nested loop
            }

            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[j] + nums[left] + nums[right];

                if (currentSum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;

                    // Skip duplicate values in the inner loop
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicate values in the inner loop
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (currentSum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
    }

    return result;
}
