#include <iostream>
#include<string>
#include<cctype>
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
 bool deleteUtil(Trie*root,string word,int depth)
    {
         if (depth == word.length())
         {
            if(root->isTerminal)
              root->isTerminal=false;
           
             for(int i=0;i<26;i++)
               {
                   if (root->children[i] != NULL)
                       return false;
               }
             
                return true;
           }

        int index = word[depth] -'A';


        if(root->children[index]==NULL)
            return false;

        bool shouldDeleteCurrentNode = deleteUtil(root->children[index],word,depth+1);

        if(shouldDeleteCurrentNode)
        {
            delete root->children[index];
            root->children[index]=NULL;
        }

        

    }



string LowerToUppercasestring(string WordToInsert)
{
    string wordinCaps;
    for(char c : WordToInsert) {
        if (islower(c)) {
            wordinCaps += toupper(c);
        }else {
            wordinCaps += c;
        }
    }
    return wordinCaps;
}
// Main function
int main()
{
    Trie *t = new Trie(); // Object Created

    string WordToInsert;
    cout << "Enter Word To Insert" << endl;
    cin >> WordToInsert;

    WordToInsert = LowerToUppercasestring(WordToInsert);

    t -> insertWord(WordToInsert);
    
    string WordToSearch;
    cout << "Enter Word To Search" << endl;
    cin >> WordToSearch;
    WordToSearch = LowerToUppercasestring(WordToSearch);
  
    

    if (t -> searchWord(WordToSearch))
    {
        cout << "The Word is Present" << endl;
    }

    else
    {
        cout << "The Word is Not Present" << endl;
    }

    return 0;
}
