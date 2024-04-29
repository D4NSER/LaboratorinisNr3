#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <vector>

/**
 * @brief Bazinė klasė Human reprezentuoja žmogų.
 * 
 * Ši klasė apibrėžia abstrakčius metodus, kurie turi būti implementuoti vaikų klasėse.
 */
class Human
{
public:
    /**
     * @brief Virtualus destruktorius.
     */
    virtual ~Human() = default;

    /**
     * @brief Nustato žmogaus vardą.
     * 
     * @param vardas Nustatomas vardas.
     */
    virtual void setVardas(const std::string &vardas) = 0;

    /**
     * @brief Gauna žmogaus vardą.
     * 
     * @return Žmogaus vardas.
     */
    virtual std::string getVardas() const = 0;

    /**
     * @brief Nustato žmogaus pavardę.
     * 
     * @param pavarde Nustatoma pavardė.
     */
    virtual void setPavarde(const std::string &pavarde) = 0;

    /**
     * @brief Gauna žmogaus pavardę.
     * 
     * @return Žmogaus pavardė.
     */
    virtual std::string getPavarde() const = 0;

    // Abstraktūs metodai, kurie gali būti įgyvendinti vaikinėse klasėse:
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

#endif
