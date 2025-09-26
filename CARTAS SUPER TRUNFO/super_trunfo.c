#include <stdio.h>

int main() {
    // --- Variáveis da Carta 1 ---
    char estado1;
    char codigoCarta1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    float superPoder1;

    // --- Variáveis da Carta 2 ---
    char estado2;
    char codigoCarta2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;
    
    // --- Variáveis para armazenar o resultado (1 ou 0) das comparações ---
    int vitoriaPopulacao;
    int vitoriaArea;
    int vitoriaPib;
    int vitoriaPontosTuristicos;
    int vitoriaDensidade;
    int vitoriaPibPerCapita;
    int vitoriaSuperPoder;


    // --- CADASTRO DA CARTA 1 ---
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf("%s", codigoCarta1);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("Digite a Populacao: ");
    scanf("%lu", &populacao1);
    printf("Digite a Area (em km2): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);
    printf("\n");

    // --- CADASTRO DA CARTA 2 ---
    printf("--- Cadastro da Carta 2 ---\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o Codigo da Carta (ex: B02): ");
    scanf("%s", codigoCarta2);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("Digite a Populacao: ");
    scanf("%lu", &populacao2);
    printf("Digite a Area (em km2): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- CÁLCULOS PARA AS CARTAS ---
    // Cálculos para a Carta 1
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / (float)populacao1;
    superPoder1 = (float)populacao1 + area1 + (pib1 * 1000000000) + (float)pontosTuristicos1 + pibPerCapita1 + (1.0 / densidadePopulacional1);

    // Cálculos para a Carta 2
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / (float)populacao2;
    superPoder2 = (float)populacao2 + area2 + (pib2 * 1000000000) + (float)pontosTuristicos2 + pibPerCapita2 + (1.0 / densidadePopulacional2);

    // --- COMPARAÇÃO DOS ATRIBUTOS ---
    vitoriaPopulacao = populacao1 > populacao2;
    vitoriaArea = area1 > area2;
    vitoriaPib = pib1 > pib2;
    vitoriaPontosTuristicos = pontosTuristicos1 > pontosTuristicos2;
    vitoriaPibPerCapita = pibPerCapita1 > pibPerCapita2;
    vitoriaSuperPoder = superPoder1 > superPoder2;
    vitoriaDensidade = densidadePopulacional1 < densidadePopulacional2;
    
    // --- EXIBIÇÃO DOS RESULTADOS DA BATALHA ---
    printf("\n\n--- Comparacao de Cartas ---\n");
    printf("Populacao: Carta %d venceu (%d)\n", (vitoriaPopulacao ? 1 : 2), vitoriaPopulacao);
    printf("Area: Carta %d venceu (%d)\n", (vitoriaArea ? 1 : 2), vitoriaArea);
    printf("PIB: Carta %d venceu (%d)\n", (vitoriaPib ? 1 : 2), vitoriaPib);
    printf("Pontos Turisticos: Carta %d venceu (%d)\n", (vitoriaPontosTuristicos ? 1 : 2), vitoriaPontosTuristicos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", (vitoriaDensidade ? 1 : 2), vitoriaDensidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n", (vitoriaPibPerCapita ? 1 : 2), vitoriaPibPerCapita);
    printf("Super Poder: Carta %d venceu (%d)\n", (vitoriaSuperPoder ? 1 : 2), vitoriaSuperPoder);

    return 0;
}