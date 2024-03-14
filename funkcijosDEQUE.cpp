#include "funkcijosDEQUE.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <deque>
#include <string>
#include <algorithm>

void readDataDeque(std::deque<Studentas> &studentai, const std::string &failoVardas)
{
    std::ifstream file(failoVardas);
    if (!file)
    {
        std::cerr << "Failed to open file: " << failoVardas << std::endl;
        return;
    }
    std::string headerLine;
    std::getline(file, headerLine); // Skip the header

    Studentas studentas;
    std::string line;
    while (getline(file, line))
    {
        std::istringstream iss(line);
        iss >> studentas.vardas >> studentas.pavarde;
        int pazymys;
        studentas.nd_rezultatai.clear();
        while (iss >> pazymys)
        {
            studentas.nd_rezultatai.push_back(pazymys);
        }
        if (!studentas.nd_rezultatai.empty())
        {
            studentas.egzaminas = studentas.nd_rezultatai.back();
            studentas.nd_rezultatai.pop_back();
        }
        studentai.push_back(studentas);
    }
    file.close();
}

void generateStudentFilesDeque(int size)
{
    std::string fileName = "studentai" + std::to_string(size) + ".txt";
    std::ofstream outFile(fileName);

    if (!outFile)
    {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return;
    }

    outFile << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde";
    for (int i = 1; i <= 15; ++i)
    {
        outFile << std::setw(10) << "ND" + std::to_string(i);
    }
    outFile << std::setw(10) << "Egz." << std::endl;

    for (int i = 1; i <= size; ++i)
    {
        outFile << std::left << std::setw(15) << "Vardas" + std::to_string(i)
                << std::setw(15) << "Pavarde" + std::to_string(i);
        for (int j = 0; j < 15; j++)
        {
            outFile << std::setw(10) << (rand() % 10 + 1);
        }
        outFile << std::setw(10) << (rand() % 10 + 1) << std::endl;
    }
    outFile.close();
}

void divideStudentsDeque(const std::string &fileName)
{
    std::deque<Studentas> studentai;

    // Timer for reading data
    auto readStart = std::chrono::high_resolution_clock::now();
    readDataDeque(studentai, fileName);
    auto readEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> readElapsed = readEnd - readStart;
    std::cout << "Time taken to read data (Deque): " << readElapsed.count() << "s\n";

    // Timer for sorting data (assuming the sorting logic is implemented correctly)
    auto sortStart = std::chrono::high_resolution_clock::now();
    std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b)
              { return (0.4 * vidurkis(a.nd_rezultatai) + 0.6 * a.egzaminas) < (0.4 * vidurkis(b.nd_rezultatai) + 0.6 * b.egzaminas); });
    auto sortEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sortElapsed = sortEnd - sortStart;
    std::cout << "Time taken to sort data (Deque): " << sortElapsed.count() << "s\n";

    // Timer for dividing students
    auto divideStart = std::chrono::high_resolution_clock::now();
    std::deque<Studentas> kietiakiai, vargsiukai;
    for (const auto &studentas : studentai)
    {
        double galutinisBalas = 0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas;
        if (galutinisBalas < 5.0)
        {
            vargsiukai.push_back(studentas);
        }
        else
        {
            kietiakiai.push_back(studentas);
        }
    }
    auto divideEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> divideElapsed = divideEnd - divideStart;
    std::cout << "Time taken to divide students (Deque): " << divideElapsed.count() << "s\n";

    std::ofstream kietiakiaiFile("kietiakiai.txt"), vargsiukaiFile("vargsiukai.txt");
    for (const auto &studentas : kietiakiai)
    {
        kietiakiaiFile << studentas.vardas << " " << studentas.pavarde << " "
                       << std::fixed << std::setprecision(2)
                       << (0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas)
                       << std::endl;
    }
    for (const auto &studentas : vargsiukai)
    {
        vargsiukaiFile << studentas.vardas << " " << studentas.pavarde << " "
                       << std::fixed << std::setprecision(2)
                       << (0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas)
                       << std::endl;
    }
    kietiakiaiFile.close();
    vargsiukaiFile.close();
}
