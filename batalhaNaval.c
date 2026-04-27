#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3
#define HAB_TAM 5

int main() {

    int tabuleiro[TAM][TAM];

    // =========================
    // INICIALIZA TABULEIRO
    // =========================
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // =========================
    // NAVIOS (mesmo do nível anterior)
    // =========================
    int navio[NAVIO_TAM] = {3,3,3};

    // Horizontal
    for (int i = 0; i < NAVIO_TAM; i++)
        tabuleiro[1][2+i] = navio[i];

    // Vertical
    for (int i = 0; i < NAVIO_TAM; i++)
        tabuleiro[5+i][0] = navio[i];

    // Diagonal ↘
    for (int i = 0; i < NAVIO_TAM; i++)
        tabuleiro[0+i][0+i] = navio[i];

    // Diagonal ↙
    for (int i = 0; i < NAVIO_TAM; i++)
        tabuleiro[0+i][9-i] = navio[i];

    // =========================
    // MATRIZES DE HABILIDADE
    // =========================

    int cone[HAB_TAM][HAB_TAM];
    int cruz[HAB_TAM][HAB_TAM];
    int octaedro[HAB_TAM][HAB_TAM];

    // CONE (aponta pra baixo)
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (j >= (HAB_TAM/2 - i) && j <= (HAB_TAM/2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // CRUZ
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            if (i == HAB_TAM/2 || j == HAB_TAM/2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // OCTAEDRO (losango)
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {
            int centro = HAB_TAM / 2;
            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // =========================
    // POSIÇÕES DAS HABILIDADES
    // =========================
    int origemConeLinha = 4, origemConeCol = 4;
    int origemCruzLinha = 7, origemCruzCol = 7;
    int origemOctLinha = 2, origemOctCol = 7;

    // =========================
    // SOBREPOR HABILIDADES
    // =========================

    // Cone
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {

            int linha = origemConeLinha + i - HAB_TAM/2;
            int col = origemConeCol + j - HAB_TAM/2;

            if (linha >= 0 && linha < TAM && col >= 0 && col < TAM) {
                if (cone[i][j] == 1 && tabuleiro[linha][col] == 0) {
                    tabuleiro[linha][col] = 5;
                }
            }
        }
    }

    // Cruz
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {

            int linha = origemCruzLinha + i - HAB_TAM/2;
            int col = origemCruzCol + j - HAB_TAM/2;

            if (linha >= 0 && linha < TAM && col >= 0 && col < TAM) {
                if (cruz[i][j] == 1 && tabuleiro[linha][col] == 0) {
                    tabuleiro[linha][col] = 5;
                }
            }
        }
    }

    // Octaedro
    for (int i = 0; i < HAB_TAM; i++) {
        for (int j = 0; j < HAB_TAM; j++) {

            int linha = origemOctLinha + i - HAB_TAM/2;
            int col = origemOctCol + j - HAB_TAM/2;

            if (linha >= 0 && linha < TAM && col >= 0 && col < TAM) {
                if (octaedro[i][j] == 1 && tabuleiro[linha][col] == 0) {
                    tabuleiro[linha][col] = 5;
                }
            }
        }
    }

    // =========================
    // EXIBIR TABULEIRO
    // =========================
    printf("\nTabuleiro Final:\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            if (tabuleiro[i][j] == 0)
                printf("~ "); // água
            else if (tabuleiro[i][j] == 3)
                printf("N "); // navio
            else if (tabuleiro[i][j] == 5)
                printf("* "); // habilidade

        }
        printf("\n");
    }

    return 0;
}