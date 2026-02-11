#include "usuario.h"

#ifndef LISTA2_H
#define LISTA2_H

typedef struct Lista2 Lista2;
typedef struct Celula2 Celula2;

/**
 * @brief Cria uma lista que armazena char*.
 * 
 * @return Lista2* 
 */
Lista2 *CriaLista2();
/**
 * @brief Insere um char* no final da lista.
 * 
 * @param l - A lista.
 * @param u - char* a ser inserido.
 * @return Lista2* 
 */
Lista2 *Insere2(Lista2 *l, char *u);
/**
 * @brief Imprime os char* contidos na lista em um arquivo.
 * 
 * @param l - A lista.
 * @param f - O arquivo.
 */
void ImprimeLista2(Lista2 *l, FILE *f);
/**
 * @brief Imprime em um arquivo os posts enviados por um usuário e a quantidade de pessoas atingidas pelo post.
 * 
 * @param l - A lista de posts.
 * @param f - O arquivo.
 * @param num - Vetor que apresenta a quantidade de pessoas atingidas por cada um dos posts.
 */
void PostsEnviados(Lista2 *l, FILE *f, int *num);
/**
 * @brief Imprime em um arquivo os posts recebidos por um usuário e por quem foi enviado.
 * 
 * @param l - A lista de posts.
 * @param f - O arquivo.
 * @param autor - Vetor que armazena o nome dos autores de cada post.
 */
void PostsRecebidos(Lista2 *l, FILE *f, Lista2 *autor);
/**
 * @brief Libera completamente uma lista de char*: char*, a célula e a lista em si.
 * 
 * @param l -  A lista a ser liberada.
 */
void LiberaLista2(Lista2 *l);

#endif