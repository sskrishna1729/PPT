#include <iostream>
#include <vector>

void findCommonElements(const std::vector<int>& ar1, const std::vector<int>& ar2, const std::vector<int>& ar3) {
    int n1 = ar1.size();
    int n2 = ar2.size();
    int n3 = ar3.size();
    
    int i = 0, j = 0, k = 0;
    
    while (i < n1 && j < n2 && k < n3) {
        if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) {
            std::cout << ar1[i] << " ";
            i++;
            j++;
            k++;
        } else if (ar1[i] < ar2[j]) {
            i++;
        } else if (ar2[j] < ar3[k]) {
            j++;
        } else {
            k++;
        }
    }
}

int main() {
    std::vector<int> ar1 = {1, 5, 10, 20, 40, 80};
    std::vector<int> ar2 = {6, 7, 20, 80, 100};
    std::vector<int> ar3 = {3, 4, 15, 20, 30, 70, 80, 120};
    
    std::cout << "Common elements: ";
    findCommonElements(ar1, ar2, ar3);
    std::cout << std::endl;
    
    return 0;
}
