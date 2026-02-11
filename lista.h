#include "usuario.h"
#ifndef LISTA_H
#define LISTA_H


typedef struct Lista Lista;
typedef struct Celula Celula;

/**
 * @brief Cria uma Lista que armazena usuários.
 * 
 * @return Lista* 
 */
Lista *CriaLista();
/**
 * @brief Insere um usuário no fim da lista.
 * 
 * @param l - A lista.
 * @param u - O usuário a ser inserido.
 * @return Lista* 
 */
Lista *Insere(Lista *l, tUsuario *u);
/**
 * @brief Remove o usuário da lista que possuir o nome "nome".
 * 
 * @param l - A lista.
 * @param nome - Nome do usuário que deve ser removido.
 * @return Lista* 
 */
Lista *RemovePeloNome(Lista *l, char *nome);
/**
 * @brief Libera as células e a lista
 * 
 * @param l - A lista.
 */
void LiberaLista(Lista *l);
/**
 * @brief Libera os usuários, as células e a lista.
 * 
 * @param l - A lista.
 */
void LiberaListaUsuarios(Lista *l);
/**
 * @brief Retorna a célula do início da lista
 * 
 * @param l - A lista.
 * @return Celula* 
 */
Celula *RetornaInicio(Lista *l);
/**
 * @brief Busca por um usuário com nome "nome", retornando o usuário caso seja encontrado ou NULL caso contrário.
 * 
 * @param l - A lista.
 * @param nome - Nome do usuário a ser encontrado.
 * @return tUsuario* 
 */
tUsuario *BuscaPeloNome(Lista *l, char *nome);
/**
 * @brief Retorna a próxima célula de uma célula.
 * 
 * @param c - A célula que se deseja a próxima.
 * @return Celula* 
 */
Celula *RetornaProx(Celula *c);
/**
 * @brief Retorna o usuário da célula.
 * 
 * @param c - A célula que se deseja o usuário.
 * @return tUsuario* 
 */
tUsuario *RetornaUsuario(Celula *c);
/**
 * @brief   Imprime o nome dos usuários da lista em um arquivo.
 * 
 * @param f - Arquivo em que os nomes devem ser impressos.
 * @param l - Lista que possui os usuários a serem impressos.
 */
void ImprimeUsuarios(FILE *f, Lista *l);

#endif