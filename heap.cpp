#include<iostream>
#include<queue>
using namespace std;

class heap{
    public:
    int arr[1000];
    int size = 0;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size +1;
        int index = size;
        arr[index] = val;

        while(index>1)
        {
            int parent = index/2;

            if(arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for(int i = 1; i<size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteFromHeap()
    {
        if(size == 0)
        {
            cout<<"Nothing to delete"<<endl;
            return;

        }
        arr[1] = arr[size];
        size--;

        //take root to its correct position
        int i = 1;
        while(i<size)
        {
            int left = 2*i;
            int right = 2*i +1;

            if(left < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if(right < size && arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }

    void heapifyMax(int arr[], int size, int i)
    {
        int largest = i;
        int left = 2* i;
        int right = 2*i + 1;

        if(largest < size && arr[largest] < arr[right])
        {
            largest  = right;        }

        if(largest < size && arr[largest] < arr[left])
        {
            largest = left;
        }
        if(largest != i)
        {
            swap(arr[largest], arr[i]);
            heapifyMax(arr, size, largest);
        }
    }

    void heapifyMin(int arr[], int size, int i)
    {
        int smallest = i;
        int left = 2* i;
        int right = 2*i + 1;

        if(smallest < size && arr[smallest] > arr[right])
        {
            smallest  = right;        }

        if(smallest < size && arr[smallest] > arr[left])
        {
            smallest = left;
        }
        if(smallest != i)
        {
            swap(arr[smallest], arr[i]);
            heapifyMin(arr, size, smallest);
        }
    }

    void buildMaxHeap(int arr[], int size, int i)
    {
        for(int i = size/2; i>0; i--)
        {
            heapifyMax(arr, size, i);
        }
    }

    void buildMinHeap(int arr[], int size, int i)
    {
        for(int i = size/2; i>0; i--)
        {
            heapifyMin(arr, size, i);
        }
    }

    void heapSort(int arr[], int size)
    {
        int n = size;
        while( n >1)
        {
            swap(arr[1], arr[n]);
            n--;
            heapifyMax(arr, n, 1);
        }
    }
};

int main()
{
    priority_queue<int> maxHeap;
    maxHeap.push(34);
    maxHeap.push(33);
    maxHeap.push(54);
    maxHeap.push(11);
    maxHeap.push(9);

    cout<<"Element at top: "<<maxHeap.top()<<endl;
    maxHeap.pop();
    cout<<"Element at top: "<<maxHeap.top()<<endl;
    return 0;
}