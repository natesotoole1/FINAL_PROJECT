#ifndef HASHTABLEINDEX_H
#define HASHTABLEINDEX_H


#include "term.h"
#include "termbucket.h"

#include <string>
#include <vector>
#include <fstream>

using namespace std;

typedef unordered_map<int, int> pageMap;
/*! \brief
 * Hash Table Index implementation for the hash table data structure.
 * connects to term buckets and creates a 1024 of them
 */
class HashTableIndex
{
public:
    HashTableIndex();
    ~HashTableIndex();

    void add_term_to_ht_index(Term* term);
    Term*& find(string term);
    int hash_key(string key);
    void write_hti(ofstream& persistence);
    void clear_table();
private:
    const int arrSize = 1000001;
    TermBucket* buckets;

};

#endif // HASHTABLEINDEX_H
