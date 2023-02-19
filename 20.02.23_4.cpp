#include <iostream>
#include <vector>

std::vector<int> merge(const std::vector<int> &first, const std::vector<int> &second){
    std::vector<int> result;
    std::size_t i = 0, j = 0;

    while (i < first.size() && j < second.size()) {
        if (first[i] < second[j]) {
            result.push_back(first[i]);
            i++;
        } else {
            result.push_back(second[j]);
            j++;
        }
    }

    while (i < first.size()) {
        result.push_back(first[i]);
        i++;
    }

    while (j < second.size()) {
        result.push_back(second[j]);
        j++;
    }

    return result;
}

std::vector<int> merge_sort(const std::vector<int> &vec, std::size_t start, std::size_t end){
    if(end - start == 1)
        return {vec[start]};

    std::size_t middle = (end + start) / 2;
    return merge(merge_sort(vec, start, middle), merge_sort(vec, middle, end));
}

std::vector<int> merge_sort(std::vector<int> &vec){
    return merge_sort(vec, 0, vec.size());
}

int main() {
    std::vector<int> vec{5, 2, 7, 3, 8, 1, 9, 4, 6};

    std::cout << "Before sorting: ";
    for (const auto &v : vec)
        std::cout << v << " ";
    std::cout << std::endl;

    vec = merge_sort(vec);

    std::cout << "After sorting: ";
    for (const auto &v : vec)
        std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}
