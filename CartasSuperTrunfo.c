#include <stdio.h>
#include <string.h>

#define TOTAL_CARTAS 4

typedef struct {
    char codigo[4];          
    long int populacao;
    double area;
    double pib;
    int pontosTuristicos;
    double densidadePop;     
    double pibPerCapita;     
    double superPoder;       
} Carta;

int main() {
    Carta cartas[TOTAL_CARTAS];

    for (int i = 0; i < TOTAL_CARTAS; i++) {
        printf("\nCadastro da carta %d:\n", i + 1);

        printf("Codigo da carta (ex: A01): ");
        scanf("%3s", cartas[i].codigo);

        printf("Populacao: ");
        scanf("%ld", &cartas[i].populacao);

        printf("Area (km2): ");
        scanf("%lf", &cartas[i].area);

        printf("PIB (em bilhoes): ");
        scanf("%lf", &cartas[i].pib);

        printf("Numero de pontos turisticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        cartas[i].densidadePop = (cartas[i].area > 0) ?
            (double)cartas[i].populacao / cartas[i].area : 0;

        cartas[i].pibPerCapita = (cartas[i].populacao > 0) ?
            cartas[i].pib * 1e9 / cartas[i].populacao : 0; 

        cartas[i].superPoder =
            cartas[i].populacao +
            cartas[i].area +
            cartas[i].pib +
            cartas[i].pontosTuristicos +
            cartas[i].densidadePop +
            cartas[i].pibPerCapita;
    }

    printf("\n===== CARTAS CADASTRADAS =====\n");
    for (int i = 0; i < TOTAL_CARTAS; i++) {
        printf("\nCarta %d\n", i + 1);
        printf("Codigo: %s\n", cartas[i].codigo);
        printf("Populacao: %ld\n", cartas[i].populacao);
        printf("Area: %.2lf km2\n", cartas[i].area);
        printf("PIB: %.2lf bilhoes\n", cartas[i].pib);
        printf("Pontos turisticos: %d\n", cartas[i].pontosTuristicos);
        printf("Densidade Populacional: %.2lf hab/km2\n", cartas[i].densidadePop);
        printf("PIB per Capita: %.2lf reais/hab\n", cartas[i].pibPerCapita);
        printf("Super Poder: %.2lf\n", cartas[i].superPoder);
    }

    int c1, c2;
    printf("\n\n=== COMPARAR DUAS CARTAS ===\n");
    printf("Digite o indice da primeira carta (1-%d): ", TOTAL_CARTAS);
    scanf("%d", &c1);
    printf("Digite o indice da segunda carta (1-%d): ", TOTAL_CARTAS);
    scanf("%d", &c2);

    c1--; c2--;

    printf("\nComparando %s x %s\n", cartas[c1].codigo, cartas[c2].codigo);

    if (cartas[c1].densidadePop < cartas[c2].densidadePop)
        printf("Densidade Populacional: Vence %s (%.2lf)\n",
               cartas[c1].codigo, cartas[c1].densidadePop);
    else if (cartas[c2].densidadePop < cartas[c1].densidadePop)
        printf("Densidade Populacional: Vence %s (%.2lf)\n",
               cartas[c2].codigo, cartas[c2].densidadePop);
    else
        printf("Densidade Populacional: Empate\n");

    if (cartas[c1].populacao > cartas[c2].populacao)
        printf("Populacao: Vence %s (%ld)\n", cartas[c1].codigo, cartas[c1].populacao);
    else if (cartas[c2].populacao > cartas[c1].populacao)
        printf("Populacao: Vence %s (%ld)\n", cartas[c2].codigo, cartas[c2].populacao);
    else
        printf("Populacao: Empate\n");

    if (cartas[c1].area > cartas[c2].area)
        printf("Area: Vence %s (%.2lf)\n", cartas[c1].codigo, cartas[c1].area);
    else if (cartas[c2].area > cartas[c1].area)
        printf("Area: Vence %s (%.2lf)\n", cartas[c2].codigo, cartas[c2].area);
    else
        printf("Area: Empate\n");

    if (cartas[c1].pib > cartas[c2].pib)
        printf("PIB: Vence %s (%.2lf)\n", cartas[c1].codigo, cartas[c1].pib);
    else if (cartas[c2].pib > cartas[c1].pib)
        printf("PIB: Vence %s (%.2lf)\n", cartas[c2].codigo, cartas[c2].pib);
    else
        printf("PIB: Empate\n");

    if (cartas[c1].pontosTuristicos > cartas[c2].pontosTuristicos)
        printf("Pontos Turisticos: Vence %s (%d)\n",
               cartas[c1].codigo, cartas[c1].pontosTuristicos);
    else if (cartas[c2].pontosTuristicos > cartas[c1].pontosTuristicos)
        printf("Pontos Turisticos: Vence %s (%d)\n",
               cartas[c2].codigo, cartas[c2].pontosTuristicos);
    else
        printf("Pontos Turisticos: Empate\n");

    if (cartas[c1].pibPerCapita > cartas[c2].pibPerCapita)
        printf("PIB per Capita: Vence %s (%.2lf)\n",
               cartas[c1].codigo, cartas[c1].pibPerCapita);
    else if (cartas[c2].pibPerCapita > cartas[c1].pibPerCapita)
        printf("PIB per Capita: Vence %s (%.2lf)\n",
               cartas[c2].codigo, cartas[c2].pibPerCapita);
    else
        printf("PIB per Capita: Empate\n");

    if (cartas[c1].superPoder > cartas[c2].superPoder)
        printf("Super Poder: Vence %s (%.2lf)\n",
               cartas[c1].codigo, cartas[c1].superPoder);
    else if (cartas[c2].superPoder > cartas[c1].superPoder)
        printf("Super Poder: Vence %s (%.2lf)\n",
               cartas[c2].codigo, cartas[c2].superPoder);
    else
        printf("Super Poder: Empate\n");

    return 0;
}
