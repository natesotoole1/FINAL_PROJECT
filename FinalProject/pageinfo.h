#ifndef PAGEINFO_H
#define PAGEINFO_H

#include <string>

using namespace std;
/*! \brief
 * AVL Node implementation for the AVL Tree structure.
 */
class PageInfo
{
public:
    PageInfo();
    ~PageInfo();
    PageInfo(string theContent, string theContributor, string theTimestamp, string theTitle);

    // Getters.
    string get_content();
    string get_contributor();
    string get_timestamp();
    string get_title();
    int get_totalWords();

    // Setters.
    void set_content(string theContent);
    void set_contributor(string theInfo);
    void set_timestamp(string theTimestamp);
    void set_title(string theTitle);

    void incr_totalWords(int incr);
    void set_totalWords(int theTotal);
private:
    string content;
    string contributorNameOrIP;
    string timestamp;
    string title;
    int totalWords;
};

#endif // PAGEINFO_H
