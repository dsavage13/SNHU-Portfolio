#include "ItemTracker.h"

#include <iostream>
#include <sstream>
#include <string>

namespace {

void printMenu() {
    std::cout << "\n" << std::string(40, '=') << '\n'
              << "       CORNER GROCER ITEM TRACKER\n"
              << std::string(40, '=') << '\n'
              << "1. Find the frequency of an item\n"
              << "2. Display all item frequencies\n"
              << "3. Display frequency histogram\n"
              << "4. Exit\n"
              << std::string(40, '-') << '\n';
}

int readMenuChoice() {
    while (true) {
        std::cout << "Enter your choice (1-4): ";
        std::string input;
        std::getline(std::cin, input);
        std::istringstream inputStream(input);
        int choice = 0;
        char extraCharacter = '\0';

        if (inputStream >> choice && !(inputStream >> extraCharacter) &&
            choice >= 1 && choice <= 4) {
            return choice;
        }
        std::cout << "Invalid selection. Please enter 1, 2, 3, or 4.\n";
    }
}

}  // namespace

int main() {
    const std::string inputFileName = "CS210_Project_Three_Input_File.txt";
    const std::string backupFileName = "frequency.dat";
    ItemTracker tracker;

    if (!tracker.loadItems(inputFileName)) {
        std::cerr << "Error: Unable to read " << inputFileName << ".\n"
                  << "Place the input file in the same folder as the program.\n";
        return 1;
    }

    // The required backup is created automatically before the menu is displayed.
    if (!tracker.createBackupFile(backupFileName)) {
        std::cerr << "Error: Unable to create " << backupFileName << ".\n";
        return 1;
    }

    bool keepRunning = true;
    while (keepRunning) {
        printMenu();
        switch (readMenuChoice()) {
            case 1: {
                std::cout << "Enter an item to find: ";
                std::string itemName;
                std::getline(std::cin, itemName);
                std::cout << itemName << " appeared "
                          << tracker.getItemFrequency(itemName) << " time(s).\n";
                break;
            }
            case 2:
                tracker.printAllFrequencies();
                break;
            case 3:
                tracker.printHistogram();
                break;
            case 4:
                keepRunning = false;
                break;
        }
    }

    std::cout << "Thank you for using the Corner Grocer Item Tracker.\n";
    return 0;
}
