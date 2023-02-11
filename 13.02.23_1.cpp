#include <iostream>
#include <unordered_map>
#include <vector>

void insertionSort(std::vector<int> &arr, std::vector<int> &frequency) {
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int keyFrequency = frequency[i];
    int j = i - 1;
    while (j >= 0 && frequency[j] < keyFrequency) {
      arr[j + 1] = arr[j];
      frequency[j + 1] = frequency[j];
      j--;
    }
    arr[j + 1] = key;
    frequency[j + 1] = keyFrequency;
  }
}

int main() {
  std::vector<int> arr = {3, 6, 3, 9, 6, 7, 9, 9};
  int n = arr.size();

  std::unordered_map<int, int> frequencyMap;
  for (int i = 0; i < n; i++) {
    frequencyMap[arr[i]]++;
  }

  std::vector<int> frequency(n);
  int index = 0;
  for (const auto &kv : frequencyMap) {
    arr[index] = kv.first;
    frequency[index] = kv.second;
    index++;
  }

  insertionSort(frequency, arr);

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < frequency[i]; j++) {
      std::cout << arr[i] << " ";
    }
  }
  std::cout << std::endl;

  return 0;
}


