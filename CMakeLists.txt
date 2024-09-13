cmake_minimum_required(VERSION 3.10)
project(MPointers)

set(CMAKE_CXX_STANDARD 17)

# Añadir GoogleTest usando FetchContent
include(FetchContent)
FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(gtest)

# Añadir los archivos fuente
add_executable(MPointers
        main.cpp
        test_MPointer.cpp
        MPointer.h
        MPointerGC.h
        SortingAlgorithms.h
        SortingAlgorithms.inl
        DoublyLinkedList.h
        DoublyLinkedList.inl
        MPointerGC.tpp
        MPointer.tpp
)

# Enlazar GoogleTest
target_link_libraries(MPointers gtest gtest_main)

# Configurar el directorio de pruebas
enable_testing()
add_test(NAME MPointerTests COMMAND MPointers)
