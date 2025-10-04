#include <stdio.h>
#include <string.h>

int main() {
    // =========================================================================
    // 1. DADOS PRÉ-DEFINIDOS DAS CARTAS
    // =========================================================================
    // Mantemos os dados fixos para focar na lógica do menu e da comparação.

    // --- Atributos da Carta 1: Brasil ---
    char pais1[50];
    long int populacao1;
    float area1;
    float pib1; // Em trilhões de USD
    int pontosTuristicos1;
    float densidadeDemografica1;

    // --- Atributos da Carta 2: Argentina ---
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
    pib1 = 1.609; // em trilhões
    pontosTuristicos1 = 180;

    // --- Populando a Carta 2: Argentina ---
    strcpy(pais2, "Argentina");
    populacao2 = 45810000;
    area2 = 2780000.0;
    pib2 = 0.487; // em trilhões
    pontosTuristicos2 = 120;

    // =========================================================================
    // 2. CÁLCULO DOS ATRIBUTOS DERIVADOS
    // =========================================================================
    densidadeDemografica1 = (float)populacao1 / area1;
    densidadeDemografica2 = (float)populacao2 / area2;

    // =========================================================================
    // 3. MENU INTERATIVO E ESCOLHA DO USUÁRIO
    // =========================================================================
    int escolha_usuario;

    // Exibe as cartas e o menu de opções para o jogador
    printf("--- BATALHA SUPER TRUNFO ---\n\n");
    printf("Carta 1: %s\n", pais1);
    printf("Carta 2: %s\n\n", pais2);
    printf("Escolha o atributo para a comparacao:\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica (menor vence)\n");
    printf("Digite sua escolha (1-5): ");

    // Lê a opção digitada pelo usuário
    scanf("%d", &escolha_usuario);
    printf("\n");

    // =========================================================================
    // 4. COMPARAÇÃO USANDO SWITCH E IF-ELSE
    // =========================================================================
    // A estrutura 'switch' direciona o programa para o bloco de código correto
    // com base na escolha do usuário.
    switch (escolha_usuario) {
        case 1: // Comparação por População
            printf("--- Comparacao por: Populacao ---\n");
            printf("%s: %ld habitantes\n", pais1, populacao1);
            printf("%s: %ld habitantes\n", pais2, populacao2);
            printf("\n");
            if (populacao1 > populacao2) {
                printf("Resultado: %s venceu!\n", pais1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: %s venceu!\n", pais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break; // 'break' impede que o código continue executando os outros casos

        case 2: // Comparação por Área
            printf("--- Comparacao por: Area ---\n");
            printf("%s: %.0f km2\n", pais1, area1);
            printf("%s: %.0f km2\n", pais2, area2);
            printf("\n");
            if (area1 > area2) {
                printf("Resultado: %s venceu!\n", pais1);
            } else if (area2 > area1) {
                printf("Resultado: %s venceu!\n", pais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // Comparação por PIB
            printf("--- Comparacao por: PIB ---\n");
            printf("%s: %.3f trilhoes USD\n", pais1, pib1);
            printf("%s: %.3f trilhoes USD\n", pais2, pib2);
            printf("\n");
            if (pib1 > pib2) {
                printf("Resultado: %s venceu!\n", pais1);
            } else if (pib2 > pib1) {
                printf("Resultado: %s venceu!\n", pais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Comparação por Pontos Turísticos
            printf("--- Comparacao por: Pontos Turisticos ---\n");
            printf("%s: %d pontos\n", pais1, pontosTuristicos1);
            printf("%s: %d pontos\n", pais2, pontosTuristicos2);
            printf("\n");
            if (pontosTuristicos1 > pontosTuristicos2) {
                printf("Resultado: %s venceu!\n", pais1);
            } else if (pontosTuristicos2 > pontosTuristicos1) {
                printf("Resultado: %s venceu!\n", pais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Comparação por Densidade Demográfica
            printf("--- Comparacao por: Densidade Demografica ---\n");
            printf("%s: %.2f hab/km2\n", pais1, densidadeDemografica1);
            printf("%s: %.2f hab/km2\n", pais2, densidadeDemografica2);
            printf("\n");
            // REGRA ESPECIAL: para Densidade, o MENOR valor vence.
            if (densidadeDemografica1 < densidadeDemografica2) {
                printf("Resultado: %s venceu!\n", pais1);
            } else if (densidadeDemografica2 < densidadeDemografica1) {
                printf("Resultado: %s venceu!\n", pais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        default: // Caso o usuário digite uma opção inválida
            printf("Opcao invalida! Por favor, escolha um numero entre 1 e 5.\n");
            break;
    }

    return 0;
}