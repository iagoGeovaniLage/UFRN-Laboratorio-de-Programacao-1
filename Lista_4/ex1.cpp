/*
 * Escreva uma só função que seja capaz de somar elementos do tipo float e
 * elementos do tipo Int e retornar o resultado.
 */

#include <iostream>
// inclusão de alguns metodos do namespace std
	using std::cout;
	using std::cin;

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
			cout << "Digite dois números (int):";
				cin >> *num1;
				cin >> *num2;

		// leitura dos ponto-flutuantes
			cout << "Digite dois números (float):";
				cin >> *num3;
				cin >> *num4;

		// mostrando os resultados
			cout << "A soma é: " << soma(*num1, *num2) << " (int)\n";
			cout << "A soma é: " << soma(*num3, *num4) << " (float)\n";

		// desalocando as variáveis
			delete num1;
			delete num2;
			delete num3;
			delete num4;

		return 0;	
	}