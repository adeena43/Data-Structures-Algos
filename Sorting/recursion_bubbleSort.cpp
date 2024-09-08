#include<iostream>
using namespace std;

// Bubble sort using recursion
void bubbleSort(int* arr, int n)
{
    // Base case: If array size is 1 or less, it's already sorted
    if (n <= 1)
        return;

    // Perform a single pass of bubble sort and recursively call for the reduced array
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    
    // Recursive call with reduced array size
    bubbleSort(arr, n - 1);
}

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    int n = 5;

    bubbleSort(arr, n);

    // Output the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

