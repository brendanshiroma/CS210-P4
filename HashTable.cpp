/**
 * @file HashTable.cpp
 * @author <Brendan Shiroma> <129846870>
 * @brief This is the cpp file HashTable.cpp
 * @date 2024-04-30
 */
#include "HashTable.h"

namespace HashTableNS {

    /**
     * @brief Construct a new HashTable object
     * 
     * @note initializes an array of size 10, with each bucket's value being nullptr
    */
    HashTable::HashTable() {
        // Initialize hashArray to nullptr
        for (int i = 0; i < SIZE; ++i) {
            hashArray[i] = nullptr;
        }
    }

    /**
     * @brief deletes all the linked lists in HashTable
    */
    HashTable::~HashTable() {
        // Delete all linked lists in hashArray
        for (int i = 0; i < SIZE; ++i) {
            delete hashArray[i];
        }
    }

    /**
     * @brief adds a string into HashTable using chaining
     * 
     * @param s string object to be inserted
    */
    void HashTable::put(string s) {
        int hashValue = computeHash(s);
        if (hashArray[hashValue] == nullptr) {
            hashArray[hashValue] = new Node<string>(s, nullptr); // if nothing in bucket, map to bucket
        } else {
            Node<string>* current = hashArray[hashValue];
            while (current->getLink() != nullptr) { // traverses to end of linked list in chaining
                current = current->getLink();
            }
            current->setLink(new Node<string>(s, nullptr)); // maps string into end of linked list in the correct bucket
        }
    }

    /**
     * @brief checks if target is in HashTable
     * 
     * @param target string object trying to be found
     * 
     * @return true if found, false otherwise
    */
    bool HashTable::containsString(string target) const {
        int hashValue = computeHash(target);
        if (hashArray[hashValue] == nullptr) { // if bucket is empty, return false
            return false;
        } else {
            Node<string>* current = hashArray[hashValue];
            while (current != nullptr) {
                if (current->getData() == target) {
                    return true;
                }
                current = current->getLink();
            }
            return false;
        }
    }

    /**
     * @brief maps the string into the proper bucket
     * 
     * @param s the string object used to compute hashcode to input into table
     * 
     * @return the hashcode to properly input into HashTable
    */
    // Compute hash value for string
    int HashTable::computeHash(string s) {
        const int modulo = 193;  // A large prime number for modulo operation
        int hash = 0;
        for (size_t i = 0; i < s.length(); ++i) {
                hash = (hash * 128 + static_cast<int>(s[i])) % modulo; // 128 is the maximum ASCII value for a character
            }
        return hash % SIZE;
    }


} // namespace HashTableNS
