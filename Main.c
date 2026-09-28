#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Centro_de_Pesquisa.h"

int main (int argc, char *argv[]) {
// 1. Inicialização

    CentroPesquisa centro;
    Treinador treinador1;
    Treinador treinador2;

    centro_inicializar (&centro);

// 2. Registro de informações dos treinadores e Pokémon fugitivos

    int id_treinador1 = 1;
    int id_treinador2 = 2;
    char nome_treinador1[20];
    char nome_treinador2[20];
    int pokebolas_treinador1;
    int pokebolas_treinador2;

    FILE *pEntrada;

    if (argc == 1) {
        pEntrada = stdin;
    }

    else if (argc == 2) {
        pEntrada = fopen (argv[1], "r");

        if (pEntrada == NULL) {
            printf ("Erro ao abrir o arquivo\n");
            exit (1);
        }
    }

    fscanf (pEntrada, "%s %d", nome_treinador1, &pokebolas_treinador1);
    fscanf (pEntrada, "%s %d", nome_treinador2, &pokebolas_treinador2);

    treinador_inicializar (&treinador1, id_treinador1, nome_treinador1, pokebolas_treinador1);
    treinador_inicializar (&treinador2, id_treinador2, nome_treinador2, pokebolas_treinador2);

    int qnt_pokemons_fugitivos;

    fscanf (pEntrada, "%d", &qnt_pokemons_fugitivos);

    for (int i; i < qnt_pokemons_fugitivos; i++) {
        int id_pokemon;
        char nome_pokemon[20];
        char tipo_pokemon[15];
        Coordenadap coordenada_pokemon;
        Pokemon pokemon;

        fscanf (pEntrada, "%d %s %s %d %d", &id_pokemon, nome_pokemon, tipo_pokemon, &coordenada_pokemon.x, &coordenada_pokemon.y);

        pokemon_set_id (&pokemon, id_pokemon);
        pokemon_set_nome (&pokemon, nome_pokemon);
        pokemon_set_tipo (&pokemon, tipo_pokemon);
        pokemon_set_localizacao (&pokemon, coordenada_pokemon);

        centro_insercao_fugitivos (&centro, &pokemon);
    }

// 3. Missão de captura

    PokeCelula *pAux = centro.fugitivos.pPrimeiro->pProx;

    while (pAux != NULL) {
        Pokemon pokemon = pAux->pokemon;

        int distancia_x1 = pokemon.localizacaop.x - treinador1.localizacaot.x;
        int distancia_y1 = pokemon.localizacaop.y - treinador1.localizacaot.y;

        int distancia_x2 = pokemon.localizacaop.x - treinador2.localizacaot.x;
        int distancia_y2 = pokemon.localizacaop.y - treinador2.localizacaot.y;

        int distancia_treinador1 = distancia_x1 * distancia_x1 + distancia_y1 * distancia_y1;
        int distancia_treinador2 = distancia_x2 * distancia_x2 + distancia_y2 * distancia_y2;

        Treinador *treinador_escolhido;

        if (distancia_treinador1 < distancia_treinador2) {
            treinador_escolhido = &treinador1;
        }

        else if (distancia_treinador2 < distancia_treinador1) {
            treinador_escolhido = &treinador2;
        }
        
        else {
            if (treinador1.id < treinador2.id) {
                treinador_escolhido = &treinador1;
            }
        
            else {
                treinador_escolhido = &treinador2;
            }
        }

        treinador_movimentacao(treinador_escolhido, pokemon.localizacaop.x, pokemon.localizacaop.y);

        treinador_capturar_pokemon(treinador_escolhido, &pokemon);

        pAux = pAux->pProx;
    }

    return 0;
}