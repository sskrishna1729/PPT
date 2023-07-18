#include <iostream>
#include <vector>

std::vector<std::vector<int>> convertTo2DArray(const std::vector<int>& original, int m, int n) {
    if (original.size() != m * n) {
        return {};  // Return an empty 2D array if it's impossible
    }

    std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));

    for (int i = 0; i < original.size(); ++i) {
        int row = i / n;
        int col = i % n;
        result[row][col] = original[i];
    }

    return result;
}

int main() {
    std::vector<int> original = {1, 2, 3, 4, 5, 6};
    int m = 2;
    int n = 3;

    std::vector<std::vector<int>> result = convertTo2DArray(original, m, n);

    // Display the result
    for (const auto& row : result) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

