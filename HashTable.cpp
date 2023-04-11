//
// Created by Lucas Vas on 4/10/2023.
//

#include <climits>
#include <iostream>
#include "HashTable.h"

using namespace std;

HashTable::HashTable(int hashValue) : hashValue(hashValue) {
    buckets = new Data*[hashValue];
    for (int i = 0; i < hashValue; i++) {
        buckets[i] = nullptr;
    }
}

int HashTable::hash(int key) const {
    int hashedKey = key % hashValue;
    return hashedKey;
}

tuple<int, bool> HashTable::insert(int key, int value) {
    // Get the hash of the key.
    int hashedKey = hash(key);

    // Store number of iterations.
    int iterations = 1;

    // Create new Data struct. Default settings are to be the start of a list.
    Data* newData = new Data {value, key, nullptr, nullptr};

    Data* last = buckets[hashedKey];

    // If list is empty, create new list.
    if (last == nullptr) {
        buckets[hashedKey] = newData;
        return {iterations, true};
    }

    while (last->next != nullptr) {
        iterations++;
        last = last->next;
    }

    // Link list nodes together.
    last->next = newData;
    newData->prev = last;

    // Return.
    return {iterations, true};
}

tuple<int, bool> HashTable::search(int key) {
    // Get hashed key value.
    int hashedKey = hash(key);

    // Store number of iterations.
    int iterations = 0;

    // Find data at the location indicated by hashedKey.
    Data* temp = buckets[hashedKey];
    while (temp != nullptr) {
        iterations++;
        if (temp->key == key) {
            cout << "Found in " << iterations << " iterations." << endl;
            return {temp->value, true};
        }
        temp = temp->next;
    }
    cout << "Not found." << endl;
    return {INT_MAX, false};
}

void HashTable::printBucket(int hashedKey) {
    Data* temp = buckets[hashedKey];

    while (temp != nullptr) {
        cout << temp->value << endl;
        temp = temp->next;
    }
}
