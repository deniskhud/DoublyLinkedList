#include "A_Doubly_Linked_List.h"

template<typename T>
void DoublyLinkedList<T>::push_back(T data)
{
    if (head == nullptr) {
        head = new Node(data);
        tail = head;
    }
    else {
        tail->next = new Node<T>(data, nullptr, tail);
        tail = tail->next;
    }
    ++size;
}

template<typename T>
void DoublyLinkedList<T>::push_front(T data)
{
    Node<T>* newNode = new Node<T>(data, head, nullptr);

    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;

    if (tail == nullptr) {
        tail = head;
    }
    ++size;
}

template<typename T>
void DoublyLinkedList<T>::insertAt(T data, int index)
{
    if (index < 0 || index >= size) return;
    if (index == 0) {
        push_front(data);
        return;
    }
    if (index == size) {
        push_back(data);
        return;
    }
    Node<T>* current;
    if (index > size / 2) {
        current = tail;
        for (int i = size - 1; i > index; --i) {
            current = current->prev;
        }
    }
    else {
        current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
    }
    Node<T>* newNode = new Node<T>(data, current, current->prev);
    if (current->prev) {
        current->prev->next = newNode;
    }
    if (current) {
        current->prev = newNode;
    }
    ++size;
}

template<typename T>
T DoublyLinkedList<T>::get(int index)
{
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    Node<T>* current = (index < size / 2) ? head : tail; 
    if(index < size / 2) {
        for (int i = 0; i < index; ++i) {
            current = current->next;
        } 
    }
    else {
        for (int i = size - 1; i > index; --i) {
            current = current->prev;
        }
    }
    return current->data;
}

template<typename T>
void DoublyLinkedList<T>::merge(DoublyLinkedList<T>& other)
{
    if (other.head == nullptr) return;
    if (head == nullptr) {
        head = other.head;
        tail = other.tail;
    }
    else {
        tail->next = other.head;
        other.head->prev = tail;
        tail = other.tail;
    }
    size += other.size;
    other.head = other.tail = nullptr;
    other.size = 0;
}

template<typename T>
int DoublyLinkedList<T>::find(T data)
{
    Node<T>* current = head;
    int index = 0;
    while (current) {
        if (current->data == data) return index;
        current = current->next;
        ++index;
    }
    return -1;
}

template<typename T>
void DoublyLinkedList<T>::pop_front()
{
    if (!head) return;

    Node<T>* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete temp;
    --size;
}

template<typename T>
void DoublyLinkedList<T>::pop_back()
{
    if (!tail) return;

    Node<T>* temp = tail;
    if (tail->prev) {
        tail = tail->prev;
        tail->next = nullptr;
    }
    else {
        head = tail = nullptr;
    }
    delete temp;
    --size;
}

template<typename T>
void DoublyLinkedList<T>::remoteAt(int index)
{
    if (index < 0 || index >= size) return;
    if (index == 0) {
        pop_front();
        return;
    }
    if (index == size - 1) {
        pop_back();
        return;
    }
    Node<T>* current;

    if (index > size / 2) {
        current = tail;
        for (int i = size - 1; i > index; --i) {
            current = current->prev;
        }
    }
    else {
        current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    --size;
}

template<typename T>
void DoublyLinkedList<T>::reverse()
{
    if (size == 0 || size == 1) return;
    Node<T>* current = head;
    Node<T>* temp = nullptr;
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp) {
        tail = head;
        head = temp->prev;
        
    }
}

template<typename T>
void DoublyLinkedList<T>::clear()
{
    while (size) {
        pop_front();
    }
}

template<typename T>
void DoublyLinkedList<T>::print()
{
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node<T>* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
    
}

template<typename T>
T& DoublyLinkedList<T>::operator[](int index)
{
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    Node<T>* current = (index < size / 2) ? head : tail;
    if (index < size / 2) {
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
    }
    else {
        for (int i = size - 1; i > index; --i) {
            current = current->prev;
        }  
    }
    return current->data;
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other)
{
    if (this == &other) return *this;
    clear();
    if (!other.head) {
        head = tail = nullptr;
        size = 0;
        return *this;
    }

    head = new Node<T>(other.head->data);
    Node<T>* current = head;
    Node<T>* otherCurrent = other.head->next;

    while (otherCurrent) {
        Node<T>* newNode = new Node<T>(otherCurrent->data, nullptr, current);
        current->next = newNode;
        current = newNode;
        otherCurrent = otherCurrent->next;
    }

    size = other.size;
    tail = current;
    return *this;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other)
{
    size = 0;
    head = tail = nullptr;
    clear();

    if (!other.head) return;

    head = new Node<T>(other.head->data);
    Node<T>* current = head;
    Node<T>* otherCurrent = other.head->next;

    while (otherCurrent) {
        Node<T>* newNode = new Node<T>(otherCurrent->data, nullptr, current);
        current->next = newNode;
        current = newNode;
        otherCurrent = otherCurrent->next;
    }
    size = other.size;
    tail = current;

}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
}




