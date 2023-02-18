#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int min_num_of_swaps(std::vector<int> arr) {
    int n = arr.size();
    std::vector<int> sorted_arr(arr.begin(), arr.end());
    std::sort(sorted_arr.begin(), sorted_arr.end());

    int result = 0;
    std::queue<int> q;
    std::vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }
        int j = i, size = 0;
        q.push(j);
        visited[j] = true;
        while (!q.empty()) {
            j = q.front();
            q.pop();
            size++;
            int k = std::lower_bound(sorted_arr.begin(), sorted_arr.end(), arr[j]) - sorted_arr.begin();
            if (!visited[k]) {
                q.push(k);
                visited[k] = true;
            }
        }
        result += size - 1;
    }

    return result;
}

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vec(arr, arr + n);
    std::cout << "Minimum number of swaps required to sort the array: " << min_num_of_swaps(vec) << std::endl;
    return 0;
}
