#ifndef FUNKCIJOSVECTOR_H
#define FUNKCIJOSVECTOR_H

#include "studentas.h"
#include <vector>

void manualInput(std::vector<Studentas> &studentai);
void spausdintiGalutiniusBalus(const std::vector<Studentas> &studentai, const std::string &isvedimoFailoVardas, int rusiavimoTipas);
void generateGradesOnly(std::vector<Studentas> &studentai);
void readFileDataFromFile(std::vector<Studentas> &studentai, const std::string &failoVardas);


/**
 * @brief Įrašo studentų duomenis į vektorių iš failo.
 * 
 * @param studentai Vektorius, į kurį įrašomi studentų duomenys.
 * @param failoVardas Failo pavadinimas, iš kurio skaitomi duomenys.
 */
void readDataVector(std::vector<Studentas>& studentai, const std::string& failoVardas);

/**
 * @brief Generuoja atsitiktinius studentų failus pagal nurodytą dydį.
 * 
 * @param size Studentų failų dydis.
 */
void generateStudentFilesVector(int size);

/**
 * @brief Rusiuoja studentų duomenis pagal vidurkį ir įrašo į failą.
 * 
 * @param failoVardas Failo pavadinimas, į kurį įrašomi surikiuoti studentų duomenys.
 */
void rusiuotStudentusVector(const std::string& failoVardas);

/**
 * @brief Rusiuoja studentų duomenis pagal vidurkį kitu algoritmu ir įrašo į failą.
 * 
 * @param failoVardas Failo pavadinimas, į kurį įrašomi surikiuoti studentų duomenys.
 */
void rusiuotStudentusVector2(const std::string& failoVardas);

/**
 * @brief Rusiuoja studentų duomenis pagal medianą ir įrašo į failą.
 * 
 * @param failoVardas Failo pavadinimas, į kurį įrašomi surikiuoti studentų duomenys.
 */
void rusiuotStudentusVector3(const std::string& failoVardas);

#endif // FUNKCIJOSVECTOR_H
