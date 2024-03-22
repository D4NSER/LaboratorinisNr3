#include "funkcijosDEQUE.h"
#include "funkcijosVECTOR.h"
#include "funkcijosLIST.h"
#include "funkcijos.h"
#include "studentas.h"
#include <iostream>
#include <vector>
#include <limits>
#include <deque>
#include <list>
#include <string>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include <filesystem>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <stdexcept>

enum class ContainerType { None, Vector, List, Deque };
enum class Action { None, Generate, Sort };

ContainerType getContainerChoice() {
    int choice;
    while (true) {
        std::cout << "Pasirinkite konteinerio tipą:\n"
                  << "1. Vector\n"
                  << "2. List\n"
                  << "3. Deque\n"
                  << "Pasirinkimas: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Įveskite skaičių.\n";
        } else if (choice >= 1 && choice <= 3) {
            break;
        } else {
            std::cout << "Netinkamas pasirinkimas. Prašome bandyti dar kartą.\n";
        }
    }

    switch (choice) {
        case 1: return ContainerType::Vector;
        case 2: return ContainerType::List;
        case 3: return ContainerType::Deque;
        default: return ContainerType::None;
    }
}

Action getActionChoice() {
    int choice;
    while (true) {
        std::cout << "Pasirinkite veiksmą:\n"
                  << "1. Generuoti studentų failus\n"
                  << "2. Rūšiuoti esamus studentų failus\n"
                  << "Pasirinkimas: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Įveskite skaičių.\n";
        } else if (choice == 1 || choice == 2) {
            break;
        } else {
            std::cout << "Netinkamas pasirinkimas. Prašome bandyti dar kartą.\n";
        }
    }

    switch (choice) {
        case 1: return Action::Generate;
        case 2: return Action::Sort;
        default: return Action::None;
    }
}

std::string getSortingFileChoice() {
    std::vector<std::string> files;

    std::cout << "Turimi failai:\n";
    int fileIndex = 1;
    for (const auto& entry : std::filesystem::directory_iterator(".")) {
        std::string filename = entry.path().filename().string();
        if (filename.find("studentai") != std::string::npos && filename.find(".txt") != std::string::npos) {
            files.push_back(filename);
            std::cout << fileIndex++ << ". " << filename << "\n";
        }
    }

    if (files.empty()) {
        std::cout << "Nerasti studentų failai.\n";
        return "";
    }

    std::cout << "Pasirinkite failą, kurį norite rūšiuoti: ";
    int choice;
    std::cin >> choice;

    if (std::cin.fail() || choice < 1 || choice > files.size()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Netinkamas pasirinkimas. Įveskite iš naujo.\n";
        return "";
    }

    return files[choice - 1];
}

void performAction(ContainerType containerChoice, Action actionChoice, const std::vector<int>& sizes) {
    if (actionChoice == Action::Generate) {
        for (int size : sizes) {
            auto start = std::chrono::high_resolution_clock::now();
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
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            std::cout << "Užimtas laikas generuojant šio dydžio failą: " << size << ": " << elapsed.count() << "s\n";
        }
    } else if (actionChoice == Action::Sort) {
        std::string filename = getSortingFileChoice();
        if (!filename.empty()) {
            auto start = std::chrono::high_resolution_clock::now();
            switch (containerChoice) {
                case ContainerType::Vector:
                    rusiuotStudentusVector(filename);
                    break;
                case ContainerType::List:
                    divideStudentsList(filename);
                    break;
                case ContainerType::Deque:
                    divideStudentsDeque(filename);
                    break;
                default:
                    std::cout << "Netinkamas konteinerio pasirinkimas.\n";
                    break;
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            std::cout << "Užimtas laikas rūšiojant ir skaidant studentus: " << filename << ": " << elapsed.count() << "s\n";
        }
    }
}


void runApp() {
    std::vector<int> sizes = {1000, 10000, 100000, 1000000, 10000000};
    bool exitProgram = false;

    while (!exitProgram) {
        ContainerType containerChoice = getContainerChoice();
        if (containerChoice == ContainerType::None) {
            continue;
        }

        Action actionChoice = getActionChoice();
        if (actionChoice == Action::None) {
            continue;
        }

        performAction(containerChoice, actionChoice, sizes);

        std::cout << "Ar norite tęsti?? (Y/N): ";
        char userChoice;
        std::cin >> userChoice;
        if (userChoice == 'N' || userChoice == 'n') {
            exitProgram = true;
        }
    }
}

