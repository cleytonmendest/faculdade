#include <stdio.h>

// --- Constantes para definir a quantidade de movimentos ---
// Define que a Torre se moverá 5 casas.
#define MOVIMENTOS_TORRE 5
// Define que o Bispo se moverá 5 casas.
#define MOVIMENTOS_BISPO 5
// Define que a Rainha se moverá 8 casas.
#define MOVIMENTOS_RAINHA 8

int main() {
    // Movimento da Torre (usando a estrutura FOR)

    printf("--- Movimento da Torre (%d casas para a Direita) ---\n", MOVIMENTOS_TORRE);

    for (int i = 0; i < MOVIMENTOS_TORRE; i++) {
        // Printa a direção do movimento a cada passo.
        printf("Direita\n");
    }

    // Movimento do Bispo

    printf("\n--- Movimento do Bispo (%d casas na Diagonal Cima-Direita) ---\n", MOVIMENTOS_BISPO);

    // Variável para controlar o while.
    int passos_bispo = 0;

    while (passos_bispo < MOVIMENTOS_BISPO) {
        // Printa a combinação de direções para o movimento diagonal.
        printf("Cima, Direita\n");

        passos_bispo++;
    }

    // Movimento da Rainha

    printf("\n--- Movimento da Rainha (%d casas para a Esquerda) ---\n", MOVIMENTOS_RAINHA);

    int passos_rainha = 0;

    do {
        // Printa a direção do movimento.
        printf("Esquerda\n");

        // Incrementa o contador.
        passos_rainha++;
    } while (passos_rainha < MOVIMENTOS_RAINHA);

    return 0;
}