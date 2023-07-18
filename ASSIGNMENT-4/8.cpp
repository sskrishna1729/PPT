#include <iostream>
#include <vector>

std::vector<int> rearrangeArray(const std::vector<int>& nums, int n) {
    std::vector<int> result(2 * n);

    for (int i = 0; i < n; ++i) {
        result[2 * i] = nums[i];
        result[2 * i + 1] = nums[i + n];
    }

    return result;
}

int main() {
    std::vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;

    std::vector<int> result = rearrangeArray(nums, n);

    std::cout << "Rearranged array: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
