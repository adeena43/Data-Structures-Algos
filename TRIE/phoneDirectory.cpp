#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
    bool isTerminal;
    TrieNode* children[26];
    char ch;
    TrieNode(char data)
    {
        ch = data;
        for(int i = 0; i<26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
        TrieNode* root;

        Trie(char data)
        {
            root = new TrieNode(data);
        }

        void insertUtil(TrieNode* root, string word)
        {
            //base case
            if(word.length() == NULL)
            {
                root->isTerminal= true;
                return;
            }

            int index = word[0] - 'a';
            TrieNode* child;

            //already present
            if(root->children[index] != NULL)
            {
                child = root->children[index];
            }

            //not present, need to insert
            else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            //recursive call to complete te insertion
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word)
        {
            insertUtil(root, word);
        }

        void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix)
        {
            if(curr->isTerminal)
            {
                temp.push_back(prefix);
            }

            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                TrieNode* next = curr->children[ch-'a'];

                if(next != NULL)
                {
                    prefix.push_back(ch);
                    printSuggestions(next, temp, prefix);
                    prefix.pop_back();
                }
            }
        }

        vector<vector<string> > getSuggestions(string str)
        {
            TrieNode* prev = root;
            vector<vector<string> > output;
            string prefix = " ";

            for(int i = 0; i<str.length(); i++)
            {
                char lastch = str[i];

                prefix.push_back(lastch);

                //check for lastch
                TrieNode* curr = prev->children[lastch-'a'];

                //if not found
                if(curr == NULL)
                {
                    break;
                }

                //if found
                vector<string> temp;
                printSuggestions(curr, temp, prefix);

                output.push_back(temp);
                temp.clear();
                prev = curr;
            }

            return output;
        }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //creation of a trie
    Trie *t = new Trie('\0');

    //insert all contacts in Trie
    for(int i=0; i< contactList.size(); i++)
    {
        string str = contactList[i];
        t->insertWord(str);
    }
    //return ans
    return t->getSuggestions(queryStr);
}
