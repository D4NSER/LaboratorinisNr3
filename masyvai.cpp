#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char vardas[50];
    char pavarde[50];
    int *nd_rezultatai;
    int nd_kiekis;
    int egzaminas;
} Studentas;

// Funkcija, skirta int masyvo rūšiavimui didėjimo tvarka
void sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Funkcija, skirta medianos apskaičiavimui
double calculateMedian(int *array, int size) {
    sort(array, size); // Rūšiuojame masyvą
    if (size % 2 == 0) {
        return (array[size / 2 - 1] + array[size / 2]) / 2.0;
    } else {
        return array[size / 2];
    }
}

void generateRandomGrades(Studentas *studentas) {
    studentas->nd_kiekis = rand() % 10 + 1; // nd KIEKIS - tarp 1 ir 10
    studentas->nd_rezultatai = (int *)malloc(studentas->nd_kiekis * sizeof(int));
    for (int i = 0; i < studentas->nd_kiekis; i++) {
        studentas->nd_rezultatai[i] = rand() % 10 + 1; //nd - tarp 1 ir 10
    }
    studentas->egzaminas = rand() % 10 + 1; //egzas - tarp 1 ir 10
}

int main() {
    int m = 0, i, j;
    Studentas *studentai = NULL;
    char testi = 't', metodas, generavimas;

    srand(time(NULL)); 

    printf("Pasirinkite skaičiavimo metodą (v - vidurkis, m - mediana): ");
    scanf(" %c", &metodas);
    printf("Ar norite generuoti balus atsitiktinai? (t - Taip / n - Ne): ");
    scanf(" %c", &generavimas);

    while (testi == 't') {
        studentai = (Studentas *)realloc(studentai, (m + 1) * sizeof(Studentas));
        printf("Įveskite studento vardą ir pavardę: ");
        scanf("%s %s", studentai[m].vardas, studentai[m].pavarde);

        if (generavimas == 't') {
            generateRandomGrades(&studentai[m]);
        } else {
            studentai[m].nd_rezultatai = NULL;
            studentai[m].nd_kiekis = 0;
            printf("Įveskite ND rezultatus (0 baigia įvedimą): ");
            int rez = 1;
            while (rez != 0) {
                scanf("%d", &rez);
                if (rez != 0) {
                    studentai[m].nd_rezultatai = (int *)realloc(studentai[m].nd_rezultatai, (studentai[m].nd_kiekis + 1) * sizeof(int));
                    studentai[m].nd_rezultatai[studentai[m].nd_kiekis] = rez;
                    studentai[m].nd_kiekis++;
                }
            }
            printf("Įveskite egzamino rezultatą: ");
            scanf("%d", &studentai[m].egzaminas);
        }

        m++;
        printf("Ar norite įvesti dar vieną studentą? (t/n): ");
        scanf(" %c", &testi);
    }

    for (i = 0; i < m; i++) {
        double galutinis;
        if (metodas == 'v' || metodas == 'V') {
            double vidurkis = 0;
            for (j = 0; j < studentai[i].nd_kiekis; j++) {
                vidurkis += studentai[i].nd_rezultatai[j];
            }
            vidurkis /= studentai[i].nd_kiekis;
            galutinis = 0.4 * vidurkis + 0.6 * studentai[i].egzaminas;
        } else if (metodas == 'm' || metodas == 'M') { 
            double mediana = calculateMedian(studentai[i].nd_rezultatai, studentai[i].nd_kiekis);
            galutinis = 0.4 * mediana + 0.6 * studentai[i].egzaminas;
        }
        printf("%s %s: Galutinis balas = %.2f\n", studentai[i].vardas, studentai[i].pavarde, galutinis);
    }

    // Atminties valymas
    for (i = 0; i < m; i++) {
        free(studentai[i].nd_rezultatai);
    }
    free(studentai);

    return 0;
}
