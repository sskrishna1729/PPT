#include <iostream>
#include <algorithm>
#include <vector>

int arrayPairSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int maxSum = 0;
    for (int i = 0; i < nums.size(); i += 2) {
        maxSum += nums[i];
    }
    return maxSum;
}

int main() {
    std::vector<int> nums = {1, 4, 3, 2};

    int result = arrayPairSum(nums);

    std::cout << "Maximized sum: " << result << std::endl;

    return 0;
}
