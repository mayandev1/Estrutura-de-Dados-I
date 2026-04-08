#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void separar(int *v, int n, int **pares, int *tamP, int **impares, int *tamI){
    *tamP = 0;
    *tamI = 0;

    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0)
            (*tamP)++;
        else
            (*tamI)++;
    }

    if(*tamP > 0)
        *pares = (int*) malloc((*tamP) * sizeof(int));

    if(*tamI > 0)
        *impares = (int*) malloc((*tamI) * sizeof(int));

    int p = 0, im = 0;
    
    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0)
            (*pares)[p++] = v[i];
        else
            (*impares)[im++] = v[i];
    }
}

int main(){
    int v[10];
    int *pares = NULL, *impares = NULL;
    int tamP, tamI;

    srand(time(NULL));

    for(int i = 0; i < 10; i++){
        v[i] = rand() % 10 + 1;
    }

    separar(v, 10, &pares, &tamP, &impares, &tamI);

    printf("Vetor principal: ");
    for(int i = 0; i < 10; i++)
        printf("%d ", v[i]);

    printf("\nPares: ");
    if(pares == NULL)
        printf("NULL");
    else
        for(int i = 0; i < tamP; i++)
            printf("%d ", pares[i]);

    printf("\nImpares: ");
    if(impares == NULL)
        printf("NULL");
    else
        for(int i = 0; i < tamI; i++)
            printf("%d ", impares[i]);

    free(pares);
    free(impares);

    return 0;
}