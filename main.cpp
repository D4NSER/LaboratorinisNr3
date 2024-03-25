#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <limits>
#include "studentas.h"
#include "app.h"
#include "funkcijos.h"
#include "funkcijosVECTOR.h"


using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<Studentas> studentai;
    char testi;
    int meniu = 0;

    double visoLaikoSuma = 0.0;
    int testuSkaicius = 0;
    double laikas = 0;
    double laikasGalutinis = 0;

    vector<int> sizes = {1000, 10000, 100000, 1000000, 10000000};

    do
    {
        try
        {
            cout << "Pasirinkite buda:\n"
                 << "1 - ivesti studentu duomenis rankiniu budu \n"
                 << "2 - sugeneruoti pazymius \n"
                 << "3 - generuoti ir pazymius ir studentu vardus, pavardes \n"
                 << "4 - skaityti is failo \n"
                 << "5 - generuoti failus \n"
                 << "6 - rusiuoti studentus sugeneruotuose failuose \n"
                 << "7 - testavimas\n"
                 << "8 - baigti darba \n";
            try
            {
                cin >> meniu;
                if (!cin)
                {
                    throw runtime_error("Netinkamas pasirinkimas. Iveskite skaiciu.");
                }
            }
            catch (const std::exception &e)
            {
                cerr << "Klaida: " << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue; 
            }

            switch (meniu)
            {
            case 1:
            {
                try
                {
                    do
                    {
                        Studentas studentas;

                        cout << "Iveskite studento varda: ";
                        string vardas;
                        cin >> vardas;
                        studentas.setVardas(vardas);

                        cout << "Iveskite studento pavarde: ";
                        string pavarde;
                        cin >> pavarde;
                        studentas.setPavarde(pavarde);

                        studentas.setNamuDarbai({}); // Clear previous data
                        int pazymys;
                        cout << "Iveskite namu darbu rezultatus (iveskite 0 jei baigete ivedima): " << endl;
                        int k = 1;

                        while (true)
                        {
                            cout << k << "-asis pazymys: ";
                            cin >> pazymys;
                            if (pazymys == 0)
                            {
                                break;
                            }
                            if (pazymys < 1 || pazymys > 10)
                            {
                                cout << "Neteisingas pazymys. Iveskite skaiciu nuo 1 iki 10." << endl;
                                continue;
                            }
                            studentas.getNamuDarbai().push_back(pazymys);
                            k++;
                        }

                        cout << "Iveskite egzamino rezultata: ";
                        int egzaminas;
                        cin >> egzaminas;
                        if (egzaminas < 1 || egzaminas > 10)
                        {
                            cout << "Neteisingas egzamino rezultatas. Iveskite skaiciu nuo 1 iki 10." << endl;
                            continue;
                        }
                        studentas.setEgzaminas(egzaminas);

                        studentai.push_back(studentas);

                        cout << "Ar norite ivesti dar vieno studento duomenis? (t/n): ";
                        cin >> testi;
                    } while (testi == 't');

                    spausdinimas(studentai);
                }
                catch (const std::exception &e)
                {
                    cerr << "Klaida ivedant duomenis: " << e.what() << endl;
                }
                break;
            }

            case 2:
            {
                try
                {
                    for (auto &studentas : studentai)
                    {
                        auto startTest = chrono::high_resolution_clock::now();

                        studentas.atsitiktiniai();
                        cout << "Studentas: \nEgzaminas: " << studentas.getEgzaminas()
                             << "\nNamu darbu pazymiai: ";
                        for (int pazymys : studentas.getNamuDarbai())
                        {
                            cout << pazymys << " ";
                        }
                        cout << "\n\n";

                        auto endTest = chrono::high_resolution_clock::now();
                        chrono::duration<double> timeTest = endTest - startTest;
                        double laikasTest = timeTest.count();
                        visoLaikoSuma += laikasTest;
                        testuSkaicius++;
                    }
                }
                catch (const std::exception &e)
                {
                    cerr << "Klaida: " << e.what() << endl;
                }
                break;
            }

            case 3:
            {
                try
                {
                    auto startTest = chrono::high_resolution_clock::now();

                    cout << fixed << setprecision(2);
                    cout << "Studentu galutiniai balai:\n";
                    cout << "----------------------------------------------------------------\n";
                    cout << "Vardas" << setw(15) << "Pavardė" << setw(20) << "Galutinis (Vid.)"
                         << setw(20) << "Galutinis (Med.)\n";
                    cout << "----------------------------------------------------------------\n";

                    for (int i = 0; i < 6; i++)
                    {
                        Studentas naujasStudentas;
                        naujasStudentas.atsitiktiniaiStudentai(); 
                        studentai.push_back(naujasStudentas);

                        double galutinisVidurkis = naujasStudentas.skaiciuotiGalutini(true);
                        double galutineMediana = naujasStudentas.skaiciuotiGalutini(false);
                        cout << left << setw(15) << naujasStudentas.getVardas() << setw(15)
                             << naujasStudentas.getPavarde() << setw(20) << galutinisVidurkis << setw(20)
                             << galutineMediana << "\n";
                    }
                    cout << "----------------------------------------------------------------\n";

                    auto endTest = chrono::high_resolution_clock::now();
                    chrono::duration<double> timeTest = endTest - startTest;
                    double laikasTest = timeTest.count();
                    visoLaikoSuma += laikasTest;
                    testuSkaicius++;
                }
                catch (const std::exception &e)
                {
                    cerr << "Klaida: " << e.what() << endl;
                }
                break;
            }

            case 4:
            {
                try
                {
                    auto startTest = chrono::high_resolution_clock::now();
                    nuskaitymas(studentai, pasirinktiFaila(), laikas);
                    spausdinimas(studentai, "isvedimas.txt");
                    auto endTest = chrono::high_resolution_clock::now();
                    chrono::duration<double> timeTest = endTest - startTest;
                    double laikasTest = timeTest.count();
                    visoLaikoSuma += laikasTest;
                    testuSkaicius++;
                }
                catch (const std::exception &e)
                {
                    cerr << "Klaida skaitymo/metimo metu: " << e.what() << endl;
                }
                break;
            }

            case 5:
            {
                auto start = std::chrono::high_resolution_clock::now();
                generuotiStudentuFailus(sizes);
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> laikas = end - start;
                std::cout << "Failu generavimas uztruko: " << laikas.count() << " sekundziu." << std::endl;
                laikasGalutinis += laikas.count();
                break;
            }

            case 6:
            {
                auto startTest = std::chrono::high_resolution_clock::now(); // pradzia matavimo

                std::cout << "Kuri faila noretumete isrusiuoti:" << std::endl;
                for (std::vector<int>::size_type i = 0; i < sizes.size(); ++i)
                {
                    std::cout << i + 1 << ". studentai" << sizes[i] << ".txt" << std::endl;
                }

                int choice;
                std::cin >> choice;
                if (choice < 1 || static_cast<size_t>(choice) > sizes.size())
                {
                    std::cout << "Netinkamas pasirinkimas. Rušiuojamas pirmasis failas" << std::endl;
                    choice = 1;
                }

                std::string failoPavadinimas = "studentai" + std::to_string(sizes[choice - 1]) + ".txt";
                std::vector<Studentas> studentai;
                nuskaitymas(studentai, failoPavadinimas, laikas);
                std::cout << "Nuskaitymas uztruko: " << laikas << " sekundziu" << std::endl;
                laikasGalutinis += laikas;

                std::vector<Studentas> vargsiukai;
                std::vector<Studentas> kietiakai;

                surusiuotiKategorijas(studentai, vargsiukai, kietiakai, laikas);
                laikasGalutinis+=laikas;

                auto endTest = std::chrono::high_resolution_clock::now(); // pabaiga laiko skaiciavimo
                std::chrono::duration<double> timeTest = endTest - startTest;
                double laikas = timeTest.count();
                std::cout << "Rusiavimas uztruko: " << laikas << " sekundziu." << std::endl;
                laikasGalutinis+=laikas;

                irasymasFaile(vargsiukai, "vargsiukai.txt", laikas);
                std::cout << "Isvedimas i faila vargsiukai.txt: " << laikas << std::endl;
                laikasGalutinis+=laikas;
                
                irasymasFaile(kietiakai, "kietiakai.txt", laikas);
                std::cout << "Isvedimas i faila kietiakai.txt: " << laikas << std::endl;
                laikasGalutinis+=laikas;

                break;
            }

            case 7:
            {
                runApp();
                break;
            }

            case 8:
                break;

            default:
                cout << "Netinkamas pasirinkimas" << endl;
                break;
            }
        }
        catch (const std::exception &e)
        {
            cerr << "Klaida: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Visas sugaistas laikas: " << laikasGalutinis << " s" << endl;

    } while (meniu != 8);

    double vidurkis = visoLaikoSuma / testuSkaicius;                    // Suskaiciuojamas laiku vidurkis
    cout << "Keliu testu laiku vidurkis: " << vidurkis << " s" << endl; // Isvedamas laiku vidurkis

    return 0;
}
