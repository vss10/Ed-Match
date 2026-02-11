#ifndef REDE_H
#define REDE_H
#include "usuario.h"

typedef struct tRede tRede;

/**
 * @brief Inicializa a rede. Insere todos os usuários presentes no arquivo "users.txt" em uma lista que faz parte do struct rede.
 * 
 * @param numCiclos - Número de ciclos na rede.
 * @return tRede* 
 */
tRede *InicializaRede(int numCiclos);
/**
 * @brief Responsável por atualizar os likes, dislikes, hobbies e posts de cada um dos usuários a cada ciclo.
 * 
 * @param r - A rede.
 */
void AtualizaUsuario(tRede *r);
/**
 * @brief Função responsável por imprimir o arquivo "reports.txt" que contém o relatório do que ocorreu na Rede.
 * 
 * @param r - A rede.
 */
void ImprimeRelatorio(tRede *r);
/**
 * @brief Libera a lista de usuários completamente e o struct rede.
 * 
 * @param r  - A rede a ser liberada.
 */
void LiberaRede(tRede *r);

#endif