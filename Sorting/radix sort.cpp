#include <iostream>
using namespace std;

int getMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int size, int div)
{
    int output[size];
    int count[10] = {0};
    
    // Count occurrences of each digit
    for (int i = 0; i < size; i++)
    {
        count[(arr[i] / div) % 10]++;
    }
    
    // Update count[i] to contain actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    
    // Build the output array using the updated count[]
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / div) % 10] - 1] = arr[i];
        count[(arr[i] / div) % 10]--;
    }
    
    // Copy the output array back to arr[]
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int size)
{
    int max = getMax(arr, size);
    for (int div = 1; max / div > 0; div *= 10)
    {
        countingSort(arr, size, div);
    }
}

int main()
{
    int size;
    cout << "Enter the size of your array: ";
    cin >> size;
    
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
        cout << endl;
    }
    
    cout << "Before sorting: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;

    radixSort(arr, size);
    
    cout << "After sorting: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
    
    return 0;
}

