// Include necessary libraries
#include<bits/stdc++.h>
#include<stack>
using namespace std;

// Creation of Node
class TrieNode {
    public:
        char data; // Character stored in the node
        TrieNode* children[26]; // Array to hold pointers to children nodes
        bool isTerminal; // Flag to indicate if a word ends at this node

  // Constructor
        TrieNode(char ch)
        {
          
            data = ch;
                  // Initialize children array to NULL  
            for(int i = 0;i<26;i++)
            {
                children[i] = NULL;
            }
           
            isTerminal = false; // Initially, not a terminal node

        }

};

// Trie class definition
class Trie {
    public:
        TrieNode* root; // Pointer to the root of the trie

// Utility function to insert a word into the trie

    void insertUtil(TrieNode* root, string word){
        
        if(word.length() == 0){
            root -> isTerminal = true; // Mark current node as terminal if word ends here
        }
        
        int index = word[0] -'A'; // Convert character to index
        TrieNode* child;
        
        // Check if child node already exists for the character
        if( root -> children[index] != NULL) {
            child  = root->children[index]; // If yes, get the existing child node
        }
        else{
            child = new TrieNode(word[0]); // If not, create a new child node
            root ->children[index] = child; // Link the child node to the parent
        }

    }
// Function to insert a word into the trie
    void insertWord(string word){
        insertUtil(root,word);

    }
 // Utility function to search for a word in the trie
  bool searchUtil(TrieNode* root, string word){
      if(word.length() == 0){
          return root->isTerminal; // If word is empty, check if current node is terminal
      }
        int index = word[0] - 'A'; // Convert character to index
        TrieNode* child;
      
      // Check if child node exists for the character
      if(root->children[index] !=NULL){
          child = root->children[index]; // If yes, get the child node
      }
      else{
          return false; // If not, word does not exist in the trie
      }

      return searchUtil(child, word.substr(1));
  }


    bool search(string word){
        retun searchUtil(root,word);
    }

};
// Main function
int main()
{
    Trie *t = new Trie(); //Object Created
    t->insertWord("abcd");

    return 0;
    
    
}
