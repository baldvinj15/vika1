#include "models/computers.h"
#include "utilities/utils.h"
#include "utilities/constants.h"
#include <string>

using namespace std;

Computers::Computers(string name, enum comType type, int yearBuild) //lagaði þetta (var string type)
{
    this->name = name;
    this->type = type;
    this->yearBuild = yearBuild;
}

Computers::Computers(string name, enum comType type, int yearBuild, string built) //lagaði þetta(var string type)
{
    this->name = name;
    this->type = type;
    this->yearBuild = yearBuild;
    this->built = built;
}

string Computers::getName() const
{
    return name;
}

enum comType Computers::getType() const
{
    return type;
}

int Computers::getYearBuild() const
{
    return yearBuild;
}

string Computers::didItGetBuilt() const
{
    return built;
}

//<<<<<<< Updated upstream

bool Computers::contains(string searchTerm)
{
    string searchTermLower = utils::stringToLower(searchTerm);

    string nameLower = utils::stringToLower(name);
    if (nameLower.find(searchTermLower) != string::npos)
    {
        return true;
    }

    if (searchTermLower == "electronic" && type == comType::electronic)
    {
        return true;
    }

    if (searchTermLower == "mechanic" && type == comType::mechanic)
    {
        return true;
    }

    string yearBuildString = utils::intToString(yearBuild);

    if (yearBuildString.find(searchTerm) != string::npos)
    {
        return true;
    }

    else
    {
        if (searchTermLower == "Built")
        {
            return true;
        }
    }

    return false;
}
