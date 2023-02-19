#include <iostream>
#include <vector>

long long merge(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right) {
    long long count = 0;
    int i = left;
    int j = mid;
    int k = left;

    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            count += mid - i;
        }
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return count;
}

long long mergeSort(std::vector<int>& arr, std::vector<int>& temp, int left, int right) {
    long long count = 0;
    if (right > left) {
        int mid = (left + right) / 2;
        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid + 1, right);
    }
    return count;
}

long long countSwaps(std::vector<int> arr) {
    int n = arr.size();
    std::vector<int> temp(n);
    return mergeSort(arr, temp, 0, n - 1);
}

int main() {
    std::vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::cout << countSwaps(arr) << std::endl; 
    
    return 0;
}
