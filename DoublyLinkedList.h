#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void append(const T& value);
    void printList() const;
    void remove(typename DoublyLinkedList<T>::Node* node);
    typename DoublyLinkedList<T>::Node* find(const T& value) const;
    typename DoublyLinkedList<T>::Node* getHead() const;
    typename DoublyLinkedList<T>::Node* getTail() const;

private:
    class Node {
    public:
        T data;
        Node* next;
        Node* prev;
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
};

#include "DoublyLinkedList.inl"

#endif // DOUBLYLINKEDLIST_H
