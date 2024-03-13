#ifndef FUNKCIJOSLIST_H
#define FUNKCIJOSLIST_H

#include "studentas.h"
#include <list>

void readDataList(std::list<Studentas>& studentai, const std::string& failoVardas);
void generateStudentFilesList(int size);
void sortStudentsList(std::list<Studentas>& studentai);
void writeStudentsToFile(const std::list<Studentas>& students, const std::string& fileName);
void divideStudentsList(int size);

#endif // FUNKCIJOSLIST_H
