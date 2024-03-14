#ifndef FUNKCIJOSDEQUE_H
#define FUNKCIJOSDEQUE_H

#include "studentas.h"
#include <deque>

void readDataDeque(std::deque<Studentas>& studentai, const std::string& failoVardas);
void generateStudentFilesDeque(int size);
void divideStudentsDeque(const std::string& fileName);

#endif // FUNKCIJOSDEQUE_H
