#include "LinkedList.h"

// to keep char limit under 80
#define NODE LinkedList<T>::Node

template <typename T> std::shared_ptr<NODE> LinkedList<T>::getNodePtr(int it) {
    std::shared_ptr<Node> result = nodeHeadPtr;

    for (int i = 0; i < it; i++) {
        result = result->next;
    }

    return result;
}

template <typename T> LinkedList<T>::LinkedList() : size(0) {
    nodeHeadPtr = std::make_shared<Node>();

    nodeHeadPtr->next = nullptr;
    nodeHeadPtr->prev = nullptr;
}

template <typename T> void LinkedList<T>::pushBack(T data) {
    std::shared_ptr<Node> tempPtr = std::make_shared<Node>();
    std::shared_ptr<Node> lastPtr = getNodePtr(size);

    tempPtr->data = data;
    tempPtr->next = lastPtr->next;

    if (lastPtr == nodeHeadPtr) {
        tempPtr->prev = nullptr;
    }
    else {
        tempPtr->prev = lastPtr;
    }

    if (isCircular) {
        std::shared_ptr<Node> firstPtr = nodeHeadPtr->next;

        // check this
        firstPtr->prev = tempPtr;
    }

    lastPtr->next = tempPtr;
}

template <typename T> void LinkedList<T>::pushFront(T data) {
    std::shared_ptr<Node> tempPtr = std::make_shared<Node>();
    std::shared_ptr<Node> firstPtr = nodeHeadPtr->next;

    tempPtr->data = data;
    tempPtr->next = firstPtr;

    if (firstPtr == nullptr) {
        tempPtr->prev = nullptr;
    }
    else {
        tempPtr->prev = firstPtr->prev;
        firstPtr->prev = tempPtr;
    }

    if (isCircular) {
        std::shared_ptr<Node> lastPtr = getNodePtr(size);

        //check this
        lastPtr->next = tempPtr;
    }

    // modify this once check successful
    nodeHeadPtr->next = tempPtr;
}

template <typename T> void LinkedList<T>::popBack() {
    std::shared_ptr<Node> lastPtr = getNodePtr(size);

    (lastPtr->prev)->next = nodeHeadPtr;
    nodeHeadPtr->prev = (nodeHeadPtr->prev)->prev;
}

template <typename T> void LinkedList<T>::popFront() {
    (nodeHeadPtr->next->next)->prev = nodeHeadPtr;
    nodeHeadPtr->next = (nodeHeadPtr->next)->next;
}

template <typename T> T LinkedList<T>::getBack() {
    return (nodeHeadPtr->prev)->data;
}

template <typename T> T LinkedList<T>::getFront() {
    return (nodeHeadPtr->next)->data;
}

template <typename T> void LinkedList<T>::makeCircular();

template <typename T> void LinkedList<T>::makeNormal();