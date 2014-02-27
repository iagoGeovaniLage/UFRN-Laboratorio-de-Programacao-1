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
#include <stack> // para usar uma pilha para guardar os pontos válidos percorridos na matriz

// Definição das LINHAS X COLUNAS do labirinto
	#define LINHAS 10 // quantidade de linhas do labirinto
	#define COLUNAS 10 // quantidade de colunas do labirinto

// Estrutura feita para declarar um ponto
	typedef struct {
		int x;
		int y;
	} Ponto;

/*
 * Função para buscar possível saída do labirinto.
 * Adaptada do código feito pela aluna Karydja
 */
	bool buscaLabirinto (Ponto anterior, Ponto atual, bool **lab, std::stack<Ponto>& pilha) {
	 	pilha.push(atual);
	 	if (lab[atual.x][atual.y]) { // Se o ponto for TRUE
	 		if (atual.x == 0 || atual.x == LINHAS - 1 || atual.y == 0 || atual.y == COLUNAS - 1) // Se o ponto estiver em alguma borda
	 			return true;
	 		else {
				lab[anterior.x][anterior.y] = false; // Anulando o ponto anterior, para que nao seja visitado novamente
				
				Ponto p1, p2, p3, p4;
					p1.x = atual.x; 		// p1 = ponto acima do atual
					p1.y = atual.y - 1;
					p2.x = atual.x + 1;		// p2 = ponto a direita da atual
					p2.y = atual.y;
					p3.x = atual.x;			// p3 = ponto abaixo do atual
					p3.y = atual.y + 1;
					p4.x = atual.x - 1;		// p4 = ponto a esquerda do atual
					p4.y = atual.y;
				
				// chamadas recursivas para os pontos adjacentes
					bool a, b, c, d;
					a = buscaLabirinto(atual, p1, lab, pilha);
					b = buscaLabirinto(atual, p2, lab, pilha);
					c = buscaLabirinto(atual, p3, lab, pilha);
					d = buscaLabirinto(atual, p4, lab, pilha);
				
				if (a || b || c || d)
	               return true;
	            else
	       	       return false;
			}
	 	} else { //Se o ponto for FALSE
			pilha.pop();
			return false;
	 	}
	}

int main(){
 	// alocação das variáveis
		Ponto *inicio = new Ponto;
	 	int *i        = new int;
	 	int *j        = new int;
		std::stack<Ponto> pilha;

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
		std::cin >> (*inicio).x;
		std::cout << "Informe a coluna inicial: ";
		std::cin >> (*inicio).y;

	// Chamada da função para verificar se há saída para o labirinto
		if(buscaLabirinto(*inicio, *inicio, lab, pilha)) {
	    	std::cout << "Existe solucao para o labirinto!\n";
	    	std::cout << "As coordenadas visitadas foram:";
	    	while (!pilha.empty()) {
	    		std::cout << "(" << pilha.top().x << "," << pilha.top().y << ") ";
	    		pilha.pop();
	    	}
	    } else
	    	std::cout << "Nao existe solucao para o labirinto!";

    std::cout << "\n"; // pula linha

	// desalocação das variáveis
		delete i;
		delete j;
		delete lab;
		delete inicio;

 	return 0;
}