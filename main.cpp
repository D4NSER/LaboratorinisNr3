#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <limits>
#include <deque>
#include <list>
#include <string>
#include <algorithm>
#include <sstream>
#include <random>
#include <filesystem>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "studentas.h"
#include "funkcijos.h"
#include "funkcijosVECTOR.h"
#include "app.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<Studentas> studentai;
    int pasirinkimas;
    int rusiavimoTipas;
    vector<int> sizes = {1000, 10000, 100000, 1000000, 10000000};
    vector<Studentas> kietiakiai, vargsiukai;

    do
    {
        try
        {
            cout << "Meniu:" << endl
                 << "1 - Įvesti studentų duomenis rankiniu būdu" << endl
                 << "2 - Generuoti pažymius esamiems studentams" << endl
                 << "3 - Generuoti naujus studentus su atsitiktiniais pažymiais" << endl
                 << "4 - Skaityti duomenis iš failo" << endl
                 << "5 - Pakeisti rūšiavimo tipą" << endl
                 << "6 - Rūšiuoti studentus sugeneruotuose failuose" << endl
                 << "7 - Testavimas" << endl
                 << "0 - Baigti darbą" << endl
                 << "Pasirinkite veiksmą: ";
            cin >> pasirinkimas;
            if (!cin)
            {
                throw invalid_argument("Netinkamas pasirinkimas.");
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (pasirinkimas)
            {
            case 1:
                try
                {
                    manualInput(studentai);
                    spausdintiGalutiniusBalus(studentai, "isvedimas.txt");
                }
                catch (const exception &e)
                {
                    cerr << "Įvedimo klaida: " << e.what() << '\n';
                }
                break;
            case 2:
                try
                {
                    generateGradesOnly(studentai);
                }
                catch (const exception &e)
                {
                    cerr << "Pažymių generavimo klaida: " << e.what() << '\n';
                }
                break;
            case 3:
                try
                {
                    for (int i = 0; i < 5; ++i)
                    {
                        Studentas naujasStudentas;
                        //generateRandomNamesAndGrades(naujasStudentas);
                        studentai.push_back(naujasStudentas);
                    }
                    spausdintiGalutiniusBalus(studentai, "isvedimas.txt");
                }
                catch (const exception &e)
                {
                    cerr << "Studentų generavimo klaida: " << e.what() << '\n';
                }
                break;
            case 4:
                try
                {
                    string failoVardas;
                    cout << "Pasirinkite failą:" << endl
                         << "1 - studentai10000.txt" << endl
                         << "2 - studentai100000.txt" << endl
                         << "3 - studentai1000000.txt" << endl
                         << "4 - kursiokai.txt" << endl
                         << "Pasirinkimas: ";
                    int failoPasirinkimas;
                    cin >> failoPasirinkimas;
                    if (cin.fail())
                    {
                        throw invalid_argument("Netinkamas failo pasirinkimas.");
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
                        cout << "Neteisingas pasirinkimas." << endl;
                        continue;
                    }

                    if (!failoVardas.empty())
                    {
                        cout << "Pasirinkite rūšiavimo būdą:" << endl
                             << "1 - Pagal vardą" << endl
                             << "2 - Pagal pavardę" << endl
                             << "3 - Pagal vidurkį" << endl
                             << "4 - Pagal medianą" << endl
                             << "Pasirinkimas: ";
                        cin >> rusiavimoTipas;
                        if (cin.fail())
                        {
                            throw invalid_argument("Netinkamas rūšiavimo būdo pasirinkimas.");
                        }

                        readFileDataFromFile(studentai, failoVardas);
                        spausdintiGalutiniusBalus(studentai, "isvedimas.txt", rusiavimoTipas);
                    }
                }
                catch (const exception &e)
                {
                    cerr << "Failo skaitymo klaida: " << e.what() << '\n';
                }
                catch (const runtime_error &e)
                {
                    cerr << "Klaida: " << e.what() << '\n';
                }
                break;
            case 5:
                try
                {
                    cout << "Pasirinkite naują rūšiavimo būdą:" << endl
                         << "1 - Pagal vardą" << endl
                         << "2 - Pagal pavardę" << endl
                         << "3 - Pagal vidurkį" << endl
                         << "4 - Pagal medianą" << endl
                         << "Pasirinkimas: ";
                    cin >> rusiavimoTipas;
                    if (cin.fail())
                    {
                        throw invalid_argument("Netinkamas rūšiavimo būdo pasirinkimas.");
                    }
                    spausdintiGalutiniusBalus(studentai, "isvedimas.txt", rusiavimoTipas);
                }
                catch (const exception &e)
                {
                    cerr << "Rūšiavimo būdo keitimo klaida: " << e.what() << '\n';
                }
                break;
            case 6:
                try
                {
                    runApp();
                }
                catch (const exception &e)
                {
                    cerr << "Programos klaida: " << e.what() << '\n';
                }
                break;
            case 7:
            
            case 0:
                cout << "Programa baigia darbą." << endl;
                break;
            default:
                cout << "Neatpažintas pasirinkimas. Bandykite dar kartą." << endl;
                break;
            }
        }
        catch (const invalid_argument &e)
        {
            cerr << "Klaida: " << e.what() << '\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (const exception &e)
        {
            cerr << "Išimtis: " << e.what() << '\n';
        }
    } while (pasirinkimas != 0);

    return 0;
}

