#include <stdio.h>

#define ALUNOS 4
#define PROVAS 3

void lernotas(float notas[ALUNOS][PROVAS]) {
    for (int i = 0; i < ALUNOS; i++) {
        printf("Aluno %d:\n", i + 1);
        for (int j = 0; j < PROVAS; j++) {
            printf("  Nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }
}

float mediaaluno(float notas[PROVAS]) {
    float soma = 0;
    for (int i = 0; i < PROVAS; i++) {
        soma += notas[i];
    }
    return soma / PROVAS;
}

float mediaturma(float notas[ALUNOS][PROVAS]) {
    float soma = 0;
    for (int i = 0; i < ALUNOS; i++) {
        soma += mediaaluno(notas[i]);
    }
    return soma / ALUNOS;
}

int main() {
    float notas[ALUNOS][PROVAS];
    float maior = 0, menor = 10;
    lernotas(notas);

    printf("\nMedias dos alunos:\n");
    for (int i = 0; i < ALUNOS; i++) {
        float media = mediaaluno(notas[i]);
        printf("Aluno %d: %.2f\n", i + 1, media);

        if (media > maior) maior = media;
        if (media < menor) menor = media;
    }

    printf("\nMedia da turma: %.2f\n", mediaturma(notas));
    printf("Maior media: %.2f\n", maior);
    printf("Menor media: %.2f\n", menor);

    return 0;
}
