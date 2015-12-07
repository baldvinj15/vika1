#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>

#include "models/scientist.h"
#include "models/computers.h" //til þess að geta unnið með computers skjölunum
using namespace std;
/**
 * This file contains reusable utility functions used throughout the application
 */

namespace utils {
    vector<string> splitString(string line, char delimeter);

    int stringToInt(string str);

    string stringToLower(string str);

    string intToString(int number);

   // string stringToType(string str); //bætti þessu við

    enum comType stringToType(string str);

    enum comType intToType(int number); //bætti þessu við

    enum sexType intToSex(int number);

    enum sexType stringToSex(string str);



}

#endif  //UTILS_H

