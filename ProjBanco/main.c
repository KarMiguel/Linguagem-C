#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "banco.h"

int main() {
    TListaClientesAr *lista = criarLista();
    int opcao = 0;
    unsigned int numConta;
    TCliente *cliente;
    int numeroConta = 0;


    do{
        printf("\n=================== BANCO DO BIGODIN =========================\n");
        printf("\t1. Cadastrar cliente\n");
        printf("\t2. Remover cliente\n");
        printf("\t3. Imprimir lista de clientes\n");
        printf("\t4. Inserir cliente ordenado por numero de conta\n");
        printf("\t5. Destruir lista de clientes\n");
        printf("\t6. Verificar se lista esta cheia\n");
        printf("\t7. Sair\n");
        printf("\n================================================================");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cliente = criaCliente();
                insere(lista, cliente);
                break;
            case 2:
                printf("Digite o numero da conta do cliente a ser removido: ");
                scanf("%u", &numConta);
                if (removeConta(lista, numConta)) {
                    printf("Cliente removido com sucesso.\n");
                } else {
                    printf("Cliente nao encontrado.\n");
                }
                break;
            case 3:
                printf("Lista de clientes:\n");
                imprime(lista);
                break;
            case 4:
                do{
                    printf("Informe o numero da conta: ");
                    scanf("%d", &numeroConta);
                    if(validarNumConta(lista, cliente,numeroConta)){
                        printf("\nNumero de conta ja existente!!\n");
                    }
                }while(validarNumConta(lista, cliente,numeroConta));

                cliente = criaCliente();
                insereOrdenadoPorConta(lista, cliente, numeroConta);
                break;
            case 5:
                destroiLista(lista);
                lista = criarLista();
                printf("Lista de clientes destruida.\n");
                break;
            case 6:
                if(isNotCheia(lista)){
                    int qtdSobra = NUM_MAX - lista->ultimo;
                    printf("Lista ainda tem %d posicoes!!\n",qtdSobra);
                }else{
                    printf("Lista Cheia!!");
                }
                break;
             case 7:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao inválida.\n");
                break;
        }
    }while (opcao != 7);

    destroiLista(lista);
    free(lista);

    return 0;
}
