#ifndef PRIORIDADES_H
#define PRIORIDADES_H

typedef struct {
    char nome[81];
    int idade;
    char profissao[55];
    int deficiencia;
    int molestia;
}Contribuinte;


typedef struct {
    Contribuinte contribuinte;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

typedef struct {
    Fila* filasPrioridade[2];
}LotesRestituicao;

Fila* criarFila();
void inicializarLotesRestituicao(LotesRestituicao** lotes);
void inserirFila(Fila* fila, Contribuinte contribuinte);
void organizarBeneficiarios(LotesRestituicao* lotes, Contribuinte contribuinte);
void imprimirBeneficiarios(Fila* fila);
void liberarFila(Fila* fila);
void liberarFilaLotes(Fila* fila) ;
#endif
