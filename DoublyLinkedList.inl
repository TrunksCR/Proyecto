#ifndef DOUBLYLINKEDLIST_INL
#define DOUBLYLINKEDLIST_INL

#include "DoublyLinkedList.h"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    // Destructor implementation
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void DoublyLinkedList<T>::append(const T& value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::printList() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::remove(Node* node) {
    if (!node) return;

    if (node->prev) {
        node->prev->next = node->next;
    } else {
        head = node->next;
    }

    if (node->next) {
        node->next->prev = node->prev;
    } else {
        tail = node->prev;
    }

    delete node;
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::find(const T& value) const {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::getHead() const {
    return head;
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::getTail() const {
    return tail;
}

#endif // DOUBLYLINKEDLIST_INL
