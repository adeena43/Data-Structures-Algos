#include <iostream>
#include <vector>
#include <algorithm>
#include<utility>
using namespace std;

int main() {
    vector<std::pair<int, int>> arr = {{2, 4}, {5, 9}, {10, 12}, {3, 9}, {7, 11}};
    int n = arr.size();

    // Step 1: Create a vector of pairs (element, index)
    std::vector<std::pair<pair<int, int>, int>> indexed_arr(n);
    for (int i = 0; i < n; ++i) {
        indexed_arr[i] = {arr[i], i};  // Pair element with its index
    }

    // Step 2: Sort the array based on the elements (first of the pair)
    std::sort(indexed_arr.begin(), indexed_arr.end());

    // Step 3: Extract the sorted indices
    std::vector<int> sorted_indices(n);
    for (int i = 0; i < n; ++i) {
        sorted_indices[i] = indexed_arr[i].second;  // Store the index of the sorted element
    }

    // Step 4: Print the sorted indices
    std::cout << "Sorted indices: ";
    for (int i = 0; i < n; ++i) {
        std::cout << sorted_indices[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
