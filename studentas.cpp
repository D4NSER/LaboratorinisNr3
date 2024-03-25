#include "studentas.h"
#include <algorithm>
#include <cstdlib> // For rand()

// Constructor
Studentas::Studentas() : egzaminas(0) {}

// Constructor with parameters
Studentas::Studentas(const std::string& vardas, const std::string& pavarde)
    : vardas(vardas), pavarde(pavarde), egzaminas(0) {}

// Public member functions
void Studentas::setVardas(const std::string& vardas) {
    this->vardas = vardas;
}

std::string Studentas::getVardas() const {
    return vardas;
}

void Studentas::setPavarde(const std::string& pavarde) {
    this->pavarde = pavarde;
}

std::string Studentas::getPavarde() const {
    return pavarde;
}

void Studentas::setNamuDarbai(const std::vector<int>& nd) {
    namuDarbai = nd;
}

std::vector<int> Studentas::getNamuDarbai() const {
    return namuDarbai;
}

void Studentas::setEgzaminas(int egzaminas) {
    this->egzaminas = egzaminas;
}

int Studentas::getEgzaminas() const {
    return egzaminas;
}

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
    return (dydis % 2 == 0) ? (tempNamuDarbai[dydis / 2 - 1] + tempNamuDarbai[dydis / 2]) / 2.0 : tempNamuDarbai[dydis / 2];
}

double Studentas::skaiciuotiGalutini(bool naudotiVidurki) const {
    double galutinis = naudotiVidurki ? (0.4 * skaiciuotiVidurki() + 0.6 * egzaminas) : (0.4 * skaiciuotiMediana() + 0.6 * egzaminas);
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
    const char* vardai[] = {"Ana", "Gloria", "Sofia", "Ugne", "Aina", "Guoda"};
    const char* pavardes[] = {"Mockute", "Liuc", "Mickute", "Macaite", "Migonyte", "Peleda"};
    int vardasIndex = rand() % 6;
    int pavardeIndex = rand() % 6;
    vardas = vardai[vardasIndex];
    pavarde = pavardes[pavardeIndex];
    atsitiktiniai();
}
