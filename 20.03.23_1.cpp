#include <iostream>
#include <vector>
#include <algorithm>



void sumOfUnitFractions(int a, int b) {
    if (a >= b || a == 0) {
        std::cout << "Invalid input: numerator should be positive and less than denominator\n";
        return;
    }
    
    std::vector<int> denominators; 
    
    while (a != 0) {
        int d = (b + a - 1) / a; 
        
        denominators.push_back(d);
        
        a = a * d - b;
        b = b * d;
        
        // check for repeated denominators and remove them
        auto it = unique(denominators.begin(), denominators.end());
        denominators.resize(distance(denominators.begin(), it));
    }
    
    
    std::cout << "Sum of unique fractions with numerator 1:\n";
    for (int i = 0; i < denominators.size(); i++) {
        if (i == denominators.size() - 1) {
            std::cout << "1/" << denominators[i] << std::endl;
        } else {
            std::cout << "1/" << denominators[i] << " + ";
        }
    }
}

int main() {
    
    int a,b; 
    std::cin>>a>>b;
    sumOfUnitFractions(a, b); // call the function
    
    return 0;
}
