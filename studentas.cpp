#include "studentas.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

// konstruktorius
Studentas::Studentas() : egzaminas(0) {}

Studentas::Studentas(const std::string& vardas, const std::string& pavarde)
    : vardas(vardas), pavarde(pavarde), egzaminas(0) {}

Studentas::Studentas(const Studentas& other)
    : vardas(other.vardas), pavarde(other.pavarde),
      namuDarbai(other.namuDarbai), egzaminas(other.egzaminas) {}

Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vardas = other.vardas;
        pavarde = other.pavarde;
        namuDarbai = other.namuDarbai;
        egzaminas = other.egzaminas;
    }
    return *this;
}

Studentas::Studentas(Studentas&& other) noexcept
    : vardas(std::move(other.vardas)), pavarde(std::move(other.pavarde)),
      namuDarbai(std::move(other.namuDarbai)), egzaminas(other.egzaminas) {
    other.egzaminas = 0;
}

Studentas& Studentas::operator=(Studentas&& other) noexcept {
    if (this != &other) {
        vardas = std::move(other.vardas);
        pavarde = std::move(other.pavarde);
        namuDarbai = std::move(other.namuDarbai);
        egzaminas = other.egzaminas;
        other.egzaminas = 0;
    }
    return *this;
}
// destruktorius
Studentas::~Studentas() {
    namuDarbai.clear();
    vardas.clear();
    pavarde.clear();
    egzaminas = 0;
}

void Studentas::setVardas(const std::string& vardas) { this->vardas = vardas; }
std::string Studentas::getVardas() const { return vardas; }

void Studentas::setPavarde(const std::string& pavarde) { this->pavarde = pavarde; }
std::string Studentas::getPavarde() const { return pavarde; }

void Studentas::setNamuDarbai(const std::vector<int>& nd) { namuDarbai = nd; }
std::vector<int> Studentas::getNamuDarbai() const { return namuDarbai; }

void Studentas::addNamuDarbas(int pazymys) { namuDarbai.push_back(pazymys); }

void Studentas::setEgzaminas(int egzaminas) { this->egzaminas = egzaminas; }
int Studentas::getEgzaminas() const { return egzaminas; }

double Studentas::skaiciuotiVidurki() const {
    double suma = 0.0;
    for (int pazymys : namuDarbai) {
        suma += pazymys;
    }
    return namuDarbai.empty() ? 0.0 : suma / namuDarbai.size();
}

double Studentas::skaiciuotiMediana() const {
    if (namuDarbai.empty()) return 0.0;
    std::vector<int> tempNamuDarbai = namuDarbai;
    std::sort(tempNamuDarbai.begin(), tempNamuDarbai.end());
    int dydis = tempNamuDarbai.size();
    return (dydis % 2 == 0) ? (tempNamuDarbai[dydis / 2 - 1] + tempNamuDarbai[dydis / 2]) / 2.0
                            : tempNamuDarbai[dydis / 2];
}

double Studentas::skaiciuotiGalutini(bool naudotiVidurki) const {
    double galutinis = naudotiVidurki ? (0.4 * skaiciuotiVidurki() + 0.6 * egzaminas)
                                        : (0.4 * skaiciuotiMediana() + 0.6 * egzaminas);
    return galutinis;
}

void Studentas::atsitiktiniai() {
    namuDarbai.resize(rand() % 10 + 1);
    for (int& pazymys : namuDarbai) {
        pazymys = rand() % 10 + 1;
    }
    egzaminas = rand() % 10 + 1;
}

void Studentas::atsitiktiniaiStudentai() {
    const char* vardai[] = {"Morta", "Aina", "Guoda", "Marija", "Paulina"};
    const char* pavardes[] = {"Petraityte", "Jurksaityte", "Mockute", "Macaite", "Liekyte"};
    int vardasIndex = rand() % 5; // 5, nes masyvas prasideda nuo 0
    int pavardeIndex = rand() % 5; // 5, nes masyvas prasideda nuo 0
    vardas = vardai[vardasIndex];
    pavarde = pavardes[pavardeIndex];
    atsitiktiniai();
}

std::ostream& operator<<(std::ostream& os, const Studentas& student) {
    os << student.vardas << " " << student.pavarde << " " << student.egzaminas << " ";
    for (int pazymys : student.namuDarbai) {
        os << pazymys << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Studentas& student) {
    is >> student.vardas >> student.pavarde >> student.egzaminas;
    student.namuDarbai.clear();
    int pazymys;
    while (is >> pazymys) {
        student.namuDarbai.push_back(pazymys);
    }
    return is;
}
