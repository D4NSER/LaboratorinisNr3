#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

class Studentas
{
public:
    Studentas();
    Studentas(const std::string &vardas, const std::string &pavarde);

    // Rule of Five
    Studentas(const Studentas &other);                // kopijavimo konstruktorius
    Studentas &operator=(const Studentas &other);     // priskyrimo operatorius
    Studentas(Studentas &&other) noexcept;            // perkelimo konstruktorius
    Studentas &operator=(Studentas &&other) noexcept; // perkelimo priskyrimo operatorius

    ~Studentas();

    void setVardas(const std::string &vardas);
    std::string getVardas() const;

    void setPavarde(const std::string &pavarde);
    std::string getPavarde() const;

    void setNamuDarbai(const std::vector<int> &nd);
    std::vector<int> getNamuDarbai() const;

    void addNamuDarbas(int pazymys);

    void setEgzaminas(int egzaminas);
    int getEgzaminas() const;

    double skaiciuotiVidurki() const;
    double skaiciuotiMediana() const;
    double skaiciuotiGalutini(bool naudotiVidurki) const;
    void atsitiktiniai();
    void atsitiktiniaiStudentai();

private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> nd_rezultatai;
    int egzaminas;
};

#endif // STUDENTAS_H
