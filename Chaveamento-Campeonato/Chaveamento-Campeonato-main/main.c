#include <stdio.h>
#include <stdlib.h>
#include "libertadores.h"


int main() {
    int n;

    do {
        printf("\nInforme a quantidade de times (2, 4, 8, 16, ...): ");
        scanf("%d", &n);

        if (!verificaSequencia(n)) {
            printf("\nNúmero invalido. Por favor, informe um número da sequencia.\n");
        }
    } while (!verificaSequencia(n));


    Time* times = malloc(n * sizeof(Time));

    for (int i = 0; i < n; i++) {
        printf("\nTime %d:\n", i + 1);
        criarTime(&times[i]);
    }

    No* raiz = torneio(times, 0, n - 1);
    printf("\n\t==================================================\n");
    printf("\t\tCHAVIAMENTO COPA LIBERTADORES 2023\n");
    printf("\t\==================================================\n");
    inordem(raiz);
    return 0;
}
