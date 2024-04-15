#include "studentas.h"
#include <algorithm>
#include <cstdlib>

Studentas::Studentas() : egzaminas(0) {}

Studentas::Studentas(const std::string &vardas, const std::string &pavarde)
    : vardas(vardas), pavarde(pavarde), egzaminas(0) {}

Studentas::~Studentas()
{
    nd_rezultatai.clear();
    vardas.clear();
    pavarde.clear();
    egzaminas = 0;
}

Studentas::Studentas(const Studentas &other)
    : vardas(other.vardas), pavarde(other.pavarde), nd_rezultatai(other.nd_rezultatai), egzaminas(other.egzaminas) {}

Studentas &Studentas::operator=(const Studentas &other)
{
    if (this != &other)
    {
        vardas = other.vardas;
        pavarde = other.pavarde;
        nd_rezultatai = other.nd_rezultatai;
        egzaminas = other.egzaminas;
    }
    return *this;
}

Studentas::Studentas(Studentas &&other) noexcept
    : vardas(std::move(other.vardas)), pavarde(std::move(other.pavarde)), nd_rezultatai(std::move(other.nd_rezultatai)), egzaminas(other.egzaminas)
{
    other.egzaminas = 0;
}

Studentas &Studentas::operator=(Studentas &&other) noexcept
{
    if (this != &other)
    {
        vardas = std::move(other.vardas);
        pavarde = std::move(other.pavarde);
        nd_rezultatai = std::move(other.nd_rezultatai);
        egzaminas = other.egzaminas;
        other.egzaminas = 0;
    }
    return *this;
}

void Studentas::setVardas(const std::string &vardas)
{
    this->vardas = vardas;
}

std::string Studentas::getVardas() const
{
    return vardas;
}

void Studentas::setPavarde(const std::string &pavarde)
{
    this->pavarde = pavarde;
}

std::string Studentas::getPavarde() const
{
    return pavarde;
}

void Studentas::setNamuDarbai(const std::vector<int> &nd)
{
    nd_rezultatai = nd;
}

std::vector<int> Studentas::getNamuDarbai() const
{
    return nd_rezultatai;
}

void Studentas::addNamuDarbas(int pazymys)
{
    nd_rezultatai.push_back(pazymys);
}

void Studentas::setEgzaminas(int egzaminas)
{
    this->egzaminas = egzaminas;
}

int Studentas::getEgzaminas() const
{
    return egzaminas;
}

double Studentas::skaiciuotiVidurki() const
{
    double suma = 0.0;
    for (int pazymys : nd_rezultatai)
    {
        suma += pazymys;
    }
    return nd_rezultatai.empty() ? 0.0 : suma / nd_rezultatai.size();
}

double Studentas::skaiciuotiMediana() const
{
    if (nd_rezultatai.empty())
        return 0.0;
    std::vector<int> tempNamuDarbai = nd_rezultatai;
    std::sort(tempNamuDarbai.begin(), tempNamuDarbai.end());
    int dydis = tempNamuDarbai.size();
    return (dydis % 2 == 0) ? (tempNamuDarbai[dydis / 2 - 1] + tempNamuDarbai[dydis / 2]) / 2.0 : tempNamuDarbai[dydis / 2];
}

double Studentas::skaiciuotiGalutini(bool naudotiVidurki) const
{
    double galutinis = naudotiVidurki ? (0.4 * skaiciuotiVidurki() + 0.6 * egzaminas) : (0.4 * skaiciuotiMediana() + 0.6 * egzaminas);
    return galutinis;
}

void Studentas::atsitiktiniai()
{
    nd_rezultatai.resize(rand() % 10 + 1);
    for (int &pazymys : nd_rezultatai)
    {
        pazymys = rand() % 10 + 1;
    }
    egzaminas = rand() % 10 + 1;
}

void Studentas::atsitiktiniaiStudentai()
{
    const char *vardai[] = {"Jonas", "Petras", "Antanas", "Juozas", "Kazimieras"};
    const char *pavardes[] = {"Jonaitis", "Petraitis", "Antanaitis", "Juozaitis", "Kazimieraitis"};
    int vardasIndex = rand() % 5;
    int pavardeIndex = rand() % 5;
    vardas = vardai[vardasIndex];
    pavarde = pavardes[pavardeIndex];
    atsitiktiniai();
}
