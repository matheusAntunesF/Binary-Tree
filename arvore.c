#include "Arvore.h"
#include <stdio.h>
#include <stdlib.h>

bool insere(Arvore * ap_arv, int x){
	if((*ap_arv) == NULL){
		Arvore novo_No;
		novo_No = (Arvore) malloc(sizeof(No));
		novo_No->valor = x;
		novo_No->esq = NULL;
		novo_No->dir = NULL;
		(*ap_arv) = novo_No;
		return true;
	}
	if(x == (*ap_arv)->valor)
		return false;
	if(x < (*ap_arv)->valor)
		return insere(&((*ap_arv)->esq), x);
	return insere(&((*ap_arv)->dir), x);
}

bool busca(Arvore arv, int x){
	if(arv == NULL)
		return false;
	if(arv->valor == x)
		return true;
	if(arv->valor > x)
		return busca(arv->esq, x);
	return busca(arv->dir, x);
}

int maximo(Arvore arv){
	while(arv->dir != NULL){
		arv = arv->dir;
	}
	return arv->valor;
}

bool remove_(Arvore* ap_arv, int x){
	int check = 0;
	if(*ap_arv == NULL) 
		return false;
	if((*ap_arv)->valor > x)
		return remove_(&(*ap_arv)->esq, x);
	if((*ap_arv)->valor < x)
		return remove_(&(*ap_arv)->dir, x);
	No* subst;
	if((*ap_arv)->dir == NULL){
		subst = (*ap_arv)->esq;
		check = 1;
	}
	if((*ap_arv)->esq == NULL){
		subst = (*ap_arv)->dir;
		check = 1;
	}
	if(check == 1){
		No* temp = (*ap_arv);
		(*ap_arv) = subst;
		free(temp);
		return true;
	}
	int valmaxesq = maximo((*ap_arv)->esq);
	(*ap_arv)->valor = valmaxesq;
	return remove_(&((*ap_arv)->esq), valmaxesq);
}

void imprimeArvores(Arvore arv){
	if(arv == NULL){
		printf(".");
	}else{
		printf("[%d:", arv->valor);
		printf("e=");
		imprimeArvores(arv->esq);
		printf(",d=");
		imprimeArvores(arv->dir);
		printf("]");
	}
}

void imprime(Arvore arv){
	imprimeArvores(arv);
	printf("\n");
}
