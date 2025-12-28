#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível: Novato

int main() {
  int board[10][10];

  // Inicialização do tabuleiro
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
     board[i][j] = 0;

  // Navio vertical: [3, 4] [4, 4] [5, 4]
  for(int x = 3; x < 6; x++)
    board[x][4] = 3;
  
  // Navio horizontal: [1, 3] [1, 4] [1, 5]
  for(int y = 3; y < 6; y++)
    board[1][y] = 3;

  // Exibição do tabuleiro
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++)
      printf("%i ", board[i][j]);
    printf("\n");
  }

  return 0;
}
