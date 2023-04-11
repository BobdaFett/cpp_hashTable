//
// Created by Lucas Vas on 4/10/2023.
//

#ifndef CPP_HASHTABLE_HASHTABLE_H
#define CPP_HASHTABLE_HASHTABLE_H

#include <exception>
#include <tuple>

using std::tuple;

/// An implementation of a HashTable in C++
class HashTable {
private:
    struct Data {
        int value;   ///< The data stored in this struct.
        int key;     ///< The key associated with this struct.
        Data* prev;  ///< Pointer to the Data before this.
        Data* next;  ///< Points to the Data after this.
    };

    int hashValue;   ///< The value to use for hashing. Once set, cannot be changed. This also determines the number of buckets.

    Data** buckets;  ///< An array containing all of the buckets of Data. Max size of hashValue.

    /// @returns The hashed value, for the value of a key.
    [[nodiscard]] int hash(int value) const;

public:
    /// Creates a new HashTable object.
    explicit HashTable(int hashValue);

    /// @param key The key to search for.
    /// @returns A Tuple struct containing the value, the number of iterations, and a bool indicating if the search was successful.
    [[nodiscard]] tuple<int, bool> search(int key);

    /// Inserts a key/value pair into the HashTable.
    /// @param key The key to insert.
    /// @param value The value to insert.
    /// @returns A tuple containing the number of iterations required and whether insertion was successful. The way I
    ///          designed it means that it cannot return false however.
    tuple<int, bool> insert(int key, int value);

    /// Prints the whole bucket at the specified index. This index will not be hashed and is a direct accessor.
    void printBucket(int hashedKey);
};


#endif //CPP_HASHTABLE_HASHTABLE_H
