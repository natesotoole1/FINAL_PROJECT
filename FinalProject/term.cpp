/* Search Engine Project
 * CSE 2341: Data Stuctures
 * 05/03/2015
 * Nate O'Toole
 * Kiko Whiteley
 **/
#include "term.h"

Term::Term()
{
    totalFreq = 0;
    spread = 0;
    name = '/0';
}

Term::~Term()
{

}

Term::Term(string theName)
{
    name = theName;
    totalFreq = 0;
    spread = 0;
}

Term::Term(string theName, pageMap &theAprns)
{
    totalFreq = 0;
    spread = 0;
    next = NULL;
    name = theName;
    pageAprns = theAprns;
    /*
    for (auto& aprn : theAprns)
    {
        // First is the pageID, second is the frequency.
        pageAprns.emplace(make_pair(aprn.first, aprn.second));
    }
    */
}

void Term::add_pageAprn(int freq, int pageID)
{
    pageAprns.emplace(make_pair(pageID, freq));
}

void Term::incrm_aprn_for_pageID(int currID)
{
    // If the term has already appeared at currID,
    // increment that frequency by 1.  Otherwise,
    // emplace a new pageAprn (currID, 1).
    try
    {
        pageAprns.at(currID);
    }
    catch (out_of_range& notInPageAprns)
    {
        pageAprns.emplace(make_pair(currID, 1));
        return;
    }
    pageAprns.at(currID)++;
}

void Term::init_spread_and_totalFreq()
{
    spread = pageAprns.size();
    totalFreq = 0; // Just in case this gets called twice.
    for (auto& aprn : pageAprns)
    {
        totalFreq+=aprn.second;
    }

}

void Term::init_tdidfs(IndexInterface &index)
{
    init_spread_and_totalFreq();
    for (auto& page : pageAprns)
    {
        // First = pageID, second = freq.
        double tdidf = index.calc_tdidf(page.first, page.second, spread);
        tdidfs.emplace(make_pair(page.first, tdidf));
    }
}

int Term::get_spread()
{
    return spread;
}

double Term::get_tdidf_for_page(int pageID)
{
    return tdidfs.at(pageID);
}

int Term::get_totalFreq()
{
    return totalFreq;
}

pageMap Term::get_pageAprns()
{
    return pageAprns;
}

string Term::get_name()
{
    return name;
}

Term* Term::get_next()
{
    return next;
}

void Term::set_next(Term* theNext)
{
    next = theNext;
}

void Term::write_term(ofstream &persistence)
{
    persistence<<"! "<<name;
    for (auto& page : pageAprns)
    {
        persistence<<" "<<page.first<<" "<<page.second;
    }
    persistence<<endl;
}

