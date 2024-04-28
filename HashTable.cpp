#include "HashTable.h"

namespace HashTableNS {

    // Default Constructor
    HashTable::HashTable() {
        // Initialize hashArray to nullptr
        for (int i = 0; i < SIZE; ++i) {
            hashArray[i] = nullptr;
        }
    }

    // Destructor
    HashTable::~HashTable() {
        // Delete all linked lists in hashArray
        for (int i = 0; i < SIZE; ++i) {
            delete hashArray[i];
        }
    }

    // Checks if the target is in the hash table
    bool HashTable::containsString(string target) const {
        int hashValue = computeHash(target);
        if (hashArray[hashValue] == nullptr) {
            return false;
        } else {
            return hashArray[hashValue]->contains(target);
        }
    }

    // Adds a new string to the hash table
    void HashTable::put(string s) {
        int hashValue = computeHash(s);
        if (hashArray[hashValue] == nullptr) {
            hashArray[hashValue] = new Node<string>(s, nullptr);
        } else {
            hashArray[hashValue]->insert(s);
        }
    }

    // Compute hash value for string
    int HashTable::computeHash(string s) {
        int hash = 0;
        for (char c : s) {
            hash += c;
        }
        return hash % SIZE;
    }

} // namespace HashTableNS
