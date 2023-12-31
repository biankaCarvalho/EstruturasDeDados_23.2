#include <stdio.h>
#include<stdlib.h>
#include "fila.h"

struct lista{
 int info;
 Lista *prox;
};

struct fila{
 Lista *ini;
 Lista *fim;
}; 

Fila* fila_cria(void){
 Fila *f = (Fila*)malloc(sizeof(Fila));
 if(f==NULL){
 printf("Memoria insuficiente!\n");
 exit(1);
 }
 f->ini = NULL;
 f->fim = NULL;
 return f;
}

void fila_insere(Fila *f, int info){
 Lista *l = (Lista*)malloc(sizeof(Lista));
 if(l==NULL){
 printf("Memoria insuficiente\n");
 exit(1);
 }
 l->info = info;
 l->prox = NULL;
 if(!fila_vazia(f))
 f->fim->prox = l;
 else{
 f->ini = l;
 f->fim = l;
}
}

int fila_vazia(Fila *f){
 return f->ini==NULL;
}

int fila_remove(Fila *f){
 Lista *l; int a;
 if(fila_vazia(f)){
  printf("Fila Vazia!!!\n");
  exit(1);
  }
 a = f->ini->info;
 l = f->ini;
 f->ini = f->ini->prox;
 free(l);
 if(fila_vazia(f)){
  f->fim = NULL;
 }
 return a;
}

void fila_imprime(Fila *f){
 Lista *lAux = f->ini;
 while(lAux!=NULL){
 printf("%d\n",lAux->info);
 lAux = lAux->prox;
 }
}

void fila_libera(Fila *f){
 Lista* l = f->ini;
 Lista* lAux;
 while(l!=NULL){
  lAux = l->prox;
  free(l);
  l = lAux;
 }
 free(f);
}

int qtd_maior(Fila* f, int n){
	int aux = 0;
	if(!(fila_vazia(f))){
	 while(f->fim->prox != NULL){
	 	if(f->ini->info > n){
			aux++;
		}
		f->ini = f->ini->prox;		
	}		  
  }
  return aux;
}

//Fila* inverte(Fila* f){
//	  Fila* faux = fila_cria();
//	  while(f->fim->prox != NULL){
//	    faux->ini->info = f->fim->info;
//		faux->fim = faux->ini->prox;		 
//	  }
//   }
   
int pares(Fila* f){
 Lista* laux; 
 if(fila_vazia(f)){
        printf("FILA VAZIA");
        exit(1);
    }
    int aux = 0;
    for(laux = f->ini; laux != NULL; laux = laux->prox){
        if(laux->info%2==0){
            aux++;
	  }
    }
    return aux;	
}

