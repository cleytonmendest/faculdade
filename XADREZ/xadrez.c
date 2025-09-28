#include <stdio.h>

// --- Constantes para definir a quantidade de movimentos ---
// Define que a Torre se moverá 5 casas.
#define MOVIMENTOS_TORRE 5
// Define que o Bispo se moverá 5 casas.
#define MOVIMENTOS_BISPO 5
// Define que a Rainha se moverá 8 casas.
#define MOVIMENTOS_RAINHA 8
// Novas constantes para o movimento em "L" do Cavalo
#define PASSOS_VERTICAIS_CAVALO 2
#define PASSOS_HORIZONTAIS_CAVALO 1

int main()
{
    // Movimento da Torre (FOR)

    printf("--- Movimento da Torre (%d casas para a Direita) ---\n", MOVIMENTOS_TORRE);

    for (int i = 0; i < MOVIMENTOS_TORRE; i++)
    {
        // Printa a direção do movimento a cada passo.
        printf("Direita\n");
    }

    // Movimento do Bispo (WHILE)

    printf("\n--- Movimento do Bispo (%d casas na Diagonal Cima-Direita) ---\n", MOVIMENTOS_BISPO);

    // Variável para controlar o while.
    int passos_bispo = 0;

    while (passos_bispo < MOVIMENTOS_BISPO)
    {
        // Printa a combinação de direções para o movimento diagonal.
        printf("Cima, Direita\n");

        passos_bispo++;
    }

    // Movimento da Rainha (DO-WHILE)

    printf("\n--- Movimento da Rainha (%d casas para a Esquerda) ---\n", MOVIMENTOS_RAINHA);

    int passos_rainha = 0;

    do
    {
        // Printa a direção do movimento.
        printf("Esquerda\n");

        // Incrementa o contador.
        passos_rainha++;
    } while (passos_rainha < MOVIMENTOS_RAINHA);

    // Movimento do Cavalo ( FOR e WHILE)

    printf("\n--- Movimento do Cavalo (%d casas para Baixo, %d para Esquerda) ---\n",
           PASSOS_VERTICAIS_CAVALO, PASSOS_HORIZONTAIS_CAVALO);

    // O movimento em "L" do cavalo pode ser dividido em duas fases:
    // Fase 0: O movimento vertical (para baixo).
    // Fase 1: O movimento horizontal (para a esquerda).

    // O loop 'for' externo irá controlar essas duas fases.
    for (int fase = 0; fase < 2; fase++)
    {

        // Usamos um 'if/else' para tratar cada fase de forma diferente.
        if (fase == 0)
        {
            int contador_passos = 0;
            while (contador_passos < PASSOS_VERTICAIS_CAVALO)
            {
                printf("Baixo\n");
                contador_passos++;
            }
        }
        else
        {
            int contador_passos = 0;
            while (contador_passos < PASSOS_HORIZONTAIS_CAVALO)
            {
                printf("Esquerda\n");
                contador_passos++;
            }
        }
    }

    return 0;
}