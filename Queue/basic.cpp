//Queue implementation using both arrays and linked list
#include<iostream>
using namespace std;
//using array
/*
class Queue{
	int front, rear, size;
	int *queue;
	
	public:
		Queue(int size)
		{
			front = rear = -1;
			size = size;
			queue = new int[size];
		}
		
		void enqueue(int data)
		{
			if(rear == size -1)
			{
				cout<<"Queue is full"<<endl;
				return;
			}
			else
			{
				if(front == -1)
				{
					front = 0;
				}
				queue[++rear] = data;
				cout<<data<<" enqueued into the queue"<<endl;
			}
		}
		
		void dequeue()
		{
			if(front == -1 || front > rear)
			{
				cout<<"Queue is empty"<<endl;
				return;
			}
			else
			{
				cout<<queue[front++]<<" dequeued from the queue"<<endl;
			}
		}
};
*/

//using linked list
class Node{
	public:
		int data;
		Node* next;
		
		Node(int value)
		{
			this->data = value;
			this->next = NULL;
		}
};

class Queue{
	Node* front;
	Node* rear;
	
	public:
		Queue()
		{
			front = rear = NULL;
		}
		
		void enqueue(int data)
		{
			Node* newNode = new Node(data);
			if(rear == NULL)
			{
				front = rear = newNode;	//when queue is empty
				cout<<data<<" enqueued into the queue"<<endl;
				return;
			}
			rear -> next = newNode;		//rear is a tail pointer
			rear = newNode;
			cout<<data<<" enqueued into the queue"<<endl;
		}
		
		void dequeue()
		{
			if(front == NULL)
			{
				cout<<"Queue is empty"<<endl;
				return;
			}
			Node* temp = front;
			cout<<front->data<<"dequeued from the queue"<<endl;
			
			//if front becomes NULL, then set the rear as well to NULL
			//when it has only one node
			if(front == NULL)
			{
				rear = NULL;
			}
			delete temp;
		}
};

class CircularQueue{
	int front, rear, size;
	int* queue;
	
	public:
		CircularQueue(int size)
		{
			this->size = size;
			rear=front = -1;
			queue = new int[size];
		}
		void enqueue(int data)
		{
			//front = 0, rear = 4
			//Queue state : [fornt, X, X, X, rear]
			//(rear+1) % size = (4 + 1)%5 = 0(front)
			if((rear+1)%size == front)
			{
				cout<<"Queue is full"<<endl;
				return;
			}
			else if(front == -1)
			{
				front = rear = 0;
			}
			//Move rear in a circular manner
			else
			{
				rear = (rear + 1) %size;
			}
			queue[rear] = value;
			cout<<data<<" enqueued into the queue"<<endl;
		}
		void dequeue()
		{
			if(front == -1)
			{
				cout<<"Queue is empty"<<endl;
				return;
			}
			cout<<queue[front]<<" dequeued from the queue"<<endl;
			//if there was only one element in the queue
			if(front == rear)
			{
				front = rear = -1;
			}
			//Move front in a circular manner
			else
			{
				front = (front+1) % size;
			}
		}		
};
