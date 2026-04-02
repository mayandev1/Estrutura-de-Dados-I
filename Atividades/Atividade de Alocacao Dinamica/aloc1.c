#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char tipo[10];

    printf("Escolha o tipo da variavel (int, float, char): ");
    scanf("%s", tipo);

    if (strcmp(tipo, "int") == 0){
        int *p = (int*) malloc(sizeof(int));

        printf("\nDigite um valor inteiro: ");
        scanf("%d", p);

        printf("Saida: %d\n", *p);
        free(p);

    } else if (strcmp(tipo, "float") == 0){
        float *p = (float*) malloc(sizeof(float));

        printf("\nDigite um valor float: ");
        scanf("%f", p);
        
        printf("Saida: %.2f\n", *p);
        free(p);
        
    } else if (strcmp(tipo, "char") == 0){
        char *p = (char*) malloc(sizeof(char));
        
        printf("\nDigite um char: ");
        scanf(" %c", p);
        
        printf("Saida: %c\n", *p);
        free(p);

    } else {
        printf("Tipo invalido!");
    }
    
    return 0;
}