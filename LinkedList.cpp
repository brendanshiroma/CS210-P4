#include "LinkedList.h"

namespace LinkedListNS {

    template<class T>
    void headInsert(Node<T>*& head, const T& theData) {
        Node<T> *newNode = new Node<T>(theData);
        newNode->next = head;
        head = newNode;
    }

    template<class T>
    void insert(Node<T>* afterMe, const T& theData) {
        Node<T> *newNode = new Node<T>(theData);
        newNode->next = afterMe->next;
        afterMe->next = newNode;
    }

    template<class T>
    void deleteNode(Node<T>* before) {
        if (before == nullptr || before->next == nullptr) {
            return;  // Invalid input, do nothing.
        }
        Node<T> *temp = before->next;
        before->next = temp->next;
        delete temp;
    }


    template<class T>
    void deleteFirstNode(Node<T>*& head) {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }

    template<class T>
    Node<T>* search(Node<T>* head, const T& target) {
        Node<T> *curr = head;
        while (curr != nullptr) {
            if (curr->data == target) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

} // namespace LinkedListNS
