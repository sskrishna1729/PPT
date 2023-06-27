#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int nonZeroIndex = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[nonZeroIndex] = nums[i];
            nonZeroIndex++;
        }
    }
    for (int i = nonZeroIndex; i < n; i++) {
        nums[i] = 0;
    }
}
int main() {
    vector<int> nums1 = {0, 1, 0, 3, 12};
    moveZeroes(nums1);
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    vector<int> nums2 = {0};
    moveZeroes(nums2);
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
