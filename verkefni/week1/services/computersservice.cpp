#include "services/computersservice.h"
#include "utilities/computerscomparator.h"

#include <algorithm>

using namespace std;

ComputersService::ComputersService()
{

}

vector<Computers> ComputersService::getAllComputers(string orderBy, bool orderAscending)
{
    vector<Computers> computers = computersRepo.getAllComputers();

    sort(computers.begin(), computers.end(), ComputersComparator(orderBy, orderAscending));

    return computers;
}

vector<Computers> ComputersService::searchForComputers(string searchTerm)
{
    return computersRepo.searchForComputers(searchTerm);
}

bool ComputersService::addComputers(Computers computers)
{
    return computersRepo.addComputers(computers);
}
