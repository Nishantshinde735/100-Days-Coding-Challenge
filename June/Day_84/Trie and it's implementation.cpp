#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Define a Trie node structure
struct TrieNode {
    // Array of child nodes (one for each character)
    vector<unique_ptr<TrieNode>> children;
    // Flag to indicate the end of a word
    bool isEndOfWord;

    // Constructor (initialize children and endOfWord)
    TrieNode() : children(26, nullptr), isEndOfWord(false) {}
};

class Trie {
private:
    unique_ptr<TrieNode> root;

public:
    Trie() : root(make_unique<TrieNode>()) {} // Create a root node

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* current = root.get();
        for (char c : word) {
            int index = c - 'a'; // Get the index for the character (assuming lowercase alphabet)
            if (!current->children[index]) {
                current->children[index] = make_unique<TrieNode>();
            }
            current = current->children[index].get();
        }
        current->isEndOfWord = true;
    }

    // Search for a word in the Trie (returns true if found, false otherwise)
    bool search(const string& word) const {
        TrieNode* current = root.get();
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index]) {
                return false; // Word not found in the Trie
            }
            current = current->children[index].get();
        }
        return current->isEndOfWord;
    }

    // Check if a given prefix exists in the Trie
    bool startsWith(const string& prefix) const {
        TrieNode* current = root.get();
        for (char c : prefix) {
            int index = c - 'a';
            if (!current->children[index]) {
                return false; // Prefix not found in the Trie
            }
            current = current->children[index].get();
        }
        return true; // Prefix found
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("ape");
    trie.insert("application");

    cout << "apple found: " << trie.search("apple") << endl;
    cout << "ape found: " << trie.search("ape") << endl;
    cout << "app found: " << trie.search("app") << endl; // Not a full word
    cout << "application found: " << trie.search("application") << endl;
    cout << "app starts with 'app': " << trie.startsWith("app") << endl;

    return 0;
}
