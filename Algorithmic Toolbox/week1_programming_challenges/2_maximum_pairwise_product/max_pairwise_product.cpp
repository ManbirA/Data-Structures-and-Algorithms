#include <iostream>
#include <vector>
#include <algorithm>

long MaxPairwiseProduct(const std::vector<long>& numbers) {
    //int max_product = 0;
    int n = numbers.size();
    std::vector<long> numbers_copy(n);
    numbers_copy = numbers;
    std::sort(numbers_copy.begin(), numbers_copy.end());
    
    return numbers_copy[n - 2] * numbers_copy[n - 1];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
