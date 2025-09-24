// Conversor de Temperatura
// Autor: Aleixo Martins

#include <stdio.h>

// Função que converte Celsius para Fahrenheit
// Fórmula: (9 * C / 5) + 32
float funcaoCel(float Cel) {
    return (9 * Cel / 5) + 32;
}

// Função que converte Fahrenheit para Celsius
// Fórmula: 5 * (F - 32) / 9
float funcaoFah(float Fah) {
    return 5 * (Fah - 32) / 9;
}

int main() {
    char escolha;
    float temp, result;

    // Pergunta ao usuário qual conversão deseja
    printf("Digite C para Celsius ou F para Fahrenheit: ");
    scanf("%c", &escolha);

    // Se o usuário escolher Celsius → Fahrenheit
    if (escolha == 'C' || escolha == 'c') {
        printf("\nDigite a temperatura em Celsius: ");
        scanf("%f", &temp);

        result = funcaoCel(temp);

        printf("\nA temperatura em Fahrenheit fica: %.2f\n", result);
    } 
    // Se o usuário escolher Fahrenheit → Celsius
    else if (escolha == 'F' || escolha == 'f') {
        printf("\nDigite a temperatura em Fahrenheit: ");
        scanf("%f", &temp);

        result = funcaoFah(temp);

        printf("\nA temperatura em Celsius fica: %.2f\n", result);
    } 
    // Caso o usuário digite algo inválido
    else {
        printf("\nOpcao invalida.\n");
    }

    return 0;
}
