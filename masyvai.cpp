#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char vardas[50];
    char pavarde[50];
    int *nd_rezultatai;
    int nd_kiekis;
    int egzaminas;
} Studentas;

//Rusiuoju array didejimo tvarka
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

double calculateMedian(int *array, int size) {
    sort(array, size);
    if (size % 2 == 0) {
        return (array[size / 2 - 1] + array[size / 2]) / 2.0;
    } else {
        return array[size / 2];
    }
}

void generateRandomGrades(Studentas *studentas) {
    studentas->nd_kiekis = rand() % 10 + 1; //nd KIEKIS nuo 1 iki 10
    studentas->nd_rezultatai = (int *)malloc(studentas->nd_kiekis * sizeof(int));
    for (int i = 0; i < studentas->nd_kiekis; i++) {
        studentas->nd_rezultatai[i] = rand() % 10 + 1; //nd balai nuo 1 iki 10
    }
    studentas->egzaminas = rand() % 10 + 1; //egzo balas nuo 1 iki 10
}

void generateRandomNamesAndGrades(Studentas *studentas) {
    const char *vardai[] = {"Jonas", "Petras", "Antanas", "Juozas", "Kazimieras"};
    const char *pavardes[] = {"Jonaitis", "Petraitis", "Antanaitis", "Juozaitis", "Kazimieraitis"};
    int vardasIndex = rand() % 5;
    int pavardeIndex = rand() % 5;
    strcpy(studentas->vardas, vardai[vardasIndex]);
    strcpy(studentas->pavarde, pavardes[pavardeIndex]);
    generateRandomGrades(studentas);
}

int main() {
    srand(time(NULL));
    int pasirinkimas, m = 0;
    char metodas;
    Studentas *studentai = NULL;

    printf("Pasirinkite skaičiavimo metodą (v - vidurkis, m - mediana): ");
    scanf(" %c", &metodas);

    while (1) {
        printf("Meniu:\n");
        printf("1 - Įvesti studentų vardus rankiniu būdu\n");
        printf("2 - Generuoti atsitiktinius pažymius\n");
        printf("3 - Generuoti atsitiktinius studentų vardus ir jų pažymius\n");
        printf("4 - Baigti darbą\n");
        printf("Įveskite savo pasirinkimą: ");
        scanf("%d", &pasirinkimas);

        if (pasirinkimas == 4) {
            break;
        }

        switch (pasirinkimas) {
            case 1: {
                char testi = 't';
                do {
                    studentai = (Studentas *)realloc(studentai, (m + 1) * sizeof(Studentas));
                    printf("Įveskite studento vardą ir pavardę: ");
                    scanf("%s %s", studentai[m].vardas, studentai[m].pavarde);

                    studentai[m].nd_rezultatai = NULL;
                    studentai[m].nd_kiekis = 0;
                    printf("Įveskite ND rezultatus (0 baigia įvedimą): ");
                    int rez;
                    do {
                        scanf("%d", &rez);
                        if (rez != 0) {
                            studentai[m].nd_rezultatai = (int *)realloc(studentai[m].nd_rezultatai, (studentai[m].nd_kiekis + 1) * sizeof(int));
                            studentai[m].nd_rezultatai[studentai[m].nd_kiekis++] = rez;
                        }
                    } while (rez != 0);

                    printf("Įveskite egzamino rezultatą: ");
                    scanf("%d", &studentai[m].egzaminas);

                    m++;
                    printf("Ar norite įvesti dar vieną studentą? (t/n): ");
                    scanf(" %c", &testi);
                } while (testi == 't');
                break;
            }
            case 2: {
                for (int i = 0; i < m; i++) {
                    generateRandomGrades(&studentai[i]);
                }
                printf("Visiems esamiems studentams sėkmingai sugeneruoti atsitiktiniai pažymiai.\n");
                break;
            }
            case 3: {
                char testi = 't';
                    do {
                        studentai = (Studentas *)realloc(studentai, (m + 1) * sizeof(Studentas));
                        generateRandomNamesAndGrades(&studentai[m]);
                        m++;
                        printf("Sugeneruotas naujas studentas. Ar norite generuoti dar vieną? (t/n): ");
                        scanf(" %c", &testi);
                } while (testi == 't');
                break;
                }
            case 4: {
                printf("Programa išjungta.\n");
                break;
            }
            default: {
                printf("Neteisingai įvesti pasirinkimo duomenys. Bandykite dar kartą.\n");
                break;
            }
        }
    } for (int i = 0; i < m; i++) {
        double galutinis;
        if (metodas == 'v' || metodas == 'V') {
            double vidurkis = 0;
            for (int j = 0; j < studentai[i].nd_kiekis; j++) {
                vidurkis += studentai[i].nd_rezultatai[j];
            }
            if (studentai[i].nd_kiekis > 0) {
                vidurkis /= studentai[i].nd_kiekis;
            }
            galutinis = 0.4 * vidurkis + 0.6 * studentai[i].egzaminas;
        } else if (metodas == 'm' || metodas == 'M') {
            double mediana = calculateMedian(studentai[i].nd_rezultatai, studentai[i].nd_kiekis);
            galutinis = 0.4 * mediana + 0.6 * studentai[i].egzaminas;
        }
        printf("%s %s: Galutinis balas = %.2f\n", studentai[i].vardas, studentai[i].pavarde, galutinis);
    }

    for (int i = 0; i < m; i++) {
        free(studentai[i].nd_rezultatai);
    }
    free(studentai);

    return 0;
}
