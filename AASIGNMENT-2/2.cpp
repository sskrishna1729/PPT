#include <iostream>
#include <vector>
#include <unordered_set>

int maxCandies(std::vector<int>& candyType) {
    std::unordered_set<int> uniqueCandies;
    int n = candyType.size();
    for (int candy : candyType) {
        uniqueCandies.insert(candy);
    }
    int maxCandyTypes = uniqueCandies.size();
    return std::min(maxCandyTypes, n / 2);
}

int main() {
    std::vector<int> candyType = {1, 1, 2, 2, 3, 3};
    std::cout << maxCandies(candyType) << std::endl;
    return 0;
}