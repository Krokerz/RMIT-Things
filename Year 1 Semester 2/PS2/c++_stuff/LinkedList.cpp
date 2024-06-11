#include "LinkedList.h"

template <typename T> LinkedList<T>::LinkedList() : size(0) {
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
    if (!(size <= 0)) {
        if (isCircular) {
            nodeHeadPtr->prev->next->prev = nodeHeadPtr->prev->prev;
        }

        nodeHeadPtr->prev->prev->next = nodeHeadPtr->prev->next;
        nodeHeadPtr->prev = nodeHeadPtr->prev->prev;

        size--;
    }
}

template <typename T> void LinkedList<T>::popFront() {
    if (!(size <= 0)) {
        if (isCircular) {
            nodeHeadPtr->next->prev->next = nodeHeadPtr->next->next;
        }
        
        nodeHeadPtr->next->next->prev = nodeHeadPtr->next->prev;
        nodeHeadPtr->next = nodeHeadPtr->next->next;

        size--;
    }
}

template <typename T> Iterator LinkedList<T>::begin() {
    return 
}

template <typename T> T LinkedList<T>::getAt(Iterator iter) {
    T result = T();

    if (size == 0) {
        throw std::runtime_error("The list is empty!");
    }
    else {
        result = 
    }

    return result;
}

template <typename T> void LinkedList<T>::makeCircular() {
    nodeHeadPtr->prev->next = nodeHeadPtr->next;
    nodeHeadPtr->next->prev = nodeHeadPtr->prev;


}

template <typename T> void LinkedList<T>::makeNormal() {

}