#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class ListNode{
    public:
    int value;
    ListNode* next;

    ListNode(int data)
    {
        this->value=data;
        this->next = NULL;
    }
};

struct mycmp{
    bool operator() (ListNode* a, ListNode* b)
    {
        return a->value > b->value;
    }
};


ListNode* mergeKLists(vector<ListNode*> &A)
{
    priority_queue<ListNode*, vector<ListNode*>, mycmp> pq; 

    for(ListNode* x: A)
    {
        if(x)
        {
            pq.push(x);
        }
        
    }
    ListNode* head = NULL;
    ListNode* tail = NULL;

    while(!pq.empty())
    {
        ListNode* x = pq.top();
        pq.pop();

        if(head == NULL)
        {
            head = x;
            tail = x;
        }
        else{
            tail->next = x;
            tail = x;
        }

        if(x->next)
        {
            pq.push(x->next);
        }
    }

    return head;
}

int main()
{

    return 0;
}