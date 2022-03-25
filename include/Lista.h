#ifndef LISTADOGS_H
#define LISTADOGS_H

typedef struct lista Lista;

Lista* iniciaLista();

void insereLista(Lista* lista, int pid);

int retiraPrimeiroLista(Lista* lista);

int getTamanhoLista(Lista *lista);

void imprimeLista(Lista* lista);

void destroiLista(Lista* lista);

#endif