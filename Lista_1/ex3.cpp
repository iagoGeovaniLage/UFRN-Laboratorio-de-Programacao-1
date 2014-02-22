/* 
 * Seja um labirinto descrito através de uma matriz de booleanos, onde cada posição com
 * valor igual a verdadeiro corresponde a uma passagem livre e uma posição falsa representa
 * uma obstrução. Escreva um algoritmo que encontre um caminho que leve uma posição inicial
 * qualquer a uma saída do labirinto, caso exista. Uma saída é uma posição livre na borda da
 * matriz que define o labirinto. Indique em seguida qual tipo de recursão está sendo utilizada no
 * algoritmo desenvolvido.
 */
#include <iostream>
int buscaSaida(int lab, int i, int j){
	
}
int main(){
 	int *i = new int;
 	int *j = new int;
	// Alocação da matriz
		int **lab = new int *[5];
		for(*i = 0; *i < 5; (*i)++){
			lab[*i] = new int[6];
		}

	// criação do labirinto
		lab[0][0] = 0; lab[0][1] = 0; lab[0][2] = 0; lab[0][3] = 0; lab[0][4] = 0; lab[0][5] = 0;
		lab[1][0] = 1; lab[1][1] = 1; lab[1][2] = 1; lab[1][3] = 1; lab[1][4] = 0; lab[1][5] = 0;
		lab[2][0] = 0; lab[2][1] = 1; lab[2][2] = 0; lab[2][3] = 0; lab[2][4] = 0; lab[2][5] = 0;
		lab[3][0] = 0; lab[3][1] = 1; lab[3][2] = 1; lab[3][3] = 1; lab[3][4] = 1; lab[3][5] = 0;
		lab[4][0] = 0; lab[4][1] = 0; lab[4][2] = 0; lab[4][3] = 0; lab[4][4] = 1; lab[4][5] = 0;

	for(*i = 0; *i < 5; (*i)++) {
		for(*j = 0; *j < 6; (*j)++ )
			std::cout << lab[*i][*j];
		std::cout << "\n";
	}

	// desalocação das variáveis
		delete i;
		delete j;
		delete lab;

 	return 0;
}