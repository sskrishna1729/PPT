#include <iostream>

int arrangeCoins(int n) {
    int k = 0;
    while ((k * (k + 1L)) / 2L <= n) {
        ++k;
    }
    return k - 1;
}

int main() {
    int n = 8;
    int completeRows = arrangeCoins(n);
    std::cout << "Number of complete rows: " << completeRows << std::endl;
    return 0;
}
