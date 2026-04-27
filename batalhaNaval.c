#include <stdio.h>

#define TAM 10
#define NAVIO_TAM 3

int main() {

    // =========================
    // TABULEIRO 10x10
    // =========================
    int tabuleiro[TAM][TAM];

    // Inicializa tudo com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // =========================
    // NAVIOS (vetores)
    // =========================
    int navioHorizontal[NAVIO_TAM] = {3, 3, 3};
    int navioVertical[NAVIO_TAM] = {3, 3, 3};

    // =========================
    // COORDENADAS INICIAIS
    // =========================
    int linhaH = 2, colunaH = 3; // horizontal
    int linhaV = 5, colunaV = 1; // vertical

    // =========================
    // VALIDAÇÃO SIMPLES (limite)
    // =========================
    if (colunaH + NAVIO_TAM > TAM) {
        printf("Erro: navio horizontal sai do tabuleiro!\n");
        return 1;
    }

    if (linhaV + NAVIO_TAM > TAM) {
        printf("Erro: navio vertical sai do tabuleiro!\n");
        return 1;
    }

    // =========================
    // POSICIONAR NAVIO HORIZONTAL
    // =========================
    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tabuleiro[linhaH][colunaH + i] == 0) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        } else {
            printf("Erro: sobreposição de navios!\n");
            return 1;
        }
    }

    // =========================
    // POSICIONAR NAVIO VERTICAL
    // =========================
    for (int i = 0; i < NAVIO_TAM; i++) {
        if (tabuleiro[linhaV + i][colunaV] == 0) {
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        } else {
            printf("Erro: sobreposição de navios!\n");
            return 1;
        }
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