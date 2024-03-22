#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector>
#include <string>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> nd_rezultatai;
    int egzaminas;
};

double vidurkis(const std::vector<int>& nd);
double mediana(std::vector<int> nd);
void generateRandomGrades(Studentas& studentas);
void generateRandomNamesAndGrades(Studentas& studentas);

#endif // STUDENTAS_H
