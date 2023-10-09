#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

struct lista{
		int info;
		Lista* prox;
		};

Lista* lst_cria(){
    return NULL;
}

Lista* lst_insere(Lista* l, int info){
    Lista* laux = (Lista*)malloc(sizeof(Lista));
    laux->info = info;
    laux->prox = l;
    return laux;
}

Lista* lst_busca(Lista* l, int info){
    Lista* laux = l;
    while(laux != NULL){
        if(laux->info == info){
            return laux;
        }
        laux = laux->prox;
    }
    return NULL;
}

void lst_imprime(Lista* l){
    if(!lst_vazia(l)){
        Lista* laux=l;
        while(laux!=NULL){
            printf("Info: %d\n", laux->info);
            laux=laux->prox;
        }
    }
    
 }

 Lista* lst_remove(Lista* l, int info){
    if(l != NULL){
        Lista* laux = l->prox;
        if(l->info == info){ 
            free(l);
            return laux;
        }
		else{
            Lista* lant = l;
            while(laux != NULL){
                if(laux->info == info){
                    lant->prox = laux->prox;
                    free(laux);
                    break;
                }
                else{
                    lant = laux;
                    laux = laux->prox;
                }
            }
            }
    }
    return l;
}

void lst_libera(Lista* l){
    Lista* lprox;
    while(l != NULL){
        lprox = l->prox;
        free(l);
        l = lprox;
    }
}

//

void lst_imprime_rec(Lista* l){
    if(!lst_vazia(l)){
        printf("info: %d\n",l->info);
        lst_imprime_rec(l->prox);
    }
    
}

void lst_imprime_invertida_rec (Lista* l){
    if(!lst_vazia(l)){
        lst_imprime_invertida_rec(l->prox);
        printf("info: %d\n",l->info);
    }
}

Lista* lst_remove_rec(Lista* l, int info){
    if(!lst_vazia(l)){
        if(l->info==info){
            Lista* laux=l;
            l=l->prox;
            free(laux);
        }
        else{
            l->prox=lst_remove_rec(l->prox,info);
        }
    }
    return l;
}

// inicio
		
int comprimento(Lista* l){
	Lista *laux = l;
	int cont = 0;
	while(laux->prox != NULL){
      cont++;
      laux = laux->prox;
	  }
	  return cont;
}

int menores(Lista* l, int n){
	Lista *laux = l;
	int cont = 0;
	while(laux->prox != NULL){
     if(laux->info < n){
      cont++;
      laux = laux->prox;
	    }
	  }
	  return cont;
}
	
int soma(Lista* l){
	Lista *laux = l;
	int aux = 0;
	while(laux->prox != NULL){
     aux = aux + laux->info;
	 }
	 return aux;
 }
 
 int primos(Lista* l){
 	 Lista *laux = l;
 	 int aux = 0;
 	 while(laux->prox != NULL){
	   if(laux->info%2 != 0 && laux->info%3 != 0 && laux->info%5 != 0 && laux->info%7 != 0){
	   	 aux = aux + laux->info; 				   
      }
      laux = laux->prox;
    }
    return aux;
}
 
Lista* lst_conc(Lista* l1, Lista* l2){
	 Lista *laux1 = l1; Lista *laux2 = l2; Lista *listaConc = lst_cria(); Lista *lfim = NULL;
     while (laux1 != NULL){
        if(listaConc == NULL){
            listaConc = lst_insere(listaConc,laux1->info);
            lfim = listaConc;
        }
        else{
            lfim->prox = lst_insere(lfim->prox,laux1->info);
            lfim = lfim->prox;
        }
        laux1 = laux1->prox;
    }
    laux1 = laux2;
    while (laux1 != NULL){
        if(listaConc == NULL){
            listaConc = lst_insere(listaConc,laux1->info);
            lfim = listaConc;
        }
        else{
            lfim->prox = lst_insere(lfim->prox,laux1->info);
            lfim = lfim->prox;
        }
        laux1 = laux1->prox;
    }
    return listaConc;
}

Lista* lst_diferenca(Lista* l1, Lista* l2){
	   Lista *laux1 = l1; Lista *laux2 = l2;
	   do{
  	     if(laux1->info == laux2->info){
			lst_remove(laux1, laux1->info);
			}
		 laux1 = laux1->prox;	
		 laux2 = laux2->prox;
       }while(laux1->prox != NULL && laux2->prox != NULL);
       return laux1;
}
 
 
		
