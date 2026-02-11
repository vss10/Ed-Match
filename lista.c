#include "lista.h"
//Implementação de uma lista simplesmente encadeado com sentinela que armazena struct usuário.
struct Celula{
    tUsuario *u;
    Celula *prox;
};

struct Lista{
    Celula *inicio;
    Celula *fim;
};

Lista *CriaLista(){
    Lista *l = malloc(sizeof(*l));

    l->inicio = NULL;
    l->fim = NULL;

    return l;
}

Lista *Insere(Lista *l, tUsuario *u){
    Celula *c = malloc(sizeof(*c)), *aux;

    c->u = u;
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

Lista *RemovePeloNome(Lista *l, char *nome){
    Celula *aux1, *aux2, *aux3;

    aux1 = l->inicio;

    while(aux1!=NULL){
        if(strcmp(RetornaNome(aux1->u), nome)==0){
            if(l->inicio == l->fim){
                l->inicio = NULL;
                l->fim = NULL;
                free(aux1);
            }
            else if(l->inicio == aux1){
                aux2 = aux1->prox;
                l->inicio = aux2;
                free(aux1);
            }
            else if(l->fim == aux1){
                free(aux1);
                aux2->prox = NULL;
                l->fim = aux2;
            }
            else{
                aux3 = aux1 -> prox;
                free(aux1);
                aux2->prox = aux3;
            }
            break;
        }
        aux2 = aux1;
        aux1 = aux1->prox;
    }

    return l;
}

void LiberaListaUsuarios(Lista *l){
  Celula *aux1=(l->inicio), *aux2=NULL;
    while(aux1!=NULL){
      LiberaUsuario(aux1->u);
      aux2=aux1->prox;
      free(aux1);
      aux1=aux2;
    }
      free(l);
}

void LiberaLista(Lista *l){
  Celula *aux1=(l->inicio), *aux2=NULL;
    while(aux1!=NULL){
      aux2=aux1->prox;
      free(aux1);
      aux1=aux2;
    }
      free(l);
}

tUsuario *BuscaPeloNome(Lista *l, char *nome){
  Celula *aux = l->inicio;

  while(aux!=NULL){
    if(strcmp(RetornaNome(aux->u), nome)==0){
      return aux->u;
    }
    aux = aux->prox;
  }
  return NULL;
}

Celula *RetornaInicio(Lista *l){
  return l->inicio;
}

Celula *RetornaProx(Celula *c){
  return c->prox;
}

tUsuario *RetornaUsuario(Celula *c){
  return c->u;
}

void ImprimeUsuarios(FILE *f, Lista *l){
  Celula *aux = l->inicio;

  while(aux!=NULL){
    fprintf(f, "%s\n", RetornaNome(aux->u));
    aux = aux->prox;
  }
}