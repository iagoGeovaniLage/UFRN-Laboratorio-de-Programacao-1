#include <iostream>
#include <cstdlib> // para uso da função rand()

using std::cout;

// funcao que gera um numero aleatorio entre 1 e 10
	int geraNum() {
	    return (rand() % 10) + 1;
	}

// Função que determina tamanho de laço da corrida
	int tamanho(int posL, int posT) {
		if(posL > posT) return posL;
		else if(posL < posT) return posT;
		else return posT;
	}

// função que imprime a condição da corrida
	void corrida(int n, int posL, int posT) {
		for(int i = 0; i <= n; i++) {
			if(i == posT && i == posL)
				cout << "Ai!!!";
			else if(i == posL)
				cout << "L";
			else if(i == posT)
				cout << "T";
			else
				cout << " ";
		}
		cout << "\n";
	}