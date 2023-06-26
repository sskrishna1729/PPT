#include <iostream>
#include <vector>
#include <algorithm>

int arrayPairSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int max_sum = 0;
    for (int i = 0; i < nums.size(); i += 2) {
        max_sum += nums[i];
    }
    return max_sum;
}

int main() {
    std::vector<int> nums = {1, 4, 3, 2};
    std::cout << arrayPairSum(nums) << std::endl;
    return 0;
}