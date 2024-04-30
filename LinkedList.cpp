/**
 * @file LinkedList.cpp
 * @author <Brendan Shiroma> <129846870>
 * @brief This is the cpp file LinkedList.cpp
 * @date 2024-04-30
 */
#include "LinkedList.h"

namespace LinkedListNS {

    /**
     * @brief Inserts the data at the head
     * 
     * @param head
     * @param theData generic data type to be inserted
    */
    template<class T>
    void headInsert(Node<T>*& head, const T& theData) {
        Node<T> *newNode = new Node<T>(theData, head);
        head = newNode;
    }
    /**
     * @brief Inserts the data after the specified node
     * 
     * @param afterMe node to insert the data after
     * @param theData generic data type to be inserted
    */
    template<class T>
    void insert(Node<T>* afterMe, const T& theData) {
        Node<T> *newNode = new Node<T>(theData, afterMe->getLink());
        afterMe->setLink(newNode);
    }
    /**
     * @brief deletes the node before the specified node
     * 
     * @param before the node before the node to delete
    */
    template<class T>
    void deleteNode(Node<T>* before) {
        if (before == nullptr || before->getLink() == nullptr) {
            return;
        }
        Node<T> *temp = before->getLink();
        before->setLink(temp->getLink());
        delete temp;
    }
    /**
     * @brief deletes the head of the linked list, and sets the head to the node after head
     * 
     * @param head the node to be deleted
    */
    template<class T>
    void deleteFirstNode(Node<T>*& head) {
        if (head == nullptr) {
            return;
        }
        Node<T> *temp = head;
        head = head->getLink();
        delete temp;
    }
    /**
     * @brief searches for specified node, starting at the head
     * 
     * @param head starting point in traversal
     * @param target generic data value to search for
     * 
     * @return the node which contains the target, and nullptr otherwise
    */
    template<class T>
    Node<T>* search(Node<T>* head, const T& target) {
        Node<T> *curr = head;
        while (curr != nullptr) {
            if (curr->getData() == target) {
                return curr;
            }
            curr = curr->getLink();
        }
        return nullptr;
    }

} // namespace LinkedListNS
