#include <iostream>
#include <vector>

std::vector<int> CountingSort(std::vector<int> vec, int a, int b){
    int range = b - a + 1; //range of values to be sorted
    std::vector<int> count(range); //creates vector named count with size range

    for(int i = 0; i < vec.size(); ++i) // count same elements
        count[vec[i]-a]++;

    for(int i = 1; i < count.size(); ++i) //sum of previous elements
        count[i] += count[i-1];

    std::vector<int> output_array(vec.size()); 
    for(int i = vec.size()-1; i >= 0; --i){ //iterate from the end to maintain stability
        output_array[count[vec[i]-a]-1] = vec[i];
        count[vec[i]-a]--;
    }
    
    return output_array;
}

int main(){

    std::vector<int> vec{3, 1, 0, 1, 3, 3, 3, 0};
    int a = 0, b = 3, k = vec.size();
    std::vector<int> result = CountingSort(vec, a, b);
    for(auto el : result)
        std::cout << el << " ";
    
    std::cout << std::endl;
    return 0;
}
