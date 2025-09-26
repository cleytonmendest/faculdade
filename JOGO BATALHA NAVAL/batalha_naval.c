#include <stdio.h>

// --- Constantes para facilitar a manutenção do código ---
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // 1. CRIAÇÃO E INICIALIZAÇÃO DO TABULEIRO
    // Declara uma matriz 10x10 para ser o nosso tabuleiro.
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int linha, coluna; // Variáveis de controle para os loops

    // Inicializa todo o tabuleiro com o valor de AGUA (0).
    // Esta parte do código não muda em relação ao nível anterior.
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // 2. POSICIONAMENTO DOS QUATRO NAVIOS
    // As coordenadas foram escolhidas cuidadosamente para garantir que os navios
    // fiquem dentro dos limites do tabuleiro e não se sobreponham.

    // --- Navio 1: Horizontal ---
    // Posição inicial: linha 1, coluna 4. Ocupará (1,4), (1,5), (1,6).
    int navioH_linha_inicial = 1;
    int navioH_coluna_inicial = 4;

    // --- Navio 2: Vertical ---
    // Posição inicial: linha 5, coluna 8. Ocupará (5,8), (6,8), (7,8).
    int navioV_linha_inicial = 5;
    int navioV_coluna_inicial = 8;

    // --- Navio 3: Diagonal Principal (\) ---
    // Posição inicial: linha 0, coluna 0. Ocupará (0,0), (1,1), (2,2).
    // Neste tipo de diagonal, linha e coluna aumentam juntas.
    int navioD1_linha_inicial = 0;
    int navioD1_coluna_inicial = 0;

    // --- Navio 4: Diagonal Secundária (/) ---
    // Posição inicial: linha 5, coluna 3. Ocupará (5,3), (6,2), (7,1).
    // Neste tipo de diagonal, a linha aumenta e a coluna diminui.
    int navioD2_linha_inicial = 5;
    int navioD2_coluna_inicial = 3;


    // --- Colocando os navios no tabuleiro ---
    printf("Posicionando 4 navios de tamanho %d...\n\n", TAMANHO_NAVIO);

    // Loop para o navio Horizontal (linha fixa, coluna incrementa)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navioH_linha_inicial][navioH_coluna_inicial + i] = NAVIO;
    }

    // Loop para o navio Vertical (coluna fixa, linha incrementa)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navioV_linha_inicial + i][navioV_coluna_inicial] = NAVIO;
    }

    // Loop para o navio Diagonal Principal (linha e coluna incrementam)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navioD1_linha_inicial + i][navioD1_coluna_inicial + i] = NAVIO;
    }

    // Loop para o navio Diagonal Secundária (linha incrementa, coluna decrementa)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navioD2_linha_inicial + i][navioD2_coluna_inicial - i] = NAVIO;
    }

    // 3. EXIBIÇÃO DO TABULEIRO FINAL
    // Esta parte também não muda, apenas exibe a matriz final.
    printf("Tabuleiro final com os navios (%d) posicionados:\n", NAVIO);
    printf("-----------------------------------------\n");
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
    printf("-----------------------------------------\n");

    return 0;
}