#include "repositories/computersrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

#include <fstream>
#include <cstdlib>

using namespace std;




ComputersRepository::ComputersRepository()
{
    fileName = constants::DATA_FILE_NAME1;
}

std::vector<Computers> ComputersRepository::getAllComputers()
{
    ifstream file;

    file.open(fileName.c_str());

    vector<Computers> computers;

    if (file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            vector<string> fields = utils::splitString(line, constants::FILE_DELIMETER);

            if (fields.size() >= 3)
            {
                string name = fields.at(0);
                enum comType type = utils::stringToType(fields.at(1));
                int yearBuild = utils::stringToInt(fields.at(2));

                if (fields.size() == 3)
                {
                    computers.push_back(Computers(name, type, yearBuild));
                }
                else
                {
                    string getBuilt = (fields.at(3));

                    computers.push_back(Computers(name, type, yearBuild, getBuilt));
                }
            }
        }
    }

    file.close();

    return computers;
}

vector<Computers> ComputersRepository::searchForComputers(string searchTerm)
{
    vector<Computers> allComputers = getAllComputers();
    vector<Computers> filteredComputers;

    for (unsigned int i = 0; i < allComputers.size(); i++)
    {
        if (allComputers.at(i).contains(searchTerm))
        {
            filteredComputers.push_back(allComputers.at(i));
        }
    }

    return filteredComputers;
}

bool ComputersRepository::addComputers(Computers computers)
{
    ofstream file;

    file.open(fileName.c_str(), std::ios::app);

    if (file.is_open())
    {
        string name = computers.getName();
        enum comType type = computers.getType();
        int yearBuild = computers.getYearBuild();
        string didItGetBuilt = computers.didItGetBuilt();

        file << name << constants::FILE_DELIMETER
             << type << constants::FILE_DELIMETER
             << yearBuild << constants::FILE_DELIMETER;

        if (didItGetBuilt != constants::DID_IT_GET_BUILT)
        {
            file << didItGetBuilt;
        }

        file << '\n';
    }
    else
    {
        return false;
    }

    file.close();
    return true;
}

