/* 
 *
 * Seja um labirinto descrito através de uma matriz de booleanos, 
 * onde cada posição com valor igual a verdadeiro corresponde a uma passagem livre
 * e uma posição falsa representa uma obstrução.
 *
 * Escreva um algoritmo que encontre um caminho que leve uma posição inicial
 * qualquer a uma saída do labirinto, caso exista.
 * Uma saída é uma posição livre na borda da matriz que define o labirinto.
 *
 * Indique em seguida qual tipo de recursão está sendo utilizada no algoritmo desenvolvido.
 *
 */

#include <iostream>
#include <cstdlib> // para usar a função rand()

// Definição das LINHAS X COLUNAS do labirinto
	#define LINHAS 10 // quantidade de linhas do labirinto
	#define COLUNAS 10 // quantidade de colunas do labirinto

/*
 * Função para buscar possível saída do labirinto.
 * Adaptada do código feito pela aluna Karydja
 */
	bool buscaSaida(int xAnterior, int yAnterior, int xAtual, int yAtual, bool **lab) {
	 	if (lab[xAtual][yAtual]) { //Se o ponto for valido
	 		if (xAtual == 0 || xAtual == LINHAS - 1 || yAtual == 0 || yAtual == COLUNAS - 1) //Se o ponto estiver em alguma borda já é uma saida
				return true;
			else {
				lab[xAnterior][yAnterior] = false; // Anulando o ponto anterior, para que nao seja visitado novamente

				// cria os ponto de verificação
					int *cimaX     = new int; 
					int *cimaY     = new int; 
					int *baixoX    = new int; 
					int *baixoY    = new int; 
					int *direitaX  = new int; 
					int *direitaY  = new int; 
					int *esquerdaX = new int; 
					int *esquerdaY = new int;
					// ponto acima do atual
						*cimaX     = xAtual;
						*cimaX     = yAtual - 1;
					// ponto a direita da atual
						*direitaX  = xAtual + 1;
						*direitaY  = yAtual;
					// ponto abaixo do atual
						*baixoX    = xAtual;
						*baixoY    = yAtual + 1;
					// ponto a esquerda do atual
						*esquerdaX = xAtual - 1;
						*esquerdaY = yAtual;
				
				//Realizando chamadas recursivas para os pontos adjacentes
					bool a, b, c, d;
					a = buscaSaida(xAtual, yAtual, *cimaX, *cimaY, lab);
					b = buscaSaida(xAtual, yAtual, *direitaX, *direitaY, lab);
					c = buscaSaida(xAtual, yAtual, *baixoX, *baixoY, lab);
					d = buscaSaida(xAtual, yAtual, *esquerdaX, *esquerdaY, lab);
				
				if (a || b || c || d) // verifica se pelo menos um dos pontos é válido
	               return true;
	            else
	       	       return false;
			}
	 	} else // Se o ponto nao for valido
			return false;
	}

int main(){
 	// alocação das variáveis
	 	int *i        = new int;
	 	int *j        = new int;
	 	int *posicaoX = new int;
	 	int *posicaoY = new int;

		// Alocação da matriz
			bool **lab = new bool *[LINHAS];
			for(*i = 0; *i < LINHAS; (*i)++){
				lab[*i] = new bool[COLUNAS];
			}
	// Criação do labirinto
		for(*i = 0; *i < LINHAS; (*i)++) {
			for(*j = 0; *j < COLUNAS; (*j)++){
				lab[*i][*j] = rand()%2; // gera elementos da matriz de forma aleatória
				std::cout << lab[*i][*j] << " ";	 	  
			}
	 		std::cout << std::endl;
		}
	// Posição inicial no labirinto
		std::cout << "Informe a linha inicial: ";
		std::cin >> *posicaoX;
		std::cout << "Informe a coluna inicial: ";
		std::cin >> *posicaoY;

	// Chamada da função para verificar se há saída para o labirinto
		if(buscaSaida(*posicaoX, *posicaoY,*posicaoX, *posicaoY, lab))
	    	std::cout << "Existe solucao para o labirinto!\n";
	    else
	    	std::cout << "Não existe solucao para o labirinto!\n";

	// desalocação das variáveis
		delete i;
		delete j;
		delete lab;
		delete posicaoX;
		delete posicaoY;

 	return 0;
}
