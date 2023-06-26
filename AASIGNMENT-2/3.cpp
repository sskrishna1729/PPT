#include <iostream>
#include <vector>
#include <unordered_map>

int findLHS(std::vector<int>& nums) {
    std::unordered_map<int, int> countMap;
    int maxLength = 0;
    
    // Count the frequency of each number
    for (int num : nums) {
        countMap[num]++;
    }
    
    // Check the length of harmonious subsequences
    for (auto it = countMap.begin(); it != countMap.end(); ++it) {
        int num = it->first;
        if (countMap.count(num + 1)) {
            int length = it->second + countMap[num + 1];
            maxLength = std::max(maxLength, length);
        }
    }
    
    return maxLength;
}

int main() {
    std::vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    std::cout << findLHS(nums) << std::endl;
    return 0;
}