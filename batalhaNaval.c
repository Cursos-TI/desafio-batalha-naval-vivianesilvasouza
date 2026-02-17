#include <stdio.h>

// Definição de constantes para facilitar a manutenção
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // 1. Representar o Tabuleiro: Matriz 10x10 inicializada com 0
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializando o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2. Posicionar os Navios
    // Coordenadas iniciais (definidas no código conforme o nível básico)
    int navioHorizontalLinha = 2, navioHorizontalColuna = 2;
    int navioVerticalLinha = 5, navioVerticalColuna = 7;

    // Posicionando Navio Horizontal
    // Verificamos se cabe no tabuleiro (coluna inicial + tamanho <= limite)
    if (navioHorizontalColuna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            tabuleiro[navioHorizontalLinha][navioHorizontalColuna + j] = NAVIO;
        }
    }

    // Posicionando Navio Vertical
    // Verificamos se cabe (linha inicial + tamanho <= limite) e se não sobrepõe
    if (navioVerticalLinha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Validação simples de sobreposição
            if (tabuleiro[navioVerticalLinha + i][navioVerticalColuna] == AGUA) {
                tabuleiro[navioVerticalLinha + i][navioVerticalColuna] = NAVIO;
            }
        }
    }

    // 3. Exibir o Tabuleiro
    printf("--- BATALHA NAVAL (NÍVEL NOVATO) ---\n\n");
    
    // Cabeçalho das colunas para facilitar a leitura
    printf("    ");
    for(int j = 0; j < TAMANHO_TABULEIRO; j++) printf("%d ", j);
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d | ", i); // Índice da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}