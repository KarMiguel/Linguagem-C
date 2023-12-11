#ifndef _BANCO_H_
#define _BANCO_H_

#define NUM_MAX 100

struct cliente {
    int numeroConta;
    char nome[100];
    char dataNascimento[11];
    double saldo;
};
typedef struct cliente TCliente;

struct listaClientesAr {
    TCliente *clientes[NUM_MAX];
    int primeiro;
    int ultimo;
};


typedef struct listaClientesAr TListaClientesAr;

TCliente *criaCliente();
void imprimeDadosCliente(TCliente c);
void liberaMemoriaCliente(TCliente *c);
TListaClientesAr *criarLista();
void destroiLista(TListaClientesAr *l);
void insere(TListaClientesAr *l, TCliente *c);
bool isNotCheia(TListaClientesAr *l);
void imprime(TListaClientesAr *l);
bool removeConta(TListaClientesAr *l, unsigned int numConta);
void insereOrdenadoPorConta(TListaClientesAr *l, TCliente *c,int);
bool validarNumConta(TListaClientesAr *l, TCliente *c, int numConta);

#endif
