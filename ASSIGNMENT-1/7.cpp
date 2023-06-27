#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    int left = 0;
    int right = 0;
    
    while (right < nums.size()) {
        if (nums[right] != 0) {
            std::swap(nums[left], nums[right]);
            left++;
        }
        right++;
    }
    
    for (int i = left; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

int main() {
    std::vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);
    
    std::cout << "Output: [";
    for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i != nums.size() - 1)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;
    
    return 0;
}
