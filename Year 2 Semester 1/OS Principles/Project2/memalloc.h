#ifndef MEMALLOC_H
#define MEMALLOC_H

#include <vector>
#include <list>

#define ALLOWED_SIZES {32, 64, 128, 256, 512}

class Allocation {
    private:
        size_t size;
        size_t occupied;
        void *space;

    public:
        Allocation(size_t size, size_t occupied, void *space);
        size_t getSize();
        size_t getOccupied();
        void* getSpace();

        friend void* alloc(size_t chunk_size);
        friend void dealloc(void *chunk);
};

typedef std::list<Allocation>::iterator allocIter_T;

std::list<Allocation> occuList;
std::list<Allocation> freeList;

void* alloc(size_t chunk_size);
void dealloc(void *chunk);

#endif