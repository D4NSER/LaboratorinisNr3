#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <iomanip>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> nd_rezultatai;
    int egzaminas;
};

double vidurkis(const std::vector<int>& nd) {
    if(nd.empty()) return 0.0;
    double suma = 0.0;
    for (int pazymys : nd) {
        suma += pazymys;
    }
    return suma / nd.size();
}

double mediana(std::vector<int> nd) {
    if(nd.empty()) return 0.0;
    std::sort(nd.begin(), nd.end());
    size_t dydis = nd.size();
    if (dydis % 2 == 0) {
        return (nd[dydis / 2 - 1] + nd[dydis / 2]) / 2.0;
    } else {
        return nd[dydis / 2];
    }
}

void spausdintiGalutiniusBalus(const std::vector<Studentas>& studentai, char skaiciavimoBudas) {
    std::cout << std::fixed << std::setprecision(2);

    for (const Studentas& studentas : studentai) {
        double galutinisPazymys = 0.0;

        if (skaiciavimoBudas == 'v' || skaiciavimoBudas == 'V') {
            galutinisPazymys = 0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas;
        } else if (skaiciavimoBudas == 'm' || skaiciavimoBudas == 'M') {
            galutinisPazymys = 0.4 * mediana(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas;
        }

        std::cout << studentas.vardas << " " << studentas.pavarde 
                  << ": Galutinis balas = " << galutinisPazymys << std::endl;
    }
}

void generateRandomGrades(Studentas& studentas) {
    studentas.nd_rezultatai.resize(rand() % 10 + 1);
    for (int& grade : studentas.nd_rezultatai) {
        grade = rand() % 10 + 1;
    }
    studentas.egzaminas = rand() % 10 + 1;
}

void generateRandomNamesAndGrades(Studentas& studentas) {
    const char* vardai[] = {"Jonas", "Petras", "Antanas", "Juozas", "Kazimieras"};
    const char* pavardes[] = {"Jonaitis", "Petraitis", "Antanaitis", "Juozaitis", "Kazimieraitis"};
    int vardasIndex = rand() % 5;
    int pavardeIndex = rand() % 5;
    studentas.vardas = vardai[vardasIndex];
    studentas.pavarde = pavardes[pavardeIndex];
    generateRandomGrades(studentas);
}

void manualInput(std::vector<Studentas>& studentai) {
    char testi = 't';

    while (testi == 't') {
        Studentas naujasStudentas;

        std::cout << "Įveskite studento vardą: ";
        std::getline(std::cin, naujasStudentas.vardas);

        std::cout << "Įveskite studento pavardę: ";
        std::getline(std::cin, naujasStudentas.pavarde);

        int pazymys;
        std::cout << "Įveskite namų darbų pažymius (0 norint baigti): ";
        while (std::cin >> pazymys && pazymys != 0) {
            naujasStudentas.nd_rezultatai.push_back(pazymys);
        }
        std::cin.clear(); //Valo bet kokias klaidas
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Įveskite egzamino rezultatą: ";
        std::cin >> naujasStudentas.egzaminas;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        studentai.push_back(naujasStudentas);

        std::cout << "Ar norite įvesti dar vieną studentą? (t/n): ";
        std::cin >> testi;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (testi != 't') {
            break;
        }
    }
}


void generateGradesOnly(std::vector<Studentas>& studentai) {
    for (Studentas& studentas : studentai) {
        studentas.nd_rezultatai.clear();
        int ndKiekis = rand() % 10 + 1;
        for (int i = 0; i < ndKiekis; ++i) {
            studentas.nd_rezultatai.push_back(rand() % 10 + 1);
        }
        studentas.egzaminas = rand() % 10 + 1;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    std::vector<Studentas> studentai;
    int pasirinkimas = 0;

    while (pasirinkimas != 4) {
        std::cout << "Meniu:\n"
                  << "1 - Įvesti studentų duomenis rankiniu būdu\n"
                  << "2 - Generuoti pažymius esamiems studentams\n"
                  << "3 - Generuoti ir pažymius, ir studentų vardus bei pavardes\n"
                  << "4 - Baigti darbą\n"
                  << "Pasirinkite veiksmą: ";
        std::cin >> pasirinkimas;

        //if (pasirinkimas == 4) break;

        // if (pasirinkimas == 5) {
        //     studentai.clear();
        //     std::cout << "Studentų sąrašas išvalytas.\n";
        //     continue;
        // }

        char skaiciavimoBudas = ' ';
        if (pasirinkimas < 4) {
            do {
                std::cout << "Pasirinkite skaičiavimo būdą (v - vidurkis, m - mediana): ";
                std::cin >> skaiciavimoBudas;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }   while(skaiciavimoBudas != 'v' && skaiciavimoBudas != 'V' && skaiciavimoBudas != 'm' && skaiciavimoBudas != 'M');
        }

        switch (pasirinkimas) {
            case 1:
                manualInput(studentai);
                break;
            case 2:
                generateGradesOnly(studentai);
                break;
            case 3:
                for (int i = 0; i < 5; ++i) {
                    Studentas naujasStudentas;
                    generateRandomNamesAndGrades(naujasStudentas);
                    studentai.push_back(naujasStudentas);
                }
                break;
        } 

        if (pasirinkimas < 4) {
            spausdintiGalutiniusBalus(studentai, skaiciavimoBudas);
        }
    }

    return 0;
}
