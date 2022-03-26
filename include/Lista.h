#ifndef LISTADOGS_H
#define LISTADOGS_H

typedef struct lista Lista;

/**
* @brief:Funcao para inicializar e alocar uma lista encadeada com sentinela de processos
* @return: Ponteiro do tipo Lista com a posição de memoria alocada
*/
Lista* iniciaLista();

/**
* @brief:Funcao para inserir um novo elemento em uma lista previamente inicializada
* @param lista: Ponteiro do tipos Lista que carrega a sentina da lista
* @param pid: Inteiro correspondente ao valor pid a ser carregado pela nova celula ada lista
* @return: Nenhum
*/
void insereLista(Lista* lista, int pid);

/**
* @brief:Funcao para retirar primeiro elemento de uma lista
* @param lista: Ponteiro para a sentinela da lista de processos
* @return: Um inteiro correspondente ao pid do elemento retirado. Caso a lista esteje vazia, retorna-se -1
*/
int retiraPrimeiroLista(Lista* lista);

/**
* @brief:Funcao de acesso a quantidade de elementos pertencentes a uma lista
* @param lista: Ponteiro para a sentinela da lista de processos
* @return: Inteiro correspondente a quantidade de elementos
*/
int getTamanhoLista(Lista *lista);

/**
* @brief:Funcao para liberar da memoria uma lista previamente inicializada
* @param lista: Ponteiro para a sentinela da lista de processos
* @return: Nenhum
*/
void destroiLista(Lista* lista);

#endif