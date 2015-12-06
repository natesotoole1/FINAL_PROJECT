#ifndef TERM_H
#define TERM_H

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "indexinterface.h"

using namespace std;

typedef unordered_map<int, int> pageMap;
typedef unordered_map<int, double> tdidfMap;

class IndexInterface;
/*! \brief
 * Term creates the terms for the persistent index
 * creates a page map of aprns to get relevancy
 */
class Term
{
public:
    Term();
    ~Term();

    Term(string theName);
    Term(string theName, pageMap& theAprns);

    void add_pageAprn(int freq, int pageID);


    void init_spread_and_totalFreq();
    void init_tdidfs(IndexInterface& index);
    void incrm_aprn_for_pageID(int currID);

    pageMap get_pageAprns();
    string get_name();
    Term* get_next();
    int get_spread();
    int get_totalFreq();
    double get_tdidf_for_page(int pageID);
    //void getTerm;

    void set_next(Term* theNext);

    void write_term(ofstream& persistence);


private:
    // Holds the IDs of pages on which it appeared.
    pageMap pageAprns;

    string name;

    // For the linked list functionality of each TermBucket.
    // Only used in HashTableIndex.
    Term* next;

    // The number of unique documents on which the term has appeared.
    int spread;

    tdidfMap tdidfs;

    int totalFreq;
};

#endif // TERM_H
