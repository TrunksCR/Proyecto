#ifndef MPTR_TPP
#define MPTR_TPP

#include "MPointer.h"

template<typename T>
MPointer<T> MPointer<T>::New() {
    return MPointer<T>(new T());
}

template<typename T>
MPointer<T>::MPointer() : ptr(nullptr) {}

template<typename T>
MPointer<T>::MPointer(T* rawPtr) : ptr(rawPtr) {
    registerGC();
}

template<typename T>
MPointer<T>::MPointer(const MPointer<T>& other) : ptr(other.ptr) {
    registerGC();
}

template<typename T>
MPointer<T>& MPointer<T>::operator=(const MPointer<T>& other) {
    if (this != &other) {
        unregisterGC();
        ptr = other.ptr;
        registerGC();
    }
    return *this;
}

template<typename T>
MPointer<T>::~MPointer() {
    unregisterGC();
    delete ptr;
}

template<typename T>
T& MPointer<T>::operator*() {
    return *ptr;
}

template<typename T>
T* MPointer<T>::operator&() {
    return ptr;
}

template<typename T>
void MPointer<T>::registerGC() {
    MPointerGC<T>::instance().registerPointer(this);
}

template<typename T>
void MPointer<T>::unregisterGC() {
    MPointerGC<T>::instance().unregisterPointer(this);
}

#endif // MPTR_TPP
