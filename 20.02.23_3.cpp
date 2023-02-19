#include <iostream>
#include <queue>
#include <vector>


std::vector<int> mergeKSortedArrays(std::vector<std::vector<int>>& arrays) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    std::vector<int> result;
    int k = arrays.size();

    for (int i = 0; i < k; i++) {
        if (arrays[i].size() > 0) {
            pq.push(std::make_pair(arrays[i][0], i));
        }
    }

    while (!pq.empty()) {
        std::pair<int, int> minElem = pq.top();
        pq.pop();
        int elem = minElem.first;
        int arrayIndex = minElem.second;
        result.push_back(elem);
        arrays[arrayIndex].erase(arrays[arrayIndex].begin());

        if (arrays[arrayIndex].size() > 0) {
            pq.push(std::make_pair(arrays[arrayIndex][0], arrayIndex));
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> arrays = {{1, 3, 5}, {2, 3}, {2, 3, 5, 8}};
    std::vector<int> result = mergeKSortedArrays(arrays);

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
