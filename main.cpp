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
                  << "5 - Pakeisti rūšiavimo tipą" << std::endl
                  << "0 - Baigti darbą" << std::endl
                  << "Pasirinkite veiksmą: ";
        std::cin >> pasirinkimas;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Išvalome įvedimo buferį

        switch (pasirinkimas) {
            case 1:
                manualInput(studentai);
                spausdintiGalutiniusBalus(studentai, "isvedimas.txt");
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
                spausdintiGalutiniusBalus(studentai, "isvedimas.txt");
                break;
            case 4: {
                std::string failoVardas;
                std::cout << "Pasirinkite failą:" << std::endl
                          << "1 - studentai10000.txt" << std::endl
                          << "2 - studentai100000.txt" << std::endl
                          << "3 - studentai1000000.txt" << std::endl
                          << "4 - kursiokai.txt" << std::endl
                          << "Pasirinkimas: ";
                int failoPasirinkimas;
                std::cin >> failoPasirinkimas;
                switch (failoPasirinkimas) {
                    case 1: failoVardas = "studentai10000.txt"; break;
                    case 2: failoVardas = "studentai100000.txt"; break;
                    case 3: failoVardas = "studentai1000000.txt"; break;
                    case 4: failoVardas = "kursiokai.txt"; break;
                    default: std::cout << "Neteisingas pasirinkimas." << std::endl; break;
                }

                if (!failoVardas.empty()) {
                    int rusiavimoTipas;
                    std::cout << "Pasirinkite rūšiavimo būdą:" << std::endl
                              << "1 - Pagal vardą" << std::endl
                              << "2 - Pagal pavardę" << std::endl
                              << "3 - Pagal vidurkį" << std::endl
                              << "4 - Pagal medianą" << std::endl
                              << "Pasirinkimas: ";
                    std::cin >> rusiavimoTipas;

                    readFileDataFromFile(studentai, failoVardas);
                    spausdintiGalutiniusBalus(studentai, "isvedimas.txt", rusiavimoTipas);
                }
                break;
            }
            case 5:{
                int rusiavimoTipas;
                std::cout << "Pasirinkite naują rūšiavimo būdą:" << std::endl
                          << "1 - Pagal vardą" << std::endl
                          << "2 - Pagal pavardę" << std::endl
                          << "3 - Pagal vidurkį" << std::endl
                          << "4 - Pagal medianą" << std::endl
                          << "Pasirinkimas: ";
                std::cin >> rusiavimoTipas;
                spausdintiGalutiniusBalus(studentai, "isvedimas.txt", rusiavimoTipas);
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
