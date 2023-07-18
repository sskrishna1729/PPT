#include <iostream>
#include <vector>

std::vector<int> findPermutation(const std::string& s) {
    int n = s.size() + 1;
    std::vector<int> perm(n);

    int left = 0;
    int right = 0;

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'I') {
            perm[i] = left++;
        } else {
            perm[i] = right--;
        }
    }

    perm[n - 1] = (s[n - 2] == 'I') ? left : right;

    for (int i = 0; i < n; ++i) {
        perm[i] -= right;
    }

    return perm;
}

int main() {
    std::string s = "IDID";
    std::vector<int> perm = findPermutation(s);

    std::cout << "Reconstructed permutation: ";
    for (const auto& num : perm) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
