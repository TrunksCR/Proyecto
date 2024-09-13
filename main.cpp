#include <gtest/gtest.h>
#include "MPointer.h"
#include "DoublyLinkedList.h"
#include <sstream>  // Asegúrate de incluir sstream para std::ostringstream

// Prueba de creación de MPointer
TEST(MPointerTest, CreateNewMPointer) {
    MPointer<int> mp = MPointer<int>::New();
    *mp = 5;
    EXPECT_EQ(*mp, 5);
}

// Prueba de asignación de MPointer
TEST(MPointerTest, AssignMPointer) {
    MPointer<int> mp1 = MPointer<int>::New();
    MPointer<int> mp2 = MPointer<int>::New();
    *mp1 = 10;
    mp2 = mp1;
    EXPECT_EQ(*mp2, 10);
}

// Prueba de ordenamiento con QuickSort
TEST(DoublyLinkedListTest, QuickSort) {
    DoublyLinkedList<int> list;
    list.append(3);
    list.append(1);
    list.append(2);

    // Captura de salida de printList
    std::ostringstream oss;
    auto old_buf = std::cout.rdbuf(oss.rdbuf());

    list.quickSort();
    list.printList(); // Captura la salida

    std::cout.rdbuf(old_buf); // Restaura el buffer original

    EXPECT_EQ(oss.str(), "1 2 3 \n"); // Salida esperada con el salto de línea al final
}

// Prueba de ordenamiento con BubbleSort
TEST(DoublyLinkedListTest, BubbleSort) {
    DoublyLinkedList<int> list;
    list.append(3);
    list.append(1);
    list.append(2);

    // Captura de salida de printList
    std::ostringstream oss;
    auto old_buf = std::cout.rdbuf(oss.rdbuf());

    list.bubbleSort();
    list.printList(); // Captura la salida

    std::cout.rdbuf(old_buf); // Restaura el buffer original

    EXPECT_EQ(oss.str(), "1 2 3 \n"); // Ajusta la salida esperada para incluir el salto de línea al final
}

// Prueba de ordenamiento con InsertionSort
TEST(DoublyLinkedListTest, InsertionSort) {
    DoublyLinkedList<int> list;
    list.append(3);
    list.append(1);
    list.append(2);

    // Captura de salida de printList
    std::ostringstream oss;
    auto old_buf = std::cout.rdbuf(oss.rdbuf());

    list.insertionSort();
    list.printList(); // Captura la salida

    std::cout.rdbuf(old_buf); // Restaura el buffer original

    EXPECT_EQ(oss.str(), "1 2 3 \n"); // Ajusta la salida esperada para incluir el salto de línea al final
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
