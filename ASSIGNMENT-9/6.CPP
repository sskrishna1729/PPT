#include <iostream>

// Example API function
bool isBadVersion(int version) {
    // Implementation of the API function isBadVersion is not provided in this example
    // You would typically have an implementation that returns whether the version is bad
    // For the sake of demonstration, we assume that version 4 is the first bad version
    return (version >= 4);
}

int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Check if the mid version is bad
        if (isBadVersion(mid)) {
            right = mid; // Search in the left half
        } else {
            left = mid + 1; // Search in the right half
        }
    }

    // Return the first bad version
    return left;
}

int main() {
    int n = 5;

    int firstBad = firstBadVersion(n);

    std::cout << "First bad version: " << firstBad << std::endl;

    return 0;
}
