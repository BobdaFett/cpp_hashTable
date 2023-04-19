#include <cstdio>
#include <vector>
#include "HashTable.h"

using std::vector;
using std::get;

int main() {

    printf("Creating HashTables... ");
    HashTable table3 = HashTable(5);
    HashTable table10 = HashTable(3);
    HashTable table15 = HashTable(15);
    printf("Done.\n");

    printf("Inserting values into HashTables... ");
    for (int i = 0; i < 15; i++)
        table3.insert(i, i);
    for (int i = 0; i < 30; i++)
        table10.insert(i, i);
    for (int i = 0; i < 225; i++)
        table15.insert(i, i);
    printf("Done.\n");

    #pragma region Print searching information
    // There was definitely an easier way of going about this.
    printf("Searching for various values in the lists.\n");
    vector<int> t3_iter, t10_iter, t15_iter;
    printf("Searching for %i in table3... ", 2);
    t3_iter.push_back(get<int>(table3.search(2)));
    printf("Searching for %i in table3... ", 5);
    t3_iter.push_back(get<int>(table3.search(5)));
    printf("Searching for %i in table3... ", 10);
    t3_iter.push_back(get<int>(table3.search(10)));

    printf("Searching for %i in table10... ", 15);
    t10_iter.push_back(get<int>(table10.search(15)));
    printf("Searching for %i in table10... ", 20);
    t10_iter.push_back(get<int>(table10.search(20)));
    printf("Searching for %i in table10... ", 3);
    t10_iter.push_back(get<int>(table10.search(3)));

    printf("Searching for %i in table15... ", 6);
    t15_iter.push_back(get<int>(table15.search(6)));
    printf("Searching for %i in table15... ", 150);
    t15_iter.push_back(get<int>(table15.search(150)));
    printf("Searching for %i in table15... ", 220);
    t15_iter.push_back(get<int>(table15.search(220)));
    #pragma endregion

    float t3_avg = 0, t10_avg = 0, t15_avg = 0;
    for (int i : t3_iter)
        t3_avg += (float) i;
    for (int i : t10_iter)
        t10_avg += (float) i;
    for (int i : t15_iter)
        t15_avg += (float) i;

    t3_avg /= (float) t3_iter.size();
    t10_avg /= (float) t10_iter.size();
    t15_avg /= (float) t15_iter.size();

    printf("Average number of iterations for table3: %f\n", t3_avg);
    printf("Average number of iterations for table3: %f\n", t10_avg);
    printf("Average number of iterations for table3: %f\n", t15_avg);

    return 0;
}
