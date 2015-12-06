#ifndef TERMBUCKET_H
#define TERMBUCKET_H

#include "term.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

typedef unordered_map<int, int> pageMap;
/*! \brief
 * linked list of Term objects
 */
class TermBucket
{
public:
    TermBucket();
    ~TermBucket();

    void add_term_to_bucket(Term* term);
    Term *&find(string term);
    bool has_word(string term);
    void write_term_bucket(ofstream& persistence);
    void clear();
    Term *getTerm();
private:
    Term* root;
};


#endif // TERMBUCKET_H
