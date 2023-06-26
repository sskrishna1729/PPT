#include <iostream>
#include <vector>
#include <algorithm>

int maximumProduct(std::vector<int>& nums) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    int product1 = nums[n-1] * nums[n-2] * nums[n-3];
    int product2 = nums[0] * nums[1] * nums[n-1];
    return std::max(product1, product2);
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    std::cout << maximumProduct(nums) << std::endl;
    return 0;
}