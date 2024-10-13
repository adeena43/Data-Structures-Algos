#include <iostream>

using namespace std;

// Function to calculate the sum of elements in a multi-dimensional jagged array
int recursiveArraySum(int* arr[], int sizes[], int dim) {
    // Base case: If we've processed all dimensions, return 0
    if (dim < 0) {
        return 0;
    }

    int totalSum = 0; // Variable to store the sum of elements for the current dimension

    // Iterate over the current dimension
    for (int i = 0; i < sizes[dim]; ++i) {
        if (dim == 0) {
            // If we are at the last dimension, sum the values directly
            for(int i = 0; i<sizes[dim]; i++)
            {
                totalSum += arr[i][dim];
            }
        } else {
            // If we are not at the last dimension, recurse deeper into the next dimension
            totalSum += recursiveArraySum(arr, sizes, dim - 1);
        }
    }

    return totalSum; // Return the total sum for the current dimension
}

int main() {
    // Example of a jagged array
    int* jaggedArray[3]; // Declare an array of pointers

    // Size of each dimension
    int sizes[] = {3, 2, 4}; // Sizes for each dimension (3 rows, 2 columns, 4 elements in last dimension)

    // Allocate and initialize the jagged array
    jaggedArray[0] = new int[3]{1, 2, 3};         // First row
    jaggedArray[1] = new int[2]{4, 5};            // Second row
    jaggedArray[2] = new int[4]{6, 7, 8, 9};      // Third row

    // Calculate the sum of the elements in the jagged array
    int totalSum = recursiveArraySum(jaggedArray, sizes, 0); // Start from the first dimension

    // Output the total sum
    cout << "The sum of all elements in the jagged array is: " << totalSum << endl;

    // Clean up memory
    for (int i = 0; i < 3; ++i) {
        delete[] jaggedArray[i]; // Free each allocated row
    }

    return 0;
}
