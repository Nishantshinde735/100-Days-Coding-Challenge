#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int count;
    TrieNode() : count(0) {}
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->count++;
        }
    }
    
    string longestCommonPrefix(int n) {
        TrieNode* node = root;
        string prefix = "";
        while (node && node->count == n) {
            if (node->children.size() != 1) break;
            for (auto it : node->children) {
                prefix += it.first;
                node = it.second;
            }
        }
        return prefix;
    }
};

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    Trie trie;
    for (string str : strs) {
        trie.insert(str);
    }
    return trie.longestCommonPrefix(strs.size());
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;
    return 0;
}
