#include <stdio.h>

// --- Constantes para facilitar a manutenção do código ---
// Define o tamanho do tabuleiro (10x10)
#define TAMANHO_TABULEIRO 10
// Define o tamanho fixo dos navios (3 posições)
#define TAMANHO_NAVIO 3
// Define os valores que representam água e navio
#define AGUA 0
#define NAVIO 3

int main()
{
    // 1. REPRESENTAÇÃO DO TABULEIRO
    // Declara uma matriz 10x10 de inteiros para ser o nosso tabuleiro.
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int linha, coluna; // Variáveis de controle para os loops

    // --- Inicialização do Tabuleiro ---
    // Este bloco de código percorre cada posição da matriz.
    printf("Inicializando o tabuleiro com agua (%d)...\n\n", AGUA);
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++)
    {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++)
        {
            // Define o valor de cada célula como 0 (AGUA).
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // 2. POSICIONAMENTO DOS NAVIOS
    // As coordenadas são definidas diretamente no código, como pedido.
    // Lembre-se que em C, os índices de arrays começam em 0.
    // Então, um tabuleiro 10x10 vai da linha 0 a 9 e coluna 0 a 9.

    // --- Navio 1: Horizontal ---
    // Posição inicial: linha 2, coluna 1.
    // Ocupará as posições (2,1), (2,2) e (2,3).
    // Esta posição é válida pois 1 + TAMANHO_NAVIO (3) = 4, que é < 10.
    int navioH_linha_inicial = 2;
    int navioH_coluna_inicial = 1;

    // --- Navio 2: Vertical ---
    // Posição inicial: linha 5, coluna 6.
    // Ocupará as posições (5,6), (6,6) e (7,6).
    // Esta posição é válida pois 5 + TAMANHO_NAVIO (3) = 8, que é < 10.
    // As posições também não se sobrepõem com o navio horizontal.
    int navioV_linha_inicial = 5;
    int navioV_coluna_inicial = 6;

    // --- Colocando os navios no tabuleiro ---
    // Este loop posiciona o navio horizontal.
    // A linha fica fixa, e a coluna varia a partir do ponto inicial.
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[navioH_linha_inicial][navioH_coluna_inicial + i] = NAVIO;
    }

    // Este loop posiciona o navio vertical.
    // A coluna fica fixa, e a linha varia a partir do ponto inicial.
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[navioV_linha_inicial + i][navioV_coluna_inicial] = NAVIO;
    }

    // 3. EXIBIÇÃO DO TABULEIRO
    // Este bloco de código imprime o estado final do tabuleiro no console.
    printf("Tabuleiro final com os navios (%d) posicionados:\n", NAVIO);
    printf("-----------------------------------------\n");
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++)
    {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++)
        {
            // Imprime o valor da célula atual seguido de um espaço.
            printf("%d ", tabuleiro[linha][coluna]);
        }
        // Ao final de cada linha, imprime uma quebra de linha para formatar o tabuleiro.
        printf("\n");
    }
    printf("-----------------------------------------\n");

    return 0; // Indica que o programa terminou com sucesso.
}