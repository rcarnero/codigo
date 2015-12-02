#include <stdio.h>
#include <stdlib.h>

char tabuleiro[8][8];
int dirP[2][2] = {{-1,-1},{-1,1}};
int dirB[2][2] = {{1,1},{1,-1}};
int dirD[4][2] = {{-1,-1},(-1,1), {1,1}, {1,-1}};
int x,y,x2,y2;
int countP = 0;
int countB = 0;

void imprimir_mapa() {
	int i, j;
    for(i = 0; i < 8; i++) {
			for(j = 0; j < 8; j++) {
				printf("%c", tabuleiro[i][j]);
			}
			printf("\n");
		}
}

void receber_mov() {

}

void gerar_tabuleiro() {
	int i, j;
	for(i = 0; i < 8; i++) {
		if(i%2 == 0) j = 0;
		else j = 1;

		for(j; j < 8; j+=2) {
			tabuleiro[i][j] = 177;
		}
	}
}

void colocar_pecas() {
	int i, j;
	for(i = 0; i < 8; i++) {
		if(i%2 == 0) j = 1;
		else j = 0;

		for(j; j < 8 && i < 3; j+= 2) {
			tabuleiro[i][j] = 'B';
		}
		for(j; j < 8 && i > 4; j+= 2) {
			tabuleiro[i][j] = 'P';
		}
	}
}

int movimentar(int jogador,int i, int j, int x2, int y2) {
	
	if(x2 < 0 || x2 >= 8) return 0;
	if(y2 < 0 || y2 >= 8) return 0;
	if(tabuleiro[x2][y2] == 177 || tabuleiro[x2][y2] == 'B' || tabuleiro[x2][y2] == 'P') return 0;
	
		if(i < 0 || i >= 8) return 0;
		if(j < 0 || j >= 8) return 0;

		if(i == x2 && j == y2 && jogador == 1) {
			tabuleiro[x2][y2] = 'P';
			tabuleiro[x][y] = ' ';
			return 1;
		} else if(i == x2 && j == y2 && jogador == 2) {
			tabuleiro[x2][y2] = 'B';
			tabuleiro[x][y] = ' ';
			return 1;
		}
		
		int w;
		if(jogador == 1) {
			for(w = 0; w < 2; w++) {
				if(movimentar(1, i+dirP[0][w], j+dirP[1][w], x2, y2) && tabuleiro[i][j] == 'B') {
					countP++;
					tabuleiro[i][j] = ' ';
				}
			}
		} else {
			for(w = 0; w < 2; w++) {
				if(movimentar(2, i+dirB[0][w], j+dirB[1][w], x2, y2) && tabuleiro[i][j] == 'P') {
					countB++;
					tabuleiro[i][j] = ' ';
				}
			}
		}

}

int main() {
	gerar_tabuleiro();
	colocar_pecas();
	int i, j;
	int n = 3;
	int jogador = 1;
	

	imprimir_mapa();

	while(n--) {
		printf("Jogador %d:\n", jogador);
		scanf("%d%d%d%d", &x, &y, &x2, &y2);

		if(!movimentar(jogador, x, y, x2, y2)) printf("Posicao impossivel de ser acessada\n");

		imprimir_mapa();

		if(n%2 == 1) jogador = 1;
		else jogador = 2;
	}
	return 0;
}
