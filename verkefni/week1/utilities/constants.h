#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
using namespace std;
/**
 * This file contains constants that this application uses
 */

namespace constants {
    const string DATA_FILE_NAME = "database.txt";
    const string DATA_FILE_NAME1 = "database1.txt";
    const char FILE_DELIMETER = '\t';
    const int YEAR_DIED_DEFAULT_VALUE = 13337;
    const string DID_IT_GET_BUILT = "No";

    const unsigned int MENU_COMMAND_WIDTH = 15;

    const string SORT_SCIENTIST_NAME_ASCENDING = "name-asc";
    const string SORT_SCIENTIST_NAME_DESCENDING = "name-desc";
    const string SORT_SCIENTIST_YEAR_BORN_ASCENDING = "born-asc";
    const string SORT_SCIENTIST_YEAR_BORN_DESCENDING = "born-desc";
    const string SORT_SCIENTIST_YEAR_DIED_ASCENDING = "died-asc";
    const string SORT_SCIENTIST_YEAR_DIED_DESCENDING = "died-desc";
    const string SORT_COMPUTER_NAME_ASCENDING = "name-asc";
    const string SORT_COMPUTER_NAME_DESCENDING = "name-desc";
    const string SORT_COMPUTER_YEAR_BUILT_ASCENDING = "built-asc";
    const string SORT_COMPUTER_YEAR_BUILT_DESCENDING = "built-desc";
    const string SORT_COMPUTER_TYPE_ASCENDING = "type-asc";
    const string SORT_COMPUTER_TYPE_DESCENDING = "type-desc";
}

#endif // CONSTANTS_H

