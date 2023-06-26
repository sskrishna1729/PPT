#include <iostream>
#include <vector>
#include <algorithm>

int minimumScore(std::vector<int>& nums, int k) {
    int n = nums.size();
    int minScore = nums[n-1] - nums[0]; // Initialize the minimum score as the current difference
    
    for (int i = 0; i < n - 1; ++i) {
        int low = std::min(nums[0] + k, nums[i+1] - k); // Decrease the larger elements
        int high = std::max(nums[n-1] - k, nums[i] + k); // Increase the smaller elements
        minScore = std::min(minScore, high - low); // Update the minimum score
    }
    
    return minScore;
}

int main() {
    std::vector<int> nums = {1};
    int k = 0;
    std::cout << minimumScore(nums, k) << std::endl;
    return 0;
}