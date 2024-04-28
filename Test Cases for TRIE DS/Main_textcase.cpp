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

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Trie_DS.cpp" 

TEST_CASE("Trie Insertion and Search", "[Trie]") {
    Trie trie;

    // Test insertion and search for a word
    trie.insertWord("hello");
    REQUIRE(trie.searchWord("hello") == true);
    REQUIRE(trie.searchWord("world") == false);

    // Test insertion and search for another word
    trie.insertWord("world");
    REQUIRE(trie.searchWord("world") == true);
    REQUIRE(trie.searchWord("hello") == true); 

    // Test search for a non-existing word
    REQUIRE(trie.searchWord("Cyber") == false);

    // Test insertion and search for words with mixed case
    trie.insertWord("Cyber");
    REQUIRE(trie.searchWord("Cyber") == true);
    REQUIRE(trie.searchWord("Cyber") == true);
}

