#include <iostream>

int PeekFinder(int arr[], int left, int right) {
    int mid = (left + right) / 2;
    if (mid > 0 && arr[mid - 1] > arr[mid]) {
        return PeekFinder(arr, left, mid - 1);
    } else if (mid < right && arr[mid + 1] > arr[mid]) {
        return PeekFinder(arr, mid + 1, right);
    } else {
        return mid;
    }
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int peakIndex = PeekFinder(arr, 0, n - 1);
    std::cout <<"The peek of array is: "<< arr[peakIndex];
    return 0;
}
