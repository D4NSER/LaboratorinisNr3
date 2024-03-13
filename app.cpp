#include "funkcijosDEQUE.h"
#include "funkcijosVECTOR.h"
#include "funkcijosLIST.h"
#include <iostream>
#include <vector>
#include <limits>
#include <deque>
#include <list>

enum class ContainerType { None, Vector, List, Deque };
enum class Action { None, Generate, Sort };

ContainerType getContainerChoice() {
    int choice;
    while (true) { // Loop until a valid input is received
        std::cout << "Pasirinkite konteinerio tipą:\n"
                  << "1. Vector\n"
                  << "2. List\n"
                  << "3. Deque\n"
                  << "Pasirinkimas: ";
        std::cin >> choice;
        if (std::cin.fail()) { // Check if the input was not an integer
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Skip to the next line
            std::cout << "Įveskite skaičių.\n";
        } else if (choice >= 1 && choice <= 3) {
            break; // Break the loop on valid input
        } else {
            std::cout << "Netinkamas pasirinkimas. Prašome bandyti dar kartą.\n";
        }
    }

    switch (choice) {
        case 1: return ContainerType::Vector;
        case 2: return ContainerType::List;
        case 3: return ContainerType::Deque;
        default: return ContainerType::None; // This default case should never be reached due to the loop above
    }
}

Action getActionChoice() {
    int choice;
    while (true) { // Loop until a valid input is received
        std::cout << "Pasirinkite veiksmą:\n"
                  << "1. Generuoti studentų failus\n"
                  << "2. Rūšiuoti esamus studentų failus\n"
                  << "Pasirinkimas: ";
        std::cin >> choice;
        if (std::cin.fail()) { // Check if the input was not an integer
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Skip to the next line
            std::cout << "Įveskite skaičių.\n";
        } else if (choice == 1 || choice == 2) {
            break; // Break the loop on valid input
        } else {
            std::cout << "Netinkamas pasirinkimas. Prašome bandyti dar kartą.\n";
        }
    }

    switch (choice) {
        case 1: return Action::Generate;
        case 2: return Action::Sort;
        default: return Action::None; // This default case should never be reached due to the loop above
    }
}

void performAction(ContainerType containerChoice, Action actionChoice, const std::vector<int>& sizes) {
    if (actionChoice == Action::Generate) {
        for (int size : sizes) {
            switch (containerChoice) {
                case ContainerType::Vector:
                    generateStudentFilesVector(size);
                    break;
                case ContainerType::List:
                    generateStudentFilesList(size);
                    break;
                case ContainerType::Deque:
                    generateStudentFilesDeque(size);
                    break;
                default:
                    std::cout << "Nepasirinktas tinkamas konteinerio tipas.\n";
                    break;
            }
        }
    } else if (actionChoice == Action::Sort) {
        for (int size : sizes) {
            switch (containerChoice) {
                case ContainerType::Vector:
                    rusiuotStudentusVector(size);
                    break;
                case ContainerType::List:
                    divideStudentsList(size);
                    break;
                case ContainerType::Deque:
                    divideStudentsDeque(size);
                    break;
                default:
                    std::cout << "Nepasirinktas tinkamas konteinerio tipas.\n";
                    break;
            }
        }
    }
}

void runApp() {
    std::vector<int> sizes = { 1000, 10000, 100000, 1000000, 10000000 };

    ContainerType containerChoice = getContainerChoice();
    if (containerChoice == ContainerType::None) {
        return;
    }

    Action actionChoice = getActionChoice();
    if (actionChoice == Action::None) {
        return;
    }

    performAction(containerChoice, actionChoice, sizes);
}

