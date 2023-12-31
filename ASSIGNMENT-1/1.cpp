#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap;
    std::vector<int> result;
    
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        
        if (numMap.find(complement) != numMap.end()) {
            result.push_back(numMap[complement]);
            result.push_back(i);
            break;
        }
        
        numMap[nums[i]] = i;
    }
    
    return result;
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSum(nums, target);
    
    if (result.size() == 2) {
        std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
    } else {
        std::cout << "No two elements found that add up to the target." << std::endl;
    }
    
    return 0;
}
