#ifndef MPTRGC_H
#define MPTRGC_H

#include "MPointer.h" // Asegúrate de incluir MPointer.h
#include <vector>

template<typename T>
class MPointer;

template<typename T>
class MPointerGC {
public:
    static MPointerGC& instance();

    void registerPointer(MPointer<T>* ptr);
    void unregisterPointer(MPointer<T>* ptr);

private:
    MPointerGC() = default;
    ~MPointerGC() = default;

    std::vector<MPointer<T>*> pointers;
};

#include "MPointerGC.tpp" // Incluye la implementación de la plantilla
#endif // MPTRGC_H
