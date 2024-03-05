#include "studentas.h"
#include "funkcijos.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <stdexcept>
#include <chrono>

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    std::vector<Studentas> studentai;
    int pasirinkimas;
    int rusiavimoTipas;
    std::vector<int> sizes = {1000, 10000, 100000, 1000000, 10000000};
    std::vector<Studentas> kietiakiai, vargsiukai;

    do
    {
        try
        {
            std::cout << "Meniu:" << std::endl
                      << "1 - Įvesti studentų duomenis rankiniu būdu" << std::endl
                      << "2 - Generuoti pažymius esamiems studentams" << std::endl
                      << "3 - Generuoti naujus studentus su atsitiktiniais pažymiais" << std::endl
                      << "4 - Skaityti duomenis iš failo" << std::endl
                      << "5 - Pakeisti rūšiavimo tipą" << std::endl
                      << "6 - Sugeneruoti studentų failus" << std::endl
                      << "7 - Rūšiuoti studentus sugeneruotuose failuose" << std::endl
                      << "0 - Baigti darbą" << std::endl
                      << "Pasirinkite veiksmą: ";
            std::cin >> pasirinkimas;
            if (!std::cin)
            {
                throw std::invalid_argument("Netinkamas pasirinkimas.");
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (pasirinkimas)
            {
            case 1:
                try
                {
                    manualInput(studentai);
                    spausdintiGalutiniusBalus(studentai, "isvedimas.txt");
                }
                catch (const std::exception &e)
                {
                    std::cerr << "Įvedimo klaida: " << e.what() << '\n';
                }
                break;
            case 2:
                try
                {
                    generateGradesOnly(studentai);
                }
                catch (const std::exception &e)
                {
                    std::cerr << "Pažymių generavimo klaida: " << e.what() << '\n';
                }
                break;
            case 3:
                try
                {
                    for (int i = 0; i < 5; ++i)
                    {
                        Studentas naujasStudentas;
                        generateRandomNamesAndGrades(naujasStudentas);
                        studentai.push_back(naujasStudentas);
                    }
                    spausdintiGalutiniusBalus(studentai, "isvedimas.txt");
                }
                catch (const std::exception &e)
                {
                    std::cerr << "Studentų generavimo klaida: " << e.what() << '\n';
                }
                break;
            case 4:
                try
                {
                    std::string failoVardas;
                    std::cout << "Pasirinkite failą:" << std::endl
                              << "1 - studentai10000.txt" << std::endl
                              << "2 - studentai100000.txt" << std::endl
                              << "3 - studentai1000000.txt" << std::endl
                              << "4 - kursiokai.txt" << std::endl
                              << "Pasirinkimas: ";
                    int failoPasirinkimas;
                    std::cin >> failoPasirinkimas;
                    if (std::cin.fail())
                    {
                        throw std::invalid_argument("Netinkamas failo pasirinkimas.");
                    }

                    switch (failoPasirinkimas)
                    {
                    case 1:
                        failoVardas = "studentai10000.txt";
                        break;
                    case 2:
                        failoVardas = "studentai100000.txt";
                        break;
                    case 3:
                        failoVardas = "studentai1000000.txt";
                        break;
                    case 4:
                        failoVardas = "kursiokai.txt";
                        break;
                    default:
                        std::cout << "Neteisingas pasirinkimas." << std::endl;
                        continue;
                    }

                    if (!failoVardas.empty())
                    {
                        std::cout << "Pasirinkite rūšiavimo būdą:" << std::endl
                                  << "1 - Pagal vardą" << std::endl
                                  << "2 - Pagal pavardę" << std::endl
                                  << "3 - Pagal vidurkį" << std::endl
                                  << "4 - Pagal medianą" << std::endl
                                  << "Pasirinkimas: ";
                        std::cin >> rusiavimoTipas;
                        if (std::cin.fail())
                        {
                            throw std::invalid_argument("Netinkamas rūšiavimo būdo pasirinkimas.");
                        }

                        readFileDataFromFile(studentai, failoVardas);
                        spausdintiGalutiniusBalus(studentai, "isvedimas.txt", rusiavimoTipas);
                    }
                }
                catch (const std::exception &e)
                {
                    std::cerr << "Failo skaitymo klaida: " << e.what() << '\n';
                }
                catch (const std::runtime_error &e)
                {
                    std::cerr << "Klaida: " << e.what() << '\n';
                }
                break;
            case 5:
                try
                {
                    std::cout << "Pasirinkite naują rūšiavimo būdą:" << std::endl
                              << "1 - Pagal vardą" << std::endl
                              << "2 - Pagal pavardę" << std::endl
                              << "3 - Pagal vidurkį" << std::endl
                              << "4 - Pagal medianą" << std::endl
                              << "Pasirinkimas: ";
                    std::cin >> rusiavimoTipas;
                    if (std::cin.fail())
                    {
                        throw std::invalid_argument("Netinkamas rūšiavimo būdo pasirinkimas.");
                    }
                    spausdintiGalutiniusBalus(studentai, "isvedimas.txt", rusiavimoTipas);
                }
                catch (const std::exception &e)
                {
                    std::cerr << "Rūšiavimo būdo keitimo klaida: " << e.what() << '\n';
                }
                break;
            case 6:
            {
                auto start = std::chrono::high_resolution_clock::now(); 
                generateStudentFiles(sizes);
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = end - start;
                std::cout << "Failų generavimas užtruko: " << elapsed.count() << " sekundžių." << std::endl;
                break;
            }
            break;
            case 7: 
            {
                for (auto size : sizes)
                {
                    auto start = std::chrono::high_resolution_clock::now();
                    rusiuotiStudentus(sizes);
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed = end - start;
                    std::cout << "Studentų rūšiavimas ir išsaugojimas iš " << size << " įrašų failo užtruko: " << elapsed.count() << " sekundžių." << std::endl;
                }
            }
            break;

            case 0:
                std::cout << "Programa baigia darbą." << std::endl;
                break;
            default:
                std::cout << "Neatpažintas pasirinkimas. Bandykite dar kartą." << std::endl;
                break;
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Klaida: " << e.what() << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        catch (const std::exception &e)
        {
            std::cerr << "Išimtis: " << e.what() << '\n';
        }
    } while (pasirinkimas != 0);

    return 0;
}
