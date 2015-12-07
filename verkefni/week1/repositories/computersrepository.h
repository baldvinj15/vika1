#ifndef COMPUTERSREPOSITORY_H
#define COMPUTERSREPOSITORY_H

#include <vector>
#include <string>

#include "models/computers.h"
using namespace std;

/**
 * @brief The ScientistRepository class handles reading and writing scientists to and from a file
 */
class ComputersRepository
{
public:
    ComputersRepository();

    /**
     * @brief getAllComputers fetches all scientists from the data file
     * @return a vector containing all scientists in the data file
     */
    vector<Computers> getAllComputers();

    /**
     * @brief searchForComputers fetches all scientists from file and filters them on searchTerm
     * @param searchTerm Contains the input that the user wishes to filter on
     * @return a vector of scientists filtered by searchTerm
     */
    vector<Computers> searchForComputers(string searchTerm);

    /**
     * @brief addComputers saves a scientist model to a file
     * @param scientist The model to save
     * @return true if it was a success, false if it was a failure
     */
    bool addComputers(Computers computers);

private:
    string fileName;
};

#endif // COMPUTERSREPOSITORY_H
