#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Pridėta dėl std::sort

double vidurkis(const std::vector<int>& nd) {
    double suma = 0.0;
    for (int pazymys : nd) {
        suma += pazymys;
    }
    return suma / nd.size();
}

double mediana(std::vector<int> nd) {
    size_t dydis = nd.size();
    std::sort(nd.begin(), nd.end());
    if (dydis % 2 == 0) {
        return (nd[dydis / 2 - 1] + nd[dydis / 2]) / 2.0;
    } else {
        return nd[dydis / 2];
    }
}

int main() {
    int m; // Studentų skaičius
    std::cout << "Įveskite studentų skaičių: ";
    std::cin >> m;

    std::vector<std::string> vardai;
    std::vector<double> galutiniai_balai;

    char metodas;
    std::cout << "Pasirinkite skaičiavimo būdą (v - vidurkis, m - mediana): ";
    std::cin >> metodas;
    std::cin.ignore();

    for (int i = 0; i < m; ++i) {
        std::string vardas;
        std::cout << "Įveskite " << i + 1 << "-ojo studento vardą: ";
        std::cin >> vardas;
        vardai.push_back(vardas);

        int n; // Namų darbų skaičius
        std::cout << "Įveskite namų darbų skaičių: ";
        std::cin >> n;

        std::vector<int> nd(n);
        for (int j = 0; j < n; ++j) {
            std::cout << "Įveskite namų darbų Nr." << j + 1 << " rezultatą: ";
            std::cin >> nd[j];
        }

        int egz;
        std::cout << "Įveskite egzamino rezultatą: ";
        std::cin >> egz;

        double galutinis;
        if (metodas == 'v' || metodas == 'V') {
            galutinis = 0.4 * vidurkis(nd) + 0.6 * egz;
        } else {
            galutinis = 0.4 * mediana(nd) + 0.6 * egz;
        }
        galutiniai_balai.push_back(galutinis);
    }

    std::cout << "Visų studentų galutiniai balai:" << std::endl;
    for (size_t i = 0; i < vardai.size(); ++i) {
        std::cout << vardai[i] << " galutinis balas: " << galutiniai_balai[i] << std::endl;
    }

    return 0;
}
