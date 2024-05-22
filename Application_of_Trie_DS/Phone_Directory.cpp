#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

struct TrieNode {
    TrieNode* children[10];
    string name;

    TrieNode() {
        name = "";
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    void free_handler(TrieNode* current){
        if(current == nullptr){
            return;
        }
        for(int i=0; i < 10; i++){
            free_handler(current->children[i]);
        }
        delete current;
    }
public:
    TrieNode *root;

    Trie() : root(nullptr) {}

    void insert_Contact(const string &name, const string &word)
    {
        TrieNode **curr = &root;
        for (int i = 0; i < word.length(); i++)
        {
            std::cout << *curr << " ";
            if(*curr == nullptr){
                *curr = new TrieNode();
            }
            int index = word[i] - '0';
            curr = &((*curr)->children[index]);
        }
        if(*curr == nullptr){
            std::cout << *curr << " \n";
            *curr = new TrieNode();
        }
        (*curr)->name = name;
    }

    void print_handler(TrieNode* current, string phone){
        if(current == nullptr){
            return;
        }

        if(current->name != "") {
            std::cout << current->name << ": " << phone << "\n";
        }

        for (int i = 0; i < 10; i++){
            phone.push_back(i + '0');
            print_handler(current->children[i], phone);
            phone.pop_back();
        }
    }

    void print_trie(){
        print_handler(root, "");
    }

    string searchname(const string &word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            int index = c - '0';
            if (curr == nullptr){
                return "";
            }
            curr = curr->children[index];
        }
        if(curr==nullptr || curr->name == ""){
            return "";
        }
        return curr->name;
    }

    bool DeleteWordUtil(TrieNode*& current, const string &word, int depth)
    {
        if (current == nullptr)
            return false;

        if (depth == word.length()) {
            if (!current->name.empty()) {
                current->name = "";
                for (int i = 0; i < 10; ++i) {
                    if (current->children[i] != nullptr)
                        return false;
                }
                delete current;
                current = nullptr;
                return true;
            }
            return false;
        }

        int index = word[depth] - '0';
        if (DeleteWordUtil(current->children[index], word, depth + 1)) {
            for (int i = 0; i < 10; ++i) {
                if (current->children[i] != nullptr)
                    return false;
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

    ~Trie(){
        free_handler(root);
    }
};

int main() {
    Trie t;
    int choice;

    while(1){
        cout << "\nMenu:\n1. Add Contact\n2. Search Directory\n3. Delete Contact\n4. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string contact, phoneNumber;
                cout << "Enter contact name to add: ";
                cin>> contact;
                cout << "Enter contact number: ";
                cin >> phoneNumber;
                t.insert_Contact(contact, phoneNumber);
                cout << "Contact added successfully!\n";
                break;
            }
            case 2: {
                string phone;
                cout << "Enter query string to search: ";
                cin >> phone;
                string temp = t.searchname(phone);
                if(temp != ""){
                    std::cout << "Found contact: " << temp << "\n";
                } else {
                    std::cout << "Contact not found!\n";
                }
                break;
            }
            case 3:{
                string phone;
                cout << "Enter the phone number to delete: ";
                cin >> phone;
                if(t.deleteWord(phone)){
                    cout << "Successfully Deleted Contact!\n";
                } else {
                    cout << "Contact not deleted!\n";
                }
                break;
            }
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}