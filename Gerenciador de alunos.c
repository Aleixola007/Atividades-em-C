// Gerenciador de Alunos
// Autor: Aleixo Martins

#include <stdio.h>

int main() {
    int alunos[5][4], i, maiorNota = -1, matriculaMaiorNota=0; 
    float somaNotas = 0;

    // Entrada de dados dos 5 alunos
    for (i = 0; i < 5; i++) {
        printf("Aluno %d\n", i + 1);

        // Coluna 0 = matrícula
        printf("Matrícula: ");
        scanf("%d", &alunos[i][0]);

        // Coluna 1 = média das provas
        printf("Média das provas: ");
        scanf("%d", &alunos[i][1]);

        // Coluna 2 = média dos trabalhos
        printf("Média dos trabalhos: ");
        scanf("%d", &alunos[i][2]);

        // Coluna 3 = nota final (provas + trabalhos)
        alunos[i][3] = alunos[i][1] + alunos[i][2];
    }

    // Exibição dos dados em formato de tabela
    printf("\nMATRICULA  PROVAS  TRABALHOS  NOTA FINAL\n");
    for (i = 0; i < 5; i++) {
        printf("%9d %7d %10d %11d\n", 
            alunos[i][0], 
            alunos[i][1], 
            alunos[i][2], 
            alunos[i][3]
        );

        // Verifica se esta nota é a maior até agora
        if (alunos[i][3] > maiorNota) {
            maiorNota = alunos[i][3];
            matriculaMaiorNota = alunos[i][0];
        }

        // Soma para calcular média geral
        somaNotas += alunos[i][3];
    }

    // Resultados finais
    printf("\nMaior nota final: %d (Matrícula: %d)\n", maiorNota, matriculaMaiorNota);
    printf("Média das notas finais: %.2f\n", somaNotas / 5.0);

    return 0;
}
