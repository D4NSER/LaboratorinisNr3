#include "studentas.h"
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
#include "funkcijos.h"
#include "funkcijosVECTOR.h"
#include "app.h"
#include "zmogus.h"
#include <cassert>
#include <vector>
#include "vector.h"

using namespace std;

void testRuleOfFive()
{
    // Create an original student
    Studentas original("Mantas", "Globys");
    original.addNamuDarbas(8);
    original.addNamuDarbas(9);
    original.setEgzaminas(10);

    // Test copy constructor
    Studentas copy(original);
    cout << copy << endl;
    cout << original << endl;

    // Test copy assignment
    Studentas copyAssignment;
    copyAssignment = original;
    cout << original << endl;

    // Test move constructor
    Studentas moved(std::move(original));
    cout << original << endl;
    cout << moved << endl;

    // Test move assignment
    Studentas moveAssignment;
    moveAssignment = std::move(moved);
    cout << moved << endl;
    cout << moveAssignment << endl;

    std::cout << "Rule of Five tests passed successfully!" << std::endl;
}

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
                 << "8 - Testavimas su Vector" << endl
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
                    // spausdintiGalutiniusBalus(studentai, "isvedimas.txt");
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
                        // generateRandomNamesAndGrades(naujasStudentas);
                        studentai.push_back(naujasStudentas);
                    }
                    // spausdintiGalutiniusBalus(studentai, "isvedimas.txt");
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
                testRuleOfFive();
                break;
            case 8:
            {
                // Default constructor
                Vector<int> intVector;
                std::cout << "Vector contents after default construction: " << intVector << std::endl;

                // Constructor with push_back
                Vector<int> intVector2;
                intVector2.push_back(1);
                intVector2.push_back(2);
                intVector2.push_back(3);
                intVector2.push_back(4);
                intVector2.push_back(5);
                std::cout << "Vector contents after push_back construction: " << intVector2 << std::endl;

                // Push back elements
                intVector.push_back(10);
                intVector.push_back(20);
                std::cout << "Vector contents after push_back: " << intVector << std::endl;

                // Pop back element
                intVector.pop_back();
                std::cout << "Vector contents after pop_back: " << intVector << std::endl;

                // Size of vector
                std::cout << "Size of the vector: " << intVector.size() << std::endl;

                // Accessing elements using operator[]
                std::cout << "Accessing elements using operator[]: ";
                for (size_t i = 0; i < intVector.size(); ++i)
                {
                    std::cout << intVector[i] << " ";
                }
                std::cout << std::endl;

                // Test copy constructor and copy assignment operator
                Vector<int> copiedVector = intVector;
                std::cout << "Copied vector contents: " << copiedVector << std::endl;

                // Test move constructor and move assignment operator
                Vector<int> movedVector = std::move(intVector2);
                std::cout << "Moved vector contents: " << movedVector << std::endl;

                // Test clear
                movedVector.clear();
                std::cout << "Cleared vector size: " << movedVector.size() << std::endl;

                // Test reserve
                Vector<int> reservedVector;
                reservedVector.reserve(10);
                std::cout << "Reserved vector capacity: " << reservedVector.capacity() << std::endl;

                // Test resize
                Vector<int> resizedVector;
                resizedVector.resize(5);
                std::cout << "Resized vector size: " << resizedVector.size() << std::endl;

                // Test empty
                std::cout << "Is resizedVector empty? " << (resizedVector.empty() ? "Yes" : "No") << std::endl;

                // Test front and back
                std::cout << "Front element: " << resizedVector.front() << ", Back element: " << resizedVector.back() << std::endl;

                // Perform time measurement task
                std::cout << std::fixed << std::setprecision(6);
                std::cout << "\nElementu skaicius | std::vector laikas s      | Vector laikas s      | std::vector reallocs | Vector reallocs\n";
                std::cout << "----------------------------------------------------------------------------------------------------------------------\n";

                for (unsigned int sz : {10000, 100000, 1000000, 10000000, 100000000})
                {
                    // Measurement with std::vector
                    auto start_v1 = std::chrono::high_resolution_clock::now();
                    std::vector<int> v1;
                    int reallocations_std_vector = 0;
                    for (unsigned int i = 1; i <= sz; ++i)
                    {
                        v1.push_back(i);
                        if (v1.capacity() == v1.size())
                        {
                            ++reallocations_std_vector;
                        }
                    }
                    auto finish_v1 = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_v1 = finish_v1 - start_v1;

                    // Measurement with your Vector class
                    auto start_v2 = std::chrono::high_resolution_clock::now();
                    Vector<int> v2;
                    int reallocations_custom_vector = 0;
                    for (unsigned int i = 1; i <= sz; ++i)
                    {
                        v2.push_back(i);
                        if (v2.capacity() == v2.size())
                        {
                            ++reallocations_custom_vector;
                        }
                    }
                    auto finish_v2 = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed_v2 = finish_v2 - start_v2;

                    // Print results in a table with proper formatting
                    std::cout << std::setw(15) << sz << " | " << std::setw(27) << elapsed_v1.count() << " | " << std::setw(20) << elapsed_v2.count() << " | " << std::setw(20) << reallocations_std_vector << " | " << std::setw(15) << reallocations_custom_vector << "\n";
                }
                std::cout << "\n";

                // Testing additional methods
                Vector<int> testVector;
                testVector.push_back(10);
                testVector.push_back(20);
                testVector.push_back(30);

                // Test is_sorted method
                std::cout << "Is testVector sorted? " << (testVector.is_sorted() ? "Yes" : "No") << std::endl;

                // Test index_of method
                std::cout << "Index of element 20: " << testVector.index_of(20) << std::endl;

                // Test swap_elements method
                testVector.swap_elements(0, 2);
                std::cout << "After swapping elements: " << testVector << std::endl;

                break;
            }

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
