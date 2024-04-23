#include "LinkedList.h"


namespace LinkedListNS {
    template<class T>
    
    void headInsert(Node<T>*& head, const T& theData) {
        Node<T> *newNode = new Node(theData);
        Node<T> *oldHead = Node->head;
        head->newNode;
        newNode->next = oldHead;
    }

    template<class T>
    void insert(Node<T>* afterMe, const T& theData) {
        Node<T> *newNode = new Node(theData);
        afterMe->next = newNode;
        newNode->next = afterMe->next->next;
    }

    template<class T>
    void deleteNode(Node<T>* before) {
        Node<T> *temp = before->next;
        before->next = before->next->next;
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
        if (head->data == nullptr) {
            return NULL;
        }
        Node<T> *curr = head;
        while (curr != nullptr) {
            if (curr->data == target) {
                return curr;
            }
            curr = curr->next;
        }
        return NULL;
    }

    
} // namespace LinkedListNS


