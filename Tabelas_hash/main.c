#include <stdio.h>

int main() {

    int barometro,termometro;

    // pergunta ao usuário se o barômetro está subindo, descendo ou estácionario
    printf("O barômetro está:\n1 - Subindo\n2 - Descendo\n3 - Estacionário");
    // armazena o valor na variável int barometro
    scanf("%d", &barometro);

    // pergunta ao usuário se o barômetro está subindo, descendo ou estácionario
    printf("O termômetro está:\n1 - Subindo\n2 - Descendo\n3 - Estacionário");
    // armazena o valor na variável int barometro
    scanf("%d", &termometro);

    // switch case com 3 casos, que são as opções das quais o barômetro pode variar
    // dentro de cada caso, verifica se o termômetro está subindo, descendo ou estacionário
    switch(barometro) {
        // Barômetro subindo
        case 1:
            if (termometro == 1) {
                printf("Tempo bom, ventos quentes e secos");
                break;
            }
            else if (termometro == 2) {
                printf("Tempo bom, ventos de sul a sudeste");
                break;
            }
            else if (termometro == 3) {
                printf("Tempo bom, ventos de leste frescos");
                break;
            } else {
                printf("Dado incorreto, deve ser inserido um número de 1 a 3!");
                break;
            }
        // Barômetro descendo
        case 2:
            if (termometro == 1) {
                printf("Tempo instável, aproximação de frente");
                break;
            }
            else if (termometro == 2) {
                printf("Chuvas abundantes e ventos de sul a sudoeste fortes");
                break;
            }
            else if (termometro == 3) {
                printf("Frente quente com chuvas prováveis");
                break;
            }
            else {
                printf("Dado incorreto, deve ser inserido um número de 1 a 3!");
                break;
            }
        // Barômetro estacionário
        case 3:

            if (termometro == 1) {
                printf("Tempo mudando para bom, ventos de leste");
                break;
            }
            else if (termometro == 2) {
                printf("Chuva provável, ventos de sul a sudeste");
                break;
            }
            else if (termometro == 3) {
                printf("Tempo incerto, ventos variáveis");
                break;
            }
            else {
                printf("Dado incorreto, deve ser inserido um número de 1 a 3!");
                break;
            }
    }
}
