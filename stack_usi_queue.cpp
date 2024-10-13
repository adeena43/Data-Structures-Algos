//stack using queue

#include<iostream>
#include<queue>
using namespace std;

class Stack{
    private:
    queue<int> q;
    
    public:
    void push(int x)
    {
        int size = q.size();
        
        q.push(x);
        
        for(int i = 0;i<size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    bool empty()
    {
        return q.empty();
    }
    
    int pop()
    {
        if(q.empty())
        {
            return -1;
        }
        else
        {
            q.pop();
        }
    }
    
    int top()
    {
        if(!q.empty())
        {
            return q.front();
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Stack s1;
    
    s1.push(10);
    s1.push(20);
    s1.push(30);
    
   while(!s1.empty())
   {
       cout<<s1.top()<<" ";
       s1.pop();
   }
}
