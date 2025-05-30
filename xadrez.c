#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Criado por: Pedro Rufino
// Aluno: 202503565627@alunos.unifavip.edu.br
// Descrição: Sistema criado e optimizado desde o nível novato ao nível mestre conforme as videoaulas e as solicitações evoluiram.
// Além disso, o sistema foi otimizado e modularizado para evitar repetições redundantes de código.

#define TAMANHO 8

// Símbolos Unicode para as peças de xadrez
#define TORRE_NEGRA   "♖"
#define BISPO_NEGRO   "♗"
#define CAVALO_NEGRO  "♘"
#define RAINHA_NEGRA  "♕"
#define REI_NEGRO     "♔"
#define PEÃO_NEGRO    "♙"
#define TORRE_BRANCA  "♜"
#define BISPO_BRANCO  "♝"
#define CAVALO_BRANCO "♞"
#define RAINHA_BRANCA "♛"
#define REI_BRANCO    "♚"
#define PEÃO_BRANCO   "♟"
#define VAZIO_CLARO   "·"
#define VAZIO_ESCURO  " "

// Tabuleiro de xadrez (8x8)
char *tabuleiro[TAMANHO][TAMANHO];

// Inicializa o tabuleiro vazio
void inicializarTabuleiro() {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = (i + j) % 2 == 0 ? VAZIO_CLARO : VAZIO_ESCURO;
        }
    }
}

// Imprime o tabuleiro atual
void imprimirTabuleiro() {
    printf("\n   a  b  c  d  e  f  g  h\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%s ", tabuleiro[i][j]);
        }
        printf("%d\n", 8 - i);
    }
    printf("   a  b  c  d  e  f  g  h\n\n");
}

// Coloca uma peça no tabuleiro
void colocarPeca(int linha, int coluna, char *peca) {
    if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
        tabuleiro[linha][coluna] = peca;
    }
}

// Função recursiva para o movimento da Torre
void moverTorre(int linha, int coluna, int casas) {
    if (casas <= 0) return;
    colocarPeca(linha, coluna + casas, TORRE_BRANCA);
    moverTorre(linha, coluna, casas - 1);
}

// Função recursiva para o movimento do Bispo
void moverBispo(int linha, int coluna, int casas) {
    if (casas <= 0) return;
    colocarPeca(linha - casas, coluna + casas, BISPO_BRANCO);
    moverBispo(linha, coluna, casas - 1);
}

// Função recursiva para o movimento da Rainha
void moverRainha(int linha, int coluna, int casas) {
    if (casas <= 0) return;
    colocarPeca(linha, coluna - casas, RAINHA_BRANCA);
    moverRainha(linha, coluna, casas - 1);
}

// Função para o movimento do Cavalo
void moverCavalo(int linha, int coluna) {
    // Movimento em L: 2 para cima, 1 para direita
    colocarPeca(linha - 2, coluna + 1, CAVALO_BRANCO);
}

int main() {
    // Configura locale para suportar caracteres Unicode
    setlocale(LC_ALL, "");

    // Posições iniciais (linha, coluna)
    int torre_linha = 0, torre_coluna = 0;
    int bispo_linha = 3, bispo_coluna = 3;
    int rainha_linha = 7, rainha_coluna = 7;
    int cavalo_linha = 4, cavalo_coluna = 4;

    // Inicializa e mostra tabuleiro vazio
    inicializarTabuleiro();
    printf("Tabuleiro Inicial Vazio:\n");
    imprimirTabuleiro();

    // Movimento da Torre
    inicializarTabuleiro();
    colocarPeca(torre_linha, torre_coluna, TORRE_BRANCA);
    moverTorre(torre_linha, torre_coluna, 5);
    printf("Movimento da Torre (5 casas para direita):\n");
    imprimirTabuleiro();

    // Movimento do Bispo
    inicializarTabuleiro();
    colocarPeca(bispo_linha, bispo_coluna, BISPO_BRANCO);
    moverBispo(bispo_linha, bispo_coluna, 5);
    printf("Movimento do Bispo (5 casas na diagonal):\n");
    imprimirTabuleiro();

    // Movimento da Rainha
    inicializarTabuleiro();
    colocarPeca(rainha_linha, rainha_coluna, RAINHA_BRANCA);
    moverRainha(rainha_linha, rainha_coluna, 8);
    printf("Movimento da Rainha (8 casas para esquerda):\n");
    imprimirTabuleiro();

    // Movimento do Cavalo
    inicializarTabuleiro();
    colocarPeca(cavalo_linha, cavalo_coluna, CAVALO_BRANCO);
    moverCavalo(cavalo_linha, cavalo_coluna);
    printf("Movimento do Cavalo (em L: 2 cima, 1 direita):\n");
    imprimirTabuleiro();

    return 0;
}