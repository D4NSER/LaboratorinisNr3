#include <iostream>
#include <vector>
#include <string>

double vidurkis(const std::vector<int>& nd) {
    double suma = 0.0;
    for (int pazymys : nd) {
        suma += pazymys;
    }
    return suma / nd.size();
}

int main() {
    std::vector<std::string> vardai;
    std::vector<double> galutiniai_balai;
    std::string vardas;
    int pazymys;

    while (true) {
        std::cout << "Iveskite studento varda ir pavarde (arba 'baigti' norint uzbaigti): ";
        std::getline(std::cin, vardas);
        if (vardas == "baigti") break;

        vardai.push_back(vardas);

        std::vector<int> nd;
        std::cout << "Ivedinėkite namų darbų rezultatus (0 norint baigti): ";
        while (true) {
            std::cin >> pazymys;
            if (pazymys == 0) break;
            nd.push_back(pazymys);
        }

        int egz;
        std::cout << "Iveskite egzamino rezultata: ";
        std::cin >> egz;
        std::cin.ignore(); // Išvalyti įvesties buferį

        double galutinis = 0.4 * vidurkis(nd) + 0.6 * egz;
        galutiniai_balai.push_back(galutinis);

        std::cout << vardas << " galutinis balas: " << galutinis << std::endl;
    }

    return 0;
}
