#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "docparser.h"
#include "porter2_stemmer.h"
#include "term.h"

using namespace std;

// First = pageID; total = TD-IDF across all queried terms.
typedef pair<int, double> resultPair;

typedef unordered_map<int, double> relevancyMap;
/*! \brief
 * gets the queries for each search created in Interface
 */
class QueryProcessor
{
public:
    //QueryProcessor();
    ~QueryProcessor();
    QueryProcessor(IndexInterface &theIndex);

    void answer_query(istringstream& query, bool intersection);

    void display_best_fifteen_results();



    void initiate_query(string query);

    void init_relev_map(Term* term);
    void intersection_incr_relev_map(Term* term);
    void union_incr_relev_map(Term* term);

    void sort_results();

    // write this

private:
    relevancyMap results;
    vector<resultPair> sortedResults;

    IndexInterface& index;
};

#endif // QUERYPROCESSOR_H
