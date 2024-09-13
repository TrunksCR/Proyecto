#ifndef MPOINTER_H
#define MPOINTER_H

#include <utility>
#include <iostream>

template <typename T>
class MPointerGC; // Forward declaration

template <typename T>
class MPointer {
public:
    static MPointer<T> New();

    MPointer() : ptr(nullptr), id(-1) {}
    MPointer(T* p, int i) : ptr(p), id(i) {}
    MPointer(const MPointer<T>& other); // Copy constructor
    MPointer<T>& operator=(const MPointer<T>& other); // Copy assignment
    ~MPointer(); // Destructor

    T& operator*() const;
    T* operator->() const;
    MPointer<T>& operator=(const T& value);
    T& operator&() const;

private:
    T* ptr;
    int id;
    static MPointerGC<T>* gc; // Reference to the garbage collector
};

// Include implementation
#include "MPointer.tpp"

#endif // MPOINTER_H
