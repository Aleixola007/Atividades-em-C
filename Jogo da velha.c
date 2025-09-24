// Jogo da Velha - Versão 1
// Autor: Aleixo Martins
// Obs: Esta versão não possui verificação automática de vitória.

#include <stdio.h>
#define MAX 10 // Tamanho máximo permitido para o tabuleiro

int main() {
    char tabuleiro[MAX][MAX], P1[15], P2[15], jogador = 'X';    // Primeiro jogador começa com 'X'
    int i, j, jogada = 0, linha, coluna, N;

    // Pergunta o tamanho do tabuleiro
    printf("Digite o tamanho do tabuleiro (N x N), no máximo %d: ", MAX);
    scanf("%d", &N);

    // Valida o tamanho
    if (N < 3 || N > MAX) {
        printf("Número inválido, use entre 3 e 9!\n");
        return 1;
    }

    // Boas-vindas e cadastro dos jogadores
    printf("\n--------------- BEM-VINDOS AO JOGO DA VELHA ---------------\n\n");
    printf("Digite o nome do jogador 1: ");
    scanf("%s", P1);

    printf("\nDigite o nome do jogador 2: ");
    scanf("%s", P2);

    printf("\nJogador 1 (X): %s\n", P1);
    printf("Jogador 2 (O): %s\n", P2);
    printf("\n---------- BOA SORTE AOS JOGADORES %s e %s ----------\n", P1, P2);

    // Inicializa tabuleiro vazio
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
    
    // Loop principal do jogo
    while (jogada < N * N) {
        // Mostra o tabuleiro
        printf("\n    ");
        for (j = 0; j < N; j++) {
            printf(" %02d ", j + 1);
        }
        printf("\n");

        for (i = 0; i < N; i++) {
            printf(" %02d ", i + 1);
            for (j = 0; j < N; j++) {
                printf(" %c ", tabuleiro[i][j]);
                if (j < N - 1) printf("|");
            }
            printf("\n");

            if (i < N - 1) {
                printf("    ");
                for (j = 0; j < N; j++) {
                    printf("---");
                    if (j < N - 1) printf("+");
                }
                printf("\n");
            }
        }
        
        // Pergunta a jogada do jogador atual
        if (jogador == 'X') {
            printf("\nJogador %s, informe a linha e coluna (1-%d): ", P1, N);
        } else {
            printf("\nJogador %s, informe a linha e coluna (1-%d): ", P2, N);
        }
        
        scanf("%d %d", &linha, &coluna);
        linha--; coluna--; // Ajusta índice (entrada começa em 1, matriz começa em 0)

        // Valida jogada
        if (linha < 0 || linha >= N || coluna < 0 || coluna >= N || tabuleiro[linha][coluna] != ' ') {
            printf("\nJogada inválida, tente novamente!\n");
            continue;
        }
        
        // Marca no tabuleiro
        tabuleiro[linha][coluna] = jogador;
        jogada++;

        // Alterna jogador
        jogador = (jogador == 'X') ? 'O' : 'X';
    }
    
    printf("\nFim de jogo! (Obs: Esta versão não verifica vencedores automaticamente)\n");

    return 0;
}
