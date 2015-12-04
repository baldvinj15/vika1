#ifndef COMPUTERS_H
#define COMPUTERS_H
#include <QtSql>
#include <string>

using namespace std;




class Computers
{
public:
    Computers(string name, string type, int yearBuild);
    Computers(string name, string type, int yearBuild, bool built);

    string getName() const;
    string getType() const;
    int getYearBuild() const;
    bool didItGetBuilt() const;

    bool contains(string searchTerm);

private:
    string name;
    string type;
    int yearBuild;
    bool built;
};

#endif // COMPUTERS_H
