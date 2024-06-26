# TRIE DATA STRUCTURE

In this project we are going to Implement TRIE DATA STRUCTURE using classes in C++.
<br>
<h1>Table Of Contents:</h1>
    <ul style="list-style-type: circle">
        <li>Insertion</li>
        <li>Deletion</li>
        <li>Search Function</li>
    </ul>

<h1>Definiton of TRIE DATA STRUCTURE</h1>
<p>
A trie, also called a prefix tree or radix tree, is a tree-like data structure that stores strings in a way that allows for efficient retrieval</p>
<br>

![trie-datastructure-github-samirpaul1](https://github.com/CybersecurityDSA/trie/assets/143270886/bec5a4fd-7e15-4ef4-b600-dbd9b1e2df33)
<br>
<h2>Applications of TRIE DATA STRUCTURE:</h2>
<p>
    <ul style="list-style-type: circle">
        <li>Sorting Dictionaries</li>
        <li>Auto Complete Features While Typing</li>
        <li>Phone Number Searching</li>
    </ul>
</p>
<h3><b>Phone Directory Application:</b></h3>
<p>In this Project we are Going to Implement Phone Directory by using Trie Data Structure</p>
<P>The phone directory application demonstrates the practical application of the Trie data structure. It allows users to:
    <ul style="list-style-type: circle">
        <li><b>Add Contacts:</b> User can add Contacts along with their Phone Numbers to the directory.</li>
        <li><b>Search Directory:</b>Users can search the entire directory.</li>
    </ul>
</P>
<h3>How it Works ?</h3>
<p>The Trie data structure is implemented using a TrieNode class and a Trie class in C++. Each node in the Trie represents a single character. The TrieNode class contains an array of pointers to child nodes, representing possible next characters in the string. The Trie class provides methods for inserting words into the Trie and retrieving suggestions based on a given prefix.</p>

# Usage:
<p>To use the phone directory application:

    Compile the source code (main.cpp) using a C++ compiler.
    Run the compiled executable.
    Follow the on-screen instructions to add contacts or search the directory.
<br>
</p>

<h2>Time Complexity Analysis of Tries</h2>

<h3>Analysis for Inertion:</h3>
<p>
  - When inserting a key into a trie,the time complexity depends on the length of the key.Let n be the number of characters in the key to be inserted.<br>
   -In the worst-case scenario,each character requires traversing a new edge in the trie.So,the time complexity for insertion is O(n),where n is the length of the key. 
             
</p>
<h3>Analysis for Deletion:</h3>
<p>
  -Deletion in a trie involves traversing down the trie based on the characters of the key to be deleted,similar to insertion.<br>
  -In the worst case,this traversal extends to the length of the key,resulting in a time complexity of O(n),where n is the length of the key.
   
</p>

<h3>Analysis for Search:</h3>
<p>
 -Searching in a trie involves navigating through the trie based on the characters of the searched key.<br>
 -The traversal progresses until either the key is found or a character is not present in the trie.In the worst case,this traversal extends to the length of the key,resulting in a time complexity of O(n),where n is the length of the key being searched.
   
</p>
<img width="500" height="100" alt="image" src="https://github.com/CybersecurityDSA/trie/assets/164031015/7a141570-1a8f-4e77-8bba-1df6470bbf84">
<p>
   In the above time complexity table 'n' and 'm' represents the size of the string and the number of strings that are stored in the trie.
</p>





