#ifndef _LIBERTADORE_H_
#define _LIBERTADORE_H_

typedef struct{
    char nome[30];
    int score;
}Time , *PtrTIme;

typedef struct No {
    Time time;
    struct No *esq, *dir; /* *pai */
} No;

No* criar_arvore(Time t, No *esq, No *dir);
No* procurar_no(No *arvore, char x);
void criarTime(Time* t);
No* torneio(Time* v, int l, int r);
void inordem(No* arvore);

#endif
