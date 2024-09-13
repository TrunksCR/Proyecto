#include "MPointer.h"
#include "MPointerGC.h"

template <typename T>
MPointer<T>& MPointer<T>::operator=(const MPointer<T>& other) {
    if (this != &other) {
        // Decrease reference count of the old pointer
        if (ptr) {
            MPointerGC<T>::instance().decreaseRefCount(id);
            if (MPointerGC<T>::instance().getRefCount(id) == 0) {
                delete ptr;
            }
        }

        // Assign new values
        ptr = other.ptr;
        id = other.id;

        // Increase reference count of the new pointer
        if (ptr) {
            MPointerGC<T>::instance().increaseRefCount(id);
        }
    }
    return *this;
}

template <typename T>
MPointer<T>::MPointer(const MPointer<T>& other) : ptr(other.ptr), id(other.id) {
    if (ptr) {
        MPointerGC<T>::instance().increaseRefCount(id);
    }
}

template <typename T>
MPointer<T> MPointer<T>::New() {
    T* newPtr = new T(); // Create a new object of type T
    int newId = MPointerGC<T>::instance().registerPointer(newPtr);
    return MPointer<T>(newPtr, newId);
}

template <typename T>
MPointer<T>::~MPointer() {
    if (ptr) {
        MPointerGC<T>::instance().decreaseRefCount(id);
        if (MPointerGC<T>::instance().getRefCount(id) == 0) {
            delete ptr;
        }
    }
}

template <typename T>
T& MPointer<T>::operator*() const {
    return *ptr;
}

template <typename T>
T* MPointer<T>::operator->() const {
    return ptr;
}

template <typename T>
MPointer<T>& MPointer<T>::operator=(const T& value) {
    if (ptr) {
        *ptr = value;
    }
    return *this;
}

template <typename T>
T& MPointer<T>::operator&() const {
    return *ptr;
}
