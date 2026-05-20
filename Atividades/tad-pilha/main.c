#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    Pilha *pilha = criar_pilha();

    int opcao;

    system("cls");

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir aluno na pilha (push)\n");
        printf("2 - Remover aluno (pop)\n");
        printf("3 - Mostrar pilha\n");
        printf("4 - Mostrar o topo\n");
        printf("5 - Destruir pilha\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            push(pilha);
            break;

        case 2:
            pop(pilha);
            break;

        case 3:
            system("cls");
            mostrar_pilha(pilha);
            break;

        case 4:
            system("cls");
            int temp = topo(pilha);

            if (temp == 1){
                break;
            }

            printf("Matricula do topo atual <%d>\n", temp);
            break;

        case 5:
            system("cls");
            liberar_pilha(pilha);
            break;

        case 0:
            system("cls");
            liberar_pilha(pilha);
            printf("Encerrando programa...");
            return 0;

        default:
            printf("Erro, escolha a opcao correta.");
            break;
        }

    } while (opcao != 0);
}