# Doubly Linked List

This project is an implementation of a **doubly linked list** in C++ with basic operations like insertion, deletion, searching, and merging.  

## Features
- Insert elements at the front, back, or any index  
- Remove elements from the list  
- Reverse the list  
- Merge two lists  
- Custom `operator[]` for element access  
- Unit tests using standard C++ assertions (assert)

## How to Build
To compile and run tests, use CMake or Visual Studio.

## Usage
Include `DoublyLinkedList.h` in your project and create a list:
```cpp
DoublyLinkedList<int> list;
list.push_back(10);
list.push_front(5);
list.print(); // Output: 5 10