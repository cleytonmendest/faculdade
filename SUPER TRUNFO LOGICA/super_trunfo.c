#include <stdio.h>
#include <string.h> // Biblioteca necessária para strcpy

int main() {
    // =========================================================================
    // 1. DADOS PRÉ-DEFINIDOS E CÁLCULOS INICIAIS
    // =========================================================================
    // Mantemos os dados fixos para focar na lógica do jogo.

    // --- Atributos da Carta 1: Brasil ---
    char pais1[50];
    long int populacao1;
    float area1;
    float pib1; // Em trilhões de USD
    int pontosTuristicos1;
    float densidadeDemografica1;

    // --- Atributos da Carta 2: Japão ---
    char pais2[50];
    long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadeDemografica2;

    // --- Populando a Carta 1: Brasil ---
    strcpy(pais1, "Brasil");
    populacao1 = 215300000;
    area1 = 8516000.0;
    pib1 = 1.609;
    pontosTuristicos1 = 180;

    // --- Populando a Carta 2: Japão (para uma comparação mais interessante) ---
    strcpy(pais2, "Japao");
    populacao2 = 125700000;
    area2 = 377975.0;
    pib2 = 5.065;
    pontosTuristicos2 = 250;
    
    densidadeDemografica1 = (float)populacao1 / area1;
    densidadeDemografica2 = (float)populacao2 / area2;

    // =========================================================================
    // 2. ESCOLHA DO PRIMEIRO ATRIBUTO
    // =========================================================================
    int escolha1, escolha2;

    printf("--- BATALHA SUPER TRUNFO - ESCOLHA DUPLA ---\n\n");
    printf("Jogador, escolha o PRIMEIRO atributo para a comparacao:\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica (menor eh melhor na comparacao individual)\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &escolha1);

    // Validação da primeira escolha
    if (escolha1 < 1 || escolha1 > 5) {
        printf("\nOpcao invalida! Fim de jogo.\n");
        return 1; // Encerra o programa com um código de erro
    }

    // =========================================================================
    // 3. ESCOLHA DO SEGUNDO ATRIBUTO (MENU DINÂMICO)
    // =========================================================================
    printf("\nAgora, escolha o SEGUNDO atributo (nao pode ser o mesmo):\n");

    // O menu é impresso dinamicamente, omitindo a primeira escolha do jogador.
    if (escolha1 != 1) printf("1. Populacao\n");
    if (escolha1 != 2) printf("2. Area\n");
    if (escolha1 != 3) printf("3. PIB\n");
    if (escolha1 != 4) printf("4. Pontos Turisticos\n");
    if (escolha1 != 5) printf("5. Densidade Demografica\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha2);
    
    // Validação da segunda escolha
    if (escolha2 < 1 || escolha2 > 5 || escolha2 == escolha1) {
        printf("\nOpcao invalida ou repetida! Fim de jogo.\n");
        return 1;
    }

    // =========================================================================
    // 4. LÓGICA DE COMPARAÇÃO COM MÚLTIPLOS ATRIBUTOS
    // =========================================================================
    
    // Variáveis para armazenar os valores e nomes dos atributos escolhidos
    float valor1_carta1, valor1_carta2, valor2_carta1, valor2_carta2;
    char nome_atributo1[50], nome_atributo2[50];

    // Switch para obter os dados do PRIMEIRO atributo escolhido
    switch (escolha1) {
        case 1: valor1_carta1 = (float)populacao1; valor1_carta2 = (float)populacao2; strcpy(nome_atributo1, "Populacao"); break;
        case 2: valor1_carta1 = area1; valor1_carta2 = area2; strcpy(nome_atributo1, "Area"); break;
        case 3: valor1_carta1 = pib1; valor1_carta2 = pib2; strcpy(nome_atributo1, "PIB"); break;
        case 4: valor1_carta1 = (float)pontosTuristicos1; valor1_carta2 = (float)pontosTuristicos2; strcpy(nome_atributo1, "Pontos Turisticos"); break;
        case 5: valor1_carta1 = densidadeDemografica1; valor1_carta2 = densidadeDemografica2; strcpy(nome_atributo1, "Densidade Demografica"); break;
    }

    // Switch para obter os dados do SEGUNDO atributo escolhido
    switch (escolha2) {
        case 1: valor2_carta1 = (float)populacao1; valor2_carta2 = (float)populacao2; strcpy(nome_atributo2, "Populacao"); break;
        case 2: valor2_carta1 = area1; valor2_carta2 = area2; strcpy(nome_atributo2, "Area"); break;
        case 3: valor2_carta1 = pib1; valor2_carta2 = pib2; strcpy(nome_atributo2, "PIB"); break;
        case 4: valor2_carta1 = (float)pontosTuristicos1; valor2_carta2 = (float)pontosTuristicos2; strcpy(nome_atributo2, "Pontos Turisticos"); break;
        case 5: valor2_carta1 = densidadeDemografica1; valor2_carta2 = densidadeDemografica2; strcpy(nome_atributo2, "Densidade Demografica"); break;
    }
    
    // A regra da Densidade (menor vence) se aplica a comparações individuais.
    // Para a SOMA, consideramos o valor bruto, e a maior soma vence.
    float soma_carta1 = valor1_carta1 + valor2_carta1;
    float soma_carta2 = valor1_carta2 + valor2_carta2;
    
    // =========================================================================
    // 5. EXIBIÇÃO CLARA DO RESULTADO
    // =========================================================================
    printf("\n\n--- RESULTADO DA BATALHA ---\n\n");
    
    // Exibindo os dados da Carta 1
    printf("--- %s ---\n", pais1);
    printf("-> %s: %.2f\n", nome_atributo1, valor1_carta1);
    printf("-> %s: %.2f\n", nome_atributo2, valor2_carta1);
    printf("SOMA TOTAL: %.2f\n\n", soma_carta1);

    // Exibindo os dados da Carta 2
    printf("--- %s ---\n", pais2);
    printf("-> %s: %.2f\n", nome_atributo1, valor1_carta2);
    printf("-> %s: %.2f\n", nome_atributo2, valor2_carta2);
    printf("SOMA TOTAL: %.2f\n\n", soma_carta2);

    // Lógica final para determinar o vencedor usando if-else e operador ternário para elegância
    if (soma_carta1 > soma_carta2) {
        printf("VENCEDOR DA RODADA: %s!\n", pais1);
    } else if (soma_carta2 > soma_carta1) {
        printf("VENCEDOR DA RODADA: %s!\n", pais2);
    } else {
        printf("RESULTADO: EMPATE!\n");
    }

    return 0;
}