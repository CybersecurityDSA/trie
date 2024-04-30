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

 bool deleteUtil(TrieNode*root,string word,int depth)
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
            root->children[index] = NULL;
        }

        for(int i=0;i<26;i++)
            {
                if(root->children[i] != NULL)
                    return false;
            }

        if (!root->isTerminal)
            return true;

        return false;

    }

    bool deleteWord(string word)
    {
        return deleteUtil(root,word,0);
    }

};


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
    int choice;
    string word;
    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Insert Word\n";
        cout << "2. Search Word\n";
        cout << "3. Delete Word\n";
        cout << "4. Exit\n";
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter Word To Insert: ";
                cin >> word;
                word = LowerToUppercasestring(word);
                t->insertWord(word);
                break;
            case 2:
                cout << "Enter Word To Search: ";
                cin >> word;
                word = LowerToUppercasestring(word);
                if (t->searchWord(word)) {
                    cout << "The Word is Present\n";
                }   
                else 
                {
                    cout << "The Word is Not Present\n";
                }
                break;
            case 3:
                cout << "Enter Word To Delete: ";
                cin >> word;
                word = LowerToUppercasestring(word);
                if (t->deleteWord(word)) {
                    cout << "Word Deleted\n";
                }
                else
                {
                    cout << "Error: Word Not Deleted\n";
                }
                break;
            case 4:
                cout << "Exiting Program...\n";
                break;
            default:
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}   
