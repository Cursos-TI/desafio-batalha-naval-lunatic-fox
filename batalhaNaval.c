#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível: Mestre

// Área do tabuleiro
#define boardArea 10

// Área de efeito
#define effectArea 5

// Tabuleiro 10x10
int board[boardArea][boardArea];

// Ponto central da área de efeito
int middlePoint = effectArea / 2;

// Separador de linha
void sep() {
  printf("\n---\n\n");
}

// Zerar tabuleiro
void resetBoard() {
  for(int i = 0; i < boardArea; i++)
    for(int j = 0; j < boardArea; j++)
     board[i][j] = 0;
}

// Mostrar tabuleiro
void showBoard() {
  for(int i = 0; i < boardArea; i++) {
    for(int j = 0; j < boardArea; j++)
      printf("%i ", board[i][j]);
    printf("\n");
  }
}

// Mostrar e zerar tabuleiro
void showAndResetBoard(int separator) {
  showBoard();
  resetBoard();
  if (separator == 1) 
   sep();
}


// Habilidade cruz 5x5
void crossAbility(int x, int y) {
  // Vertical start - Início vertical do efeito
  int vs = y - middlePoint;
  vs = vs < 0 ? 0 : vs;

  // Vertical end - Fim vertical do efeito
  int ve = y + effectArea - middlePoint;

  // Horizontal start - Início horizontal do efeito
  int hs = x - middlePoint;
  hs = hs < 0 ? 0 : hs;

  // Horizontal end - Fim horizontal do efeito
  int he = x + effectArea - middlePoint;


  for(vs; vs < ve; vs++) {
    board[vs][x] = 1;
    for(hs; hs < he; hs++)
      board[y][hs] = 1;
  }
}

// Habilidade triângulo 5x5
void triangleAbility(int x, int y) {
  // Vertical start - Início vertical do efeito
  int vs = y;
  
  // Horizontal start - Início horizontal do efeito
  int hs = x - middlePoint;
  hs = hs < 0 ? 0 : hs;
  
  // Vertical end - Fim vertical do efeito
  int ve = vs + effectArea;
  
  // Horizontal end - Fim horizontal do efeito
  int he = hs + effectArea;

  // Expansion - Expansão do efeito
  int exp;

  // Variable vertical start - Início variável vertical do efeito
  int vvs;

  // Variable horizontal start - Início variável horizontal do efeito
  int vhs;

  for(vvs = vs, exp = 0; vvs < ve - middlePoint; vvs++, exp++) {
    // Effect start - Início do efeito
    int eS = hs + middlePoint - exp;

    // Effect end - Fim do efeito
    int eE = he - middlePoint + exp;

    for(vhs = hs; vhs < he; vhs++) 
      if (vhs >= eS && vhs < eE)
        board[vvs][vhs] = 1;
  }
}

// Habilidade losango 5x5
void diamondAbility(int x, int y) {
  // Vertical start - Início vertical do efeito
  int vs = y - middlePoint;
  vs = vs < 0 ? 0 : vs;
  
  // Horizontal start - Início horizontal do efeito
  int hs = x - middlePoint;
  hs = hs < 0 ? 0 : hs;
  
  // Vertical end - Fim vertical do efeito
  int ve = vs + effectArea;
  
  // Horizontal end - Fim horizontal do efeito
  int he = hs + effectArea;

  // Expansion - Expansão do efeito
  int exp;

  // Variable vertical start - Início variável vertical do efeito
  int vvs;

  // Variable horizontal start - Início variável horizontal do efeito
  int vhs;

  for(vvs = vs + middlePoint, exp = effectArea; vvs < ve; vvs++, exp--) {
    // Effect start - Início do efeito
    int eS = he - exp;

    // Effect end - Fim do efeito
    int eE = hs + exp;

    for(vhs = hs; vhs < he; vhs++) 
      if (vhs >= eS && vhs < eE)
        board[vvs][vhs] = 1;
  }

  triangleAbility(x, y - middlePoint);
}

// Inserir navios no tabuleiro
void insertShips() {
  // Navio vertical: [3, 4] [4, 4] [5, 4]
  for(int x = 3; x < 6; x++)
    board[x][4] = 3;
  
  // Navio horizontal: [1, 3] [1, 4] [1, 5]
  for(int y = 3; y < 6; y++)
    board[1][y] = 3;

  // Navio diagonal 1: [5, 1] [6, 2] [7, 3]
  for(int x = 5, y = 1; x < 8, y < 4; x++, y++)
    board[x][y] = 3;
  
  // Navio diagonal 2: [3, 8] [4, 7] [5, 6]
  for(int x = 3, y = 8; x < 6, y > 5; x++, y--)
    board[x][y] = 3;
}

int main() {
  // Inicialização do tabuleiro
  resetBoard();

  printf("Habilidade de cruz\n");
  crossAbility(3, 4);
  showAndResetBoard(1);

  printf("Habilidade de triângulo\n");
  triangleAbility(3, 4);
  showAndResetBoard(1);

  printf("Habilidade de losango\n");
  diamondAbility(4, 3);
  showAndResetBoard(1);

  printf("Tabuleiro com os navios\n");
  insertShips();
  showAndResetBoard(1);
  
  printf("Tabuleiro com as habilidades\n");
  crossAbility(2, 2);
  triangleAbility(7, 1);
  diamondAbility(6, 7);
  
  for(int x = 0; x < boardArea; x++)
    for(int y = 0; y < boardArea; y++)
      if (board[x][y] == 1)
        board[x][y] = 5;
  
  showBoard();
  sep();

  printf("Tabuleiro com os navios e habilidades\n");
  insertShips();
  showAndResetBoard(0);

  return 0;
}
