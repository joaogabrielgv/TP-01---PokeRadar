#include <stdio.h>
#include <stdlib.h>

#include "Centro_de_Pesquisa.h"

void centro_inicializar (CentroPesquisa *c) {
    c->localizacaoc.x=0;
    c->localizacaoc.y=0;

    pokelista_inicializar (&c->fugitivos);
    pokelista_inicializar (&c->recuperados);
}

void centro_insercao_fugitivos (CentroPesquisa *c, Pokemon p) {
    pokelista_inserir (&c->fugitivos, p);
}

void centro_remover_fugitivos (CentroPesquisa *c, int id) {
    pokelista_remover (&c->fugitivos, id);
}

void centro_imprimir_fugitivos (const CentroPesquisa *c) {
    pokelista_imprimir (&c->fugitivos);
}

void centro_recebimento_recuperados (CentroPesquisa *c, Pokemon p) {
    pokelista_inserir (&c->recuperados, p);
}

void centro_recarga_pokebolas (Treinador *t) {
    t->pokebolas = rand() % 20 + 1;
}