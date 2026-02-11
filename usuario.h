#ifndef USUARIO_H
#define USUARIO_H

typedef struct tusuario tUsuario;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relacoes.h"
#include "post.h"
#include "lista2.h"
#include "lista.h"

/**
 * @brief Função responsável por liberar o usuário e tudo que ele armazena: nome, post, local, hobbies e relações.
 * 
 * @param u - Usuário a ser liberado.
 */
void LiberaUsuario(tUsuario *u);
/**
 * @brief Função responsável por ler os dados do usuário do arquivo "users.txt" e retornar esse usuário com todos os seus dados salvos.
 * 
 * @param f - O arquivo.
 * @return tUsuario* 
 */
tUsuario *LeUsuario(FILE *f);
/**
 * @brief Lê o arquivo do usuário "u" no ciclo que a rede se encontra e retorna a linha lida no arquivo, que segue o modelo "nomeusuario.package.txt". 
 * 
 * @param u - Usuário que terá o ciclo lido.
 * @param cicloAtual - Ciclo que a rede se encontra.
 * @return char* 
 */
char *LeArquivoUsuario(tUsuario *u, int cicloAtual);
/**
 * @brief Retorna o struct relações de um usuário.
 * 
 * @param u - O usuário.
 * @return tRelacoes* 
 */
tRelacoes *RetornaRelacoes(tUsuario *u);
/**
 * @brief Retorna o nome de um usuário.
 * 
 * @param u - O usuário.
 * @return char* 
 */
char *RetornaNome(tUsuario *u);
/**
 * @brief Função responsável por enviar para os amigos do usuário seu post que foi publicado.
 * 
 * @param u - O usuário que publicou.
 * @param c - A publicação.
 */
void EnviaPost(tUsuario *u, char *c);
/**
 * @brief Altera os hobbies de um usuário caso seja da vontade dele.
 * 
 * @param u - O usuário.
 * @param h - Matriz em que cada uma das linhas representa um dos hobbies que serão inseridos como hobbie desse usuário.
 * @param numHobbies - Número de hobbies a serem inseridos. 
 */
void AlteraHobbies(tUsuario *u, char **h, int numHobbies);
/**
 * @brief Imprime os dados do usuário em um arquivo("reports.txt").
 * 
 * @param u -  Usuário a ter seus dados imprimidos.
 * @param f -  Arquivo em que os dados serão impressos. 
 */
void ImprimeUsuario(tUsuario *u, FILE *f);
/**
 * @brief Verifica se o usuário "u2" pode ser uma sugestão de amizade para "u1" e imprime o nome de "u2" no arquivo caso ele possa ser uma sugestão.
 * 
 * @param u1 - O usuário.
 * @param u2 - O usuário passível de ser sugestão.
 * @param f - O arquivo. 
 */
void SugestaoDeAmizade(tUsuario *u1, tUsuario *u2, FILE *f);
/**
 * @brief Retorna o struct post de um usuário.
 * 
 * @param u - O usuário.
 * @return tPost* 
 */
tPost *RetornaPost(tUsuario *u);

#endif