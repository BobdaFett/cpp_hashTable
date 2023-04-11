#include <iostream>
#include "HashTable.h"

using std::cout;
using std::endl;

int main() {
    cout << "Creating HashTable... ";
    HashTable table = HashTable(17);
    cout << "Done." << endl;

    cout << "We will insert values from 1 through 200 to illustrate collisions." << endl;
    for (int i = 1; i <= 200; i++) {
        auto [iters, success] = table.insert(i, i);
        cout << "Insertion of " << i << " took " << iters << " iterations." << endl;
    }

    cout << "Finding 77: ";
    table.search(77);

    cout << "Finding 200: ";
    table.search(200);

    cout << "Printing bucket 13:" << endl;
    table.printBucket(12);

    return 0;
}
