#ifndef MPTRGC_TPP
#define MPTRGC_TPP

#include "MPointerGC.h"
#include <algorithm>

template<typename T>
MPointerGC<T>& MPointerGC<T>::instance() {
    static MPointerGC<T> instance;
    return instance;
}

template<typename T>
void MPointerGC<T>::registerPointer(MPointer<T>* ptr) {
    pointers.push_back(ptr);
}

template<typename T>
void MPointerGC<T>::unregisterPointer(MPointer<T>* ptr) {
    auto it = std::find(pointers.begin(), pointers.end(), ptr);
    if (it != pointers.end()) {
        pointers.erase(it);
    }
}

#endif // MPTRGC_TPP
