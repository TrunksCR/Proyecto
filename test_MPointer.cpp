#include <gtest/gtest.h>
#include "MPointer.h"
#include "DoublyLinkedList.h"

TEST(MPointerTest, CreateAndAssign) {
    MPointer<int> ptr = MPointer<int>::New();
    *ptr = 5;
    EXPECT_EQ(*ptr, 5);
}

TEST(MPointerTest, CopyConstructor) {
    MPointer<int> ptr1 = MPointer<int>::New();
    *ptr1 = 10;
    MPointer<int> ptr2 = ptr1;
    EXPECT_EQ(*ptr2, 10);
}

TEST(DoublyLinkedListTest, InsertAndPrint) {
    DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    // Add checks for output
}
