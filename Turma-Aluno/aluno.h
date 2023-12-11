#ifndef _ALUNO_H_
#define _ALUNO_H_

int NUM_PROVAS ;
int NUM_ALUNOS ;


typedef enum{
    reprovado = 0,
    recuperacao = 1,
    aprovado = 2
}TSituacao;

typedef struct{
	char nome[60]; // nome do aluno
	char cpf[11];
    int matricula; // número de matrícula
	int numProvas;
    float *notas; // três notas
    float media; // média aritmética
	int frequencia;
	TSituacao situacao; // situação do aluno
}TAluno;

typedef TAluno * PtrAluno;


TAluno * criarAluno(int);
void liberarMemoriaAluno(TAluno *);
void preecheDadosAluno(TAluno *);
void copiaAluno( TAluno, TAluno *);
void calculaMedia(TAluno *);
void setFrequencia(TAluno *);
void setSituacao(TAluno *);
void imprimeDadosAluno( TAluno );
void ordAlfabetica(TAluno v[], int tam, char t);
void ordMedia (TAluno v[], int tam, char);
float calculaMediaGeral(TAluno *a);
void alunosNotasMaiores(PtrAluno a, float media);
void encontraAlunosComMaiorEMenorNota(PtrAluno a);
int validarNota(PtrAluno a);
int validarFrequencia(PtrAluno a);
int validarMatriculaRepetida(TAluno *alunos) ;


#endif
