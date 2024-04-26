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


    return 0;
}
