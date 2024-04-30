/**
 * @file test.cpp
 * @author <Brendan Shiroma> <129846870>
 * @brief This is the cpp file test.cpp that is used to test the other cpp files
 * @date 2024-04-30
 */
#include <iostream>
#include "BinarySearchTree.h"
#include "HashTable.h"

void testBinarySearchTree() {
    // Test BinarySearchTree
    BST_NS::BinarySearchTree<int> bst;

    // Test insertion
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    // Test traversals
    std::cout << "In-order traversal: ";
    bst.inOrderShow(); // Should output 3 5 7 10 12 15 18
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    bst.preOrderShow(); // Should output 10 5 3 7 15 12 18
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    bst.postOrderShow(); // Should output 3 7 5 12 18 15 10
    std::cout << std::endl;

    // Test size and height
    std::cout << "Tree size: " << bst.size() << std::endl; // Should output 7
    std::cout << "Tree height: " << bst.height() << std::endl; // Should output 2

    // Test removal
    bst.remove(5);
    std::cout << "In-order traversal after removing 5: ";
    bst.inOrderShow(); // Should output 3 7 10 12 15 18
    std::cout << std::endl;

    // Test searching
    std::cout << "Is 7 in tree? " << (bst.inTree(7) ? "Yes" : "No") << std::endl; // Should output Yes
    std::cout << "Is 5 in tree? " << (bst.inTree(5) ? "Yes" : "No") << std::endl; // Should output No
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
    std::cout << "Is 'apple' in hash table? " << (ht.containsString("apple") ? "Yes" : "No") << std::endl; // Should output Yes
    std::cout << "Is 'grape' in hash table? " << (ht.containsString("grape") ? "Yes" : "No") << std::endl; // Should output No
}

int main() {
    std::cout << "Testing BinarySearchTree..." << std::endl;
    testBinarySearchTree();
    std::cout << std::endl;

    std::cout << "Testing LinkedList..." << std::endl;
    testLinkedList();
    std::cout << std::endl;

    std::cout << "Testing HashTable..." << std::endl;
    testHashTable();
    std::cout << std::endl;

    return 0;
}
