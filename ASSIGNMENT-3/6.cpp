#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

int main() {
    std::vector<int> nums = {2, 2, 1};
    int result = singleNumber(nums);
    std::cout << result << std::endl; // Output: 1

    return 0;
}
