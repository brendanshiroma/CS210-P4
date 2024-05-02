/**
 * @file test.cpp
 * @author <Brendan Shiroma> <129846870>
 * @brief This is the cpp file test.cpp
 * @date 2024-04-30
 */
#include <iostream>
#include "BinarySearchTree.h"
#include "HashTable.h"
#include "LinkedList.h"

    void testBinarySearchTree() {
        // Test BinarySearchTree
        BST_NS::BinarySearchTree<int> bst;

        // Test insertion and deletion
        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        bst.insert(3);
        bst.insert(7);
        bst.remove(3);
        bst.insert(12);
        bst.remove(10);
        bst.insert(18);

        // Test traversals
        std::cout << "In-order traversal: ";
        bst.inOrderShow(); 
        std::cout << std::endl;

        std::cout << "Pre-order traversal: ";
        bst.preOrderShow(); 
        std::cout << std::endl;

        std::cout << "Post-order traversal: ";
        bst.postOrderShow(); 
        std::cout << std::endl;

        // Test size and height
        std::cout << "Tree size: " << bst.size() << std::endl;
        std::cout << "Tree height: " << bst.height() << std::endl;

        // Test removal
        bst.remove(5);
        std::cout << "In-order traversal after removing 5: ";
        bst.inOrderShow(); 
        std::cout << std::endl;

        // Test searching
        std::cout << "Is 7 in tree? " << (bst.inTree(7) ? "Yes" : "No") << std::endl; // Should output Yes
        std::cout << "Is 5 in tree? " << (bst.inTree(5) ? "Yes" : "No") << std::endl; // Should output No
        bst.remove(15);
        std::cout << "Is 15 in tree? " << (bst.inTree(15) ? "Yes" : "No") << std::endl; // Should output No
    }

    void testLinkedList() {
        // Test LinkedList
        LinkedListNS::Node<int>* head = nullptr;

        // Test insertion
        LinkedListNS::headInsert(head, 10);
        LinkedListNS::insert(head, 20);
        LinkedListNS::insert(head->getLink(), 15);

        // Test traversal
        std::cout << "Linked list: ";
        LinkedListNS::Node<int>* curr = head;
        while (curr != nullptr) {
            std::cout << curr->getData() << " ";
            curr = curr->getLink();
        }
        std::cout << std::endl;

        // Test deletion
        LinkedListNS::deleteNode(head->getLink());
        std::cout << "Linked list after deleting node with data 15: ";
        curr = head;
        while (curr != nullptr) {
            std::cout << curr->getData() << " ";
            curr = curr->getLink();
        }
        std::cout << std::endl;

        // Test deleting first node
        LinkedListNS::deleteFirstNode(head);
        std::cout << "Linked list after deleting first node: ";
        curr = head;
        while (curr != nullptr) {
            std::cout << curr->getData() << " ";
            curr = curr->getLink();
        }
        std::cout << std::endl;

        // Test searching
        LinkedListNS::headInsert(head, 10);
        LinkedListNS::insert(head, 20);
        LinkedListNS::insert(head->getLink(), 15);

        LinkedListNS::Node<int>* searchResult = LinkedListNS::search(head, 20);
        std::cout << "Search result for 20: " << (searchResult != nullptr ? "Found" : "Not found") << std::endl; // Should output Found
        searchResult = LinkedListNS::search(head, 25);
        std::cout << "Search result for 25: " << (searchResult != nullptr ? "Found" : "Not found") << std::endl; // Should output Not found
    }

    void testHashTable() {
        // Test HashTable
        HashTableNS::HashTable ht;

        // Test insertion
        ht.put("apple");
        ht.put("banana");
        ht.put("orange");

        // Test searching
        std::cout << "Is apple in hash table? " << (ht.containsString("apple") ? "Yes" : "No") << std::endl; // Should output Yes
        std::cout << "Is grape in hash table? " << (ht.containsString("grape") ? "Yes" : "No") << std::endl; // Should output No

        ht.put("pear");
        std::cout << "Is pear in hash table? " << (ht.containsString("pear") ? "Yes" : "No") << std::endl; // Should output Yes
    }

    int main() {
        std::cout << "Testing BinarySearchTree: " << std::endl;
        testBinarySearchTree();
        std::cout << std::endl;

        std::cout << "Testing LinkedList: " << std::endl;
        testLinkedList();
        std::cout << std::endl;

        std::cout << "Testing HashTable: " << std::endl;
        testHashTable();
        std::cout << std::endl;

        return 0;
    }
