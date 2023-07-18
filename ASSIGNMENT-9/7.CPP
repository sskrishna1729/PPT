#include <iostream>
#include <vector>

long long merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;
    long long count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += mid - i + 1;
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }

    return count;
}

long long mergeSort(std::vector<int>& arr, int left, int right) {
    long long count = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);
        count += merge(arr, left, mid, right);
    }

    return count;
}

long long countInversions(std::vector<int>& arr) {
    int n = arr.size();
    return mergeSort(arr, 0, n - 1);
}

int main() {
    std::vector<int> arr = {2, 4, 1, 3, 5};

    long long inversions = countInversions(arr);

    std::cout << "Number of inversions: " << inversions << std::endl;

    return 0;
}
