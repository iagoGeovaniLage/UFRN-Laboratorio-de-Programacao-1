/*
 * Escreva uma só função que seja capaz de somar elementos do tipo float e
 * elementos do tipo Int e retornar o resultado.
 */

#include <iostream>

// Definição de um tipo de variável genérica
	template <typename Tipo>
// Criação de uma função usando esse tipo genérico de variável
	Tipo soma(Tipo a, Tipo b) { return a + b; }

// Programa Principal
	int main(){

		// alocação dinâmica de variáveis
			// tipo Int
				int *num1 = new int;
				int *num2 = new int;

			// tipo Float
				float *num3 = new float;
				float *num4 = new float;

		// leitura dos inteiros
			std::cout << "Digite dois números (int):";
				std::cin >> *num1;
				std::cin >> *num2;

		// leitura dos ponto-flutuantes
			std::cout << "Digite dois números (float):";
				std::cin >> *num3;
				std::cin >> *num4;

		// mostrando os resultados
			std::cout << "A soma é: " << soma(*num1, *num2) << " (int)\n";
			std::cout << "A soma é: " << soma(*num3, *num4) << " (float)\n";

		// desalocando as variáveis
			delete num1;
			delete num2;
			delete num3;
			delete num4;

		return 0;	
	}