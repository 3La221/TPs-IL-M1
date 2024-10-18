#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void echanger(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void triParSelection(int tableau[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < taille; j++) {
            if (tableau[j] < tableau[minIndex]) {
                minIndex = j;
            }
        }

        echanger(&tableau[minIndex], &tableau[i]);
    }
}

void afficherTableau(int tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");
}

int main() {
    int N;
    printf("N : ");
    scanf("%d", &N);

    int tableau[N];

    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        tableau[i] = rand() % 100;
    }

 //   printf("AVANT:\n");
  //  afficherTableau(tableau, N);

    clock_t debut = clock();

    triParSelection(tableau, N);

    clock_t fin = clock();

    double temps_pris = ((double)(fin - debut)) / CLOCKS_PER_SEC;

  //  printf("APRES :\n");
    //afficherTableau(tableau, N);
    printf("Temps pris pour trier le tableau : %f secondes\n", temps_pris);

    return 0;
}
