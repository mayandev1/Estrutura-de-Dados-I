#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void verificaAlocacao(void *p){
    if (p == NULL){
        system("cls");
        printf("Falha!\n");
        exit(1);
    }
}

int main(){
    int *ptr = NULL;
    int num;

    srand(time(NULL));
    num = rand() % 100;

    ptr = (int*) malloc(sizeof(int));

    verificaAlocacao(ptr);

    *ptr = num;
    system("cls");
    printf("Sucesso!");

    free(ptr);
    return 0;
}