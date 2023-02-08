#include <iostream>
#include <map>

void printFrequency(int arr[], int n)
{

std::map<int, int> frequencyMap;

for (int i = 0; i < n; i++){
    frequencyMap[arr[i]]++;
  }

for (int i = 1; i < n; i++){
    
    int key = arr[i];
    int j = i - 1;
      while (j >= 0 && frequencyMap[arr[j]] < frequencyMap[key]){
        arr[j + 1] = arr[j];
        j = j - 1;
      }

    arr[j + 1] = key;
}

for (int i = 0; i < n; i++){
    std::cout << arr[i] << " ";
    }
}

int main(){
  int arr[] = {3, 6, 3, 9, 6, 7, 9, 9};
  int n = sizeof(arr) / sizeof(arr[0]);

  printFrequency(arr, n);

  return 0;
}

