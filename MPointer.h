#ifndef MPTR_H
#define MPTR_H

#include "MPointerGC.h"

template<typename T>
class MPointer {
public:
    static MPointer<T> New();

    MPointer();
    MPointer(T* rawPtr);
    MPointer(const MPointer<T>& other);
    MPointer<T>& operator=(const MPointer<T>& other);
    ~MPointer();

    T& operator*();
    T* operator&();

private:
    T* ptr;
    void registerGC();
    void unregisterGC();
};

#include "MPointer.tpp" // Incluye la implementación de la plantilla

#endif // MPTR_H
