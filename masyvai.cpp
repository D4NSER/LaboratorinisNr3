#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char vardas[50];
    char pavarde[50];
    int *nd_rezultatai;
    int nd_kiekis;
    int egzaminas;
} Studentas;

// rusiuoju masyvus didejimo tvarka
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

int main() {
    int m = 0, i, j;
    Studentas *studentai = NULL;
    char testi = 't';
    char metodas;

    printf("Pasirinkite skaiciavimo metoda (v - vidurkis, m - mediana): ");
    scanf(" %c", &metodas);

    while (testi == 't') {
        studentai = (Studentas *)realloc(studentai, (m + 1) * sizeof(Studentas));
        printf("Iveskite studento varda ir pavarde: ");
        scanf("%s %s", studentai[m].vardas, studentai[m].pavarde);
        
        studentai[m].nd_rezultatai = NULL;
        studentai[m].nd_kiekis = 0;
        printf("Iveskite ND rezultatus (0 baigia ivedima): ");
        int rez = 1;
        while (rez != 0) {
            scanf("%d", &rez);
            if (rez != 0) {
                studentai[m].nd_rezultatai = (int *)realloc(studentai[m].nd_rezultatai, (studentai[m].nd_kiekis + 1) * sizeof(int));
                studentai[m].nd_rezultatai[studentai[m].nd_kiekis] = rez;
                studentai[m].nd_kiekis++;
            }
        }

        printf("Iveskite egzamino rezultata: ");
        scanf("%d", &studentai[m].egzaminas);

        m++;
        printf("Ar norite ivesti dar viena studenta? (t/n): ");
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

   
    for (i = 0; i < m; i++) {
        free(studentai[i].nd_rezultatai);
    }
    free(studentai);

    return 0;
}
