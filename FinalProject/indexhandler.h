#ifndef INDEXHANDLER_H
#define INDEXHANDLER_H

#include "avltreeinterface.h"
#include "hashtableindex.h"
#include "hashtableinterface.h"
#include "indexinterface.h"
#include "queryprocessor.h"

#include <vector>

using namespace std;
/*! \brief
 * AVL Node implementation for the AVL Tree structure.
 */
class IndexHandler
{
public:
    IndexHandler();
    ~IndexHandler();
    IndexHandler(bool asHashTable);



    // Inits all PageInfo objects from the current file.  Since the persistence
    // file has already been written, if the filePath is "WikiBooks.xml", it will
    // instead load data for each term from the persistence file.
    void read_file(string filePath);

    void run_queries(string query);

    void clear_index();

private:
    IndexInterface* index;
};

#endif // INDEXHANDLER_H
