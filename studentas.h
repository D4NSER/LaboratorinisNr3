#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "zmogus.h"
#include <vector>
#include <iostream>

/**
 * @brief Klasė Studentas reprezentuoja studentą.
 * 
 * Ši klasė paveldi funkcijas iš žmogaus klasės ir prideda funkcionalumą, specifinį studentams,
 * kaip namų darbų ir egzaminų įvertinimų valdymas.
 */
class Studentas : public Human {
public:
    /**
     * @brief Numatytasis konstruktorius.
     */
    Studentas();

    /**
     * @brief Konstruktorius su parametrais vardui ir pavardėi.
     * 
     * @param vardas Studento vardas.
     * @param pavarde Studento pavardė.
     */
    Studentas(const std::string &vardas, const std::string &pavarde);

    // Rule of Five
    /**
     * @brief Kopijavimo konstruktorius.
     */
    Studentas(const Studentas &other);                // Kopijavimo konstruktorius

    /**
     * @brief Priskyrimo operatorius.
     */
    Studentas &operator=(const Studentas &other);     // Priskyrimo operatorius

    /**
     * @brief Perkėlimo konstruktorius.
     */
    Studentas(Studentas &&other) noexcept;            // Perkėlimo konstruktorius

    /**
     * @brief Perkėlimo priskyrimo operatorius.
     */
    Studentas &operator=(Studentas &&other) noexcept; // Perkėlimo priskyrimo operatorius

    // Destruktorius
    /**
     * @brief Destruktorius.
     */
    ~Studentas() override;

    // Implementacija abstrakčių klasės funkcijų
    /**
     * @brief Nustato studento vardą.
     */
    void setVardas(const std::string &vardas) override;

    /**
     * @brief Gauna studento vardą.
     */
    std::string getVardas() const override;

    /**
     * @brief Nustato studento pavardę.
     */
    void setPavarde(const std::string &pavarde) override;

    /**
     * @brief Gauna studento pavardę.
     */
    std::string getPavarde() const override;

    /**
     * @brief Nustato studento namų darbų įvertinimus.
     */
    void setNamuDarbai(const std::vector<int> &nd);

    /**
     * @brief Gauna studento namų darbų įvertinimus.
     */
    std::vector<int> getNamuDarbai() const;

    /**
     * @brief Prideda namų darbų įvertinimą studentui.
     */
    void addNamuDarbas(int pazymys);

    /**
     * @brief Nustato studento egzamino įvertinimą.
     */
    void setEgzaminas(int egzaminas);

    /**
     * @brief Gauna studento egzamino įvertinimą.
     */
    int getEgzaminas() const;

    /**
     * @brief Skaičiuoja studento vidurkį.
     */
    double skaiciuotiVidurki() const;

    /**
     * @brief Skaičiuoja studento medianą.
     */
    double skaiciuotiMediana() const;

    /**
     * @brief Skaičiuoja studento galutinį įvertinimą.
     * 
     * @param naudotiVidurki Ar naudoti vidurkį (true) ar medianą (false).
     */
    double skaiciuotiGalutini(bool naudotiVidurki) const;

    /**
     * @brief Sugeneruoja atsitiktinius įvertinimus studento namų darbams ir egzaminui.
     */
    void atsitiktiniai();

    /**
     * @brief Sugeneruoja atsitiktinius įvertinimus keliems studentų namų darbams ir egzaminams.
     */
    void atsitiktiniaiStudentai();

    /**
     * @brief Išvesti studento duomenis į srautą.
     * 
     * @param os Išvesties srautas.
     * @param student Studento objektas, kurio duomenys išvedami.
     * @return Išvesties srauto nuoroda.
     */
    friend std::ostream &operator<<(std::ostream &os, const Studentas &student);

    /**
     * @brief Įvesti studento duomenis iš srauto.
     * 
     * @param is Įvesties srautas.
     * @param student Studento objektas, į kurį įvedami duomenys.
     * @return Įvesties srauto nuoroda.
     */
    friend std::istream &operator>>(std::istream &is, Studentas &student);


private:
    std::string vardas; /**< Studento vardas. */
    std::string pavarde; /**< Studento pavardė. */
    std::vector<int> nd_rezultatai; /**< Studento namų darbų įvertinimai. */
    int egzaminas; /**< Studento egzamino įvertinimas. */
};

#endif
