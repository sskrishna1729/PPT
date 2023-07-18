#include <iostream>
#include <vector>
#include <cmath>

int distanceValue(const std::vector<int>& arr1, const std::vector<int>& arr2, int d) {
    int distance = 0;
    for (const auto& num1 : arr1) {
        bool valid = true;
        for (const auto& num2 : arr2) {
            if (std::abs(num1 - num2) <= d) {
                valid = false;
                break;
            }
        }
        if (valid) {
            ++distance;
        }
    }
    return distance;
}

int main() {
    std::vector<int> arr1 = {4, 5, 8};
    std::vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;

    int distance = distanceValue(arr1, arr2, d);

    std::cout << "Distance value: " << distance << std::endl;

    return 0;
}
