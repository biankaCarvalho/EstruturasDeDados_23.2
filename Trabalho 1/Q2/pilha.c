#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define MAX 3

struct pilha{
	   int n;
	   int v[MAX];
	   };

Pilha* pilha_cria(void){
Pilha *p = (Pilha*)malloc(sizeof(Pilha));
 if(p==NULL){
  printf("Memoria insuficiente!\n");
  exit(1);
 }
 p->n = 0;
 return p;
}

int pilha_vazia(Pilha *p){
	return p->n==0;
	}

void pilha_push(Pilha *p, int info){
 if(p->n==MAX){
  printf("Capacidade da Pilha Estourou!\n");
  exit(1);
 }
 p->v[p->n]= info;
 p->n = p->n + 1;
	 }

int pilha_pop(Pilha *p){
 int a;
 if(pilha_vazia(p)){
  printf("Pilha Vazia!!!\n");
  exit(1);
 }
 a = p->v[p->n-1];
 p->n--;
 return a;
}

void pilha_imprime(Pilha *p){
 int i;
 for(i = p->n-1; i>=0;i--){
  printf("%f\n",p->v[i]);
 }
}

void pilha_libera(Pilha *p){
 free(p);
}

int topo(Pilha* p){
	if(!pilha_vazia(p)){
        return p->v[p->n-1];
		}
    printf("PILHA VAZIA");
    exit(1); 
	}

int impares(Pilha* p){
 int aux=0; int i;
    for(i = p->n-1; i >= 0; i--){
        if(p->v[i]%2 != 0){
            aux++;
	}
    }
    return aux;	
}

Pilha* empilha_pares(Pilha* p1, Pilha* p2){
  int i;
	  for(i = p1->n-1; i >= 0; i--){
        if(p1->v[i]%2 == 0){ 
			if(p1->v[i]	> p2->v[i-1]){
				p2->v[i] = p1->v[i];	   
				}
		}
  }
  return p2;
}
