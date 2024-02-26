#include "studentas.h"
#include "funkcijos.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Užtikriname atsitiktinių skaičių generavimo įvairovę

    std::vector<Studentas> studentai;
    int pasirinkimas;

    do {
        std::cout << "Meniu:" << std::endl
                  << "1 - Įvesti studentų duomenis rankiniu būdu" << std::endl
                  << "2 - Generuoti pažymius esamiems studentams" << std::endl
                  << "3 - Generuoti ir pažymius, ir studentų vardus bei pavardes" << std::endl
                  << "4 - Skaityti duomenis iš failo" << std::endl
                  << "5 - Spausdinti studentų sąrašą" << std::endl
                  << "0 - Baigti darbą" << std::endl
                  << "Pasirinkite veiksmą: ";
        std::cin >> pasirinkimas;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Išvalome įvedimo buferį

        switch (pasirinkimas) {
            case 1:
                manualInput(studentai);
                break;
            case 2:
                generateGradesOnly(studentai);
                break;
            case 3:
                for (int i = 0; i < 5; ++i) { // Generuojame 5 atsitiktinius studentus kaip pavyzdį
                    Studentas naujasStudentas;
                    generateRandomNamesAndGrades(naujasStudentas);
                    studentai.push_back(naujasStudentas);
                }
                break;
            case 4: {
                std::string failoVardas = "duomenys.txt"; // Pakeiskite į reikiamą failo vardą
                readFileDataFromFile(studentai, failoVardas);
                break;
            }
            case 5: {
                int rusiavimoTipas = 1; // Galite leisti vartotojui pasirinkti rūšiavimo tipą
                spausdintiGalutiniusBalus(studentai, "", rusiavimoTipas); // Paskutinis parametras nurodo išvedimo failo vardą, jei reikia
                break;
            }
            case 0:
                std::cout << "Programa baigia darbą." << std::endl;
                break;
            default:
                std::cout << "Neatpažintas pasirinkimas. Bandykite dar kartą." << std::endl;
                break;
        }
    } while (pasirinkimas != 0);

    return 0;
}
