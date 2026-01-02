//
// Created by MaraMincho on 2025. 12. 26..
//

#ifndef PS_NODE_H
#define PS_NODE_H

#include <iostream>

using namespace std;

template<typename T>
class Node {
private:
    optional<Node<T>*> next;
    T value;

public:
    explicit Node(T);
    Node(T, T value);

    void setNext(Node* next);
    void makeNext(T value);
    optional<Node<T>*> getNext();
};


#endif //PS_NODE_H