#include "funkcijos.h"
#include "studentas.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <vector>
#include <string>
#include <sstream>

// Rūšiavimo funkcijos
bool sortByVardas(const Studentas& a, const Studentas& b) {
    return a.vardas < b.vardas;
}

bool sortByPavarde(const Studentas& a, const Studentas& b) {
    return a.pavarde < b.pavarde;
}

bool sortByVidurkis(const Studentas& a, const Studentas& b) {
    double vidurkisA = 0.4 * vidurkis(a.nd_rezultatai) + 0.6 * a.egzaminas;
    double vidurkisB = 0.4 * vidurkis(b.nd_rezultatai) + 0.6 * b.egzaminas;
    return vidurkisA < vidurkisB;
}

bool sortByMediana(const Studentas& a, const Studentas& b) {
    double medianaA = 0.4 * mediana(a.nd_rezultatai) + 0.6 * a.egzaminas;
    double medianaB = 0.4 * mediana(b.nd_rezultatai) + 0.6 * b.egzaminas;
    return medianaA < medianaB;
}

// Spausdina studentų galutinius balus
void spausdintiGalutiniusBalus(const std::vector<Studentas>& studentai, const std::string& isvedimoFailoVardas, int rusiavimoTipas) {
    std::ostream* out;
    std::ofstream fileOut;

    if (!isvedimoFailoVardas.empty()) {
        fileOut.open(isvedimoFailoVardas);
        out = &fileOut;
    } else {
        out = &std::cout;
    }

    std::vector<Studentas> surusiuotiStudentai = studentai;

    // Rūšiavimas
    switch (rusiavimoTipas) {
        case 1:
            sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByVardas);
            break;
        case 2:
            sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByPavarde);
            break;
        case 3:
            sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByVidurkis);
            break;
        case 4:
            sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByMediana);
            break;
    }

    // Spausdinimas
    *out << std::fixed << std::setprecision(2);
    *out << "Studentų galutiniai balai:\n";
    *out << "----------------------------------------------------------------\n";
    *out << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavardė" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)\n";
    *out << "----------------------------------------------------------------\n";

    for (const Studentas& studentas : surusiuotiStudentai) {
        double galutinisVidurkis = 0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas;
        double galutineMediana = 0.4 * mediana(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas;
        *out << std::left << std::setw(15) << studentas.vardas << std::setw(15) << studentas.pavarde << std::setw(20) << galutinisVidurkis << std::setw(20) << galutineMediana << "\n";
    }
    *out << "----------------------------------------------------------------\n";

    if (!isvedimoFailoVardas.empty()) {
        fileOut.close();
    }
}

// Rankinis studentų duomenų įvedimas
void manualInput(std::vector<Studentas>& studentai) {
    char testi = 't';
    while (testi == 't' || testi == 'T') {
        Studentas naujasStudentas;

        std::cout << "Įveskite studento vardą: ";
        std::getline(std::cin, naujasStudentas.vardas);

        std::cout << "Įveskite studento pavardę: ";
        std::getline(std::cin, naujasStudentas.pavarde);

        std::cout << "Įveskite namų darbų pažymius (0 norint baigti): ";
        int pazymys;
        while (std::cin >> pazymys && pazymys != 0) {
            naujasStudentas.nd_rezultatai.push_back(pazymys);
        }
        std::cin.clear(); // Valo bet kokias klaidas
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Įveskite egzamino rezultatą: ";
        std::cin >> naujasStudentas.egzaminas;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        studentai.push_back(naujasStudentas);

        std::cout << "Ar norite įvesti dar vieną studentą? (t/n): ";
        std::cin >> testi;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Generuoja tik pažymius esamiems studentams
void generateGradesOnly(std::vector<Studentas>& studentai) {
    for (Studentas& studentas : studentai) {
        generateRandomGrades(studentas);
    }
}

// Skaito studentų duomenis iš failo
void readFileDataFromFile(std::vector<Studentas>& studentai, const std::string& failoVardas) {
    std::ifstream failas(failoVardas);
    if (!failas.is_open()) {
        std::cerr << "Nepavyko atidaryti failo: " << failoVardas << std::endl;
        return;
    }

    Studentas studentas;
    std::string eilute;
    getline(failas, eilute); // Praleidžiama antraštė

    while (getline(failas, eilute)) {
        std::istringstream eilutesSrautas(eilute);
        eilutesSrautas >> studentas.vardas >> studentas.pavarde;

        int pazymys;
        studentas.nd_rezultatai.clear();
        while (eilutesSrautas >> pazymys && pazymys != -1) {
            studentas.nd_rezultatai.push_back(pazymys);
        }

        studentas.egzaminas = pazymys;
        studentai.push_back(studentas);
    }

    failas.close();
}
