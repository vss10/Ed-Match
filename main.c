#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rede.h"

/**
 * @brief Retorna o número de ciclos que a rede teŕa.
 * 
 * @param c - *argv[]
 * @return int 
 */
int NumCiclos(char **c);

int main(int argc, char *argv[]){
  int numCiclos = NumCiclos(argv), aux=0;
  tRede *r = InicializaRede(numCiclos);

  while(aux<numCiclos){
    AtualizaUsuario(r);
    aux++;
  }

  ImprimeRelatorio(r);

  LiberaRede(r);
  
  return 0;
}

int NumCiclos(char **c){
  return atoi(c[1]);
}