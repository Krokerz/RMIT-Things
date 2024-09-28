#include <iostream>
#include <list>
#include <vector>
#include <unistd.h>
#include <climits>
#include <stdexcept>

class Allocation {
    private:
        std::size_t size;
        void *space;

    public:
        Allocation(std::size_t size, void *space);

        friend void* alloc(std::size_t chunk_size);
        friend void dealloc(void *chunk);
};

typedef std::list<Allocation*>::iterator allocIter_T;
typedef std::vector< std::pair<std::size_t, void*> > infoVect_T;

const std::vector<size_t> allowedSizes = {32, 64, 128, 256, 512};

std::list<Allocation*> occuList;
std::list<Allocation*> freeList;

void* alloc(std::size_t chunk_size);
void dealloc(void *chunk);

bool firstFit = true;

int main() {
    std::vector<void*> allocVect;

    try {
        allocVect.push_back(alloc(32));
        allocVect.push_back(alloc(64));
        allocVect.push_back(alloc(128));
        allocVect.push_back(alloc(256));
        allocVect.push_back(alloc(512));

        std::cout << "all allocated" << std::endl;

        for (void *i : allocVect) {
            std::cout << i << std::endl;
        }

        std::cout << "----------------------------------------------------" << std::endl;

        for (void *i : occuList) {
            std::cout << i << std::endl;
        }

        // allocVect.push_back(alloc(24));
        // allocVect.push_back(alloc(-38));
        // allocVect.push_back(alloc(0));

        // for (unsigned int i = 0; i < allocVect.size(); i++) {
        //     dealloc(allocVect.at(i));

        //     std::cout << "dealloced #" << i + 1 << std::endl;
        // }

        // dealloc(nullptr);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "all good" << std::endl;

    return EXIT_SUCCESS;
}

Allocation::Allocation(std::size_t size, void *space) : size(size), space(space) {}

void* alloc(std::size_t chunk_size) {
    bool found = false;
    bool allowed = false;
    void *loc = nullptr;

    for (size_t i : allowedSizes) {
        if (chunk_size == i) {
            allowed = true;

            break;
        }
    }

    if (!allowed) {
        throw std::runtime_error("Unallowed chunk size");
    }
    else {
        if (firstFit) {
            for (allocIter_T it = freeList.begin(); it != freeList.end(); it++) {
                if ((*it)->size >= chunk_size) {
                    loc = (*it)->space;

                    occuList.push_back(*it);
                    freeList.erase(it);

                    found = true;

                    break;
                }
            }
        }
        else {
            unsigned int bestDiff = UINT_MAX;
            allocIter_T bestAlloc = freeList.begin();

            for (allocIter_T it = freeList.begin(); it != freeList.end(); it++) {
                if ((chunk_size - (*it)->size) < bestDiff) {
                    bestDiff = chunk_size - (*it)->size;
                    bestAlloc = it;

                    found = true;
                }
            }

            if (found) {
                loc = (*bestAlloc)->space;

                occuList.push_back(*bestAlloc);
                freeList.erase(bestAlloc);
            }
        }


        if (!found) {
            loc = sbrk(chunk_size);

            if (reinterpret_cast<intptr_t>(loc) == -1) {
                throw std::runtime_error("Max amount of memory allocated");
            }

            Allocation newAlloc = Allocation(chunk_size, loc);

            std::cout << "size before: " << occuList.size() << std::endl;

            occuList.push_back(&newAlloc); // check if allocation is still there

            std::cout << "size after: " << occuList.size() << std::endl;
        }
    }

    return loc;
}

void dealloc(void *chunk) {
    bool found = false;

    for (allocIter_T it = occuList.begin(); it != occuList.end(); it++) {
        std::cout << "(*it)->space = " << (*it)->space << std::endl;
        std::cout << "chunk = " << chunk << std::endl;

        if ((*it)->space == chunk) {
            freeList.push_back(*it);
            occuList.erase(it);

            found = true;

            break;
        }
    }

    if (!found) {
        throw std::runtime_error("Unable to deallocate unallocated memory");
    }
}