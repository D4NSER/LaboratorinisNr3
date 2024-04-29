#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <vector>

class Human
{
public:
    virtual ~Human() = default;

    virtual void setVardas(const std::string &vardas) = 0;
    virtual std::string getVardas() const = 0;

    virtual void setPavarde(const std::string &pavarde) = 0;
    virtual std::string getPavarde() const = 0;

    // virtual void setNamuDarbai(const std::vector<int> &nd) = 0;
    // virtual std::vector<int> getNamuDarbai() const = 0;

    // virtual void addNamuDarbas(int pazymys) = 0;

    // virtual void setEgzaminas(int egzaminas) = 0;
    // virtual int getEgzaminas() const = 0;

    // virtual double skaiciuotiVidurki() const = 0;
    // virtual double skaiciuotiMediana() const = 0;
    // virtual double skaiciuotiGalutini(bool naudotiVidurki) const = 0;
    // virtual void atsitiktiniai() = 0;
    // virtual void atsitiktiniaiStudentai() = 0;
};
