#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd_rezultatai;
    int egzaminas;
};

bool sortByVardas(const Studentas& a, const Studentas& b){
    return a.vardas < b.vardas;
    //return a.pavarde < b.pavarde;
}

double vidurkis(const vector<int>& nd) {
    if(nd.empty()) return 0.0;
    double suma = 0.0;
    for (int pazymys : nd) {
        suma += pazymys;
    }
    return suma / nd.size();
}

double mediana(vector<int> nd) {
    if(nd.empty()) return 0.0;
    sort(nd.begin(), nd.end());
    size_t dydis = nd.size();
    if (dydis % 2 == 0) {
        return (nd[dydis / 2 - 1] + nd[dydis / 2]) / 2.0;
    } else {
        return nd[dydis / 2];
    }
}

void spausdintiGalutiniusBalus(const vector<Studentas>& studentai, char skaiciavimoBudas, const string& isvedimoFailoVardas = "") {
    ostream& out = isvedimoFailoVardas.empty() ? cout : *new ofstream(isvedimoFailoVardas);

    // Rūšiavimas pagal pasirinkimą
     vector<Studentas> surusiuotiStudentai = studentai;
    sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByVardas); // arba kitas rūšiavimo būdas

    out << fixed << setprecision(2);
    string skaiciavimoMetodas = (skaiciavimoBudas == 'v' || skaiciavimoBudas == 'V') ? "Vidurkis" : "Mediana";

    out << "Studentų galutiniai balai (" << skaiciavimoMetodas << "):\n";
    out << "-------------------------------------------------\n";
    out << left << setw(15) << "Vardas" << setw(15) << "Pavardė" << setw(20) << "Galutinis balas\n";
    out << "-------------------------------------------------\n";

    for (const Studentas& studentas : surusiuotiStudentai) {
        double galutinisPazymys = (skaiciavimoBudas == 'v' || skaiciavimoBudas == 'V') ? 0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas : 0.4 * mediana(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas;

        out << left << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << setw(20) << galutinisPazymys << "\n";
    }
    out << "-------------------------------------------------\n";

    if (!isvedimoFailoVardas.empty()) {
        delete &out; // Uždarome failą, jei naudojome ofstream
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

void manualInput(vector<Studentas>& studentai) {
    char testi = 't';

    while (testi == 't') {
        Studentas naujasStudentas;

        cout << "Įveskite studento vardą: ";
        getline(cin, naujasStudentas.vardas);

        cout << "Įveskite studento pavardę: ";
        getline(cin, naujasStudentas.pavarde);

        int pazymys;
        cout << "Įveskite namų darbų pažymius (0 norint baigti): ";
        while (cin >> pazymys && pazymys != 0) {
            naujasStudentas.nd_rezultatai.push_back(pazymys);
        }
        cin.clear(); //Valo bet kokias klaidas
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Įveskite egzamino rezultatą: ";
        cin >> naujasStudentas.egzaminas;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        studentai.push_back(naujasStudentas);

        cout << "Ar norite įvesti dar vieną studentą? (t/n): ";
        cin >> testi;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void generateGradesOnly(vector<Studentas>& studentai) {
    for (Studentas& studentas : studentai) {
        studentas.nd_rezultatai.clear();
        int ndKiekis = rand() % 10 + 1;
        for (int i = 0; i < ndKiekis; ++i) {
            studentas.nd_rezultatai.push_back(rand() % 10 + 1);
        }
        studentas.egzaminas = rand() % 10 + 1;
    }
}

void readFileDataFromFile(vector<Studentas>& studentai, const string&failoVardas){
    ifstream failas(failoVardas);
    if (!failas.is_open()) {
        cerr << "Nepavyko atidaryti failo: " << failoVardas << endl;
        return;
    }

    Studentas studentas;
    string eilute;
     while (getline(failas, eilute)) {
        istringstream eilutesSrautas(eilute);
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

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    vector<Studentas> studentai;
    int pasirinkimas = 0;

    while (pasirinkimas != 5) {
        cout << "Meniu:\n"
                  << "1 - Įvesti studentų duomenis rankiniu būdu\n"
                  << "2 - Generuoti pažymius esamiems studentams\n"
                  << "3 - Generuoti ir pažymius, ir studentų vardus bei pavardes\n"
                  << "4 - Skaityti duomenis iš failo\n"
                  << "5 - Baigti darbą\n"
                  << "Pasirinkite veiksmą: ";
        cin >> pasirinkimas;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Important to ignore leftovers

        char skaiciavimoBudas = ' ';
        if (pasirinkimas < 5) {
            do {
                cout << "Pasirinkite skaičiavimo būdą (v - vidurkis, m - mediana): ";
                cin >> skaiciavimoBudas;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
            case 4:
                string failoVardas;
                cout << "Įveskite failo pavadinimą: ";
                cin >> failoVardas;
                readFileDataFromFile(studentai, failoVardas);
                break;
        }

        if (pasirinkimas < 5) {
            spausdintiGalutiniusBalus(studentai, skaiciavimoBudas);
        }
    }

    return 0;
}
