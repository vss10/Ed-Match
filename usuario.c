#include "usuario.h"

struct tusuario{
  int idade;//Idade do usuário.
  char *nome;//Nome do usuário.
  tPost *post;//Struct post, responsável por armazenar todos os tipos de posts que envolvem o usuário.
  char *local;//Localização do usuário.
  Lista2 *hobbies;//Lista com os hobbies do usuário.
  int numHobbies;//Número de hobbies que o usuário possui.
  tRelacoes *relacoes;//Struct relações do usuário, o qual armazena as interações dele durante a rede.
};

tRelacoes *RetornaRelacoes(tUsuario *u){
  return u->relacoes;
}

void LiberaUsuario(tUsuario *u){
 int i=0;

  LiberaLista2(u->hobbies);
  LiberaRelacao(u->relacoes);
  LiberaPost(u->post);
  free(u->local);
  free(u->nome);
  free(u);
  
}

tUsuario *LeUsuario(FILE *f){
  tUsuario *u = malloc(sizeof(*u));
  char *nome = malloc(sizeof(*nome)*40);
  char *local = malloc(sizeof(*local)*40), *h = malloc(sizeof(*h)*200),
  **hobbies;
  int numHobbies=1, aux=0;

  fscanf(f, "%[^;]", nome);
  fscanf(f, "%*c");
  u->nome = nome;
  fscanf(f, "%d", &u->idade);
  fscanf(f, "%*c");
  fscanf(f, "%[^;]", local);
  fscanf(f, "%*c");
  u->local = local;
  fscanf(f,"%[^\n]", h);
  if(!feof(f)){
    fscanf(f, "%*c");
  }
  
  while(1){
    if(h[aux]=='\0'){
      break;
    }
    if(h[aux]==','){
      numHobbies++;
    }
    aux++;
  }

  hobbies = malloc(sizeof(char*)*numHobbies);
  
  if(numHobbies==1){
      hobbies[0] = strdup(h);
  }
  else{
      aux=0; 
      hobbies[aux] = strdup(strtok(h, ","));
      aux++;
      while(aux<numHobbies-1){
        hobbies[aux] = strdup(strtok(NULL, ","));
        aux++;
      }
      hobbies[aux] = strdup(strtok(NULL, "\n"));
    }
  u->hobbies = CriaLista2();
  free(h);
  
  for(int v=0;v<numHobbies;v++){
      u->hobbies = Insere2(u->hobbies, hobbies[v]);
  }
  free(hobbies);
  u->relacoes = InicializaRelacao();

  u->post = InicializaPost();

  u->numHobbies = numHobbies;
  
  return u;
}

char *LeArquivoUsuario(tUsuario *u, int cicloAtual){
  char txt[14] = ".package.txt";
  char arq[42]="", 
  *linha = malloc(sizeof(*linha)*200);
  FILE *f;
  int numLinha=0;
  
  strcat(arq, u->nome);
  strcat(arq, txt);

  f = fopen(arq, "r");

  while(numLinha!=cicloAtual){
    fscanf(f, "%[^\n]", linha);
    if(!feof(f)){
      fscanf(f, "%*c");
    }
    numLinha++;
  }

  fclose(f);

  return linha;
}

char *RetornaNome(tUsuario *u){
  return u->nome;
}

void EnviaPost(tUsuario *u, char *c){
  int numAmigos=RetornaNumAmigos(u->relacoes);
  FILE *f;
  
  if(strcmp(c, ".")==0){
    free(c);
    return ;;
  }
    EscrevePost(u->post, c, numAmigos);
   
    f = fopen("logs.txt", "a+");
    fprintf(f, "* %s publicou:\n-> %s\n", RetornaNome(u), c);
    fclose(f);
  
    EnviaParaAmigos(u->relacoes, c, u->nome);
}

void AlteraHobbies(tUsuario *u, char **h, int numHobbies){
  FILE *f;
  if(numHobbies==1 && strcmp(h[0], ".")==0){
    free(h[0]);
    free(h);
    return ;;
  }
    LiberaLista2(u->hobbies);
    u->hobbies=CriaLista2();
   
    f = fopen("logs.txt", "a+");
    fprintf(f, "! %s mudou seu hobbie para:\n", RetornaNome(u));
    for(int b=0;b<numHobbies;b++){
      u->hobbies=Insere2(u->hobbies, strdup(h[b]));
      fprintf(f, "~ %s\n", h[b]);
      free(h[b]);
    }
    free(h);
    fclose(f);
}

void ImprimeUsuario(tUsuario *u, FILE *f){
  fprintf(f, "====================\n");
  fprintf(f,"%s\n", u->nome);
  fprintf(f, "%d anos\n", u->idade);
  fprintf(f, "%s\n", u->local);
  fprintf(f, "%d amigos\n\n", RetornaNumAmigos(u->relacoes));
  fprintf(f, "HOBBIES\n");
  ImprimeLista2(u->hobbies, f);
  fprintf(f, "\nPOSTS PUBLICADOS\n");
  ImprimePostsEnviados(f, u->post);
  fprintf(f, "\nPOSTS DO FEED\n");
  ImprimePostsRecebidos(f, u->post);
  fprintf(f, "\nMATCHES\n");
  ImprimeAmigos(f, u->relacoes);
  fprintf(f, "\nSUGESTOES DE AMIZADE\n");
}

void SugestaoDeAmizade(tUsuario *u1, tUsuario *u2, FILE *f){
  if(abs(u1->idade-u2->idade)<=5 && strcmp(u1->nome, u2->nome)!=0 && strcmp(u1->local, u2->local)==0 && !(SaoAmigos(u1->relacoes, u2->nome))){
    fprintf(f, "%s\n", u2->nome);
  }
}

tPost *RetornaPost(tUsuario *u){
  return u->post;
}