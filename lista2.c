#include "lista2.h"
//Implementação de uma lista simplesmente encadeado com sentinela que armazena char*.
struct Celula2{
    char *c;
    Celula2 *prox;
};

struct Lista2{
    Celula2 *inicio;
    Celula2 *fim;
};

Lista2 *CriaLista2(){
    Lista2 *l = malloc(sizeof(*l));

    l->inicio = NULL;
    l->fim = NULL;

    return l;
}

Lista2 *Insere2(Lista2 *l, char *u){
    Celula2 *c = malloc(sizeof(*c)), *aux;

    c->c = u;
    c->prox = NULL;
    
    if(l->inicio==NULL){
        l->inicio = c;
        l->fim = c;
    }
    else{
        aux = l->fim;
        aux->prox = c;
        l->fim = c;
    }

    return l;
}

void ImprimeLista2(Lista2 *l, FILE *f){
  Celula2 *aux = l->inicio;

  while(aux!=NULL){
    fprintf(f, "%s\n", aux->c);
    aux = aux->prox;
  }
}

void PostsEnviados(Lista2 *l, FILE *f, int *num){
  Celula2 *aux = l->inicio;
  int i=0;

  while(aux!=NULL){
    fprintf(f, "\"%s\" alcance: %d\n", aux->c, num[i]);
    aux = aux->prox;
    i++;
  }
}

void PostsRecebidos(Lista2 *l, FILE *f, Lista2 *autor){
  Celula2 *aux1 = l->inicio, *aux2 = autor->inicio;

  while(aux1!=NULL){
    fprintf(f, "\"%s\" - %s\n", aux1->c, aux2->c);
    aux1 = aux1->prox;
    aux2 = aux2->prox;
  }
}

void LiberaLista2(Lista2 *l){
  Celula2 *aux1=(l->inicio), *aux2=NULL;
    while(aux1){
      free(aux1->c);
      aux2=aux1->prox;
      free(aux1);
      aux1=aux2;
    }
    free(l);
}