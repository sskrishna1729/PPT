#include <iostream>
#include <vector>

bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    int left = 0;
    int right = m * n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midElement = matrix[mid / n][mid % n];
        
        if (midElement == target) {
            return true;
        } else if (midElement < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    
    bool found = searchMatrix(matrix, target);
    
    if (found) {
        std::cout << "Target found in the matrix." << std::endl;
    } else {
        std::cout << "Target not found in the matrix." << std::endl;
    }
    
    return 0;
}
