#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "MPointer.h"

template <typename T>
class DoublyLinkedList {
public:
    class Node {
    public:
        Node(const T& value)
            : data(MPointer<T>::New()), next(nullptr), prev(nullptr) {
            *data = value;
        }

        MPointer<T> data;
        Node* next;
        Node* prev;
    };

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(const T& value);
    void quickSort();
    void bubbleSort();
    void insertionSort();
    void printList() const;

private:
    Node* head;
    Node* tail;

    Node* partition(Node* low, Node* high);
    void quickSort(Node* low, Node* high);
    void swap(Node* a, Node* b);
};

#include "DoublyLinkedList.tpp"

#endif // DO
