#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "services/scientistservice.h"
#include "services/computersservice.h"

/**
 * @brief Holds commands that are available in the UI
 */
enum command {
    menu,
    add,
    add2,
    display,
    search,
    sort,
    sort2,
    back,
    quit,
    unknown,
    display2

};

class ConsoleUI
{
public:
    ConsoleUI();

    /**
     * @brief start is the main run loop for the application
     * @return should indicate how the program exists, currently always safely
     */
    int start();

private:
    /**
     * @brief display serves as a router to according display functions
     */
    void display();

    /**
     * @brief readInput handles user input by settings commands or processing it
     */
    void readInput();

    void displayMenu();
    void displayAddScientistMenu();
    void displayAddComputerMenu();
    void displayAllScientists();
    void displayAllComputers();
    void displayScientistSearchMenu();
    void displayScientistSortMenu();
    void displayUnknownCommandMenu();
    void displayScientists(std::vector<Scientist> scientists);
    void displayComputers(std::vector<Computers> computers);

    /**
     * @brief addCommandHandler calls the addScientist function and notifies the user how it went
     * @param userInput the input the user is trying to create a scientist from
     */
    void addCommandHandler(std::string userInput);
    void add2CommandHandler(std::string userInput);

    /**
     * @brief sortCommandHandler calls the setSort function and notifies the user how it went
     * @param userInput the input the user is trying to change sort from
     */
    void sortCommandHandler(std::string userInput);

    /**
     * @brief searchCommandHandler calls the scientistService displays a list of filtered users
     * @param userInput a string sent as input to the search function
     */
    void searchCommandHandler(std::string userInput);

    /**
     * @brief addScientist attempts to add a scientist
     * @param data A string containing the user input
     * @return true if it was a success, false if it was a failure
     */
    bool addScientist(std::string data);
    bool addComputers(std::string data);

    /**
     * @brief setSort attempts to change how scientists will be sorted based on userinput
     * @param sortCommand the sort rule, rules are stored in constants.h
     * @return true if it was a success, false if it was a failure
     */
    bool setSort(std::string sortCommand);
    bool setSort2(std::string sort2Command);

    void displayError(std::string error);

    ScientistService scientistService;
    ComputersService computersService;
    enum command lastCommand;

    std::string sortBy;
    bool sortAscending;
};

#endif // CONSOLEUI_H
