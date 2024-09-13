#ifndef MPTRGC_H
#define MPTRGC_H

#include <unordered_map>
#include <mutex>

template <typename T>
class MPointerGC {
public:
    static MPointerGC& instance() {
        static MPointerGC instance;
        return instance;
    }

    int registerPointer(T* ptr) {
        std::lock_guard<std::mutex> lock(mtx);
        int id = nextId++;
        refCount[id] = 1;
        pointerMap[id] = ptr;
        return id;
    }

    void increaseRefCount(int id) {
        std::lock_guard<std::mutex> lock(mtx);
        refCount[id]++;
    }

    void decreaseRefCount(int id) {
        std::lock_guard<std::mutex> lock(mtx);
        if (--refCount[id] == 0) {
            delete pointerMap[id];
            pointerMap.erase(id);
            refCount.erase(id);
        }
    }

    int getRefCount(int id) const {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = refCount.find(id);
        return it != refCount.end() ? it->second : 0;
    }

private:
    MPointerGC() : nextId(0) {}
    MPointerGC(const MPointerGC&) = delete;
    MPointerGC& operator=(const MPointerGC&) = delete;

    std::unordered_map<int, T*> pointerMap;
    std::unordered_map<int, int> refCount;
    mutable std::mutex mtx;
    int nextId;
};

#endif // MPTRGC_H
