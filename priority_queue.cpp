#include<iostream>
#include<vector>

struct item{
    int value;
    int priority;
};

item prQ[1000];
int size = -1;

void enqueue(int value, int priority)
{
    size++;
    prQ[size].value = value;
    prQ[size].priority = priority;
}

int peek()
{
    int highest = -1;
    int index = -1;

    for(int i = 0;i< size; i++)
    {
        if(highest < prQ[i].priority)
        {
            highest = prQ[i].priority;
            index = i;
        }
    }

    return index;
}

void dequeue()
{
    int ind = peek();
    for(int i = ind; i<size; i++)
    {
        prQ[i] = prQ[i+1];
    }
    size--;
}

int main()
{
    // Adding elements to the priority queue
    enqueue(10, 2);  // Value: 10, Priority: 2
    enqueue(20, 3);  // Value: 20, Priority: 3
    enqueue(30, 1);  // Value: 30, Priority: 1
    enqueue(40, 5);  // Value: 40, Priority: 5

    // Display the priority queue before any removal
    std::cout << "Priority Queue before dequeue operations:\n";
    for (int i = 0; i <= size; i++) {
        std::cout << "Value: " << prQ[i].value << ", Priority: " << prQ[i].priority << '\n';
    }

    // Dequeue the item with the highest priority
    std::cout << "\nDequeue operation...\n";
    dequeue();

    // Display the priority queue after the first removal
    std::cout << "Priority Queue after one dequeue operation:\n";
    for (int i = 0; i <= size; i++) {
        std::cout << "Value: " << prQ[i].value << ", Priority: " << prQ[i].priority << '\n';
    }

    // Peek at the item with the current highest priority
    int highestPriorityIndex = peek();
    if (highestPriorityIndex != -1) {
        std::cout << "\nItem with highest priority:\n";
        std::cout << "Value: " << prQ[highestPriorityIndex].value
                  << ", Priority: " << prQ[highestPriorityIndex].priority << '\n';
    } else {
        std::cout << "\nPriority Queue is empty.\n";
    }

    return 0;
}