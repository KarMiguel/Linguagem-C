#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prioridades.h"

int main() {
 LotesRestituicao * lotes;
    inicializarLotesRestituicao(&lotes);

    int qtd;
    Contribuinte  contribuinte;


    int op;
    do{
        printf("======================================\n");
        printf("========LOTES IMPOSTO DE RENDA========\n");
        printf("======================================\n");
        printf("\t1 - Cadastrar contribuinte\n");
        printf("\t2 - Imprimir lotes\n");
        printf("\t3 - Sair\n");
        printf("======================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);
            printf("======================================\n");


        switch (op) {
             case 1:
                  printf("\nInforme qts contribuente deseja cadastrar:");
                  scanf("%d",&qtd);
                for (int i = 0; i < qtd; i++) {
                    printf("\nContribuente #%d\n",i+1);
                    cadastrarContribuinte(&contribuinte);
                    organizarBeneficiarios(lotes, contribuinte);
                }
                break;
            case 2:
                printf("\n\nLOTE 1- BENEFICIARIOS +80 ANOS:\n\n");
                imprimirBeneficiarios(lotes->filasPrioridade[0]);

                printf("\nLOTE 2 - BENEFICIARIOS DEFICIENTES:\n\n");
                imprimirBeneficiarios(lotes->filasPrioridade[1]);

                printf("\nLOTE 3 - BENEFICIARIOS +60 ANOS (molestia):\n\n");
                imprimirBeneficiarios(lotes->filasPrioridade[2]);

                printf("\nLOTE 4 - PROFISSAO SEJA MAGISTERIO:\n\n");
                imprimirBeneficiarios(lotes->filasPrioridade[3]);

                printf("\nLOTE 5 - OUTROS BENEFICIARIOS:\n\n");
                imprimirBeneficiarios(lotes->filasPrioridade[4]);
                break;
            case 3:
                printf("Saindo do programa...\n");
                liberarLotesRestituicao(lotes);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

        printf("\n");


    }while(op!=3);

    liberarLotesRestituicao(lotes);

    return 0;
}
/*

*/
