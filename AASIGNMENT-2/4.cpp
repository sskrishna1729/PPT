#include <iostream>
#include <vector>

bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    int count = 0;
    int size = flowerbed.size();
    int i = 0;
    
    while (i < size) {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
            (i == size - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            count++;
        }
        i++;
    }
    
    return count >= n;
}

int main() {
    std::vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    std::cout << std::boolalpha << canPlaceFlowers(flowerbed, n) << std::endl;
    return 0;
}