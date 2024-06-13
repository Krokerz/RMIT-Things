#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <memory>
#include <stdexcept>

template <typename T> class LinkedList {
    private:
        struct Node {
            T data;
            std::shared_ptr<Node> next;
            std::shared_ptr<Node> prev;
        };

        std::shared_ptr<Node> nodeHeadPtr;
        unsigned int size;
        bool isCircular;

    public:
        class Iterator {
            private:
                friend class LinkedList<T>;

                std::shared_ptr<LinkedList<T>> currList;
                std::shared_ptr<Node> currPtr;

                Iterator(const std::shared_ptr<Node> &ptr, const LinkedList<T> *list);

            public:
                Iterator(const Iterator &iter);

                ~Iterator();

                /**
                 * Assigns the current Iterator with another Iterator
                 * @param iter
                 * @return Iterator reference
                 */
                Iterator& operator=(const Iterator &iter);

                /**
                 * Increments Iterator
                 */
                void operator++();

                /**
                 * Decrements Iterator
                 */
                void operator--();
                
                /**
                 * Gets the data at the current Iterator
                 * @return Stored data at the current Iterator
                 * @throw Runtime error when Iterator is not pointing to anything
                 */
                T getData() const;
        };

        LinkedList();

        ~LinkedList();

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
         * Returns Iterator object pointing to the beginning of the list
         * @return Iterator object pointing to the beginning of the list
         */
        Iterator begin() const;

        /**
         * Returns Iterator object pointing to the end of the list
         * @return Iterator object pointing to the end of the list
         */
        Iterator end() const;

        /**
         * Makes the list circular (the back of the list points to the front of the list)
         */
        void makeCircular();

        /**
         * Makes the list normal
         */
        void makeNormal();

        /**
         * Gets the size of the list
         * @return size
         */
        unsigned int getSize() const;

        /**
         * Prints the list along with other information about the list
         */
        void print() const;
};

#endif