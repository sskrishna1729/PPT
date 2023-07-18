#include <iostream>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
    int left = 0; // Left pointer starting from the beginning of the array
    int right = numbers.size() - 1; // Right pointer starting from the end of the array

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            return {left + 1, right + 1}; // Return the indices (1-indexed)
        } else if (sum < target) {
            left++; // Increment the left pointer to increase the sum
        } else {
            right--; // Decrement the right pointer to decrease the sum
        }
    }

    // No solution found
    return {};
}

int main() {
    std::vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> indices = twoSum(numbers, target);

    std::cout << "Indices of the two numbers: ";
    for (int index : indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}
