#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int key;
    Node* next;
    Node(int data)

    {
        this->key = data;
        this->next = nullptr;
    }
};

class Hashtable{
    private:
        vector<Node*> table;
        int size;
        int capacity;
        const double loadfactor = 0.75;

        int hashfunc(int key)
        {
            return key%capacity;
        }

        void rehash()
        {
            cout<<"rehashing..."<<endl;
            int oldCapacity = capacity;
            capacity *= 2;
            vector<Node*> oldtable = table;
            table.clear();
            table.resize(capacity, nullptr);
            size = 0;

            for(int i = 0; i< oldCapacity; i++)
            {
                Node* current = oldtable[i];
                while(current)
                {
                    insert(current->key);
                    current = current->next;
                }
            }
        }

    public:
        Hashtable(int initialCapacity)
        {
            this->capacity = initialCapacity;
            this->size= 0;
            table.resize(capacity, nullptr);
        }

        void insert(int key)
        {
            int index = hashfunc(key);
            Node* newNode = new Node(key);
            newNode->next = table[index];
            table[index] = newNode;
            size++;

            if((double)size / capacity > loadfactor)
            {
                rehash();
            }
        }

        bool search(int key)
        {
            int index = hashfunc(key);
            Node* current = table[index];
            while(current)
            {
                if(current->key == key)
                {
                    return true;
                }
                current = current->next;
            }
            return false;
        }

        void display()
        {
            for(int i = 0; i<capacity; i++)
            {
                cout<<"Index "<<i<<": ";
                Node* current = table[i];
                while(current)
                {
                    cout<<" -> "<<current->key;
                    current = current->next;
                }
                cout<<endl;
            }
        }
};

int main()
{
    return 0;
}