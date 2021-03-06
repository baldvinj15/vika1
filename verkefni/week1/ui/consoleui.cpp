#include "ui/consoleui.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

#include <iostream>
#include <iomanip>

using namespace std;

ConsoleUI::ConsoleUI()
{
    lastCommand = command::menu;
    sortBy = "name";
    sortAscending = true;
}

int ConsoleUI::start()
{
    while(lastCommand != command::quit)
    {
        display();
        readInput();
    }

    return 0;
}

void ConsoleUI::display()
{
    switch (lastCommand)
    {
        case command::menu:
            displayMenu();
            break;
        case command::add:
            displayAddScientistMenu();
            break;
        case command::add2:
            displayAddComputerMenu();
            break;
        case command::display:
            displayAllScientists();
            break;
        case command::display2:
            displayAllComputers();
            break;
        case command::search:
            displayScientistSearchMenu();
            break;
        case command::search2:
            displayComputerSearchMenu();
            break;
        case command::sort:
            displayScientistSortMenu();
            break;
        case command::sort2:
             displayComputerSortMenu();
             break;
        default:
            displayUnknownCommandMenu();
            break;
    }
}

void ConsoleUI::readInput()
{
    if (lastCommand == command::display)
    {
        lastCommand = command::sort;
        return;
    }
    else if (lastCommand == command::display2)
    {
        lastCommand = command::sort2;
        return;
    }

    string userInput;
    getline(cin, userInput);

    cout << "\n\n";

    bool shouldTreatInputAsCommand = (lastCommand != command::search);

    if (userInput == "display" && shouldTreatInputAsCommand)
    {
        lastCommand = command::sort;
    }
    if (userInput == "display2" && shouldTreatInputAsCommand)
    {
        lastCommand = command::sort2;
    }
    else if (userInput == "add" && shouldTreatInputAsCommand)
    {
        lastCommand = command::add;
    }
    else if (userInput == "add2" && shouldTreatInputAsCommand)
    {
        lastCommand = command::add2;
    }
    else if (userInput == "search" && shouldTreatInputAsCommand)
    {
        lastCommand = command::search;
    }
    else if (userInput == "search2" && shouldTreatInputAsCommand)
    {
        lastCommand = command::search2;
    }
    else if (userInput == "back")
    {
        lastCommand = command::menu;
    }
    else if (userInput == "quit")
    {
        lastCommand = command::quit;
    }
    else
    {
        if (lastCommand == command::add)
        {
            addCommandHandler(userInput);
        }
        else if (lastCommand == command::add2)
        {
            addCommandHandler2(userInput);
        }
        else if (lastCommand == command::sort)
        {
            sortCommandHandler(userInput);
        }
        else if (lastCommand == command::sort2)
        {
            sortCommandHandler2(userInput);
        }
        else if (lastCommand == command::search)
        {
            searchCommandHandler(userInput);
        }
        else if (lastCommand == command::search2)
        {
            searchCommandHandler2(userInput);
        }
        else
        {
            lastCommand = command::unknown;
        }
    }
}

void ConsoleUI::addCommandHandler(string userInput)
{
    if (addScientist(userInput)) {
        cout << "Successfully added a scientist\n\n";
        lastCommand = command::menu;
    }
    else
    {
        displayError("There was an error in your input.");
    }
}
void ConsoleUI::addCommandHandler2(string userInput) {
    if (addComputer(userInput)) {
        cout << "Successfully added a computer\n\n";
        lastCommand = command::menu;
        }
    else
    {
        displayError("There was an error in your input.");
    }
}

void ConsoleUI::sortCommandHandler(string userInput)
{
    if (setSort(userInput))
    {
        lastCommand = command::display;
    }
    else
    {
        displayError("Your input did not match any of the sort commands");
    }
}
void ConsoleUI::sortCommandHandler2(string userInput)
{
    if (setSort2(userInput))
        {
            lastCommand = command::display2;
        }
        else
        {
            displayError("Your input did not match any of the sort commands");
        }
}

void ConsoleUI::searchCommandHandler(string userInput)
{
    displayScientists(scientistService.searchForScientists(userInput));
}
void ConsoleUI::searchCommandHandler2(string userInput)
{
    displayComputers(computersService.searchForComputers(userInput));
}

void ConsoleUI::displayMenu()
{
    cout << "Enter a command:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "add:" << "Adds a scientist\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "display:" << "Displays scientists\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "search:" << "Search for a scientist\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "quit:" << "Quits the program\n\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "add2:" << "Adds a computer\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "display2:" << "Displays computers\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << "search2:" << "Search for a computer\n";

    cout << "Command: ";
}

void ConsoleUI::displayAddScientistMenu()
{
    cout << "To add a scientist, type in:\n";
    cout << "Name,sex,yearBorn,yearDied (optional)\n";
    cout << "Comma separated like in the example above.\n\n";
    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayAddComputerMenu(){
    cout << "To add a computer, type in:\n";
    cout << "Name, type, year built,was it built?\n";
    cout << "Comma seperated like in example above.\n\n";
    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayAllScientists()
{
    vector<Scientist> scientists = scientistService.getAllScientists(sortBy, sortAscending);

    displayScientists(scientists);

    cout << '\n';

    lastCommand = command::display;
}

void ConsoleUI::displayAllComputers(){
    vector<Computers> computers = computersService.getAllComputers(sortBy, sortAscending);

    displayComputers(computers);

    cout << '\n';

    lastCommand = command::display2;
}

void ConsoleUI::displayScientistSearchMenu()
{
    cout << "Search for a scientist.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}
void ConsoleUI::displayComputerSearchMenu()
{
    cout << "Search for a Computer.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayScientistSortMenu()
{
    cout << "How should the list be sorted:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_NAME_ASCENDING << "Sorts by name, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_NAME_DESCENDING << "Sorts by name, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING << "Sorts by year born, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING << "Sorts by year born, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING << "Sorts by year died, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING << "Sorts by year died, descending.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";

    cout << "Command: ";
}

void ConsoleUI::displayComputerSortMenu()
{
    cout << "How should the list be sorted:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_NAME_ASCENDING << "Sorts by name, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_NAME_DESCENDING << "Sorts by name, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_YEAR_BUILT_ASCENDING << "Sorts by year built, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_YEAR_BUILT_DESCENDING << "Sorts by year built, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_TYPE_ASCENDING << "Sorts by type, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << std::left
         << constants::SORT_COMPUTER_TYPE_DESCENDING << "Sorts by type, descending.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";

    cout << "Command: ";
}

void ConsoleUI::displayUnknownCommandMenu()
{
    displayError("Unknown command");
    cout << "Command: ";
}

void ConsoleUI::displayScientists(std::vector<Scientist> scientists)
{
    if (scientists.size() == 0)
    {
        cout << "No scientist found.\n";
        return;
    }

    cout << "Printing all scientists:\n";

    cout << setw(20) << std::left << "Name:"
         << setw(8) << std::left << "Sex:"
         << setw(12) << std::left << "Year born:"
         << setw(12) << std::left << "Year died:" << endl;

    for (unsigned int i = 0; i < scientists.size(); i++)
    {
        string scientistSex = (scientists.at(i).getSex() == sexType::male) ? "Male" : "Female";

        int yearDied = scientists.at(i).getYearDied();
        string died = (yearDied == constants::YEAR_DIED_DEFAULT_VALUE) ? "Alive" : utils::intToString(yearDied);

        cout << setw(20) << std::left << scientists.at(i).getName()
             << setw(8) << std::left << scientistSex
             << setw(12) << std::left << scientists.at(i).getYearBorn()
             << setw(12) << std::left << died << endl;
    }
}
void ConsoleUI::displayComputers(std::vector<Computers> computers){
    if (computers.size() == 0)
    {
        cout << "No computers found.\n";
        return;
    }

    cout << "Printing all computers:\n";

    cout << setw(20) << std::left << "Name:"
         << setw(12) << std::left << "Type:"
         << setw(40) << std::left << "Year build:"
         << setw(12) << std::left << endl;

    for (unsigned int i = 0; i < computers.size(); i++)
    {
        string computersType = (computers.at(i).getType() == comType::mechanic) ? "Mechanic" : "Electronic";

        cout << setw(20) << std::left << computers.at(i).getName()
             << setw(12) << std::left << computersType
             << setw(12) << std::left << computers.at(i).getYearBuild()
             << setw(12) << std::left << endl;
    }
}

bool ConsoleUI::addScientist(string data)
{
    vector<string> fields = utils::splitString(data, ',');

    if (fields.size() > 2 && fields.size() < 5)
    {
        string name = fields.at(0);

        enum sexType sex;
        if (fields.at(1) == "male")
        {
            sex = sexType::male;
        }
        else
        {
            sex = sexType::female;
        }
        int yearBorn = utils::stringToInt(fields.at(2));

        if (fields.size() == 3)
        {
            return scientistService.addScientist(Scientist(name, sex, yearBorn));
        }
        else
        {
            int yearDied = utils::stringToInt(fields.at(3));

            return scientistService.addScientist(Scientist(name, sex, yearBorn, yearDied));
        }
    }

    return false;
}

bool ConsoleUI::addComputer(string data)
{
    vector<string> fields = utils::splitString(data, ',');

    if (fields.size() > 2 && fields.size() < 5)
    {
        string name = fields.at(0);

        enum comType type;
        if (fields.at(1) == "mechanic")
        {
            type = comType::mechanic;
        }
        else
        {
            type = comType::electronic;
        }
        int yearBuild = utils::stringToInt(fields.at(2));

        if (fields.size() == 3)
        {
            return computersService.addComputers(Computers(name, type, yearBuild));
        }
        else
        {
            string DidItGetBuilt = (fields.at(3));

            return computersService.addComputers(Computers(name, type, yearBuild, DidItGetBuilt));
        }
    }

    return false;
}


bool ConsoleUI::setSort(string sortCommand)
{
    if (sortCommand == constants::SORT_SCIENTIST_NAME_ASCENDING)
    {
        sortBy = "name";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_NAME_DESCENDING)
    {
        sortBy = "name";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING)
    {
        sortBy = "yearBorn";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING)
    {
        sortBy = "yearBorn";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING)
    {
        sortBy = "yearDied";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING)
    {
        sortBy = "yearDied";
        sortAscending = false;
    }
    else
    {
        return false;
    }

    return true;
}
bool ConsoleUI::setSort2(string sortCommand)
{
    if (sortCommand == constants::SORT_COMPUTER_NAME_ASCENDING)
    {
        sortBy = "name";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_NAME_DESCENDING)
    {
        sortBy = "name";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_COMPUTER_YEAR_BUILT_ASCENDING)
    {
        sortBy = "yearBuilt";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_YEAR_BUILT_DESCENDING)
    {
        sortBy = "yearBuilt";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_COMPUTER_TYPE_ASCENDING)
    {
        sortBy = "Type";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_TYPE_DESCENDING)
    {
        sortBy = "Type";
        sortAscending = false;
    }
    else
    {
        return false;
    }

    return true;
}

void ConsoleUI::displayError(string error)
{
    cout << "There was an error: " << error << "\n";
    cout << "Please try again or type 'back' to go back.\n\n";
}
