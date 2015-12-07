#ifndef COMPUTERS_H
#define COMPUTERS_H

#include <string>

using namespace std;

enum comType{ //lagaði þetta
    mechanic,
    electronic
};


class Computers
{
public:
    Computers(string name, enum comType type, int yearBuild); //(breyttir úr string type í enum comType type)
    Computers(string name, enum comType type, int yearBuild, string built); //(breyttir úr string type í enum comType type)

    string getName() const;
    enum comType getType() const;
    int getYearBuild() const;
    string didItGetBuilt() const;
    bool contains(string searchTerm);

private:
    string name;
    enum comType type;
    int yearBuild;
    string built;
};

#endif // COMPUTERS_H
