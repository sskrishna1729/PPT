#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int count = 0;
    int n = nums.size();
    
    for (int j = 0; j < n; ++j) {
        if (nums[j] != val) {
            nums[count] = nums[j];
            ++count;
        }
    }
    
    return count;
}

int main() {
    std::vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int result = removeElement(nums, val);
    
    std::cout << "Output: " << result << ", nums = [";
    for (int i = 0; i < result; ++i) {
        std::cout << nums[i];
        if (i != result - 1)
            std::cout << ",";
    }
    std::cout << ",_*]" << std::endl;
    
    return 0;
}
