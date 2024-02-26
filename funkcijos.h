#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentas.h"
#include <vector>
#include <string>

void spausdintiGalutiniusBalus(const std::vector<Studentas>& studentai, const std::string& isvedimoFailoVardas = "", int rusiavimoTipas = 1);
void manualInput(std::vector<Studentas>& studentai);
void generateGradesOnly(std::vector<Studentas>& studentai);
void readFileDataFromFile(std::vector<Studentas>& studentai, const std::string& failoVardas);

#endif