#include <stdio.h>
#include <stdlib.h>

// --- Constantes do Jogo ---
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

// --- Representações no Tabuleiro ---
#define AGUA 0
#define NAVIO 3
#define AREA_EFEITO 5

// --- Representações na Matriz de Habilidade ---
#define AFETADO 1
#define NAO_AFETADO 0

int main() {
    // Declaração do tabuleiro principal
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int linha, coluna;

    // Inicializa o tabuleiro com água
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // Posiciona os 4 navios (horizontal, vertical e diagonais)
    // Coordenadas dos navios
    int navioH_l = 1, navioH_c = 4;
    int navioV_l = 5, navioV_c = 8;
    int navioD1_l = 0, navioD1_c = 0;
    int navioD2_l = 5, navioD2_c = 3;

    // Colocando os navios no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navioH_l][navioH_c + i] = NAVIO;
        tabuleiro[navioV_l + i][navioV_c] = NAVIO;
        tabuleiro[navioD1_l + i][navioD1_c + i] = NAVIO;
        tabuleiro[navioD2_l + i][navioD2_c - i] = NAVIO;
    }

    // GERAÇÃO DINÂMICA DAS MATRIZES DE HABILIDADE (NOVO)

    printf("Gerando padroes de habilidades especiais...\n");

    // Declara as matrizes 5x5 para cada habilidade
    int habilidade_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    int centro_habilidade = TAMANHO_HABILIDADE / 2; // O centro de uma matriz 5x5 é o índice 2

    // --- Gerando a Habilidade Cone ---
    for (linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            // A área afetada se expande a cada linha. A largura é 2*linha+1.
            // A condição verifica se a coluna está dentro do intervalo [centro - linha] a [centro + linha].
            if (coluna >= centro_habilidade - linha && coluna <= centro_habilidade + linha) {
                habilidade_cone[linha][coluna] = AFETADO;
            } else {
                habilidade_cone[linha][coluna] = NAO_AFETADO;
            }
        }
    }

    // --- Gerando a Habilidade Cruz ---
    for (linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            // A área afetada é a linha central OU a coluna central.
            if (linha == centro_habilidade || coluna == centro_habilidade) {
                habilidade_cruz[linha][coluna] = AFETADO;
            } else {
                habilidade_cruz[linha][coluna] = NAO_AFETADO;
            }
        }
    }

    // --- Gerando a Habilidade Octaedro (Losango/Diamond) ---
    for (linha = 0; linha < TAMANHO_HABILIDADE; linha++) {
        for (coluna = 0; coluna < TAMANHO_HABILIDADE; coluna++) {
            // Usa a "distância de Manhattan" do centro. Se a soma das distâncias
            // vertical e horizontal do centro for menor ou igual ao raio (o próprio centro),
            // a célula é afetada. abs() calcula o valor absoluto.
            if (abs(linha - centro_habilidade) + abs(coluna - centro_habilidade) <= centro_habilidade) {
                habilidade_octaedro[linha][coluna] = AFETADO;
            } else {
                habilidade_octaedro[linha][coluna] = NAO_AFETADO;
            }
        }
    }

    // 3. SOBREPOSIÇÃO DAS HABILIDADES NO TABULEIRO (NOVO)
    printf("Aplicando habilidades no tabuleiro...\n\n");

    // --- Define os pontos de origem (centro) de cada habilidade no tabuleiro ---
    int origem_cone_l = 2, origem_cone_c = 7;
    int origem_cruz_l = 7, origem_cruz_c = 2;
    int origem_octaedro_l = 8, origem_octaedro_c = 6;

    // --- Aplicando o Cone ---
    for (int l_hab = 0; l_hab < TAMANHO_HABILIDADE; l_hab++) {
        for (int c_hab = 0; c_hab < TAMANHO_HABILIDADE; c_hab++) {
            // Verifica se a posição na matriz de habilidade deve ser aplicada
            if (habilidade_cone[l_hab][c_hab] == AFETADO) {
                // Calcula a posição correspondente no tabuleiro principal
                int pos_l_tabuleiro = origem_cone_l - centro_habilidade + l_hab;
                int pos_c_tabuleiro = origem_cone_c - centro_habilidade + c_hab;

                // **Validação de Limites**: Garante que a posição calculada está DENTRO do tabuleiro 10x10
                if (pos_l_tabuleiro >= 0 && pos_l_tabuleiro < TAMANHO_TABULEIRO &&
                    pos_c_tabuleiro >= 0 && pos_c_tabuleiro < TAMANHO_TABULEIRO) {
                    tabuleiro[pos_l_tabuleiro][pos_c_tabuleiro] = AREA_EFEITO;
                }
            }
        }
    }
    
    // --- Aplicando a Cruz ---
     for (int l_hab = 0; l_hab < TAMANHO_HABILIDADE; l_hab++) {
        for (int c_hab = 0; c_hab < TAMANHO_HABILIDADE; c_hab++) {
            if (habilidade_cruz[l_hab][c_hab] == AFETADO) {
                int pos_l_tabuleiro = origem_cruz_l - centro_habilidade + l_hab;
                int pos_c_tabuleiro = origem_cruz_c - centro_habilidade + c_hab;
                if (pos_l_tabuleiro >= 0 && pos_l_tabuleiro < TAMANHO_TABULEIRO &&
                    pos_c_tabuleiro >= 0 && pos_c_tabuleiro < TAMANHO_TABULEIRO) {
                    tabuleiro[pos_l_tabuleiro][pos_c_tabuleiro] = AREA_EFEITO;
                }
            }
        }
    }
    
    // --- Aplicando o Octaedro ---
     for (int l_hab = 0; l_hab < TAMANHO_HABILIDADE; l_hab++) {
        for (int c_hab = 0; c_hab < TAMANHO_HABILIDADE; c_hab++) {
            if (habilidade_octaedro[l_hab][c_hab] == AFETADO) {
                int pos_l_tabuleiro = origem_octaedro_l - centro_habilidade + l_hab;
                int pos_c_tabuleiro = origem_octaedro_c - centro_habilidade + c_hab;
                if (pos_l_tabuleiro >= 0 && pos_l_tabuleiro < TAMANHO_TABULEIRO &&
                    pos_c_tabuleiro >= 0 && pos_c_tabuleiro < TAMANHO_TABULEIRO) {
                    tabuleiro[pos_l_tabuleiro][pos_c_tabuleiro] = AREA_EFEITO;
                }
            }
        }
    }

    // 4. EXIBIÇÃO DO TABULEIRO FINAL

    printf("Tabuleiro final com navios (3) e areas de efeito (5):\n");
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