#include <iostream>

int countCompleteRows(int n) {
    int k = 0;
    int totalCoins = 0;
    
    while (totalCoins <= n) {
        k++;
        totalCoins += k;
    }
    
    k--;
    
    return k;
}

int main() {
    int n = 10;
    
    int completeRows = countCompleteRows(n);
    
    std::cout << "Number of complete rows: " << completeRows << std::endl;
    
    return 0;
}
