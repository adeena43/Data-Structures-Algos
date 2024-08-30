#include<iostream>
using namespace std;

class TrieNode{
	public:
		char data;
		TrieNode* children[26];
		bool isTerminal;
		
		TrieNode(char ch)
		{
			data = ch;
			for(int i=0; i<26; i++)
			{
				children[i] = NULL;
			}
			isTerminal = false;
		}
		
		~TrieNode()
		{
			for(int i = 0; i<26; i++)
			{
				delete children[i];
			}
		}
};

class Trie{
	public:
		TrieNode* root;
		
		Trie()
		{
			root = new TrieNode('\0');
		}
		
		void insertUtil(TrieNode* root, string word)
		{
			//base case
			if(word.length() == 0)
			{
				root->isTerminal = true;
				return;
			}
			//assumption: word will be in all caps
			int index = word[0]-'A';
			TrieNode* child;
			
			//present
			if(root->children[index] != NULL)
			{
				child = root->children[index];
			}
			
			//absent
			else
			{
				child = new TrieNode(word[0]);
				root->children[index] = child;
			}
			
			//recursive call
			insertUtil(child, word.substr(1));
		}
		void insertWord(string word)
		{
			insertUtil(root, word);
		}
		
		bool searchUtil(TrieNode* root, string word)
		{
			//base case
			if(word.length()==0)
			{
				return root->isTerminal;
			}
			int index = word[0]-'A';
			TrieNode* child;
			
			//present
			if(root->children[index] != NULL)
			{
				child= root->children[index];
			}
			//absent
			else
			{
				return false;
			}
			
			return searchUtil(child, word.substr(1));
		}
		
		bool searchWord(string word)
		{
			return searchUtil(root, word);
		}
		
		bool deleteWord(TrieNode* root, const string& word, int depth = 0)
{
    // Base case: if the word is empty
    if (depth == word.size())
    {
        if (root->isTerminal)
        {
            root->isTerminal = false;
            // Check if node has children
            for (int i = 0; i < 26; i++)
            {
                if (root->children[i] != NULL)
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    int index = word[depth] - 'A';
    TrieNode* child = root->children[index];

    if (child == NULL)
    {
        return false;
    }

    bool shouldDeleteChild = deleteWord(child, word, depth + 1);

    // If the child node should be deleted
    if (shouldDeleteChild)
    {
        delete root->children[index];
        root->children[index] = NULL;

        // Check if current node is a terminal or has other children
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                return false;
            }
        }

        return !root->isTerminal;
    }

    return false;
}



   

void deleteString(const string& word)
{
    if (searchWord(word))
    {
        deleteWord(root, word);
    }
}


 
    bool prefixUtil(root, word){
    	//base case
			if(word.length()==0)
			{
				return true;
			}
			int index = word[0]-'A';
			TrieNode* child;
			
			//present
			if(root->children[index] != NULL)
			{
				child= root->children[index];
			}
			//absent
			else
			{
				return false;
			}
			
			return prefixUtil(child, word.substr(1));
	}
    
    bool searchPrefix(string word)
    {
    	return prefixUtil(root, word);
	}
		
};

int main()
{
	
	Trie *t = new Trie();
	t->insertWord("ARM");
	t->insertWord("ME");
	t->insertWord("DONT");
	t->insertWord("TIMER");
	
	cout<<"Present or not "<<t->searchWord("arm")<<endl;
	
	delete t;
	return 0;
}
