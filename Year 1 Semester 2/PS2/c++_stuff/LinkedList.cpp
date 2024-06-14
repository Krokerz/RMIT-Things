#include "LinkedList.h"

template <typename T> LinkedList<T>::Iterator::Iterator(
    const std::shared_ptr<Node> &ptr, const LinkedList<T> *list
) {
    currList = std::make_shared<LinkedList<T>>(*list);
    currPtr = ptr;
}

template <typename T> LinkedList<T>::Iterator::Iterator(
    const Iterator &iter
) {
    currList = iter.currList;
    currPtr = iter.currPtr;
}

template <typename T> LinkedList<T>::Iterator::~Iterator() {}

template <typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator=(
    const LinkedList<T>::Iterator &iter
) {
    currPtr = iter.currPtr;
}

template <typename T> void LinkedList<T>::Iterator::operator++() {
    currPtr = currPtr->next;
}

template <typename T> void LinkedList<T>::Iterator::operator--() {
    currPtr = currPtr->prev;
}

template <typename T> T LinkedList<T>::Iterator::getData() const {
    if ((currPtr == nullptr) || (currPtr == currList->nodeHeadPtr)) {
        throw std::runtime_error("The iterator is not pointing to anything!");
    }

    return currPtr->data;
}

template <typename T> LinkedList<T>::LinkedList() : size(0), isCircular(false) {
    nodeHeadPtr = std::make_shared<Node>();

    nodeHeadPtr->data = T();
    nodeHeadPtr->next = nodeHeadPtr;
    nodeHeadPtr->prev = nodeHeadPtr;
}

template <typename T> LinkedList<T>::~LinkedList() {}

template <typename T> void LinkedList<T>::pushBack(T data) {
    std::shared_ptr<Node> tempPtr = std::make_shared<Node>();

    tempPtr->data = data;

    if (nodeHeadPtr->prev == nodeHeadPtr) {
        tempPtr->prev = nullptr;
        tempPtr->next = nullptr;
    }
    else {
        tempPtr->prev = nodeHeadPtr->prev;
        tempPtr->next = nodeHeadPtr->prev->next;
    }

    nodeHeadPtr->prev->next = tempPtr;
    nodeHeadPtr->prev = tempPtr;

    if (isCircular) {
        nodeHeadPtr->next->prev = tempPtr;

        if (size == 0) {
            nodeHeadPtr->prev->next = tempPtr;
        }
    }

    size++;
}

template <typename T> void LinkedList<T>::pushFront(T data) {
    std::shared_ptr<Node> tempPtr = std::make_shared<Node>();

    tempPtr->data = data;

    if (nodeHeadPtr->next == nodeHeadPtr) {
        tempPtr->prev = nullptr;
        tempPtr->next = nullptr;
    }
    else {
        tempPtr->next = nodeHeadPtr->next;
        tempPtr->prev = nodeHeadPtr->next->prev;
    }

    nodeHeadPtr->next->prev = tempPtr;
    nodeHeadPtr->next = tempPtr;

    if (isCircular) {
        nodeHeadPtr->prev->next = tempPtr;

        if (size == 0) {
            nodeHeadPtr->next->prev = tempPtr;
        }
    }

    size++;
}

template <typename T> void LinkedList<T>::popBack() {
    if (size == 1) {
        if (isCircular) {
            nodeHeadPtr->prev->prev = nullptr;
            nodeHeadPtr->next->next = nullptr;
        }

        nodeHeadPtr->prev = nodeHeadPtr;
        nodeHeadPtr->next = nodeHeadPtr;

        size--;
    }
    else if (size > 0) {
        if (isCircular) {
            nodeHeadPtr->prev->next->prev = nodeHeadPtr->prev->prev;
        }

        nodeHeadPtr->prev->prev->next = nodeHeadPtr->prev->next;
        nodeHeadPtr->prev = nodeHeadPtr->prev->prev;

        size--;
    }
}

template <typename T> void LinkedList<T>::popFront() {
    if (size == 1) {
        if (isCircular) {
            nodeHeadPtr->next->next = nullptr;
            nodeHeadPtr->prev->prev = nullptr;
        }

        nodeHeadPtr->next = nodeHeadPtr;
        nodeHeadPtr->prev = nodeHeadPtr;

        size--;
    }
    else if (size > 0) {
        if (isCircular) {
            nodeHeadPtr->next->prev->next = nodeHeadPtr->next->next;
        }
        
        nodeHeadPtr->next->next->prev = nodeHeadPtr->next->prev;
        nodeHeadPtr->next = nodeHeadPtr->next->next;

        size--;
    }
}

template <typename T> typename LinkedList<T>::Iterator LinkedList<T>::begin() const {
    return Iterator(nodeHeadPtr->next, this);
}

template <typename T> typename LinkedList<T>::Iterator LinkedList<T>::end() const {
    return Iterator(nodeHeadPtr->prev, this);
}

template <typename T> void LinkedList<T>::makeCircular() {
    nodeHeadPtr->prev->next = nodeHeadPtr->next;
    nodeHeadPtr->next->prev = nodeHeadPtr->prev;

    isCircular = true;
}

template <typename T> void LinkedList<T>::makeNormal() {
    if (size > 0) {
        nodeHeadPtr->prev->next = nullptr;
        nodeHeadPtr->next->prev = nullptr;
    }

    isCircular = false;
}

template <typename T> unsigned int LinkedList<T>::getSize() const {
    return size;
}

template <typename T> void LinkedList<T>::print() const {
    std::shared_ptr<Node> temp = nodeHeadPtr->next;

    for (int i = 0; i < size; i++) {
        std::cout << temp->data;
        std::cout << " | amount of pointers pointing to it: ";
        std::cout << temp.use_count() - 1;
        std::cout << std::endl;

        temp = temp->next;
    }

    std::cout << '(';

    if (isCircular) {
        std::cout << "circular";
    }
    else {
        std::cout << "normal";
    }

    std::cout << ')' << std::endl;

    std::cout << "size: " << size << std::endl;
}