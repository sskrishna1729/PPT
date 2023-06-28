#include <iostream>
#include <vector>

std::vector<std::vector<int>> findMissingRanges(std::vector<int>& nums, int lower, int upper) {
    std::vector<std::vector<int>> result;
    int start = lower;

    for (int num : nums) {
        if (num > start) {
            result.push_back({start, num - 1});
            start = num + 1;
        }
    }

    if (start <= upper) {
        result.push_back({start, upper});
    }

    return result;
}

int main() {
    std::vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0;
    int upper = 99;

    std::vector<std::vector<int>> result = findMissingRanges(nums, lower, upper);

    // Print the result
    for (const auto& range : result) {
        std::cout << "[" << range[0] << "," << range[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}
