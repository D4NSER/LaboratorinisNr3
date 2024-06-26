#include "funkcijosVECTOR.h"
#include "studentas.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <random>
#include <cstdlib>
#include <ctime>

void readDataVector(std::vector<Studentas> &studentai, const std::string &failoVardas)
{
    std::ifstream file(failoVardas);
    if (!file)
    {
        std::cerr << "Nepavyko atidaryti failo: " << failoVardas << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::istringstream iss(line);
        std::string vardas, pavarde;
        iss >> vardas >> pavarde;

        Studentas studentas(vardas, pavarde);

        int pazymys;
        studentas.setNamuDarbai({});
        while (iss >> pazymys)
        {
            studentas.getNamuDarbai().push_back(pazymys);
        }

        if (!studentas.getNamuDarbai().empty())
        {
            studentas.setEgzaminas(studentas.getNamuDarbai().back());
            studentas.getNamuDarbai().pop_back();
            studentai.push_back(studentas);
        }
    }
    file.close();
}

void generateStudentFilesVector(int size)
{
    std::string fileName = "studentai" + std::to_string(size) + ".txt";
    std::ofstream outFile(fileName);

    if (!outFile)
    {
        std::cerr << "Nepavyko atidaryti failo: " << fileName << std::endl;
        return;
    }

    outFile << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavardė";
    for (int i = 1; i <= 15; ++i)
    {
        outFile << std::setw(10) << "ND" + std::to_string(i);
    }
    outFile << std::setw(10) << "Egz." << std::endl;

    for (int i = 1; i <= size; i++)
    {
        outFile << std::left << std::setw(15) << "Vardas" + std::to_string(i)
                << std::setw(15) << "Pavardė" + std::to_string(i);
        for (int j = 0; j < 15; j++)
        {
            outFile << std::setw(10) << (rand() % 10 + 1);
        }
        outFile << std::setw(10) << (rand() % 10 + 1);
        outFile << std::endl;
    }

    outFile.close();
}

void rusiuotStudentusVector(const std::string &failoVardas) // 1 strategija
{
    std::vector<Studentas> studentai;

    auto readStart = std::chrono::high_resolution_clock::now();
    readDataVector(studentai, failoVardas);
    auto readEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> readElapsed = readEnd - readStart;
    std::cout << std::fixed << std::setprecision(9) << "Time taken to read data: " << readElapsed.count() << "s\n";

    auto sortStart = std::chrono::high_resolution_clock::now();
    std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b)
              { return (0.4 * a.skaiciuotiVidurki() + 0.6 * a.getEgzaminas()) < (0.4 * b.skaiciuotiVidurki() + 0.6 * b.getEgzaminas()); });
    auto sortEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sortElapsed = sortEnd - sortStart;
    std::cout << "Time taken to sort data: " << sortElapsed.count() << "s\n";

    auto divideStart = std::chrono::high_resolution_clock::now();
    std::vector<Studentas> kietiakai, vargsiukai;
    for (const auto &studentas : studentai)
    {
        double galutinisBalas = 0.4 * studentas.skaiciuotiVidurki() + 0.6 * studentas.getEgzaminas();
        if (galutinisBalas < 5.0)
        {
            vargsiukai.push_back(studentas);
        }
        else
        {
            kietiakai.push_back(studentas);
        }
    }
    auto divideEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> divideElapsed = divideEnd - divideStart;
    std::cout << "Time taken to divide students: " << divideElapsed.count() << "s\n";

    std::ofstream kietiakaiFile("kietiakai.txt"), vargsiukaiFile("vargsiukai.txt");

    for (const auto &studentas : kietiakai)
    {
        kietiakaiFile << studentas.getVardas() << " " << studentas.getPavarde() << " "
                      << std::fixed << std::setprecision(2)
                      << studentas.skaiciuotiGalutini(true)
                      << std::endl;
    }

    for (const auto &studentas : vargsiukai)
    {
        vargsiukaiFile << studentas.getVardas() << " " << studentas.getPavarde() << " "
                       << std::fixed << std::setprecision(2)
                       << studentas.skaiciuotiGalutini(true)
                       << std::endl;
    }

    kietiakaiFile.close();
    vargsiukaiFile.close();
}

void rusiuotStudentusVector2(const std::string &failoVardas) //2 startegija
{
    std::vector<Studentas> studentai;

    auto readStart = std::chrono::high_resolution_clock::now();
    readDataVector(studentai, failoVardas);
    auto readEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> readElapsed = readEnd - readStart;
    std::cout << std::fixed << std::setprecision(7) << "Time taken to read data: " << readElapsed.count() << "s\n";

    auto sortStart = std::chrono::high_resolution_clock::now();
    std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b) {
        return (0.4 * a.skaiciuotiVidurki() + 0.6 * a.getEgzaminas()) < (0.4 * b.skaiciuotiVidurki() + 0.6 * b.getEgzaminas());
    });
    auto sortEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sortElapsed = sortEnd - sortStart;
    std::cout << std::fixed << std::setprecision(7) << "Time taken to sort data: " << sortElapsed.count() << "s\n";

    auto divideStart = std::chrono::high_resolution_clock::now();
    std::vector<Studentas> vargsiukai;

    for (auto it = studentai.begin(); it != studentai.end();)
    {
        double galutinisBalas = 0.4 * it->skaiciuotiVidurki() + 0.6 * it->getEgzaminas();
        if (galutinisBalas < 5.0)
        {
            vargsiukai.push_back(*it);
            it = studentai.erase(it);
        }
        else
        {
            ++it;
        }
    }

    auto divideEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> divideElapsed = divideEnd - divideStart;
    std::cout << std::fixed << std::setprecision(7) << "Time taken to divide students: " << divideElapsed.count() << "s\n";

    std::ofstream kietiakaiFile("kietiakai.txt"), vargsiukaiFile("vargsiukai.txt");

    for (const auto &studentas : studentai)
    {
        kietiakaiFile << studentas.getVardas() << " " << studentas.getPavarde() << " "
                      << std::fixed << std::setprecision(2)
                      << studentas.skaiciuotiGalutini(true)
                      << std::endl;
    }

    for (const auto &studentas : vargsiukai)
    {
        vargsiukaiFile << studentas.getVardas() << " " << studentas.getPavarde() << " "
                       << std::fixed << std::setprecision(2)
                       << studentas.skaiciuotiGalutini(true)
                       << std::endl;
    }

    kietiakaiFile.close();
    vargsiukaiFile.close();
}

void rusiuotStudentusVector3(const std::string &failoVardas) //3 startegija
{
    std::vector<Studentas> studentai;

    auto readStart = std::chrono::high_resolution_clock::now();
    readDataVector(studentai, failoVardas);
    auto readEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> readElapsed = readEnd - readStart;
    std::cout << std::fixed << std::setprecision(7) << "Time taken to read data: " << readElapsed.count() << "s\n";

    auto sortStart = std::chrono::high_resolution_clock::now();
    std::sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b) {
        return (0.4 * a.skaiciuotiVidurki() + 0.6 * a.getEgzaminas()) < (0.4 * b.skaiciuotiVidurki() + 0.6 * b.getEgzaminas());
    });
    auto sortEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sortElapsed = sortEnd - sortStart;
    std::cout << std::fixed << std::setprecision(7) << "Time taken to sort data: " << sortElapsed.count() << "s\n";

    auto divideStart = std::chrono::high_resolution_clock::now();
    std::vector<Studentas> kietiakai, vargsiukai;
    auto iter = std::stable_partition(studentai.begin(), studentai.end(), [](const Studentas &studentas) {
        return studentas.skaiciuotiGalutini(true) >= 5.0;
    });
    kietiakai.assign(studentai.begin(), iter);
    vargsiukai.assign(iter, studentai.end());
    auto divideEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> divideElapsed = divideEnd - divideStart;
    std::cout << std::fixed << std::setprecision(7) << "Time taken to divide students: " << divideElapsed.count() << "s\n";

    std::ofstream kietiakaiFile("kietiakai.txt"), vargsiukaiFile("vargsiukai.txt");

    for (const auto &studentas : kietiakai)
    {
        kietiakaiFile << studentas.getVardas() << " " << studentas.getPavarde() << " "
                      << std::fixed << std::setprecision(2)
                      << studentas.skaiciuotiGalutini(true)
                      << std::endl;
    }

    for (const auto &studentas : vargsiukai)
    {
        vargsiukaiFile << studentas.getVardas() << " " << studentas.getPavarde() << " "
                       << std::fixed << std::setprecision(2)
                       << studentas.skaiciuotiGalutini(true)
                       << std::endl;
    }

    kietiakaiFile.close();
    vargsiukaiFile.close();
}
