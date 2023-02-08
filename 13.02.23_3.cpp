#include <iostream>
#include <vector>

std::vector<int> findClosestElements(std::vector<int>& arr, int target, int k){
    int left = 0, right = arr.size() - 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
                if (arr[mid] == target){
                    left = mid;
                    break;
                }

                else if (arr[mid] < target){
                    left = mid + 1;
                }
                
                else
                right = mid - 1;
        }
int i = left - 1, j = left;

while (k > 0 && (i >= 0 || j < arr.size())){
    if (i < 0){
        j++;
    }
    else if (j >= arr.size()){
        i--;
    }
    else if (target - arr[i] <= arr[j] - target){
        i--;
    }
    else{
        j++;
    }
    k--;
}

std::vector<int> result;
for (int p = i + 1; p < j; p++){
    result.push_back(arr[p]);
}
return result;
}

int main(){    
    std::vector<int> arr = {2, 3, 4, 5, 6, 7};
    int target = 1;
    int k = 3;

    std::vector<int> result = findClosestElements(arr, target, k);
    std::cout << "The " << k << " closest elements to " << target << " are: ";

for (int i = 0; i < result.size(); i++){
    std::cout << result[i] << " ";
}
    std::cout << std::endl;

return 0;
}