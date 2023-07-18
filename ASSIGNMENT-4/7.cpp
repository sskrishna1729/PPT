#include <iostream>
#include <vector>
#include <limits>

int maxCount(int m, int n, const std::vector<std::vector<int>>& ops) {
    int minAi = std::numeric_limits<int>::max();
    int minBi = std::numeric_limits<int>::max();

    for (const auto& op : ops) {
        minAi = std::min(minAi, op[0]);
        minBi = std::min(minBi, op[1]);
    }

    return minAi * minBi;
}

int main() {
    int m = 3;
    int n = 4;
    std::vector<std::vector<int>> ops = {{2, 2}, {3, 3}};

    int maxIntegers = maxCount(m, n, ops);

    std::cout << "Number of maximum integers: " << maxIntegers << std::endl;

    return 0;
}
