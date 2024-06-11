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
        }

        std::shared_ptr<Node> nodeHeadPtr;
        unsigned int size;
        bool isCircular;

    public:
        class Iterator {
            private:
                friend class LinkedList;
                
                std::shared_ptr<Node> currPtr;

            public:
                Iterator();

                ~Iterator();
                
                /** 
                 * Increments Iterator by 1
                 */
                Iterator& operator++();

                /**
                 * Increments Iterator by an int
                 * @param num
                 */
                Iterator& operator+=(int num);
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
         * Returns the data at ta specified part of the list
         * @throw 
         * @return Data stored at that part of the list
         */
        T getAt(Iterator iter);



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