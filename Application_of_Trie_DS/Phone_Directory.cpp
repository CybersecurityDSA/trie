#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Node Created
class TrieNode
{
public:
    char data;
    TrieNode *children[128];
    bool isTerminal;
    string phoneNumber;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 128; i++)
        {
            children[i] = nullptr;
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
    void insertUtil(TrieNode *root, string word, string phoneNumber)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            root->phoneNumber = phoneNumber;
            return;
        }
        int index = word[0];
        TrieNode *child;
        if (root->children[index] != nullptr)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1), phoneNumber);
    }
    void insertWord(string word, string phoneNumber)
    {
        insertUtil(root, word, phoneNumber);
    }

    void printSuggestions(TrieNode *curr, vector<pair<string, string>> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(make_pair(prefix, curr -> phoneNumber));
        }
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch];
            if (next != nullptr)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<pair<string, string>>> getSuggestions(string str)
    {
        TrieNode *prev = root;
        vector<vector<pair<string, string>>> output;
        string prefix = "";
        for (int i = 0; i < str.length(); i++)
        {
            char lastch = str[i];
            prefix.push_back(lastch);
            //check for lastch
            TrieNode *curr = prev->children[lastch];
            //if not found
            if (curr == nullptr)
            {
                break;
            }
            //if found
            vector<pair<string, string>> temp;
            printSuggestions(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }

    ~Trie()
    {
        deleteTrie(root);
    }

private:
    void deleteTrie(TrieNode *node)
    {
        if (node == nullptr)
            return;
        for (int i = 0; i < 128; i++)
        {
            if (node->children[i] != nullptr)
            {
                deleteTrie(node->children[i]);
            }
        }
        delete node;
    }
};

vector<vector<pair<string, string>>> phoneDirectory(vector<pair<string, string>> &contactList, string &queryStr)
{
    //creation of trie
    Trie *t = new Trie();
    //insert all contact in Trie
    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i].first;
        string phoneNumber = contactList[i].second;
        t->insertWord(str, phoneNumber);
    }
    //return ans
    return t->getSuggestions(queryStr);
}

int main()
{
    vector<pair<string, string>> contactList;
    string queryStr;

    char choice;
    do
    {
        cout << "\nMenu:\n1. Add Contact\n2. Search Directory\n3. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character from previous input

        switch (choice)
        {
        case '1':
        {
            string contact, phoneNumber;
            cout << "Enter contact name to add: ";
            getline(cin, contact);
            cout << "Enter contact number: ";
            getline(cin, phoneNumber);
            contactList.push_back(make_pair(contact, phoneNumber));
            cout << "Contact added successfully!" << endl;
            break;
        }
        case '2':
        {
            cout << "Enter query string to search: ";
            getline(cin, queryStr);
            vector<vector<pair<string, string>>> suggestions = phoneDirectory(contactList, queryStr);
            cout << "Suggestions:" << endl;
            for (const auto &group : suggestions)
            {
                for (const auto &contact : group)
                {
                    cout << "Name: " << contact.first << ", Phone Number: " << contact.second << endl;
                }
            }
            break;
        }
        case '3':
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '3');

    return 0;
}
