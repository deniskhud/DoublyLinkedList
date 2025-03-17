#include <iostream>
#include <cassert>
#include "../A_Doubly_Linked_List/A_Doubly_Linked_List.h"

void testPushBack() {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    assert(list.getSize() == 2);
    assert(list.get(0) == 10);
    assert(list.get(1) == 20);
    std::cout << "testPushBack passed!\n";
}

void testPushFront() {
    DoublyLinkedList<int> list;
    list.push_front(5);
    list.push_front(3);
    assert(list.getSize() == 2);
    assert(list.get(0) == 3);
    assert(list.get(1) == 5);
    std::cout << "testPushFront passed!\n";
}

int main() {
    testPushBack();
    testPushFront();
    std::cout << "All tests passed!\n";
    return 0;
}

