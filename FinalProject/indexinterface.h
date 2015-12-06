#ifndef INDEXINTERFACE_H
#define INDEXINTERFACE_H

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <math.h>
#include <pthread.h>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include <unordered_map>
#include "docparser.h"
#include "pageinfo.h"
#include "term.h"


class DocParser;
class HashTableIndex;
class Term;

typedef unordered_map<int, int> pageMap;

/*! \brief
 * AVL Node implementation for the AVL Tree structure.
 */


using namespace std;
/*! \brief
 * AVL Node implementation for the AVL Tree structure.
 */
class IndexInterface
{
public:

    IndexInterface();
    ~IndexInterface();

    //void add_term_to_persistence(Term* term);
    void append_page_info(PageInfo* currInfo);
    double calc_tdidf(int pageID, int freq, int spread);
    void display_result(int rank, int pageID, double tdidf);
    void display_page_content(int pageID);
    void incr_total_words_on_page(int currID, int incr);
    void read_file(string filePath);
    void read_persistence_files();
    void read_pers_file(int index);

    virtual void add_term_to_ii(int letterIndex, Term *term);
    virtual void clear();

    virtual Term*& find_term(string term);
    virtual void write_persistence_files();

    int index_for_letter(char letter);
    PageInfo* info_for_pageID(int pageID);

    int get_totalWordsInCorpus();
    int get_totalPages();

protected:
    const string ext = ".txt";

    // Only used for HashTableIndex.
    HashTableIndex* letters;

    // PageInfo will be passed by a pageID (int).
    vector<PageInfo*> infoForIDs;

    DocParser& parser;

    int totalPages;
    int totalWordsInCorpus;
};

#endif // INDEXINTERFACE_H
