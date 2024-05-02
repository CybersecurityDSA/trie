#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Node Created
class TrieNode
{
public:
    char data;
    TrieNode *children[128];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0;i < 128;i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
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
        void insertUtil(TrieNode *root,string word)
        {
            if (word.length() == 0)
            {
                root -> isTerminal = true;
                return;
            }
            int index = word[0];
            TrieNode *child;
            if (root -> children[index] != NULL)
            {
                child = root -> children[index];
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
            insertUtil(root,word);
        }
        bool searchUtil(TrieNode *root, string word)
        {
            if (word.length() == 0)
            {
                return root -> isTerminal;
            }
            int index = word[0];
            TrieNode *child;

            if (root -> children[index] != NULL)
            {
                child = root -> children[index];
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
        bool deleteUtil(TrieNode *root, string word, int depth)
        {
            if (depth == word.length())
            { 
                if (!root -> isTerminal)
                    return false;
                root -> isTerminal = false;

                for (int i = 0;i < 128;i++)
                {
                    if (root -> children[i] != NULL)
                        return false;
                }
                return true;
            }
            int index = word[depth];

            if (root -> children[index] == NULL)
                return false;

            bool shouldDeleteCurrentNode = deleteUtil(root -> children[index], word, depth + 1);

            if (shouldDeleteCurrentNode)
            {
                delete root -> children[index];
                root -> children[index] = NULL;
            }

            for (int i = 0;i < 128;i++)
            {

                if (root -> children[i] != NULL)
                    return false;
            }
            if (!root -> isTerminal)
            
                return true;
            return false;
        }

        bool deleteWord(string word)
        {
            return deleteUtil(root, word, 0);
        }
};

// Main Function

int main()
{
    Trie *t = new Trie(); // Object Created
    int choice;
    string word;
    do
    {
        cout << "\nMenu: \n";
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
                t -> insertWord(word);
                break;
            case 2:
                cout  << "Enter Word To Search: ";
                cin >> word;
                if (t -> searchWord(word))
                {
                    cout  << "The Word is Present\n";
                }
                else
                {
                    cout  << "The Word is Not Present\n";
                }
                break;
            case 3:
                cout << "Enter Word To Delete: ";
                cin >> word;
                if (t -> deleteWord(word))
                {
                    cout << "Word Deleted\n";
                }
                else
                {
                    cout << "Error: Wprd Not Deleted\n";
                }
                break;
            case 4:
                cout  << "Exiting Program...\n";
            default:
            cout  << "Invalid Choice\n";
        }
    } while (choice != 4);

    return 0;
}