#include<iostream>
#include<vector>
using namespace std;

#define SIZE 10
#define THRESHOLD 0.75

struct item{
    int data;
    int key;
};

class Hashtable{
    private:
        vector<item*> hashArray;
        item* dummyItem;
        int currentsize;
        int tableSize;

        int hashCode(int key)
        {
            return key%tableSize;
        }

        double loadFactor()
        {
            return currentsize/tableSize;
        }

        void resizeTable()
        {
            int oldSize = tableSize;
            tableSize*= 2;

            vector<item*> oldArray = hashArray;
            hashArray.clear();
            hashArray.resize(tableSize, NULL);
            currentsize = 0;

            for(int i = 0; i<oldSize; i++)
            {
                if(oldArray[i] != NULL && oldArray[i] != dummyItem)
                {
                    insert(oldArray[i]->key, oldArray[i]->data);
                    delete oldArray[i];
                }
            }
        }

    public:
        Hashtable(): tableSize(SIZE), currentsize(0)
        {
            hashArray.resize(tableSize, NULL);
            dummyItem = new item;
            dummyItem->data = -1;
            dummyItem->key = -1;
        }

        ~Hashtable()
        {
            for(auto i: hashArray)
            {
                if(i != NULL && i != dummyItem)
                {
                    delete i;
                }

            }
            delete dummyItem;
        }

        item* serach(int key)
        {
            int hashIndex = hashCode(key);
            while(hashArray[hashIndex] != NULL)
            {
                if(hashArray[hashIndex]!= dummyItem && hashArray[hashIndex] -> key == key)
                {
                    return hashArray[hashIndex];
                }
                hashIndex = hashIndex%tableSize;
            }
            return NULL;
        }

        void insert(int key, int value)
        {
            if(loadFactor() > THRESHOLD)
            {
                resizeTable();
            }

            item* newItem = new item;
            newItem->key = key;
            newItem->data= value;

            int hashIndex = hashCode(key);

            while(hashArray[hashIndex] != NULL && hashArray[hashIndex] != dummyItem && hashArray[hashIndex]->key != -1)
            {
                if(hashArray[hashIndex]->key == key)
                {
                    delete newItem;
                    hashArray[hashIndex]->data = value;
                    return;
                }
                hashIndex = hashIndex % tableSize;
            }
            hashArray[hashIndex] = newItem;
            currentsize++;
        }

        item* deleteItem(int key)
        {
            int hashIndex = hashCode(key);
            while(hashArray[hashIndex]!= NULL)
            {
                if(hashArray[hashIndex] != dummyItem && hashArray[hashIndex] -> key == key)
                {
                    item* temp = hashArray[hashIndex];
                    hashArray[hashIndex] = dummyItem;
                    currentsize--;
                    return temp;
                }
                hashIndex = hashIndex % tableSize;
            }
            return NULL;
        }

        void display()
        {
            for(int i =0; i<tableSize; i++)
            {
               if (hashArray[i] != nullptr && hashArray[i] != dummyItem)
                cout << " (" << hashArray[i]->key << "," << hashArray[i]->data << ")"; // Print key-value pair
                else
                    cout << " ~~ ";
            }
            cout<<endl;
        }
};

int main()
{
    Hashtable hashTable;
    hashTable.insert(1, 20);
    hashTable.insert(2, 70);
    hashTable.insert(42, 80);
    hashTable.insert(4, 25);
    hashTable.insert(12, 44);
    hashTable.insert(14, 32);
    hashTable.insert(17, 11);
    hashTable.insert(13, 78);
    hashTable.insert(37, 97);

     // Search for an element
    int ele = 37;
    cout << "Searching for element: " << ele;
    item* item = hashTable.serach(ele);
    if (item != nullptr) {
        cout << "\nElement found: (" << item->key << ", " << item->data << ")";
    } else {
        cout << "\nElement not found";
    }

    // Delete an element
    hashTable.deleteItem(ele);
    cout << "\nHash Table contents after deletion: ";
    hashTable.display();

    return 0;
}