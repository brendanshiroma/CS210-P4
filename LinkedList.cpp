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
