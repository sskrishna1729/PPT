#include <iostream>
#include <vector>
#include <unordered_map>

int findMaxLength(const std::vector<int>& nums) {
    int maxLength = 0;
    int count = 0;
    std::unordered_map<int, int> countMap;
    countMap[0] = -1;

    for (int i = 0; i < nums.size(); ++i) {
        count += (nums[i] == 1) ? 1 : -1;

        if (countMap.find(count) != countMap.end()) {
            maxLength = std::max(maxLength, i - countMap[count]);
        } else {
            countMap[count] = i;
        }
    }

    return maxLength;
}

int main() {
    std::vector<int> nums = {0, 1};
    int maxLength = findMaxLength(nums);

    std::cout << "Maximum length: " << maxLength << std::endl;

    return 0;
}
