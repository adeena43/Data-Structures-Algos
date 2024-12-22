#include <iostream>
using namespace std;

void merge(int arr[], int s, int e, int mid)
{
    int n1 = mid - s + 1;
    int n2 = e - mid;

    int arr1[n1], arr2[n2];

    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[s + i];
    }
    for (int i = 0; i < n2; i++) {
        arr2[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = s;

    // Merge the two subarrays into the original array
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from arr1
    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    // Copy any remaining elements from arr2
    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int s, int e)
{
    if (s < e) {
        int mid = s + (e - s) / 2;

        // Recursively split and sort the array
        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);

        // Merge the two sorted halves
        merge(arr, s, e, mid);
    }
}

bool hasAllUnique(int arr[], int size)
{
    mergeSort(arr, 0, size - 1);  // Fix the upper bound here
    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1]) {
            return false;  // Return false if a duplicate is found
        }
    }
    return true;  // Return true if all elements are unique
}

int main()
{
    int arr[5] = {1, 78, 2, 3, 4};
    int size = 5;

    if (hasAllUnique(arr, size)) {
        cout << "All elements are unique." << endl;
    } else {
        cout << "There are duplicates." << endl;
    }

    return 0;
}
