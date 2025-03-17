#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

using namespace std;
template<typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<T>& other);
    ~DoublyLinkedList();
    void getTail() { cout << tail->data << endl; }  void getHead() { cout << head->data << endl; } //for checks and tests


    void push_back(T data);
    void push_front(T data);
    void insertAt(T data, int index);

    int getSize() { return size; }
    bool isEmpty() { return size == 0; }
    T get(int index);
    void merge(DoublyLinkedList<T>& other);
    int find(T data);

    void pop_front();
    void pop_back();
    void remoteAt(int index);

    void reverse();
    void clear();
    void print();

    T& operator [] (int index);
    DoublyLinkedList<T>& operator = (const DoublyLinkedList<T>& other);
private:
    template<typename T>
    class Node {
    public:
        T data;
        Node* next;
        Node* prev;
        Node(T data = T(), Node* next = nullptr, Node* prev = nullptr) {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }

    };
    int size;
    Node<T>* head;
    Node<T>* tail;
};

#include "A_Doubly_Linked_List.cpp"

#endif
