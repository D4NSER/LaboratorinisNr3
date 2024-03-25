#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

class Studentas
{
public:
    Studentas();                                                      // Constructor
    Studentas(const std::string &vardas, const std::string &pavarde); // Constructor with parameters

    // Public member functions
    void setVardas(const std::string &vardas);
    std::string getVardas() const;

    void setPavarde(const std::string &pavarde);
    std::string getPavarde() const;

    void setNamuDarbai(const std::vector<int> &nd);
    std::vector<int> getNamuDarbai() const;

    void setEgzaminas(int egzaminas);
    int getEgzaminas() const;

    double skaiciuotiVidurki() const;
    double skaiciuotiMediana() const;
    double skaiciuotiGalutini(bool naudotiVidurki) const;
    void atsitiktiniai();
    void atsitiktiniaiStudentai();
    

private:
    // Private data members
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
};

#endif // STUDENTAS_H
