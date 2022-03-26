#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

typedef struct celula Celula;

struct celula{
    int pid;
    Celula* prox;
};

struct lista{
    Celula* prim;
    Celula* ult;
};


Lista* iniciaLista(){
  Lista* lista = (Lista*)malloc(sizeof(Lista));
  lista->prim = NULL;
  lista->ult = NULL;

  return lista;
}

void insereLista(Lista* lista, int pid){
  Celula* cel_nova = (Celula*)malloc(sizeof(Celula));

    cel_nova->pid = pid;
    cel_nova->prox = NULL;
    if(lista->prim == NULL){
        lista->prim = cel_nova;
        lista->ult = cel_nova;
    }
    else{
        lista->ult->prox = cel_nova; 
        lista->ult = cel_nova;
  }
}

int getTamanhoLista(Lista *lista){
  int tam = 0;
  Celula* cel_aux;
  for(cel_aux = lista->prim; cel_aux != NULL; cel_aux = cel_aux->prox)
    tam++;

  return tam;
}

int retiraPrimeiroLista(Lista* lista){
  Celula* cel_aux = lista->prim;
  int pid;

  if(cel_aux == NULL) 
    return -1;
  pid = cel_aux->pid;

  if(cel_aux == lista->ult) 
    lista->prim = lista->ult = NULL; 
  else 
    lista->prim = cel_aux->prox; 

  free(cel_aux); 
  return pid;
}

void destroiLista(Lista* lista){
  Celula* cel_atual = lista->prim;
  Celula* cel_prox;

  while(cel_atual != NULL){
    cel_prox = cel_atual->prox;
    free(cel_atual);

    cel_atual = cel_prox;
  }

  free(lista);
}