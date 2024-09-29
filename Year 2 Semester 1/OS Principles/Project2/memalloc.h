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

        friend void* alloc(size_t chunk_size);
        friend void dealloc(void *chunk);
        friend void closing();
};

typedef std::list<Allocation>::iterator allocIter_T;

std::list<Allocation> occuList;
std::list<Allocation> freeList;

void* alloc(size_t chunk_size);
void dealloc(void *chunk);
void closing();

#endif