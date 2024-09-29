#include <iostream>
#include <string>
#include <fstream>
#include <climits>
#include <stdexcept>
#include <unistd.h>
#include "memalloc.h"

int main(int argc, char* *argv) {
    std::vector<void*> allocedVect;
    std::ifstream inStream;
    std::string str = "";
    
    try {
        if (argc < 2) {
            throw std::logic_error("Not enough arguments");
        }

        inStream.open(argv[1]);

        if (inStream.fail()) {
            throw std::runtime_error("Unable to open source file");
        }

        while (getline(inStream, str)) {
            if (str.substr(0, 7) == "alloc: ") {
                str = str.substr(6, str.size() - 6);

                allocedVect.push_back(alloc(stoi(str)));
            }
            else if (str.substr(0, 7) == "dealloc") {
                dealloc(allocedVect.back());

                allocedVect.pop_back();
            }
            else {
                throw std::runtime_error("Unknown input");
            }
        }
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    inStream.close();

    closing();

    return EXIT_SUCCESS;
}

Allocation::Allocation(size_t size, size_t occupied, void *space) : size(size), occupied(occupied), space(space) {}

void* alloc(size_t chunk_size) {
    bool found = false;
    void *loc = nullptr;

    if ((chunk_size <= 0) || (chunk_size > 512)) {
        throw std::runtime_error("Unallowed chunk size");
    }
    else {
        int bestDiff = INT_MAX;
        allocIter_T bestAlloc = freeList.begin();

        for (allocIter_T it = freeList.begin(); it != freeList.end(); it++) {
            int temp = abs(static_cast<int>(chunk_size) - static_cast<int>(it->size));

            if (temp < bestDiff) {
                bestDiff = temp;
                bestAlloc = it;

                found = true;
            }
        }

        if (found) {
            loc = bestAlloc->space;

            occuList.push_back(*bestAlloc);
            freeList.erase(bestAlloc);
        }
        else {
            size_t alloc_size = 0;

            for (size_t i : ALLOWED_SIZES) {
                if (chunk_size <= i) {
                    alloc_size = i;

                    break;
                }
            }

            loc = sbrk(alloc_size);

            if (reinterpret_cast<intptr_t>(loc) == -1) {
                throw std::runtime_error("Max amount of memory allocated");
            }

            occuList.push_back(Allocation(alloc_size, chunk_size, loc));
        }
    }

    return loc;
}

void dealloc(void *chunk) {
    bool found = false;

    for (allocIter_T it = occuList.begin(); it != occuList.end(); it++) {
        if (it->space == chunk) {
            it->occupied = 0;

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

void closing() {
    int temp = 0;

    std::cout << "Allocated List: " << std::endl;

    for (Allocation i : occuList) {
        std::cout << "- Address: " << i.space << " | Total Size: " << i.size << " | Occupied Size: " << i.occupied << std::endl;

        temp += i.size;
    }

    std::cout << "\nFree List: " << std::endl;

    for (Allocation i : freeList) {
        std::cout << "- Address: " << i.space << " | Total Size: " << i.size << std::endl;
        
        temp += i.size;
    }

    std::cout << -temp << std::endl;

    sbrk(0 - temp);
}