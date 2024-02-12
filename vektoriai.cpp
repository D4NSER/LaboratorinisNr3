#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
    std::vector<std::string> vardai;
    std::vector<double> galutinis_pazymys;
    std::string vardas;
    int pazymys;
    char skaiciavimoBudas;

    std::cout << "Pasirinkte skaičiavimo būdą (v - vidurkis arba m - mediana): ";
    std::cin >> skaiciavimoBudas;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //tiesiog ignoruos viska po paskutinio ivesto charo


    while (true) {
        std::cout << "Iveskite studento varda ir pavarde (arba 'baigti' norint uzbaigti): ";
        std::getline(std::cin, vardas);
        if (vardas == "baigti") break;

        vardai.push_back(vardas);

        std::vector<int> nd;
        std::cout << "Ivedinėkite namų darbų rezultatus (0 norint baigti): ";
        while (std::cin >> pazymys && pazymys != 0) {
            nd.push_back(pazymys);
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Valo viska, kas netinka eiluteje

        int egz;
        std::cout << "Iveskite egzamino rezultata: ";
        std::cin >> egz;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        double galutinis;
        if (skaiciavimoBudas == 'v' || skaiciavimoBudas == 'V'){
            galutinis = 0.6 * egz + 0.4 * vidurkis(nd);
        }else {
            galutinis = 0.6 * egz + 0.4 * mediana(nd);
        }
        galutinis_pazymys.push_back(galutinis);

        std::cout << vardas << " galutinis balas: " << galutinis << std::endl;
    }

    return 0;
}
