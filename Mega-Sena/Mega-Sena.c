#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_aposta(int *aposta, int n){
    printf("\nDigite os numeros de intervalo de 0 a 100!\n");
    for (int i = 0; i < n; i++){
        printf("digite o seu %d numero :",i+1);
        scanf("%d",(aposta+i));
        while(*(aposta+i)<0 || *(aposta+i)>100){
            printf("\nAposta invalida!");
            printf("\nDigite novamente:");
            scanf("%d",(aposta+i));
        }
    }
}
void  sorteia_valores(int *sorteio, int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++)  {
        (*(sorteio+i)) = rand() % 101;
    }

    printf("Numero sorteado:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", *(sorteio+i));
    }
}

int *compara_aposta(int *aposta, int *sorteio,int *qtdacertos, int na, int ns){
    *qtdacertos = 0;
    for (int i = 0; i < na ; i++){
        for (int j = 0; j < ns ; j++){
            if(*(aposta+i) == *(sorteio+j)){
                (*qtdacertos)++;
            }
        }
    }
    return qtdacertos;
}
 void mostrarAcertos(int *sorteio,int *aposta,int *acertos,int n1,int n2){
 printf("\n\nVoce acertou %d numeros!!!\n",(*acertos));
    if(*acertos > 0){
        printf("Sendo eles:\n");
        for(int i = 0;i<n1;i++){
            for(int j = 0;j<n2;j++){
                if(*(aposta+i) == *(sorteio+j)){
                    printf("[%d] ",aposta[i]);
                }
            }
        }
    }
 }
int main(){
    int op;

    do{
        int nAposta,nSorteio;
        nAposta=0;
        nSorteio=0;
        printf("Informe qts numeros ira apostar:");
        scanf("%d",&nAposta);
        int *aposta=(int*)malloc(nAposta*sizeof(int));
        ler_aposta(aposta,nAposta);

        printf("Informe qts numeros sera sorteados:");
        scanf("%d",&nSorteio);
        while(nSorteio<1 || nSorteio>20){
            printf("\nNumero  invalida!");
            printf("\nDigite numero entre 1 e 20... :");
            scanf("%d",&nSorteio);
        }

        printf("\n");
        int *sorteio=(int*)malloc(nSorteio*sizeof(int));
        sorteia_valores(sorteio,nSorteio);
        int *qtdacertos;
        int *acertos = compara_aposta(aposta, sorteio, &qtdacertos, nAposta, nSorteio);

        mostrarAcertos(sorteio,aposta,acertos,nAposta,nSorteio);
        free(aposta);
        free(sorteio);

        printf("\n\nDigite '1' - continuar apostando || Outro numero encerra a aposta.");
        scanf("%d",&op);
            if(op!=1){
                break;
            }
    }while(op == 1);

    return 0;
}
