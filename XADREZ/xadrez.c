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

// PROTÓTIPOS DAS FUNÇÕES RECURSIVAS
void moverTorre(int passos_restantes);
void moverBispo(int passos_restantes);
void moverRainha(int passos_restantes);

int main()
{
    // Movimento da Torre com Recursividade
    printf("--- Movimento da Torre (5 casas para a Direita) ---\n", MOVIMENTOS_TORRE);
    moverTorre(MOVIMENTOS_TORRE);

    // Movimento do Bispo com Recursividade
    printf("\n--- Movimento do Bispo (5 casas na Diagonal Cima-Direita) ---\n", MOVIMENTOS_BISPO);
    moverBispo(MOVIMENTOS_BISPO);

    // Movimento da Rainha com Recursividade
    printf("\n--- Movimento da Rainha (8 casas para a Esquerda) ---\n", MOVIMENTOS_RAINHA);
    moverRainha(MOVIMENTOS_RAINHA);

    // --- Movimento do Cavalo com Loops Complexos ---
    printf("\n--- Movimento do Cavalo (2 casas para Baixo, 1 para Esquerda) ---\n", 
           PASSOS_VERTICAIS_CAVALO, PASSOS_HORIZONTAIS_CAVALO);

    for (int v_dados = 0, h_dados = 0; ; ) {
        // PRIMEIRO, foca em completar os movimentos verticais.
        if (v_dados < PASSOS_VERTICAIS_CAVALO) {
            printf("Cima\n");
            v_dados++;

            // Isso garante que todos os movimentos para "Cima" sejam feitos antes de passar para "Direita".
            continue; 
        }

        // DEPOIS que os movimentos verticais terminam, o 'if' acima se torna falso.
        // O código então prossegue para o movimento horizontal.
        if (h_dados < PASSOS_HORIZONTAIS_CAVALO) {
            printf("Direita\n");
            h_dados++;
        }

        // CONDIÇÃO DE SAÍDA:
        // Quando ambos os contadores atingem o total de movimentos necessários...
        if (v_dados == PASSOS_VERTICAIS_CAVALO && h_dados == PASSOS_HORIZONTAIS_CAVALO) {
            // 'break' encerra o loop 'for' imediatamente.
            break; 
        }
    }

    return 0;
}


// --- DEFINIÇÃO DAS FUNÇÕES RECURSIVAS ---

//Move a Torre recursivamente.
void moverTorre(int passos_restantes) {
    // Caso Base: A condição de parada da recursão.
    // Se não houver mais passos, a função simplesmente retorna e encerra a cadeia de chamadas.
    if (passos_restantes <= 0) {
        return;
    }

    // Ação: Imprime o movimento do passo atual.
    printf("Direita\n");

    // Passo Recursivo: A função chama a si mesma, mas com o problema reduzido (um passo a menos).
    moverTorre(passos_restantes - 1);
}


// Move o Bispo recursivamente.

void moverBispo(int passos_restantes) {
    // Caso Base: Condição de parada.
    if (passos_restantes <= 0) {
        return;
    }
    // Ação:
    printf("Cima, Direita\n");
    // Passo Recursivo:
    moverBispo(passos_restantes - 1);
}


// Move a Rainha recursivamente.
void moverRainha(int passos_restantes) {
    // Caso Base: Condição de parada.
    if (passos_restantes <= 0) {
        return;
    }
    // Ação:
    printf("Esquerda\n");
    // Passo Recursivo:
    moverRainha(passos_restantes - 1);
}