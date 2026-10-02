#include <stdio.h>
#include <stdlib.h>

#include "Pokelista.h"

void pokelista_inicializar(PokeLista * Lista){
    Lista->pPrimeiro = (struct Celula *)  malloc(sizeof(PokeCelula));
    Lista->pUltimo = Lista->pPrimeiro;
    Lista->pPrimeiro->pProx = NULL;
}

int pokelista_inserir(PokeLista *Lista, Pokemon* p){
    Lista->pUltimo->pProx = (struct Celula*) malloc(sizeof(PokeCelula));
    if (Lista->pUltimo->pProx == NULL) {
        return 0;
    }
    Lista->pUltimo = Lista->pUltimo->pProx;
    Lista->pUltimo->pokemon = *p;
    Lista->pUltimo->pProx = NULL;
    return 1;
}

int pokelista_remover(PokeLista *Lista, Pokemon *p) {
    PokeCelula *pAnterior = Lista->pPrimeiro;
    PokeCelula *pAux = Lista->pPrimeiro->pProx;

    while (pAux != NULL)
    {
        if (pokemon_get_id(&pAux->pokemon) == pokemon_get_id(p))
        {
            *p = pAux->pokemon;

            pAnterior->pProx = pAux->pProx;

            if (pAux == Lista->pUltimo)
            {
                Lista->pUltimo = pAnterior;
            }

            free(pAux);

            return 1;
        }

        pAnterior = pAux;
        pAux = pAux->pProx;
    }

    return 0;
}

Pokemon* pokelista_buscar(PokeLista *Lista, int id){
        struct Celula* pAux;
        pAux = Lista->pPrimeiro->pProx;
        while (pAux != NULL) {
            if (pAux->pokemon.id == id) {
                return &(pAux->pokemon); 
            }
        pAux = pAux->pProx; 
    }
    return NULL;
}

void pokelista_imprimir(PokeLista *Lista){
    struct Celula* pAux;
    pAux = Lista->pPrimeiro->pProx;
    while(pAux != NULL){
        printf("Id: %d\nNumero da pokedex: %d\nNome: %s\nTipo: %s\nCoordenada x: %d\nCoordenada y: %d\n", pAux->pokemon.id, pAux->pokemon.numpoke, pAux->pokemon.nome, pAux->pokemon.tipo, pAux->pokemon.localizacaop.x, pAux->pokemon.localizacaop.y);
        pAux = pAux->pProx; 
    }
}