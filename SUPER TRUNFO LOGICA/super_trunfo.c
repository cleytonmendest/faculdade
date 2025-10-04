#include <stdio.h>
#include <string.h> // Biblioteca necessária para usar a função strcpy

int main() {
    // =========================================================================
    // 1. DADOS PRÉ-DEFINIDOS DAS CARTAS (conforme simplificação do desafio)
    // =========================================================================
    // Em vez de pedir ao usuário, definimos os dados de 2 cartas diretamente aqui.

    // --- Atributos da Carta 1 ---
    char estado1[3];         // Alterado para 3 caracteres para caber "SP" + terminador nulo '\0'
    char codigoCarta1[4];
    char nomeCidade1[50];
    long int populacao1;     // Usando long int para números grandes
    float area1;
    float pib1;              // Em bilhões de reais
    int pontosTuristicos1;
    // Atributos calculados
    float densidadePopulacional1;
    float pibPerCapita1;

    // --- Atributos da Carta 2 ---
    char estado2[3];
    char codigoCarta2[4];
    char nomeCidade2[50];
    long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    // Atributos calculados
    float densidadePopulacional2;
    float pibPerCapita2;

    // --- Populando a Carta 1: São Paulo ---
    strcpy(estado1, "SP"); // strcpy é usado para copiar strings
    strcpy(codigoCarta1, "A01");
    strcpy(nomeCidade1, "Sao Paulo");
    populacao1 = 12396372;
    area1 = 1521.11;
    pib1 = 763.8; // em bilhões
    pontosTuristicos1 = 150;

    // --- Populando a Carta 2: Rio de Janeiro ---
    strcpy(estado2, "RJ");
    strcpy(codigoCarta2, "B02");
    strcpy(nomeCidade2, "Rio de Janeiro");
    populacao2 = 6775561;
    area2 = 1200.32;
    pib2 = 358.5; // em bilhões
    pontosTuristicos2 = 200;

    // =========================================================================
    // 2. CÁLCULO DOS ATRIBUTOS DERIVADOS
    // =========================================================================
    // Esta lógica é reaproveitada do desafio anterior.

    // Cálculos para a Carta 1
    densidadePopulacional1 = (float)populacao1 / area1;
    // Convertemos o PIB de bilhões para unidades (x 1 bilhão)
    pibPerCapita1 = (pib1 * 1000000000) / (float)populacao1;

    // Cálculos para a Carta 2
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / (float)populacao2;


    // =========================================================================
    // 3. COMPARAÇÃO DAS CARTAS COM IF-ELSE
    // =========================================================================
    
    // --- Escolha do atributo para comparar (direto no código) ---
    // Mude o valor desta variável para testar outros atributos.
    // 1: População | 2: Área | 3: PIB | 4: Densidade | 5: PIB per Capita | 6: Pontos Turísticos
    const int ATRIBUTO_ESCOLHIDO = 1;

    // Estrutura if-else if para executar a comparação correta
    if (ATRIBUTO_ESCOLHIDO == 1) {
        printf("--- Comparacao de cartas (Atributo: Populacao) ---\n\n");
        printf("Carta 1 - %s (%s): %ld habitantes\n", nomeCidade1, estado1, populacao1);
        printf("Carta 2 - %s (%s): %ld habitantes\n", nomeCidade2, estado2, populacao2);
        printf("\n");

        if (populacao1 > populacao2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (populacao2 > populacao1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate!\n");
        }

    } else if (ATRIBUTO_ESCOLHIDO == 4) { // Exemplo com a regra especial da Densidade
        printf("--- Comparacao de cartas (Atributo: Densidade Populacional) ---\n\n");
        printf("Carta 1 - %s (%s): %.2f hab/km2\n", nomeCidade1, estado1, densidadePopulacional1);
        printf("Carta 2 - %s (%s): %.2f hab/km2\n", nomeCidade2, estado2, densidadePopulacional2);
        printf("\n");

        // REGRA ESPECIAL: para Densidade, o MENOR valor vence.
        if (densidadePopulacional1 < densidadePopulacional2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (densidadePopulacional2 < densidadePopulacional1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    } 
    // Você pode adicionar mais blocos 'else if' aqui para os outros atributos (Área, PIB, etc.)
    // seguindo o mesmo modelo do ATRIBUTO_ESCOLHIDO == 1.
    else {
        printf("Atributo escolhido invalido ou nao implementado.\n");
    }

    return 0;
}