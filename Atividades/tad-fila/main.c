#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){

    Fila *f = criar_fila();

    int opcao;

    do {

        printf("\n===== MENU =====\n");
        printf("1 - Inserir aluno\n");
        printf("2 - Remover aluno\n");
        printf("3 - Mostrar primeiro aluno\n");
        printf("4 - Mostrar ultimo aluno\n");
        printf("5 - Mostrar fila completa\n");
        printf("6 - Mostrar tamanho da fila\n");
        printf("7 - Liberar fila\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        while (getchar() != '\n');

        switch (opcao){

            case 1:
                inserir_fila(f);
                break;

            case 2:
                remover_fila(f);
                break;

            case 3:
                mostrar_inicio(f);
                break;

            case 4:
                mostrar_final(f);
                break;

            case 5:
                mostrar_fila(f);
                break;

            case 6:
                printf("Tamanho da fila: %d\n", tamanho_fila(f));
                break;

            case 7:
                liberar_fila(f);
                break;
            
            case 0:
                liberar_fila(f);
                printf("Programa encerrado.\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}