#include <stdio.h>

#define TAMANHO 10   // Tamanho fixo do tabuleiro 10x10
#define NAVIO 3      // Valor que representa parte do navio
#define AGUA 0       // Valor que representa água
#define TAM_NAVIO 3  // Cada navio ocupa 3 posições

int main() {
    int tabuleiro[TAMANHO][TAMANHO]; // Matriz que representa o tabuleiro
    int i, j;

    // 1️⃣ Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // 2️⃣ Define as coordenadas iniciais dos navios
    // Navio 1 → Horizontal
    int linha_h = 2;   // linha inicial (0 a 9)
    int coluna_h = 4;  // coluna inicial (0 a 9)

    // Navio 2 → Vertical
    int linha_v = 5;   // linha inicial
    int coluna_v = 7;  // coluna inicial

    // 3️⃣ Verifica se os navios cabem no tabuleiro
    if (coluna_h + TAM_NAVIO > TAMANHO) {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    if (linha_v + TAM_NAVIO > TAMANHO) {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // 4️⃣ Posiciona o navio horizontal
    for (j = 0; j < TAM_NAVIO; j++) {
        tabuleiro[linha_h][coluna_h + j] = NAVIO;
    }

    // 5️⃣ Posiciona o navio vertical (sem sobreposição)
    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_v + i][coluna_v] == NAVIO) {
            printf("Erro: Navios se sobrepõem! Corrija as coordenadas.\n");
            return 1;
        }
        tabuleiro[linha_v + i][coluna_v] = NAVIO;
    }

    // 6️⃣ Exibe o tabuleiro visualmente
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    // Cabeçalho com números das colunas
    printf("    ");
    for (j = 0; j < TAMANHO; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    // Linha separadora
    printf("   -----------------------------------------\n");

    for (i = 0; i < TAMANHO; i++) {
        printf("%2d | ", i); // Mostra o número da linha
        for (j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == AGUA)
                printf("~  ");  // Representa água
            else
                printf("█  ");  // Representa parte do navio
        }
        printf("\n");
    }

    printf("\nLegenda: ~ = Água | █ = Navio\n\n");

    return 0;
}
