#include <iostream>
#include <vector>

bool validMountainArray(const std::vector<int>& arr) {
    int n = arr.size();
    if (n < 3) {
        return false;
    }

    int i = 0;
    while (i < n - 1 && arr[i] < arr[i + 1]) {
        ++i;
    }

    if (i == 0 || i == n - 1) {
        return false;
    }

    while (i < n - 1 && arr[i] > arr[i + 1]) {
        ++i;
    }

    return i == n - 1;
}

int main() {
    std::vector<int> arr = {1, 3, 2};
    bool isValidMountain = validMountainArray(arr);

    if (isValidMountain) {
        std::cout << "The array is a valid mountain array." << std::endl;
    } else {
        std::cout << "The array is not a valid mountain array." << std::endl;
    }

    return 0;
}
