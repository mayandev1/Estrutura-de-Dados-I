#ifndef LISTA_H
#define LISTA_H

typedef struct no No;

No *criar_lista();
No *inserir_no_final(No *lista);
void mostrar_lista(No *lista);


//implementar as funcoes abaixo

void liberar_lista(No *lista);
int remover_no(No *lista, int matricula);
No *buscar_no(No *lista, int matricula);
No *inserir_no_ordenado_matricula(No *lista);
No *inserir_no_inicio(No *lista);


#endif