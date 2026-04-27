#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3

int main() {

     printf("RODANDO CODIGO NOVO\n");
    // =========================
    // TABULEIRO
    // =========================
    int tabuleiro[TAM][TAM];

    // Inicializa com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // =========================
    // NAVIO (valor 3)
    // =========================
    int navio[NAVIO_TAM] = {3, 3, 3};

    // =========================
    // COORDENADAS (sem conflito)
    // =========================

    // Horizontal
    int linhaH = 1, colunaH = 2;

    // Vertical
    int linhaV = 5, colunaV = 0;

    // Diagonal ↘
    int linhaD1 = 0, colunaD1 = 0;

    // Diagonal ↙
    int linhaD2 = 0, colunaD2 = 9;

    // =========================
    // VALIDAÇÃO DE LIMITES
    // =========================
    if (colunaH + NAVIO_TAM > TAM ||
        linhaV + NAVIO_TAM > TAM ||
        linhaD1 + NAVIO_TAM > TAM || colunaD1 + NAVIO_TAM > TAM ||
        linhaD2 + NAVIO_TAM > TAM || colunaD2 - (NAVIO_TAM - 1) < 0) {

        printf("Erro: navio fora do tabuleiro!\n");
        return 1;
    }

    // =========================
    // NAVIO HORIZONTAL
    // =========================
    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            printf("Erro: sobreposição!\n");
            return 1;
        }
        tabuleiro[linhaH][colunaH + i] = navio[i];
    }

    // =========================
    // NAVIO VERTICAL
    // =========================
    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: sobreposição!\n");
            return 1;
        }
        tabuleiro[linhaV + i][colunaV] = navio[i];
    }

    // =========================
    // NAVIO DIAGONAL ↘
    // =========================
    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {
            printf("Erro: sobreposição!\n");
            return 1;
        }
        tabuleiro[linhaD1 + i][colunaD1 + i] = navio[i];
    }

    // =========================
    // NAVIO DIAGONAL ↙
    // =========================
    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
            printf("Erro: sobreposição!\n");
            return 1;
        }
        tabuleiro[linhaD2 + i][colunaD2 - i] = navio[i];
    }

    // =========================
    // EXIBIR TABULEIRO
    // =========================
    printf("\nTabuleiro:\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

