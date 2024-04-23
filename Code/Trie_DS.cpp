#include<bits/stdc++.h>
#include<stack>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch)
        {
            data = ch;
            for(int i = 0;i<26;i++)
            {
                children[i] = NULL;
            }
            isTerminal = false;

        }

};


class Trie {
    public:
        TrieNode* root;
    void insertUtil(TrieNode* root, string word){
        
        if(word.length() == 0){
            root -> isTerminal = true;
        }
        
        int index = word[0] -'A';
        TrieNode* child;
        

        if( root -> children[index] != NULL) {
            child  = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root ->children[index] = child;
        }

    }
    void insertWord(string word){

    }

};
int main()
{
    
}
