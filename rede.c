#include "rede.h"

struct tRede{
  Lista *usuarios;//Lista com todos os usuários da rede.
  int numUsuarios;//Número de usuários na rede.
  int numCiclos;//Número de ciclos que terá a rede.
  int cicloAtual;//Número do ciclo atual.
};

tRede *InicializaRede(int numCiclos){
  tRede *r = malloc(sizeof(*r));
  FILE *f;
  
  f = fopen("users.txt", "r");
  
  r->cicloAtual=1;
  r->numUsuarios=0;
  r->numCiclos = numCiclos;
  r->usuarios = CriaLista();
  
  while(!feof(f)){
    if(feof(f)){
      break;
    }
    r->usuarios = Insere(r->usuarios, LeUsuario(f));
  }
  fclose(f);

  return r;
}

void AtualizaUsuario(tRede *r){
  char *comando, 
  *like = malloc(sizeof(*like)*40), 
  *dislike = malloc(sizeof(*dislike)*40),
  **hobbies, *post = malloc(sizeof(*post)*80);
  int numHobbies=1, aux=0, aux1=0;
  Celula *c = RetornaInicio(r->usuarios);

  while(c!=NULL){
    aux1=0;
    aux=0;
    numHobbies=1;
    comando = LeArquivoUsuario(RetornaUsuario(c), r->cicloAtual);

    while(comando[aux]!='\0'){
      if(comando[aux]==';'){
        aux1++;
      }
      if(aux1>=3){
        break;
      }
      if(comando[aux]==','){
        numHobbies++;
      }
      aux++;
    }

    hobbies = malloc(sizeof(char*)*numHobbies);

    like = strdup(strtok(comando, ";"));
    dislike = strdup(strtok(NULL, ";"));

    if(numHobbies==1){
      hobbies[0] = strdup(strtok(NULL, ";"));
    }
    else{
      aux=0;
      while(aux<numHobbies-1){
        hobbies[aux] = strdup(strtok(NULL, ","));
        aux++;
      }
      hobbies[aux] = strdup(strtok(NULL, ";"));
    }
    post = strdup(strtok(NULL, "\0"));

    DaLike(RetornaUsuario(c), BuscaPeloNome(r->usuarios, like));
    RemoveLike(RetornaUsuario(c), BuscaPeloNome(r->usuarios, dislike));
    AlteraHobbies(RetornaUsuario(c), hobbies, numHobbies);
    EnviaPost(RetornaUsuario(c), post);

    if(like!=NULL){
      free(like);
    }
    if(dislike!=NULL){
      free(dislike);
    }
    if(comando!=NULL){
      free(comando);
    }
    c = RetornaProx(c);
  }
  r->cicloAtual++;
}

void ImprimeRelatorio(tRede *r){
  Celula *aux1=RetornaInicio(r->usuarios), *aux2;
  FILE *f=fopen("reports.txt", "a+");
  
   while(aux1!=NULL){
    aux2 = RetornaInicio(r->usuarios);
    ImprimeUsuario(RetornaUsuario(aux1), f);
    while(aux2!=NULL){
      SugestaoDeAmizade(RetornaUsuario(aux1), RetornaUsuario(aux2), f);
      aux2 = RetornaProx(aux2);
    }  
     aux1=RetornaProx(aux1);
     fprintf(f, "\n");
   }
   fclose(f);
}

void LiberaRede(tRede *r){
  LiberaListaUsuarios(r->usuarios);
  free(r);
}