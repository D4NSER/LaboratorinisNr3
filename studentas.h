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

#endif // STUDENTAS_H
