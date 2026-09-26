#include <stdio.h>
#include "Pokelista.h"

void pokelista_inicializar(PokeLista * Lista){
    Lista->pPrimeiro = (struct Celula *)  malloc(sizeof(PokeCelula));
    Lista->pUltimo = Lista->pPrimeiro;
    Lista->pPrimeiro->pProx = NULL;
}

void pokelista_inserir(PokeLista *Lista, Pokemon* p){
    Lista->pUltimo->pProx = (struct Celula*) malloc(sizeof(PokeCelula));
    Lista->pUltimo = Lista->pUltimo->pProx;
    Lista->pUltimo->pokemon = *p;
    Lista->pUltimo->pProx = NULL;
}

int pokelista_remover(PokeLista *Lista, Pokemon *p){
    PokeCelula *pAux;
    if(Lista->pUltimo == NULL){
        return 0;
    }
    *p = Lista->pPrimeiro->pProx->pokemon; //qual o intuito dessa linha aqui?
    pAux = Lista->pPrimeiro;
    Lista->pPrimeiro = Lista->pPrimeiro->pProx;
    free(pAux);
    return 1;
}

Pokemon* pokelista_buscar(PokeLista *Lista, Pokemon *p){ //busca por id

}

void pokelista_imprimir(PokeLista *Lista){

}
/*void FLVazia(TLista* pLista);
int LEhVazia(TLista* pLista);
int LInsere(TLista* pLista, TItem *pItem);
int LRetira(TLista* pLista, TItem *pItem);
void LImprime(TLista* pLista);

void pokelista_inicializar(PokeLista *lista);

void pokelista_inserir(PokeLista *lista, Pokemon p);

int pokelista_remover(PokeLista *lista, int id);

Pokemon* pokelista_buscar(PokeLista *lista, int id);

void pokelista_imprimir(PokeLista *lista);*/