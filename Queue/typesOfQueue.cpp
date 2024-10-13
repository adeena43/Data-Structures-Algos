/* ---------------SINGLE QUEUE--------------------
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);

    // Display the front element
    cout << "Front element: " << q.front() << endl;

    // Dequeue elements
    q.pop();

    // Display the front element after dequeue
    cout << "Front element after pop: " << q.front() << endl;

    // Display queue size
    cout << "Queue size: " << q.size() << endl;

    return 0;
}

*/

/* ---------------PRIORITY QUEUE--------------------
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    // Enqueue elements
    pq.push(30);
    pq.push(20);
    pq.push(40);

    // Display the top (highest priority) element
    cout << "Top element: " << pq.top() << endl;

    // Dequeue the highest priority element
    pq.pop();

    // Display the top element after pop
    cout << "Top element after pop: " << pq.top() << endl;

    // Display queue size
    cout << "Priority queue size: " << pq.size() << endl;

    return 0;
}
*/

/*  ---------------INPUT RESTRICTED QUEUE--------------------
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Insert elements at the rear
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // Delete element from the front
    dq.pop_front();
    cout << "Element at front after pop: " << dq.front() << endl;

    // Delete element from the rear
    dq.pop_back();
    cout << "Element at front after pop_back: " << dq.front() << endl;

    // Display deque size
    cout << "Deque size: " << dq.size() << endl;

    return 0;
}

*/

/*   ---------------OUTPUT RESTRICTED QUEUE--------------------
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Insert elements at the rear
    dq.push_back(10);
    dq.push_back(20);

    // Insert elements at the front
    dq.push_front(5);

    // Delete element from the front
    dq.pop_front();
    cout << "Element at front after pop: " << dq.front() << endl;

    // Display deque size
    cout << "Deque size: " << dq.size() << endl;

    return 0;
}

*/

/*  ---------------CIRCULAR QUEUE--------------------
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Enqueue element
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }

        if (front == -1) front = 0;

        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;
    }

    // Dequeue element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        front = (front + 1) % capacity;
        size--;
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Get queue size
    int getSize() {
        return size;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }
};

int main() {
    CircularQueue cq(5);

    // Enqueue elements
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);

    // Display front element
    cout << "Front element: " << cq.getFront() << endl;

    // Dequeue element
    cq.dequeue();
    cout << "Front element after dequeue: " << cq.getFront() << endl;

    // Display queue size
    cout << "Queue size: " << cq.getSize() << endl;

    return 0;
}

*/

/*  ---------------DOUBLY ENDED QUEUE--------------------
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Insert elements at the rear
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    
    // Insert elements at the front
    dq.push_front(5);
    dq.push_front(1);

    // Display the front and rear elements
    cout << "Front element: " << dq.front() << endl;
    cout << "Rear element: " << dq.back() << endl;

    // Remove element from the front
    dq.pop_front();
    cout << "After pop_front(), Front element: " << dq.front() << endl;

    // Remove element from the rear
    dq.pop_back();
    cout << "After pop_back(), Rear element: " << dq.back() << endl;

    // Insert more elements and display all
    dq.push_back(40);
    dq.push_front(0);
    
    cout << "Current elements in the deque: ";
    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << " ";
    }
    cout << endl;

    // Display deque size
    cout << "Deque size: " << dq.size() << endl;

    return 0;
}

*/
