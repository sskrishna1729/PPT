#include <iostream>
#include <vector>

std::vector<std::vector<int>> multiply(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2) {
    int m = mat1.size();
    int k = mat1[0].size();
    int n = mat2[0].size();
    
    std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < k; ++l) {
                result[i][j] += mat1[i][l] * mat2[l][j];
            }
        }
    }
    
    return result;
}

int main() {
    std::vector<std::vector<int>> mat1 = {{1, 0, 0}, {-1, 0, 3}};
    std::vector<std::vector<int>> mat2 = {{7, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    
    std::vector<std::vector<int>> result = multiply(mat1, mat2);

    std::cout << "Result of mat1 x mat2:" << std::endl;
    for (const auto& row : result) {
        for (const auto& num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
