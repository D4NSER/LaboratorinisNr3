#include "funkcijos.h"
#include <iostream>
#include <vector>
#include <limits>
#include <chrono>
#include <filesystem>

enum class Action { None, Generate, Sort };

Action getActionChoice() {
    int choice;
    while (true) {
        std::cout << "Pasirinkite veiksma:\n"
                  << "1. Generuoti studentu failus\n"
                  << "2. Rusiuoti esamus studentu failus\n"
                  << "Pasirinkimas: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Iveskite skaiciu.\n";
        } else if (choice == 1 || choice == 2) {
            break;
        } else {
            std::cout << "Netinkamas pasirinkimas. Prasome bandyti dar karta.\n";
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
        std::cout << "Studentu failu nerasta.\n";
        return "";
    }

    std::cout << "Pasirinkite, kuri studentu faila norite rusiuoti: ";
    int choice;
    std::cin >> choice;

    if (std::cin.fail() || choice < 1 || choice > files.size()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Netinkamas pasirinkimas. Bandykite dar karta.\n";
        return "";
    }

    return files[choice - 1];
}

void performAction(Action actionChoice, const std::vector<int>& sizes) {
    if (actionChoice == Action::Generate) {
        for (int size : sizes) {
            auto start = std::chrono::high_resolution_clock::now();
            generateStudentFilesVector(size);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            std::cout << "Failu generavimas uztruko " << size << ": " << elapsed.count() << "s\n";
        }
    } else if (actionChoice == Action::Sort) {
        std::string filename = getSortingFileChoice();
        if (!filename.empty()) {
            auto start = std::chrono::high_resolution_clock::now();
            //rusiuotStudentusVector1(filename); 
            //rusiuotStudentusVector2(filename); 
            rusiuotStudentusVector3(filename); 
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            std::cout << "Rusiavimas ir skirstymas faile " << filename << ": " << elapsed.count() << "s\n";
        }
    }
}


void runApp() {
    std::vector<int> sizes = {1000, 10000, 100000, 1000000, 10000000};
    bool exitProgram = false;

    while (!exitProgram) {
        Action actionChoice = getActionChoice();
        if (actionChoice == Action::None) {
            continue;
        }

        performAction(actionChoice, sizes);

        std::cout << "Norite testi? (t/n): ";
        char userChoice;
        std::cin >> userChoice;
        if (userChoice == 'N' || userChoice == 'n') {
            exitProgram = true;
        }
        else if (userChoice == 'T' || userChoice == 'T')
        {
            continue;
        }
    }
}
