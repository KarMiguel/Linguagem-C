#include <stdbool.h>
#include <stdio.h>
#include "banco.h"

TCliente *criaCliente() {
    TCliente *cliente = (TCliente *)malloc(sizeof(TCliente));
    if (cliente != NULL) {
        fflush(stdin);

        static int numeroConta = 1;
        cliente->numeroConta = numeroConta++;

        printf("Digite o nome do cliente: ");
        scanf("%s", cliente->nome);

        printf("Digite a data de nascimento do cliente (dd/mm/aaaa): ");
        scanf("%s", cliente->dataNascimento);

        printf("Digite o saldo do cliente: ");
        scanf("%lf", &(cliente->saldo));

        return cliente;
    }

    return NULL;
}

void imprimeDadosCliente(TCliente c) {
    printf("\n------------------------------------\n");
    printf("Número da conta: %d\n", c.numeroConta);
    printf("Nome: %s\n", c.nome);
    printf("Data de nascimento: %s\n", c.dataNascimento);
    printf("Saldo: %.2lf\n", c.saldo);
}
void liberaMemoriaCliente(TCliente *c) {
    free(c);
}

TListaClientesAr *criarLista() {
    TListaClientesAr *lista = (TListaClientesAr *)malloc(sizeof(TListaClientesAr));
    if (lista != NULL) {
        lista->primeiro = 0;
        lista->ultimo = 0;
        for (int i = 0; i < NUM_MAX; i++) {
            lista->clientes[i] = NULL;
        }
        return lista;
    }
    return NULL;
}
void destroiLista(TListaClientesAr *l) {
    for (int i = l->primeiro; i < l->ultimo; i++) {
        if (l->clientes[i] != NULL) {
            liberaMemoriaCliente(l->clientes[i]);
            l->clientes[i] = NULL;
        }
    }
    free(l);
}


void insere(TListaClientesAr *l, TCliente *c) {
    if (isNotCheia(l)) {
        l->clientes[l->ultimo] = c;
        l->ultimo++;
    } else {
        printf("Lista cheia. Não foi possível inserir o cliente.\n");
    }
}

bool isNotCheia(TListaClientesAr *l) {
    return l->ultimo < NUM_MAX;
}
void imprime(TListaClientesAr *l) {
    int vazio = 1;
    printf("\n*******LISTA DE CLIENTES*******\n");
    for (int i = l->primeiro; i < l->ultimo; i++) {
        if (l->clientes[i] != NULL) {
            imprimeDadosCliente(*(l->clientes[i]));
            vazio=0;
        }
    }
    if(vazio != 0){
        printf("Lista Vazia!!");
    }
}
bool removeConta(TListaClientesAr *l, unsigned int numConta) {
    for (int i = l->primeiro; i < l->ultimo; i++) {
        if (l->clientes[i] != NULL && l->clientes[i]->numeroConta == numConta) {
            liberaMemoriaCliente(l->clientes[i]);
            l->clientes[i] = NULL;
            for (int j = i; j < l->ultimo - 1; j++) {
                l->clientes[j] = l->clientes[j + 1];
            }
            l->clientes[l->ultimo- 1] = NULL;
            l->ultimo--;
            return true;
        }
    }
    return false;
}

void insereOrdenadoPorConta(TListaClientesAr *l, TCliente *c,int numeroConta) {

    c->numeroConta = 0;
    c->numeroConta = numeroConta;
    if (isNotCheia(l)) {
        int posicao = 0;

    while (posicao < l->ultimo && l->clientes[posicao]->numeroConta < c->numeroConta) {
        posicao++;
    }

    for (int i =  l->ultimo; i > posicao; i--) {
        l->clientes[i] = l->clientes[i - 1];
    }

    l->clientes[posicao] = c;
    l->ultimo++;

    } else {
        printf("Lista cheia. Não foi possível inserir o cliente.\n");
    }
}
bool validarNumConta(TListaClientesAr *l, TCliente *c, int numConta){
    for(int i; i<=l->ultimo;i++){
        if(c->numeroConta==numConta){
            return true;
        }
    }
    return false;
}

