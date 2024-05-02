#include "../code/Trie_DS.cpp"
#include <cassert>

int main() {
  
    Trie t;
    t.insertWord("HELLO");
    assert(t.searchWord("HELLO") == true);

    t.insertWord("WORLD");
    t.insertWord("APPLE");
    assert(t.searchWord("WORLD") == true);
    assert(t.searchWord("APPLE") == true);

    assert(t.searchWord("FOOBAR") == false);

// Test insertion and search
    t.insertWord("hello");
    t.insertWord("CYBER1234");
    t.insertWord("268trie");
    t.insertWord("HeLLo");
    t.insertWord("@#$%^");
    t.insertWord("!DSA");
    t.insertWord("crypto$$");
    t.insertWord("A");
    t.insertWord("pneumonoultramicroscopicsilicovolcanoconiosis");
    t.insertWord("HeLLo1234#");
  

    assert(t.searchWord("hello") == true);
    assert(t.searchWord("CYBER1234") == true);
    assert(t.searchWord("268trie") == true);
    assert(t.searchWord("HeLLo") == true);
    assert(t.searchWord("@#$%^") == true);
    assert(t.searchWord("!DSA") == true);
    assert(t.searchWord("crypto$$") == true);
    assert(t.searchWord("A") == true);
    assert(t.searchWord("pneumonoultramicroscopicsilicovolcanoconiosis") == true);
    assert(t.searchWord("HeLLo1234#") == true);
    assert(t.searchWord("FoodIsImportant!!") == false);


// Test deletion

    assert(t.deleteWord("hello") == true);
    assert(t.deleteWord("@#$%^") == true);
    assert(t.deleteWord("!DSA") == true);
    assert(t.deleteWord("dsa!@") == false);



   // Test edge case
    assert(t.searchWord("Madness") == false);
    assert(t.deleteWord("madNESS") == false);


// Test case sensitivity

    
    t.insertWord("hello");
    t.insertWord("WORLD");
    t.insertWord("HeLLo");

    assert(t.searchWord("hello") == true);
    assert(t.searchWord("HeLLo") == true);
    assert(t.searchWord("WORLD") == true);

    return 0;
}



