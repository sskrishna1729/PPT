#include <iostream>
#include <vector>

std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    
    int num = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    
    while (num <= n * n) {
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = num++;
        }
        ++top;
        
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = num++;
        }
        --right;
        
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            --bottom;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            ++left;
        }
    }
    
    return matrix;
}

int main() {
    int n = 3;
    std::vector<std::vector<int>> matrix = generateMatrix(n);

    std::cout << "Generated Matrix:" << std::endl;
    for (const auto& row : matrix) {
        for (const auto& num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
