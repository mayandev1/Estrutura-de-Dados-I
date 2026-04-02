#include <stdio.h>
#include <stdlib.h>

int soma_e_compara_vetores(int *v1, int TAM1, int *v2, int TAM2){
    int maior = 0, soma1 = 0, soma2 = 0;

    for (int i = 0; i < TAM1; i++){
        soma1 += v1[i];
    }
    
    for (int i = 0; i < TAM2; i++){
        soma2 += v2[i];
    }
    
    if (soma1 > soma2){
        maior = 1;
    } 
    
    if (soma2 > soma1){
        maior = 2;
    }
    
    return maior;
}
 
int main(){
    int TAM1, TAM2, maior;

    printf("Digite o tamanho de cada vetor:\n");
    scanf("%d %d", &TAM1, &TAM2);

    int *ptr1 = (int*) malloc(TAM1 * sizeof(int));
    int *ptr2 = (int*) malloc(TAM2 * sizeof(int));

    if(ptr1 == NULL || ptr2 == NULL){
        printf("Falha na alocacao!\n");
        exit(1);
    }

    printf("Preencha o vetor1:\n");
    for (int i = 0; i < TAM1; i++){
        scanf("%d", &ptr1[i]);
    }

    printf("Preencha o vetor2:\n");
    for (int i = 0; i < TAM2; i++){
        scanf("%d", &ptr2[i]);
    }

    maior = soma_e_compara_vetores(ptr1, TAM1, ptr2, TAM2);

    if (maior == 1){
        printf("%d, A soma do vetor 1 eh maior do que a do vetor 2!\n", maior);
    } else if (maior == 2){
        printf("%d, A soma do vetor 2 eh maior do que a do vetor 1!\n", maior);
    } else {
        printf("%d, Ambos os vetores tem a mesma soma!\n", maior);
    }

    free(ptr1);
    free(ptr2);
    
    return 0;
}