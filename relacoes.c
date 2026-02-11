#include "relacoes.h"

struct tRelacoes{
  Lista *likes;//Lista com os likes de um usuário.
  Lista *amigos;// Lista com os amigos de um usuário.
  int numAmigos;//Número de amigos do usuário.
  int numLikes;//Número de likes que o usuário deu.
};

tRelacoes *InicializaRelacao(){
  tRelacoes *r = malloc(sizeof(*r));
  r->likes = CriaLista();
  r->amigos = CriaLista();
  r->numLikes=0;
  r->numAmigos=0;

  return r;
}

void LiberaRelacao(tRelacoes *r){
  LiberaLista(r->amigos);
  
  LiberaLista(r->likes);
  
  free(r);
}

void DaLike(tUsuario *u1, tUsuario *u2){
  tRelacoes *r=RetornaRelacoes(u1);
  FILE *f;
  
  if(u2){
    Insere(r->likes, u2);
    r->numLikes++;
    f = fopen("logs.txt", "a+");
    fprintf(f, "+ %s curtiu %s\n", RetornaNome(u1), RetornaNome(u2));
    fclose(f);
    FormaAmizade(u1, u2); 
  }
}

void RemoveLike(tUsuario *u1, tUsuario *u2){
  tRelacoes *r=RetornaRelacoes(u1);
  FILE *f;
  
  if(u2){
    RemovePeloNome(r->likes, RetornaNome(u2));

    f = fopen("logs.txt", "a+");
    fprintf(f, "_ %s descurtiu %s\n", RetornaNome(u1), RetornaNome(u2));
    fclose(f);

    DestroiAmizade(u1, u2);
  
    r->numLikes--;
  }
}

void FormaAmizade(tUsuario *u1, tUsuario *u2){
  tRelacoes *r1=RetornaRelacoes(u1);
  tRelacoes *r2=RetornaRelacoes(u2);
  char *nome1=RetornaNome(u1);
  char *nome2=RetornaNome(u2);
  FILE *f;

    if(BuscaPeloNome(r1->likes, nome2) && BuscaPeloNome(r2->likes, nome1)){
      Insere(r1->amigos, u2);
      Insere(r2->amigos, u1);
      r1->numAmigos++;
      r2->numAmigos++;

      f = fopen("logs.txt", "a+");
      fprintf(f, "# %s e %s viraram amigos\n", RetornaNome(u1), RetornaNome(u2));
      fclose(f);
      
    } 
}

void DestroiAmizade(tUsuario *u1, tUsuario *u2){
  tRelacoes *r1=RetornaRelacoes(u1);
  tRelacoes *r2=RetornaRelacoes(u2);
  char *nome1=RetornaNome(u1);
  char *nome2=RetornaNome(u2);
  FILE *f;
  
  if(BuscaPeloNome(r1->amigos, nome2) && BuscaPeloNome(r2->amigos, nome1)){
    RemovePeloNome(r1->amigos, nome2);
    RemovePeloNome(r2->amigos, nome1);
    r1->numAmigos--;
    r2->numAmigos--;
    
    f = fopen("logs.txt", "a+");
    fprintf(f, "$ %s desfez amizade com %s\n", RetornaNome(u1), RetornaNome(u2));
    fclose(f);
    
  }
}

void EnviaParaAmigos(tRelacoes *r,char *c, char *autor){
  Celula *aux = RetornaInicio(r->amigos);

  while(aux!=NULL){
    RecebePost(RetornaPost(RetornaUsuario(aux)), c, autor);
    aux = RetornaProx(aux);
  }
  
}

int RetornaNumAmigos(tRelacoes *r){
  return r->numAmigos;
}

void ImprimeAmigos(FILE *f, tRelacoes *r){
  ImprimeUsuarios(f, r->amigos);
}

int SaoAmigos(tRelacoes *r, char *nome){
  Celula *aux = RetornaInicio(r->amigos);

  while(aux!=NULL){
    if(strcmp(nome, RetornaNome(RetornaUsuario(aux)))==0){
      return 1;
    }
    aux = RetornaProx(aux);
  }
  return 0;
}