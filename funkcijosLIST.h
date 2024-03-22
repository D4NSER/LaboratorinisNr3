#ifndef FUNKCIJOSLIST_H
#define FUNKCIJOSLIST_H

#include "studentas.h"
#include <list>

void readDataList(std::list<Studentas>& studentai, const std::string& failoVardas);
void generateStudentFilesList(int size);
void divideStudentsList(const std::string& failoVardas);
void divideStudentsList2(const std::string &failoVardas);
void divideStudentsList3(const std::string &failoVardas);

#endif // FUNKCIJOSLIST_H
