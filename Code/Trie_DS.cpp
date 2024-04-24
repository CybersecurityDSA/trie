// Include necessary libraries
#include<bits/stdc++.h>
#include<stack>
using namespace std;

// Creation of Node
class TrieNode {
    public:
        char data; 
        TrieNode* children[26]; 
        bool isTerminal; 

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

//Trie Class Defined
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
          return root->isTerminal; 
      }
        int index = word[0] - 'A'; //Assuming All letters are Caps
        TrieNode* child;
      
      if(root->children[index] !=NULL){
          child = root -> children[index]; 
      }
      else{
          return false;
      }

      return searchUtil(child, word.substr(1));
  }


    bool searchWord(string word){
        return searchUtil(root,word);
    }

};
// Main function
int main()
{
    Trie *t = new Trie(); //Object Created
    string WordToInsert;
    cout << "Enter Word To Insert" << endl;
    cin >> WordToInsert;
    t -> insertWord(WordToInsert);
    string WordToSearch;
    cout << "Enter Word To Search" << endl;
    cin >> WordToSearch;
    n = t -> searchWord(WordToSearch);
    if (n == 1){
        cout << "The Word is Present" <<endl;
    }
        
    else{
        cout << "The Word is Not Present" <<endl;
    }
    
    return 0;
    
}
