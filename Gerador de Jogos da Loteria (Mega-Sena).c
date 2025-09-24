// Gerador de Jogos da Loteria (Mega-Sena)
// Autor: Aleixo Martins

#include <stdio.h>

int main() {
    // Matriz tridimensional para representar até 5 cartelas
    // loteria[i][j][k] -> jogo i, linha j, coluna k
    char loteria[5][6][10]; 

    // Matriz para armazenar os números escolhidos por jogo
    int jogo[5][6]; 

    int i, j, k;   // contadores
    int qtd;       // quantidade de jogos
    int num;       // número escolhido pelo usuário
    int N;         // usado para cálculo da posição (linha/coluna)
    int linha, coluna;

    // Inicializa todas as cartelas com espaços em branco
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 6; j++) {
            for (k = 0; k < 10; k++) {
                loteria[i][j][k] = ' ';
            }
        }
    }
    
    // Pergunta quantos jogos o usuário deseja
    printf("Informe quantos jogos da mega-sena deseja (maximo 5): ");
    scanf("%d", &qtd);

    if (qtd >= 1 && qtd <= 5) {
        // Para cada jogo solicitado
        for (i = 0; i < qtd; i++) {
            printf("\n--- JOGO %d ---\n", i + 1);
            
            // O usuário deve escolher 6 números
            for (j = 0; j < 6; j++) {
                do {
                    printf("Escolha o %d° numero entre 1 e 60 (sem repetir): ", j + 1);
                    scanf("%d", &num);
                    
                    // Verifica se o número está dentro do intervalo válido
                    if (num < 1 || num > 60) {
                        printf("\nNumero inválido, tente novamente (1 a 60).\n");
                        continue;
                    }
                    
                    // Verifica se o número já foi escolhido neste jogo
                    int repetido = 0;
                    for (k = 0; k < j; k++) {
                        if (jogo[i][k] == num) {
                            repetido = 1;
                            break;
                        }
                    }
                    
                    if (repetido) {
                        printf("Numero ja escolhido! Escolha outro.\n");
                    } else {
                        jogo[i][j] = num;
                        break; // sai do loop se número válido
                    }
                } while (1);
            }

            // Marca os números escolhidos na matriz do jogo
            for (j = 0; j < 6; j++) {
                N = jogo[i][j];
                linha = (N - 1) / 10;   // define a linha (0 a 5)
                coluna = (N - 1) % 10; // define a coluna (0 a 9)
                loteria[i][linha][coluna] = 'X';
            }
        }
        
        // Impressão das cartelas
        for (i = 0; i < qtd; i++) {
            printf("\n--- Cartela do jogo %d ---", i + 1);
            printf("\nLin//Col ");

            // Cabeçalho de colunas (1 a 10)
            for (k = 0; k < 10; k++) {
                printf("%2d ", k + 1);
            }
            printf("\n");

            // Exibe cada linha (0 a 5)
            for (j = 0; j < 6; j++) {
                printf("%5d  ", j);

                for (k = 0; k < 10; k++) {
                    printf("%2c ", loteria[i][j][k]);
                }
                printf("\n");
            }
            
            // Lista os números escolhidos
            printf("\nNumeros escolhidos: ");
            for (j = 0; j < 6; j++) {
                printf("%d ", jogo[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nQuantidade inválida, escolha entre 1 e 5.\n");
    }
    return 0;
}
