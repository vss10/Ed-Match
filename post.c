#include "post.h"

struct tPost{
  Lista2 *postEnviado;//Lista com os posts enviados pelo usuário.
  int numPostEnviado;//Número de posts enviados.
  Lista2 *postRecebido;//Lista com os posts recebidos de amigos.
  int numPostRecebido;// Número de posts recebidos.
  Lista2 *autorPostRecebido;//Lista com o nome dos autores dos posts recebidos.
  int *leitoresPostEnviado;//Vetor com o número de pessoas atingidas por cada post enviado.
};

tPost *InicializaPost(){
  tPost *p = malloc(sizeof(*p));

  p->numPostEnviado = 0;

  p->numPostRecebido = 0;

  p->postEnviado = CriaLista2();

  p->postRecebido = CriaLista2();
    
  p->autorPostRecebido = CriaLista2();

  p->leitoresPostEnviado = malloc(sizeof(int)*5);

  return p;
}

void EscrevePost(tPost *p, char *c, int numAmigos){
  Insere2(p->postEnviado, c);
  if(p->numPostEnviado%5==0 && p->numPostEnviado!=0){
    p->leitoresPostEnviado = realloc(p->leitoresPostEnviado, ((p->numPostEnviado)+5)*(sizeof(int)));
  }
  p->leitoresPostEnviado[p->numPostEnviado] = numAmigos;
  p->numPostEnviado++;
}

void LiberaPost(tPost *p){
  LiberaLista2(p->postEnviado);
  LiberaLista2(p->postRecebido);
  LiberaLista2(p->autorPostRecebido);
  free(p->leitoresPostEnviado);
  free(p);
}

void RecebePost(tPost *p, char *c, char *nomeAutor){
  Insere2(p->postRecebido, strdup(c));
  Insere2(p->autorPostRecebido, strdup(nomeAutor));
  p->numPostRecebido++;
}

void ImprimePostsEnviados(FILE *f, tPost *p){
  PostsEnviados(p->postEnviado, f, p->leitoresPostEnviado);
}

void ImprimePostsRecebidos(FILE *f, tPost *p){
  PostsRecebidos(p->postRecebido, f, p->autorPostRecebido);
}