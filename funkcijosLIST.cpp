#include "funkcijosLIST.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

void readDataList(std::list<Studentas>& studentai, const std::string& failoVardas) {
    std::ifstream file(failoVardas);
    if (!file) {
        std::cerr << "Failed to open file: " << failoVardas << std::endl;
        return;
    }
    Studentas studentas;
    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        iss >> studentas.vardas >> studentas.pavarde;
        int pazymys;
        studentas.nd_rezultatai.clear();
        while (iss >> pazymys) {
            studentas.nd_rezultatai.push_back(pazymys);
        }
        studentas.egzaminas = studentas.nd_rezultatai.back();
        studentas.nd_rezultatai.pop_back();
        studentai.push_back(studentas);
    }
}

void generateStudentFilesList(int size) {
    std::string fileName = "studentai" + std::to_string(size) + ".txt";
    std::ofstream outFile(fileName);

    if (!outFile) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    outFile << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde";
    for (int i = 1; i <= 15; ++i) {
        outFile << std::setw(10) << "ND" + std::to_string(i);
    }
    outFile << std::setw(10) << "Egz." << std::endl;

    for (int i = 1; i <= size; ++i) {
        outFile << std::left << std::setw(15) << "Vardas" + std::to_string(i)
                << std::setw(15) << "Pavarde" + std::to_string(i);
        for (int j = 0; j < 15; ++j) {
            outFile << std::setw(10) << (rand() % 10 + 1);
        }
        outFile << std::setw(10) << (rand() % 10 + 1) << std::endl;
    }

    outFile.close();
}

void sortStudentsList(std::list<Studentas>& studentai) {
    studentai.sort([](const Studentas& a, const Studentas& b) {
        return a.vardas < b.vardas;
    });
}

void writeStudentsToFile(const std::list<Studentas>& students, const std::string& fileName) {
    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cerr << "Failed to open file for writing: " << fileName << std::endl;
        return;
    }

    for (const auto& studentas : students) {
        outFile << studentas.vardas << " " << studentas.pavarde << " " << std::fixed << std::setprecision(2) << (0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas) << std::endl;
    }
}

void divideStudentsList(int size) {
    std::string fileName = "studentai" + std::to_string(size) + ".txt";
    std::ifstream inFile(fileName);
    std::list<Studentas> studentai, kietiakiai, vargsiukai;

    if (!inFile) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    Studentas studentas;
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        iss >> studentas.vardas >> studentas.pavarde;
        int pazymys;
        studentas.nd_rezultatai.clear();
        while (iss >> pazymys) {
            studentas.nd_rezultatai.push_back(pazymys);
        }
        studentas.egzaminas = studentas.nd_rezultatai.back();
        studentas.nd_rezultatai.pop_back();
        studentai.push_back(studentas);
    }

    for (const auto& student : studentai) {
        double final_score = 0.4 * vidurkis(student.nd_rezultatai) + 0.6 * student.egzaminas;
        if (final_score >= 5) {
            kietiakiai.push_back(student);
        } else {
            vargsiukai.push_back(student);
        }
    }

    writeStudentsToFile(kietiakiai, "kietiakiai.txt");
    writeStudentsToFile(vargsiukai, "vargsiukai.txt");
}
