#ifndef FUNKCIJOSVECTOR_H
#define FUNKCIJOSVECTOR_H

#include "studentas.h"
#include <vector>

void readDataVector(std::vector<Studentas>& studentai, const std::string& failoVardas);
void generateStudentFilesVector(int size);
void rusiuotStudentusVector(int size);

#endif // FUNKCIJOSVECTOR_H
