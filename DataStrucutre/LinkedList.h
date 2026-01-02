//
// Created by MaraMincho on 2025. 12. 26..
//

#ifndef PS_LINKEDLIST_H
#define PS_LINKEDLIST_H



#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class LinkedList {
private:
    optional<Node<T>*> head;
    optional<Node<T>*> tail;
public:
    LinkedList(T, Node<T> head);
    void addNext(Node<T>* next);
    int getCountOfNode();
    optional<Node<T>*> popTail();
};


#endif //PS_LINKEDLIST_H