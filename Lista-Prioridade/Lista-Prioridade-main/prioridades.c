#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prioridades.h"

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}
void  cadastrarContribuinte(Contribuinte *contribuinte){
    printf("Nome:");
    scanf("%s",&contribuinte->nome);

    printf("Idade:");
    scanf("%d",&contribuinte->idade);
    getchar();
    printf("Profissao:");
    gets(contribuinte->profissao);

    printf("Deficiencia (1-sim ou 0-nao):");
    scanf("%d",&contribuinte->deficiencia);

    printf("Molestia (1-sim ou 0-nao):");
    scanf("%d",&contribuinte->molestia);

}

void inicializarLotesRestituicao(LotesRestituicao** lotes) {
    *lotes = (LotesRestituicao*)malloc(sizeof(LotesRestituicao));

    for (int i = 0; i < 2; i++) {
        (*lotes)->filasPrioridade[i] = criarFila();
    }
}

void inserirFila(Fila* fila, Contribuinte contribuinte) {
    No* novo = (No*)malloc(sizeof(No));
    novo->contribuinte = contribuinte;
    novo->prox = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}


void organizarBeneficiarios(LotesRestituicao* lotes, Contribuinte contribuinte) {

        if (contribuinte.idade > 80) {
            inserirFila(lotes->filasPrioridade[0], contribuinte);
        }else if ((contribuinte.deficiencia)==1) {
            inserirFila(lotes->filasPrioridade[1], contribuinte);
        } else if (contribuinte.idade >= 60 && contribuinte.idade <= 79 && (contribuinte.molestia)==1) {
            inserirFila(lotes->filasPrioridade[2], contribuinte);
        } else if(strcmp(contribuinte.profissao, "magisterio") == 0){
            inserirFila(lotes->filasPrioridade[3], contribuinte);
        }else{
            inserirFila(lotes->filasPrioridade[4], contribuinte);
        }
}


void imprimirBeneficiarios(Fila* fila) {
    No* atual = fila->inicio;

    while (atual != NULL) {
        Contribuinte contribuinte = atual->contribuinte;
        printf("Nome: %s\n", contribuinte.nome);
        printf("Idade: %d\n", contribuinte.idade);
        printf("Profissao: %s\n", contribuinte.profissao);
        printf("Deficiencia fisica ou mental: %s\n", (contribuinte.deficiencia == 1) ? "sim" : "nao");
        printf("Molestia Grave: %s\n", (contribuinte.molestia == 1) ? "sim" : "nao");
        printf("======================================\n");
        atual = atual->prox;
    }
}

void liberarFila(Fila* fila) {
    No* atual = fila->inicio;

    while (atual != NULL) {
        No* prox = atual->prox;
        free(atual);
        atual = prox;
    }

    free(fila);
}

void liberarLotesRestituicao(LotesRestituicao* lotes) {
    for (int i = 0; i < 2; i++) {
        liberarFila(lotes->filasPrioridade[i]);
    }

    free(lotes);
}


