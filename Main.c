#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define menor_id 1
#define maior_id 2
#include "Centro_de_Pesquisa.h"

int main (int argc, char *argv[]) {
// 1. Inicialização

    srand(time(NULL));
    CentroPesquisa centro;
    Treinador treinador1;
    Treinador treinador2;

    centro_inicializar (&centro);

// 2. Registro de informações dos treinadores e Pokémon fugitivos

    int id_treinador1 = menor_id;
    int id_treinador2 = maior_id;
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
    printf ("            INICIO DA MISSAO\n");
    printf ("========================================\n");

    printf ("\nTreinador(a) %s: posicao (%d,%d) | Pokebolas: %d\n", treinador1.nome, treinador1.localizacaot.x, treinador1.localizacaot.y, treinador1.pokebolas);
    printf ("Treinador(a) %s: posicao (%d,%d) | Pokebolas: %d\n", treinador2.nome, treinador2.localizacaot.x, treinador2.localizacaot.y, treinador2.pokebolas);

    int qnt_pokemons_fugitivos;

    fscanf (pEntrada, "%d", &qnt_pokemons_fugitivos);

    printf ("\nPokemons fugitivos a serem resgatados: %d\n", qnt_pokemons_fugitivos);
    printf ("\n----------------------------------------\n");

    int id_pokemon = menor_id;

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

    PokeCelula *pAux = centro.fugitivos.pPrimeiro->pProx;
    Pokemon pAuxdevolucao;

        FILE *pArquivoSaida; // Abrindo o arquivo de saída
        pArquivoSaida = fopen("relatorio.txt", "w");
        if (pArquivoSaida != NULL) {
            fprintf(pArquivoSaida, "Pokemons recuperados: \n");
        }
        if (pArquivoSaida == NULL) {
            printf("Erro ao criar o arquivo de saida. Execute o programa novamente.\n");
            exit(1);
        }

    while (pAux != NULL) {
        PokeCelula *pProximo = pAux->pProx;
        Pokemon pokemon = pAux->pokemon;
    

        printf ("Pokemon alvo: %s\n", pAux->pokemon.nome);
        printf ("Localizacao: (%d,%d)\n", pAux->pokemon.localizacaop.x, pAux->pokemon.localizacaop.y);

        int distancia_x1 = pokemon.localizacaop.x - treinador1.localizacaot.x;
        int distancia_y1 = pokemon.localizacaop.y - treinador1.localizacaot.y;

        int distancia_x2 = pokemon.localizacaop.x - treinador2.localizacaot.x;
        int distancia_y2 = pokemon.localizacaop.y - treinador2.localizacaot.y;

        double distancia_treinador1 = sqrt(distancia_x1 * distancia_x1 + distancia_y1 * distancia_y1);
        double distancia_treinador2 = sqrt(distancia_x2 * distancia_x2 + distancia_y2 * distancia_y2);

        printf ("\nDistancia Treinador(a) %s: %.2f\n", treinador1.nome, distancia_treinador1);
        printf ("Distancia Treinador(a) %s: %.2f\n", treinador2.nome, distancia_treinador2);

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


        printf ("\nMissao atribuida ao Treinador(a) %s.\n", treinador_captura->nome);

        treinador_movimentacao(treinador_captura, pokemon.localizacaop.x, pokemon.localizacaop.y);

        printf ("\nTreinador(a) %s se movimentou para (%d,%d).\n", treinador_captura->nome, treinador_captura->localizacaot.x, treinador_captura->localizacaot.y); 

        treinador_capturar_pokemon(treinador_captura, &pokemon);
        printf ("%s capturado com sucesso!\n", pAux->pokemon.nome);

// 4. Atualização da listagem de fugas

        centro_remover_fugitivos(&centro, &pokemon);
        printf ("\nPokebolas restantes para o Treinador(a) %s: %d\n", treinador_captura->nome, treinador_captura->pokebolas);

// 5. Retorno ao Centro de Pesquisa - Treinador sem Pokébolas

        if (treinador_captura->pokebolas == 0) {

            printf("\n======================================== \nTreinador(a) %s SEM POKEBOLAS \n========================================\n", treinador_captura->nome);
            treinador_movimentacao(treinador_captura, 0, 0);
            printf("\nTreinador(a) %s retorna ao Centro de Pesquisa\n", treinador_captura->nome);
            printf("\nEntregando Pokemon ao Centro de Pesquisa\n");

            while (treinador_captura->poke_treinador.pPrimeiro->pProx != NULL){
                pAuxdevolucao = treinador_captura->poke_treinador.pPrimeiro->pProx->pokemon;
                pokelista_remover(&treinador_captura->poke_treinador, &pAuxdevolucao);
                centro_recebimento_recuperados(&centro, &pAuxdevolucao);
            }

            centro_recarga_pokebolas (treinador_captura);
            printf ("\nTreinador(a) %s recebeu %d Pokebolas.\n", treinador_captura->nome, treinador_captura->pokebolas); 

        }

        printf ("\n----------------------------------------\n");

        pAux = pProximo;

        }

// 5.1 Retorno ao Centro de Pesquisa - Todos Pokémons resgatados

        printf("\n======================================== \n    Todos Pokemons foram resgatados \n======================================== \n");
        
        treinador_movimentacao(&treinador1, 0, 0);
        treinador_movimentacao(&treinador2, 0, 0);

        printf("\nAmbos treinadores retornam ao Centro de Pesquisa.\n");

        while (treinador1.poke_treinador.pPrimeiro->pProx != NULL) {
                pAuxdevolucao = treinador1.poke_treinador.pPrimeiro->pProx->pokemon;
                pokelista_remover(&treinador1.poke_treinador, &pAuxdevolucao);
                centro_recebimento_recuperados(&centro, &pAuxdevolucao);
        }

        while(treinador2.poke_treinador.pPrimeiro->pProx != NULL){
                pAuxdevolucao = treinador2.poke_treinador.pPrimeiro->pProx->pokemon;
                pokelista_remover(&treinador2.poke_treinador, &pAuxdevolucao);
                centro_recebimento_recuperados(&centro, &pAuxdevolucao);
        }

        printf ("\nTreinador(a) %s devolve os Pokemon.\n", treinador1.nome);
        printf ("\nTreinador(a) %s devolve os Pokemon.\n", treinador2.nome);
        printf ("\n========================================\n");
        printf ("          MISSAO CONCLUIDA\n");
        printf ("========================================\n");

// 6. Imprimir pokémons recuperados

    PokeCelula *pAuxRelatorio = centro.recuperados.pPrimeiro->pProx;
    while (pAuxRelatorio != NULL) {
        fprintf(pArquivoSaida, "%d %s\n", pAuxRelatorio->pokemon.numpoke, pAuxRelatorio->pokemon.nome);
        pAuxRelatorio = pAuxRelatorio->pProx;
    }

    if (pEntrada != stdin) {
        fclose(pEntrada);
    }

    if (pArquivoSaida != NULL) {
        fclose(pArquivoSaida);
    }      

    return 0; 
}
