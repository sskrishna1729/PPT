#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> findErrorNums(std::vector<int>& nums) {
    std::unordered_set<int> seen;
    int duplicate = 0;
    int missing = 0;
    int expectedSum = nums.size() * (nums.size() + 1) / 2;
    int actualSum = 0;
    
    for (int num : nums) {
        if (seen.count(num) > 0) {
            duplicate = num;
        }
        seen.insert(num);
        actualSum += num;
    }
    
    missing = expectedSum - actualSum + duplicate;
    
    return {duplicate, missing};
}

int main() {
    std::vector<int> nums = {1, 2, 2, 4};

    std::vector<int> result = findErrorNums(nums);
    
    std::cout << "Output: [";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i != result.size() - 1)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;
    
    return 0;
}
