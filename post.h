#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

#ifndef POST_H
#define POST_H

typedef struct tPost tPost;

/**
 * @brief Libera o struct post.
 * 
 * @param p - Post a ser liberado.
 */
void LiberaPost(tPost *p);
/**
 * @brief Inicializa um struct post. 
 * 
 * @return tPost* 
 */
tPost *InicializaPost();
/**
 * @brief Insere na lista de posts enviados de um usuário o post que foi publicado por ele e cadastra quantas pessoas receberam esse post.
 * 
 * @param p - Struct post do usuário que fez o post.
 * @param c - Texto publicado pelo usuário.
 * @param numAmigos - Número de amigos que o usuário possui.
 */
void EscrevePost(tPost *p, char *c, int numAmigos);
/**
 * @brief Insere na lista de posts recebidos um post recebido pelo usuário.
 * 
 * @param p - Struct post do usuário que recebeu a publicação.
 * @param c - Mensagem publicada.
 * @param nomeAutor - Nome do autor do post.
 */
void RecebePost(tPost *p, char *c, char *nomeAutor);
/**
 * @brief Imprime os posts enviados por um usuário em um arquivo.
 * 
 * @param f - O arquivo.
 * @param p - O struct post do usuário.
 */
void ImprimePostsEnviados(FILE *f, tPost *p);
/**
 * @brief Imprime os posts recebidos por um usuário em um arquivo.
 * 
 * @param f - O arquivo.
 * @param p - O struct post do usuário.
 */
void ImprimePostsRecebidos(FILE *f, tPost *p);


#endif