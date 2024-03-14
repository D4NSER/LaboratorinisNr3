#include "funkcijosVECTOR.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>


void readDataVector(std::vector<Studentas>& studentai, const std::string& failoVardas) {
    std::ifstream file(failoVardas);
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
    file.close();
}

void generateStudentFilesVector(int size) {
    std::string fileName = "studentai" + std::to_string(size) + ".txt";
    std::ofstream outFile(fileName);

    if (!outFile) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    outFile << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavardė";
    for (int i = 1; i <= 15; ++i) {
        outFile << std::setw(10) << "ND" + std::to_string(i);
    }
    outFile << std::setw(10) << "Egz." << std::endl;

    for (int i = 1; i <= size; i++) {
        outFile << std::left << std::setw(15) << "Vardas" + std::to_string(i)
                << std::setw(15) << "Pavardė" + std::to_string(i);
        for (int j = 0; j < 15; j++) {
            outFile << std::setw(10) << (rand() % 10 + 1);
        }
        outFile << std::setw(10) << (rand() % 10 + 1);
        outFile << std::endl;
    }

    outFile.close();
}

void rusiuotStudentusVector(const std::string& failoVardas) {
    std::ifstream inFile(failoVardas);

    if (!inFile) {
        std::cerr << "Nepavyko atidaryti failo: " << failoVardas << std::endl;
        return;
    }

    std::vector<Studentas> studentai;
    std::string eilute;
    std::getline(inFile, eilute); // Skip the header

    while (std::getline(inFile, eilute)) {
        Studentas tempStudentas;
        std::istringstream eiluteStream(eilute);
        eiluteStream >> tempStudentas.vardas >> tempStudentas.pavarde;
        tempStudentas.nd_rezultatai.clear();
        int pazymys;
        while (eiluteStream >> pazymys) {
            tempStudentas.nd_rezultatai.push_back(pazymys);
        }
        if (!tempStudentas.nd_rezultatai.empty()) {
            tempStudentas.egzaminas = tempStudentas.nd_rezultatai.back();
            tempStudentas.nd_rezultatai.pop_back();
        }
        studentai.push_back(tempStudentas);
    }

    inFile.close();

    // Sorting students
    std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        return (0.4 * vidurkis(a.nd_rezultatai) + 0.6 * a.egzaminas) < (0.4 * vidurkis(b.nd_rezultatai) + 0.6 * b.egzaminas);
    });

    // Dividing students into two categories
    std::vector<Studentas> kietiakiai, vargsiukai;
    for (const auto& studentas : studentai) {
        double galutinisBalas = 0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas;
        if (galutinisBalas < 5.0) {
            vargsiukai.push_back(studentas);
        } else {
            kietiakiai.push_back(studentas);
        }
    }

    // Writing sorted students into separate files
    std::ofstream kietiakiaiFile("kietiakiai.txt"), vargsiukaiFile("vargsiukai.txt");

    for (const auto& studentas : kietiakiai) {
        kietiakiaiFile << studentas.vardas << " " << studentas.pavarde << " " 
                       << std::fixed << std::setprecision(2) 
                       << (0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas) 
                       << std::endl;
    }

    for (const auto& studentas : vargsiukai) {
        vargsiukaiFile << studentas.vardas << " " << studentas.pavarde << " " 
                       << std::fixed << std::setprecision(2) 
                       << (0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas) 
                       << std::endl;
    }

    kietiakiaiFile.close();
    vargsiukaiFile.close();
}
