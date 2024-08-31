#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
    char data;
    int childCount;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i = 0; i<26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

   void insertUtil(TrieNode* root, string word)
   {
        if(word.length() == NULL)
        {
            root->isTerminal = true;
            return;
        }

        //assumption: word will be in all lower
        int index = word[0] - 'a';
        TrieNode* child;

        //present
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        //not present, need to enter
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }
        //recursive call to insert
        insertUtil(child, word.substr(1));
   } 

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for(int i = 0; i<str.length(); i++)
        {
            char ch = str[i];

            if(root->childCount == 1)
            {
                ans.push_back(ch);
                //go ahead
                int index = ch -'a';
                root = root->children[index];
            }
            else
            {
                break;
            }
            if(root->isTerminal)
            {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie('\0');

    //insert all the strings in the trie
    for(int i = 0; i<n; i++)
    {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);
    return ans;
}

int main()
{

    return 0;
}
