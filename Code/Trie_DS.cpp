#include <bits/stdc++.h>
#include<string>
using namespace std;

//Node Created
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    // Constructor
    TrieNode(char ch)
    {
        data = ch;
        // Initialize children array to NULL
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false; // Initially, not a terminal node
    }
};

// Trie Class Defined
class Trie
{
    public:
        TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode *root, string word)
    {
        //Base Case
        if (word.length() == 0)
        {
            root -> isTerminal = true; 
            return;
        }

        int index = word[0] - 'A'; 
        TrieNode *child;

        
        if (root->children[index] != NULL)
        {
            child = root->children[index]; 
        }
        else
        {
            child = new TrieNode(word[0]); 
            root -> children[index] = child; 
        }
        insertUtil(child, word.substr(1));
    }
 
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    // Utility function to search for a word in the trie
    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'A'; // Assuming All letters are Caps
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
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
};
// Main function
int main()
{
    Trie *t = new Trie(); // Object Created

    string WordToInsert;
    cout << "Enter Word To Insert" << endl;
    cin >> WordToInsert;
    t -> insertWord(WordToInsert);
    
    string WordToSearch;
    cout << "Enter Word To Search" << endl;
    cin >> WordToSearch;
  
    int n;
    n = t -> searchWord(WordToSearch);

    if (n == 1)
    {
        cout << "The Word is Present" << endl;
    }

    else
    {
        cout << "The Word is Not Present" << endl;
    }

    return 0;
}
