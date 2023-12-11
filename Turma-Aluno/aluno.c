#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

TAluno * criarAluno(int numProvas){
	TAluno * pAluno = (TAluno *)malloc(sizeof(TAluno));

	if (pAluno == NULL )
		printf("Erro alocando memoria!!!\n");

	pAluno->notas = (float*) calloc(numProvas, sizeof(float));
	return pAluno;
}

void liberarMemoriaAluno(TAluno *a){
	free(a->notas);
	free(a);
	a = NULL;
}

void preecheDadosAluno( TAluno *a){

	fflush(stdin);

	printf("\nEntre com os dados do aluno\n");

	printf("Nome: ");
	gets(a->nome);

    do {

        printf("CPF: ");
        gets(a->cpf);
            if (validarCpfRepetido(a,NUM_ALUNOS,a->cpf)==0) {
                printf("CPF ja cadastrado! Digite outro CPF:\n");
            }
    }while(validarCpfRepetido(a,NUM_ALUNOS,a->cpf) == 0);

    a->matricula = -1;
    printf("Matricula: ");
    scanf("%d", &a->matricula);

    while (validarMatriculasRepetidas(&a,NUM_ALUNOS)== 1) {
        printf("Matricula ja cadastrada ou invalida! Digite outra matricula: ");
        scanf("%d", &a->matricula);
    }

    a->numProvas = NUM_PROVAS;
	printf("Notas das Provas: \n");
	for(int i=0;i< a->numProvas;i++){
        do{
            printf("Nota %d: ",i+1);
            scanf("%f",&a->notas[i]);
                if(validarNota(a)==1){
                    printf("Nota Invalida!\nDigite uma nota entre 0 e 100:\n");
                    scanf("%f",&a->notas[i]);
                }
            }while(validarNota(a)==1);
    }

    do{
        printf("Frenquencia: ");
        scanf("%d",&a->frequencia);
            if(validarFrequencia(a)==1){
                printf("Frequencia Invalida! Digite frequencia[0-100]:");
                scanf("%d",&a->frequencia);
            }
    }while(validarFrequencia(a)==1);

    calculaMedia(a);
}

void copiaAluno( TAluno a1, TAluno *a2){

	a2 = criarAluno(NUM_PROVAS);
	*a2 = a1;
	strcpy (a2->nome, a1.nome);
	strcpy (a2->cpf, a1.cpf);
	for (int i = 0 ;NUM_PROVAS; i++ )
		a2->notas[i] = a1.notas[i];
}

void imprimeDadosAluno( TAluno a){

    printf("---------------------------------");
	printf("\nDADOS DO ALUNO\n");
	printf("Nome          : %s\n",a.nome);
	printf("CPF           : %s\n",a.cpf);
	printf("Matricula     : %d\n",a.matricula);
	printf("Num de provas : %d\n",a.numProvas);
	printf("Media         : %.2f\n",a.media);
	printf("Frequencia    : %d\n",a.frequencia);
    setFrequencia(&a);
    setSituacao(&a);
    printf("\n---------------------------------\n");

	return;
}

void calculaMedia(TAluno *a){
    a->media=0;
	for(int i = 0; i < a->numProvas ;i++){
		a->media += a->notas[i];
	}
   a->media /= a->numProvas;
}

float calculaMediaGeral(TAluno *a){
    float soma=0;
	for(int i = 0; i <NUM_ALUNOS ;i++){
		soma += a[i].media;
	}
    return soma /NUM_ALUNOS;
}

void alunosNotasMaiores(PtrAluno a, float media){
    int pos = -1;
    printf("\n\nAlunos acima da media geral da turma");
    for(int i = 0; i < NUM_ALUNOS; i++){
        if(a[i].media > media){
            pos = i;
        }
    }
    if(pos >= 0){
        printf("\n%s  -  %.2f", a[pos].nome, a[pos].media);
    } else {
        printf("Nenhum aluno acima da media geral da turma\n");
    }
}

void encontraAlunosComMaiorEMenorNota(PtrAluno a) {
    int posMaiorNota = 0;
    int posMenorNota = 0;

    for(int i = 1; i < NUM_ALUNOS; i++) {
        if(a[i].media > a[posMaiorNota].media) {
            posMaiorNota = i;
        }
        if(a[i].media < a[posMenorNota].media) {
            posMenorNota = i;
        }
    }

    printf("\n---------------------------------------------");
    printf("\nAluno com a maior media: %s - %.2f", a[posMaiorNota].nome, a[posMaiorNota].media);
    printf("\nAluno com a menor media: %s - %.2f", a[posMenorNota].nome, a[posMenorNota].media);
    printf("\n---------------------------------------------");

}

void setFrequencia(TAluno *a){
   if(a->media >= 60 && a->frequencia >= 75){
        a->situacao = aprovado;
    }else if(a->media >=40 && a->frequencia >=75){
        a->situacao = recuperacao;
    }else{
        a->situacao = reprovado;
    }
}

void setSituacao(TAluno *a){
  switch(a->situacao){
    case reprovado:
        printf("Situacao      : reprovado\n");
        break;
    case recuperacao:
        printf("Situacao      : recuperacao\n");
        break;
    case aprovado:
        printf("Situacao      : aprovado\n");
        break;
    default:
        printf("Situaco invalida");
        break;
    }

}

void ordAlfabetica(TAluno v[], int tam, char t) {
    int i, j;
    TAluno temp;
    for (i = 0; i < tam - 1; i++) {
        for (j = i + 1; j < tam; j++) {
            if ((t == 'c' && strcmp(v[i].nome, v[j].nome) > 0) ||
                (t != 'c' && strcmp(v[i].nome, v[j].nome) < 0)) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

void ordMedia (TAluno v[], int tam, char t){
    int i, j;
    TAluno temp;
    for (i = 0; i < tam - 1; i++) {
        for (j = i + 1; j < tam; j++) {
            if ((t == 'c' && strcmp(v[i].cpf, v[j].cpf) > 0) ||
                (t != 'c' && strcmp(v[i].cpf, v[j].cpf) < 0)) {
                    temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
            }
        }
    }
}

int validarNota(PtrAluno a){
    for(int i = 0; i < a->numProvas; i++){
        if(a->notas[i] < 0 || a->notas[i] > 100){
            return 1;
        }
    }
    return 0;
}

int validarFrequencia(PtrAluno a){
    if(a->frequencia < 0 || a->frequencia> 100){
        return 1;
    }
    return 0;
}

int validarCpfRepetido(TAluno alunos[], int n, char cpf[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(alunos[i].cpf, cpf) >0) {
            return 1; // CPF já foi cadastrado
        }
    }
    return 0;
}


int validarMatriculasRepetidas(TAluno * alunos, int tamanho) {
    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = i + 1; j < tamanho; j++) {
            if(alunos[i].matricula == alunos[j].matricula) {
                return 1;
            }
        }
    }
    return 0;
}
