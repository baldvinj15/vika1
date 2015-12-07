#ifndef COMPUTERSSERVICE_H
#define COMPUTERSSERVICE_H

#include "repositories/computersrepository.h"
using namespace std;

/**
 * @brief The ScientistService acts as a middle layer between the UI and Data layers, also handles sorting
 */
class ComputersService
{
public:
    ComputersService();

    /**
     * @brief getAllScientists fetches scientists from the ScientistRepository and sorts them
     * @param orderBy Which column the scientists should be sorted on
     * @param orderAscending Should the list be sorted in ascending order?
     * @return a vector containing all scientists in the repository
     */
    vector<Computers> getAllComputers(string orderBy, bool orderAscending);

    /**
     * @brief searchForScientists fetches all scientists from file and filters them on searchTerm
     * @param searchTerm Contains the input that the user wishes to filter on
     * @return a vector of scientists filtered by searchTerm
     */
   vector<Computers> searchForComputers(string searchTerm);

    /**
     * @brief addScientist saves a scientist model to a file
     * @param scientist The model to save
     * @return true if it was a success, false if it was a failure
     */
    bool addComputers(Computers computers);
private:
    ComputersRepository computersRepo;
};

#endif // COMPUTERSSERVICE_H
