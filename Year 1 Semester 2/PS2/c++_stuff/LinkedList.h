#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <memory>

// template <typename T> class Node {
//     private:
//         T data;
//         std::shared_ptr<Node<T>> next;
//         std::shared_ptr<Node<T>> prev;

//         friend class LinkedList;
// };

template <typename T> class LinkedList {
    private:
        struct Node {
            T data;
            std::shared_ptr<Node> next;
            std::shared_ptr<Node> prev;
        };

        std::shared_ptr<Node> nodeHeadPtr;
        // make currPtr?
        int size;
        bool isCircular;

        std::shared_ptr<Node> getNodePtr(int it);

    public:
        LinkedList();

        /**
         * Pushes the data to the back of the list
         * @param data
         */
        void pushBack(T data);

        /**
         * Pushes the data to the front of the list
         * @param data
         */
        void pushFront(T data);

        /**
         * Pops the data at the back of the list
         */
        void popBack();

        /**
         * Pops the data at the front of the list
         */
        void popFront();

        /**
         * Returns the data at the back of the list
         */
        T getBack();

        /**
         * Returns the data at the front of the list
         */
        T getFront();

        /**
         * Makes the list circular (the back of the list points to the front of the list)
         */
        void makeCircular();

        /**
         * Makes the list normal
         */
        void makeNormal();

};

#endif