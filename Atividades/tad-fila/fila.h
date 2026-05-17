#ifndef FILA_H
#define FILA_H

typedef struct no No;
typedef struct fila Fila;

Fila *criar_fila();
void inserir_fila(Fila *f);
void remover_fila(Fila *f);
void mostrar_inicio(Fila *f);
void mostrar_final(Fila *f);
void mostrar_fila(Fila *f);
void liberar_fila(Fila *f);
int tamanho_fila(Fila *f);

#endif // FILA_H