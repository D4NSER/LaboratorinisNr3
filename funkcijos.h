#ifndef FUNCTIONS_OLD_H
#define FUNCTIONS_OLD_H

#include <vector>
#include <string>
#include "studentas.h"

void surusiuotiKategorijas(const std::vector<Studentas> &studentai, std::vector<Studentas> &vargsiukai, std::vector<Studentas> &kietiakai, double &laikas);
void irasymasFaile(const std::vector<Studentas> &studentai, const std::string &failoPavadinimas, double &laikas);
void rusiuotiStudentusIrIrasymas(const std::vector<Studentas> &studentai, double &laikas);
void generuotiStudentuFailus(const std::vector<int>& sizes);
void nuskaitymas(std::vector<Studentas>& studentai, const std::string& failoPavadinimas, double &laikas);
bool rusiuotiPagalVarda(const Studentas& a, const Studentas& b);
bool rusiuotiPagalPavarde(const Studentas& a, const Studentas& b);
bool rusiuotiPagalGalutiniVidurki(const Studentas& a, const Studentas& b);
bool rusiuotiPagalGalutiniMediana(const Studentas& a, const Studentas& b);
void spausdinimas(const std::vector<Studentas>& studentai, const std::string& isvedimoFailas = "");
std::string pasirinktiFaila();

#endif // FUNCTIONS_OLD_H
