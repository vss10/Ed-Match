#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

#ifndef RELACOES_H
#define RELACOES_H

typedef struct tRelacoes tRelacoes;

/**
 * @brief Inicializa o struct relações.
 * 
 * @return tRelacoes* 
 */
tRelacoes *InicializaRelacao();
/**
 * @brief Libera o struct Relações. 
 * 
 * @param r - O struct Relações.
 */
void LiberaRelacao(tRelacoes *r);
/**
 * @brief Função responsável por inserir o usuário "u2" na lista de curtidas do usuário "u1".
 * 
 * @param u1 - Usuário que deu o like. 
 * @param u2 - Usuário que recebeu o like.
 */
void DaLike(tUsuario *u1, tUsuario *u2);
/**
 * @brief Remove da lista de likes de "u1" o usuário "u2". Caso eles fossem amigos a amizade é desfeita.
 * 
 * @param u1 - Usuário que retirou o like.
 * @param u2 - Usuário a ser retirado da lista de likes.
 */
void RemoveLike(tUsuario *u1, tUsuario *u2);
/**
 * @brief Verifica se "u1" está na lista de likes de "u2" e vice-versa. Caso ambos ocorram "u1" é inserido na lista de amigos de "u2" e vice-versa.
 * 
 * @param u1 
 * @param u2 
 */
void FormaAmizade(tUsuario *u1, tUsuario *u2);
/**
 * @brief Desfaz a amizade entre "u1" e "u2" no caso em que eles são amigos. 
 * 
 * @param u1 - Um usuário
 * @param u2 - O outro usuário.
 */
void DestroiAmizade(tUsuario *u1, tUsuario *u2);
/**
 * @brief Função que envia o post de um usuário para seus amigos.
 * 
 * @param r - Relações do usuário que publicou o post.
 * @param c - O texto publicado.
 * @param autor - Nome do autor.
 */
void EnviaParaAmigos(tRelacoes *r,char *c, char *autor);
/**
 * @brief Retorna o número de amigos de um usuário.
 * 
 * @param r - Struct relações do usuário.
 * @return int 
 */
int RetornaNumAmigos(tRelacoes *r);
/**
 * @brief Imprime os amigos de um usuário em um arquivo(reports.txt).
 * 
 * @param f - Arquivo que será impresso os amigos.
 * @param r - Relações do usuário.
 */
void ImprimeAmigos(FILE *f, tRelacoes *r);
/**
 * @brief Verifica se um usuário está contido na lista de amigos de outro.
 * 
 * @param r - Struct relações do usuário que se deseja fazer a busca.
 * @param nome - Nome do usuário que se deseja buscar.
 * @return int 
 */
int SaoAmigos(tRelacoes *r, char *nome);

#endif