#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> list = LinkedList<int>();

    list.popBack();
    list.popFront();

    list.print();

    list.pushBack(1);
    
    list.print();

    list.popBack();
    list.popFront();
    list.pushBack(2);
    list.pushFront(1);
    list.pushBack(3);

    list.popBack();
    list.popFront();

    list.print();

    list.popFront();
    list.makeCircular();

    list.print();

    list.makeNormal();

    list.print();

    for (int i = 0; i < 5; i++) {
        list.pushBack(i);
    }

    list.print();

    list.makeNormal();

    list.print();

    list.makeNormal();

    list.print();

    list.makeCircular();

    list.print();

    list.makeCircular();

    list.print();

    LinkedList<int>::Iterator iter = list.begin();

    std::cout << iter.getData() << std::endl;
    
    for (int i = 0; i < list.getSize(); i++) {
        std::cout << iter.getData() << ' ';

        ++iter;
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}