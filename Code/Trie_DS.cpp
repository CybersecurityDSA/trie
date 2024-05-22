#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode{
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode(){
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; ++i)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie() : root(nullptr) {}

    void insertWord(const string &word)
    {
        TrieNode **curr = &root;
        for (int i = 0; i < word.length(); i++)
        {
            std::cout << *curr << " ";
            if(*curr == nullptr){
                *curr = new TrieNode();
            }
            int index = word[i] - 'a';
            curr = &((*curr)->children[index]);
        }
        if(*curr == nullptr){
            std::cout << *curr << " \n";
            *curr = new TrieNode();
        }
        (*curr)->isEndOfWord = true;
    }

    bool searchWord(const string &word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (curr == nullptr){
                return false;
            }
            curr = curr->children[index];
        }
        return curr != nullptr && curr->isEndOfWord;
    }

    bool DeleteWordUtil(TrieNode*& current, const string &word, int depth)
    {
        if(depth >= word.length() && current->isEndOfWord){
            current->isEndOfWord = false;
            for(int i = 0; i < ALPHABET_SIZE; i++){
                if (current->children[i] != nullptr){
                    return true;
                }
            }
            delete current;
            current = nullptr;
            return true;
        }
        if(depth >= word.length()) {
            return false;
        }

        if (current == nullptr){
            return false;
        }

        int index = word[depth] - 'a';

        if(DeleteWordUtil(current->children[index], word, depth + 1)){

            if(current->isEndOfWord){
                return true;
            }

            for(int i = 0; i < ALPHABET_SIZE; i++){
                if (current->children[i] != nullptr){
                    return true;
                }
            }
            delete current;
            current = nullptr;
            return true;
        }
        return false;
    }

    bool deleteWord(const string &word){
        return DeleteWordUtil(root, word, 0);
    }

    void free_handler(TrieNode* current){
        if(current == nullptr){
            return;
        }
        for(int i=0; i < ALPHABET_SIZE; i++){
            free_handler(current->children[i]);
        }
        delete current;
    }

    ~Trie(){
        free_handler(root);
    }
};

int main()
{
    Trie trie = Trie();
    int choice = 0;
    string word;
    while(1){
        cout << "\nMenu: \n";
        cout << "1. Insert Word\n";
        cout << "2. Search Word\n";
        cout << "3. Delete Word\n";
        cout << "4. Exit\n";
        cout << "Enter your Choice: ";
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        switch (choice)
        {
        case 1:
            cout << "Enter Word To Insert: ";
            cin >> word;
            trie.insertWord(word);
            break;
        case 2:
            cout << "Enter Word To Search: ";
            cin >> word;
            if (trie.searchWord(word))
            {
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
            if (trie.deleteWord(word))
            {
                cout << "Word Deleted\n";
            }
            else
            {
                cout << "Error: Word Not Deleted\n";
            }
            break;
        case 4:
            cout << "Exiting Program...\n";
            return 0;
        default:
            cout << "Invalid Choice\n";
        }
    }
}