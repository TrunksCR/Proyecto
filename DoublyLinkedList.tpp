#include "DoublyLinkedList.h"
#include <iostream>

// Helper function to swap nodes
template <typename T>
void DoublyLinkedList<T>::swap(Node* a, Node* b) {
    T temp = *a->data;
    *a->data = *b->data;
    *b->data = temp;
}

template <typename T>
void DoublyLinkedList<T>::append(const T& value) {
    Node* newNode = new Node(value);
    if (tail) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        head = tail = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::quickSort() {
    if (!head || !tail) return;
    quickSort(head, tail);
}

template <typename T>
void DoublyLinkedList<T>::quickSort(Node* low, Node* high) {
    if (low && high && low != high && low != high->next) {
        Node* p = partition(low, high);
        quickSort(low, p->prev);
        quickSort(p->next, high);
    }
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::partition(Node* low, Node* high) {
    T pivot = *high->data;
    Node* i = low->prev;

    for (Node* j = low; j != high; j = j->next) {
        if (*j->data < pivot) {
            i = (i == nullptr) ? low : i->next;
            swap(i, j);
        }
    }
    i = (i == nullptr) ? low : i->next;
    swap(i, high);
    return i;
}

template <typename T>
void DoublyLinkedList<T>::bubbleSort() {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next) {
            if (*current->data > *current->next->data) {
                swap(current, current->next);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

template <typename T>
void DoublyLinkedList<T>::insertionSort() {
    if (!head) return;
    Node* sorted = nullptr;
    Node* current = head;
    while (current) {
        Node* next = current->next;
        if (!sorted || *sorted->data >= *current->data) {
            current->next = sorted;
            if (sorted) sorted->prev = current;
            sorted = current;
            sorted->prev = nullptr;
        } else {
            Node* temp = sorted;
            while (temp->next && *temp->next->data < *current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next) temp->next->prev = current;
            temp->next = current;
            current->prev = temp;
        }
        current = next;
    }
    head = sorted;
    tail = nullptr;
    while (sorted) {
        tail = sorted;
        sorted = sorted->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::printList() const {
    Node* current = head;
    while (current) {
        std::cout << *current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
