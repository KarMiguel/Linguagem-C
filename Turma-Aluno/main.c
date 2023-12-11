#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "aluno.h"

int main(int argc, char *argv[]) {

    printf("\nInforme o numeros de Alunos:");
    scanf("%d",&NUM_ALUNOS);

    printf("Informe a quantidade de provas:");
    scanf("%d",&NUM_PROVAS);

    int op = -1;
    char ordem;
    TAluno *vAlunos = (TAluno *)malloc(NUM_ALUNOS * sizeof(TAluno));
    float mediaGeral = 0;

    do{
        printf("\n\n===============DIARIO DO WILSON==================");
        printf("\n 1 - Preencher dados dos Alunos.");
        printf("\n 2 - Media Geral da turma.");
        printf("\n 3 - Mostrar dados ordenados por nome.");
        printf("\n 4 - Mostrar dados ordenados por CPF.");
        printf("\n 5 - Mostrar aluno com maior e menor media.");
        printf("\n 6 - Alunos acima da media geral.");
        printf("\n 0 - Sair do DIARIO DO WILSON.");
        printf("\n=================================================\n");
        scanf("%d",&op);

        switch(op){
            case 1:
                    for (int i = 0; i < NUM_ALUNOS; i++) {
                        vAlunos[i] = *criarAluno(NUM_PROVAS);
                        preecheDadosAluno(&vAlunos[i]);
                    }
                break;
            case 2:
                mediaGeral = calculaMediaGeral(vAlunos);
                printf("\nMedia Geral de notas da Turma = %.2f",mediaGeral);
                break;
            case 3:
                getchar();
                printf("\n Digite (c) - crescente  ou (d) - decrescente :");
                scanf("%c",&ordem);
                ordAlfabetica(vAlunos,NUM_ALUNOS,ordem);
                for (int i = 0 ; i < NUM_ALUNOS ; i++){
                    imprimeDadosAluno(vAlunos[i]);
                }
                break;
            case 4:
                getchar();
                printf("\n Digite (c) - crescente  ou (d)decrescente :");
                scanf("%c",&ordem);
                ordMedia(vAlunos,NUM_ALUNOS,ordem);
                for (int i = 0 ; i < NUM_ALUNOS ; i++){
                    imprimeDadosAluno(vAlunos[i]);
                }
                break;
            case 5:
                encontraAlunosComMaiorEMenorNota(vAlunos);
                break;
            case 6:
                alunosNotasMaiores(vAlunos,mediaGeral);
                break;
             case 0:
                 printf("Obrigado!!");
                break;
            default:
                printf("Situaco invalida");
                break;
    }
    }while(op!=0);

	free(vAlunos);

	return 0;
}
