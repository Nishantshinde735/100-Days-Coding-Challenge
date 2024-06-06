#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfNumber;
    string contactName;

    TrieNode() {
        isEndOfNumber = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& phoneNumber, const string& contactName) {
        TrieNode* node = root;
        for (char digit : phoneNumber) {
            if (node->children.find(digit) == node->children.end()) {
                node->children[digit] = new TrieNode();
            }
            node = node->children[digit];
        }
        node->isEndOfNumber = true;
        node->contactName = contactName;
    }

    bool search(const string& phoneNumber, string& contactName) {
        TrieNode* node = root;
        for (char digit : phoneNumber) {
            if (node->children.find(digit) == node->children.end()) {
                return false;
            }
            node = node->children[digit];
        }
        if (node->isEndOfNumber) {
            contactName = node->contactName;
            return true;
        }
        return false;
    }

    void displayContacts(TrieNode* node, string prefix) {
        if (node->isEndOfNumber) {
            cout << "Contact: " << node->contactName << ", Phone Number: " << prefix << endl;
        }
        for (auto it : node->children) {
            displayContacts(it.second, prefix + it.first);
        }
    }

    void displayContacts(const string& prefix) {
        TrieNode* node = root;
        for (char digit : prefix) {
            if (node->children.find(digit) == node->children.end()) {
                cout << "No contacts found with this prefix." << endl;
                return;
            }
            node = node->children[digit];
        }
        displayContacts(node, prefix);
    }
};

class PhoneDirectory {
private:
    Trie trie;

public:
    void addContact(const string& phoneNumber, const string& contactName) {
        trie.insert(phoneNumber, contactName);
    }

    void findContact(const string& phoneNumber) {
        string contactName;
        if (trie.search(phoneNumber, contactName)) {
            cout << "Contact found: " << contactName << " with phone number: " << phoneNumber << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }

    void displayContacts(const string& prefix) {
        trie.displayContacts(prefix);
    }
};

int main() {
    PhoneDirectory phoneDirectory;
    phoneDirectory.addContact("1234567890", "Alice");
    phoneDirectory.addContact("1234561234", "Bob");
    phoneDirectory.addContact("9876543210", "Charlie");
    phoneDirectory.addContact("9876543211", "David");

    phoneDirectory.findContact("1234567890");
    phoneDirectory.findContact("1234560000");

    cout << "Contacts with prefix '123':" << endl;
    phoneDirectory.displayContacts("123");

    cout << "Contacts with prefix '987':" << endl;
    phoneDirectory.displayContacts("987");

    cout << "Contacts with prefix '555':" << endl;
    phoneDirectory.displayContacts("555");

    return 0;
}
