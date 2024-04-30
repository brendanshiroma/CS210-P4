/**
 * @file LinkedList.cpp
 * @author <Brendan Shiroma> <129846870>
 * @brief This is the cpp file LinkedList.cpp
 * @note This contians the implementations of the functions given from linked
 * This contains type definitions and function declarations for manipulating a linked
 *       list to store data of any type (T). The linked list is given as a pointer of type
 *       Node<T>* which points to the head (first) node of the list. The implementation of
 *       the functions are given in the file "LinkedList.cpp"
 */
#include "LinkedList.h"

namespace LinkedListNS {

    template<class T>
    void headInsert(Node<T>*& head, const T& theData) {
        Node<T> *newNode = new Node<T>(theData, head);
        head = newNode;
    }

    template<class T>
    void insert(Node<T>* afterMe, const T& theData) {
        Node<T> *newNode = new Node<T>(theData, afterMe->getLink());
        afterMe->setLink(newNode);
    }

    template<class T>
    void deleteNode(Node<T>* before) {
        if (before == nullptr || before->getLink() == nullptr) {
            return;
        }
        Node<T> *temp = before->getLink();
        before->setLink(temp->getLink());
        delete temp;
    }

    template<class T>
    void deleteFirstNode(Node<T>*& head) {
        if (head == nullptr) {
            return;
        }
        Node<T> *temp = head;
        head = head->getLink();
        delete temp;
    }

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
