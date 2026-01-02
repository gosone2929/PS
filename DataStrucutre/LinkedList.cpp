//
// Created by MaraMincho on 2025. 12. 26..
//

#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList(T, Node<T> head) {
    this->head = head;
    this->tail = head;
}

template<typename T>
void LinkedList<T>::addNext(Node<T> *next) {
    tail->next = next;
    tail = next;
}

template<typename T>
int LinkedList<T>::getCountOfNode() {
    Node<T>* temp = head;
    int cnt = 0;

    while (temp) {
        cnt += 1;
        temp = temp->next;
    }

    return cnt;
}

template<typename T>
optional<Node<T> *> LinkedList<T>::popTail() {

}

