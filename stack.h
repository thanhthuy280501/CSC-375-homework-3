#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

template <class T>
struct Node {
    T data;
    Node<T>* next;
};

template <class T>
class Stack {
private:
    Node<T>* top;
public:
    Stack() : top(nullptr) {}
    ~Stack() { makeEmpty(); }

    void push(const T& item) {
        Node<T>* newNode = new Node<T>;
        newNode->data = item;
        newNode->next = top;
        top = newNode;
    }

    bool pop(T& item) {
        if (isEmpty()) {
            return false;
        }
        Node<T>* temp = top;
        item = top->data;
        top = top->next;
        delete temp;
        return true;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void makeEmpty() {
        T temp;
        while (pop(temp));
    }

    bool peek(T& item) const {
        if (isEmpty()) {
            return false;
        }
        item = top->data;
        return true;
    }

    void print() const {
        Node<T>* current = top;
        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }
};

#endif // STACK_H
