#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int TAM;
    char tipo[10];

    printf("Digite o tamanho do vetor que deseja alocar: ");
    scanf("%d", &TAM);

    printf("Escolha o tipo da variavel (int, float, char): ");
    scanf("%s", tipo);

    if (strcmp(tipo, "int") == 0){
        int *p = (int*) malloc(TAM * sizeof(int));

        printf("\nDigite os valores inteiros:\n");
        for (int i = 0; i < TAM; i++){
            scanf("%d", &p[i]);
        }
        
        printf("Saida: ");
        for (int i = 0; i < TAM; i++){
            printf("%d ", p[i]);
        }
        printf("\n");
        free(p);

    } else if (strcmp(tipo, "float") == 0){
        float *p = (float*) malloc(TAM * sizeof(float));

        printf("\nDigite um valor float: ");
        for (int i = 0; i < TAM; i++){
            scanf("%f", &p[i]);
        }
        
        printf("Saida: ");
        for (int i = 0; i < TAM; i++){
            printf("%.2f ", p[i]);
        }
        printf("\n");
        free(p);
        
    } else if (strcmp(tipo, "char") == 0){
        char *p = (char*) malloc(TAM * sizeof(char));
        
        printf("Digite uma palavra: ");
        for (int i = 0; i < TAM; i++){
            scanf(" %[^\n]", p);
        }
        
        printf("Saida: %s\n", p);
        free(p);

    } else{
        printf("Tipo invalido!");
    }
    
    return 0;
}