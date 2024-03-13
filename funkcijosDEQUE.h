#ifndef FUNKCIJOSDEQUE_H
#define FUNKCIJOSDEQUE_H

#include "studentas.h"
#include <deque>

void readDataDeque(std::deque<Studentas>& studentai, const std::string& failoVardas);
void generateStudentFilesDeque(int size);
void sortStudentsDeque(std::deque<Studentas>& studentai);
void writeStudentsToFile(const std::deque<Studentas>& students, const std::string& fileName);
void divideStudentsDeque(int size);

#endif // FUNKCIJOSDEQUE_H
