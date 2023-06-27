#include "MultiMapIterator.h"
#include "MultiMap.h"
#include <algorithm>
#include <stdexcept> 

//BC=O(1)
//OC=WC=O(n), n is the number of elements in the hash table
MultiMapIterator::MultiMapIterator(const MultiMap& map) : map(map), current(nullptr), head(nullptr), pos(0) {
    // Finding the first non-empty linked list in the hash table
    for (int i = 0; i < map.capacity; i++) {
        if (map.hash_table[i] != nullptr) {
            current = map.hash_table[i];
            head = current;
            break;
        }
    }
}

//BC=OC=WC=O(1)
TElem MultiMapIterator::getCurrent() const {
    if (!valid()) {
        throw runtime_error("Invalid iterator!");
    }

    return make_pair(current->key, current->values[pos]);
}

//BC=OC=WC=O(1)
bool MultiMapIterator::valid() const {
    return current != nullptr;
}

//BC=OC=O(1)
//WC=O(n)
void MultiMapIterator::next() {
    if (!valid()) 
        throw runtime_error("Invalid iterator!");

    // Move to the next position in the current node's dynamic array
    pos++;

    // If the current position exceeds the size of the dynamic array, move to the next node
    if (pos >= current->size) {
        // Move to the next node in the linked list if it exists
        if (current->next != nullptr) {
            current = current->next;
            pos = 0;
        }
        else {
            // Move to the next non-empty linked list in the hash table
            int index = map.hash_function(current->key) + 1;
            while (index < map.capacity && map.hash_table[index] == nullptr) {
                index++;
            }

            // If there are no more linked lists, the iterator becomes invalid
            if (index >= map.capacity) {
                current = nullptr;
                head = nullptr;
                pos = 0;
                return;
            }

            // Move to the next linked list
            current = map.hash_table[index];
            pos = 0;
        }
    }
}

//BC=OC=O(1)
//WC=O(n), n is the number of elements in the hash table
void MultiMapIterator::first() {
    // Finding the first non-empty linked list in the hash table
    for (int i = 0; i < map.capacity; i++) {
        if (map.hash_table[i] != nullptr) {
            current = map.hash_table[i];
            head = current;
            pos = 0;
            return;
        }
    }

    // If no non-empty linked list is found, the iterator becomes invalid
    current = nullptr;
    head = nullptr;
    pos = 0;
}

