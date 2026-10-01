#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Centro_de_Pesquisa.h"

void treinador_retornar_ao_centro(Treinador *t, CentroPesquisa *c, int pokebolas) {
    printf("\nTreinador %s retornou ao Centro de Pesquisa\n", t->nome);
    
    Pokemon pAux;
    while (t->poke_treinador.pPrimeiro->pProx != NULL) {
        pAux = t->poke_treinador.pPrimeiro->pProx->pokemon;
        pokelista_remover(&t->poke_treinador, &pAux);
        centro_insercao_recuperados(c, &pAux);
        printf("Pokémon %s entregue ao Centro de Pesquisa.\n", pAux.nome);
    }
    if (t->pokebolas == 0 && pokebolas > 0) {
        t->pokebolas = pokebolas;
        printf("Pokébolas recarregadas para %d\n", t->pokebolas);
    }
    treinador_movimentacao(t, 0, 0);
}
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
            printf ("Erro ao abrir o arquivo. Execute o programa novamente.\n");
            exit (1);
        }
    }

    fscanf (pEntrada, "%s %d", nome_treinador1, &pokebolas_treinador1);
    fscanf (pEntrada, "%s %d", nome_treinador2, &pokebolas_treinador2);

    treinador_inicializar (&treinador1, id_treinador1, nome_treinador1, pokebolas_treinador1);
    treinador_inicializar (&treinador2, id_treinador2, nome_treinador2, pokebolas_treinador2);

    printf ("========================================\n");
    printf ("            INÍCIO DA MISSÃO\n");
    printf ("========================================\n");

    printf ("\nTreinador(a) %s: posição (%d,%d) | Pokébolas: %d\n", treinador1.nome, treinador1.localizacaot.x, treinador1.localizacaot.y, treinador1.pokebolas);
    printf ("Treinador(a) %s: posição (%d,%d) | Pokébolas: %d\n", treinador2.nome, treinador2.localizacaot.x, treinador2.localizacaot.y, treinador2.pokebolas);

    int qnt_pokemons_fugitivos;

    fscanf (pEntrada, "%d", &qnt_pokemons_fugitivos);

    printf ("\nPokémons fugitivos a serem resgatados: %d\n", qnt_pokemons_fugitivos);
    printf ("\n----------------------------------------\n");

    int id_pokemon = 1;

    for (int i = 0; i < qnt_pokemons_fugitivos; i++) {
        int numpoke_pokemon;
        char nome_pokemon[20];
        char tipo_pokemon[15];
        Coordenadap coordenada_pokemon;
        Pokemon pokemon;

        fscanf (pEntrada, "%d %s %s %d %d", &numpoke_pokemon, nome_pokemon, tipo_pokemon, &coordenada_pokemon.x, &coordenada_pokemon.y);

        pokemon_set_id (&pokemon, id_pokemon);
        id_pokemon++;
        pokemon_set_numpoke (&pokemon, numpoke_pokemon);
        pokemon_set_nome (&pokemon, nome_pokemon);
        pokemon_set_tipo (&pokemon, tipo_pokemon);
        pokemon_set_localizacao (&pokemon, coordenada_pokemon);

        centro_insercao_fugitivos (&centro, &pokemon);
    }

// 3. Missão de captura

    FILE *pArquivoSaida;
    pArquivoSaida = fopen("arquivosaida.txt", "w");
    if (pArquivoSaida != NULL) {
        fprintf(pArquivoSaida, "Pokemons recuperados: \n");
    }

    PokeCelula *pAux = centro.fugitivos.pPrimeiro->pProx;

    while (pAux != NULL) {
        PokeCelula *pProximo = pAux->pProx;
        Pokemon pokemon = pAux->pokemon;
        
        printf ("Pokémon alvo: %s\n", pAux->pokemon.nome);
        printf ("Localização: (%d,%d)\n", pAux->pokemon.localizacaop.x, pAux->pokemon.localizacaop.y);

        int distancia_x1 = pokemon.localizacaop.x - treinador1.localizacaot.x;
        int distancia_y1 = pokemon.localizacaop.y - treinador1.localizacaot.y;

        int distancia_x2 = pokemon.localizacaop.x - treinador2.localizacaot.x;
        int distancia_y2 = pokemon.localizacaop.y - treinador2.localizacaot.y;

        int distancia_treinador1 = distancia_x1 * distancia_x1 + distancia_y1 * distancia_y1;
        int distancia_treinador2 = distancia_x2 * distancia_x2 + distancia_y2 * distancia_y2;

        printf ("Distância Treinador(a) %s: %.2f\n", treinador1.nome, distancia_treinador1);
        printf ("Distância Treinador(a) %s: %.2f\n", treinador2.nome, distancia_treinador2);

        Treinador *treinador_captura;

        if (distancia_treinador1 < distancia_treinador2) {
            treinador_captura = &treinador1;
        }

        else if (distancia_treinador2 < distancia_treinador1) {
            treinador_captura = &treinador2;
        }
        
        else {
            if (treinador1.id < treinador2.id) {
                treinador_captura = &treinador1;
            }
        
            else {
                treinador_captura = &treinador2;
            }
        }

        printf ("\nMissão atribuída ao Treinador(a) %s.\n", treinador_captura->nome);

        treinador_movimentacao(treinador_captura, pokemon.localizacaop.x, pokemon.localizacaop.y);

        printf ("\nTreinador(a) %s se movimentou para (%d,%d).\n", treinador_captura->nome, treinador_captura->localizacaot.x, treinador_captura->localizacaot.y); 

        treinador_capturar_pokemon(treinador_captura, &pokemon);

        printf ("%s capturado com sucesso!\n", pAux->pokemon.nome);
        if (pArquivoSaida != NULL) {
                fprintf(pArquivoSaida, "%d %s\n", pAux->pokemon.numpoke, pAux->pokemon.nome);
            } 
            centro_remover_fugitivos(&centro, &pokemon);
        printf ("\nPokébolas restantes para o Treinador(a) %s: %d\n", treinador_captura->nome, treinador_captura->pokebolas);
        printf ("\n----------------------------------------\n");

        pAux = pAux->pProx;
    }

    return 0;
}
