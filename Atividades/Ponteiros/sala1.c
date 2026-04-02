#include <stdio.h>
#include <stdlib.h>

int main(){
    int TAM = 0;

    printf("Qual o tamanho da string que deseja digitar?\n");
    scanf("%d", &TAM);
    
    char *str = (char*) malloc((TAM + 1) * sizeof(char));

    if (str == NULL){
        printf("Erro na alocacao!");
        return 1;
    }
    
    getchar();
    
    printf("Digite a string:\n");
    fgets(str, TAM + 1, stdin);

    printf("String digitada: %s\n", str);

    free(str);
   
    return 0;
}