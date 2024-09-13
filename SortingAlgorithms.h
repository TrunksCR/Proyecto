#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include "DoublyLinkedList.h"

template <typename T>
void quickSort(DoublyLinkedList<T>& list);

template <typename T>
void bubbleSort(DoublyLinkedList<T>& list);

template <typename T>
void insertionSort(DoublyLinkedList<T>& list);

#include "SortingAlgorithms.inl"

#endif // SORTINGALGORITHMS_H
