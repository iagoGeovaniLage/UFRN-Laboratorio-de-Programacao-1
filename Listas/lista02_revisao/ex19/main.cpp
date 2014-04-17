#include <iostream>
#include <cstdlib> // para uso da função rand()
#include <string>
#include <cstdio> // para uso da função getchar() que esperará um enter para movimentar a pista

// funções utilizadas no programa
	#include "funcoes.h"

// classes
	#include "Lebre.h" // classe Lebre
	#include "Tartaruga.h"// classe Tartaruga

// inclusão de alguns metódos do namespace std
	using std::cout;
	using std::cin;
	using std::endl;

// programa principal
	int main() {

	    srand(time(NULL)); // para uso da função rand()

		// competidores 
			Lebre lebre; // 1
			Tartaruga tartaruga; // 2
		// variavel da posicao de cada competidor
			int posLebre;
			int posTartaruga;

		// tamanho da pista e do laço de impressão da corrida
			int tam, n;

		// definição do tamanho da pista pelo usuário
			cout << "Digite o tamanho da pista: ";
				cin >> tam;

		// enquanto nenhum dos dois competidores ultrapassar o fim da pista mudar posição
			while(lebre.getPosicao() < tam && tartaruga.getPosicao() < tam){
				// gera posição da Lebre
					lebre.Movimento(geraNum());
				    posLebre = lebre.getPosicao();
				// gera posição da tartaruga
				    tartaruga.Movimento(geraNum());
				    posTartaruga = tartaruga.getPosicao();

				//determina onde está o mais bem posicionado
					n = tamanho(posLebre, posTartaruga);
			    
			    // mostra como está a corrida até o momento
					corrida(n, posLebre, posTartaruga);
			    getchar(); // espera um enter para continuar a corrida (opcional)
			}
		// condicional para saber quem ganho ou se houve empate
			if(posLebre == posTartaruga) // empate
				cout << "É Empate!\n";
			else if(posLebre > posTartaruga) // ganhou a Lebre
				cout << "Lebre ganha. Ohhh....\n";
			else  // ganhou a Tartaruga
				cout << "TARTARUGA VENCE!!! VALEU!!!\n";
	}