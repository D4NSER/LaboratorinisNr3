#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std

struct Studentas {
    string vardas, pavarde;
    vector<int> nd;
    int egzaminas;
};

double vidurkis(const vector<int>& nd) {
    if (nd.empty()) return 0.0;
    double suma = 0.0;
    for (int pazymys : nd) {
        suma += pazymys;
    }
    return suma / nd.size();
}

double mediana(vector<int> nd) {
    if (nd.empty()) return 0.0;
    sort(nd.begin(), nd.end());
    size_t n = nd.size();
    if (n % 2 == 0) {
        return (nd[n / 2 - 1] + nd[n / 2]) / 2.0;
    } else {
        return nd[n / 2];
    }
}

void spausdintiAntrastes() {
    cout << left << setw(15) << "Vardas"
         << setw(15) << "Pavarde"
         << setw(15) << "Galutinis" << endl;
    cout << "------------------------------------------------------------" << endl;
}

void spausdintiRezultata(const Studentas& s, bool naudotiVidurki) {
    double galutinis = naudotiVidurki ? 0.4 * vidurkis(s.nd) + 0.6 * s.egzaminas
                                      : 0.4 * mediana(s.nd) + 0.6 * s.egzaminas;
    cout << left << setw(15) << s.vardas
         << setw(15) << s.pavarde
         << setw(15) << fixed << setprecision(2) << galutinis << endl;
}

int main() {
    vector<Studentas> studentai;
    Studentas temp;
    char testi = 't';
    bool naudotiVidurki;

    cout << "Norite skaiciuoti pagal vidurki (1) ar mediana (0)? ";
    cin >> naudotiVidurki;

    while (testi == 't' || testi == 'T') {
        cout << "Iveskite studento varda: ";
        cin >> temp.vardas;
        cout << "Iveskite studento pavarde: ";
        cin >> temp.pavarde;

        temp.nd.clear();
        int pazymys;
        cout << "Iveskite namu darbu rezultatus (baigti, ivedus neigiama sk.): ";
        while (cin >> pazymys && pazymys >= 0) {
            temp.nd.push_back(pazymys);
        }

        cout << "Iveskite egzamino rezultata: ";
        cin >> temp.egzaminas;

        studentai.push_back(temp);

        cout << "Ar norite ivesti dar viena studenta? (t/n): ";
        cin >> testi;
    }

    spausdintiAntrastes();
    for (const auto& studentas : studentai) {
        spausdintiRezultata(studentas, naudotiVidurki);
    }

    return 0;
}
