/*
 * Escreva uma função chamada Compare(), que recebe dois elementos como
 * parâmetro e retorna 0 se eles são iguais, 1 se o primeiro elemento é maior e -1 se o
 * primeiro elemento for menor que o segundo, esta função deve ser capaz de trabalhar
 * com os tipos de dados float, int e char.
 */

#include <iostream>

// Criação de uma função usando esse tipo genérico de variável
	template <typename Tipo>
	int Compare(Tipo a, Tipo b) { 
		if ( a == b ) return 0;
		else if( a > b ) return 1;
		else return -1;
	}

// imprimir comparação
	void imprimi(int res) {
		switch(res){
			case 0:
				std::cout << "São iguais!\n";
				break;
			case 1:
				std::cout << "O primeiro é maior!\n";
				break;
			case -1:
				std::cout << "O segundo é maior!\n";
				break;
		}
	}

// Programa Principal
	int main(){

		// alocação dinâmica de variáveis
			// tipo Int
				int *int_1 = new int;
				int *int_2 = new int;

			// tipo Float
				float *float_1 = new float;
				float *float_2 = new float;

			// tipo char
				char *char_1 = new char;
				char *char_2 = new char;

		// leitura dos inteiros
			std::cout << "Digite dois números (int):";
				std::cin >> *int_1;
				std::cin >> *int_2;
		imprimi(Compare(*int_1, *int_2)); // imprimi o resultado da função para inteiros

		// leitura dos ponto-flutuantes
			std::cout << "Digite dois números (float):";
				std::cin >> *float_1;
				std::cin >> *float_2;
		imprimi(Compare(*float_1, *float_2)); // imprimi o resultado da função para ponto-fluantes

		// leitura dos char
			std::cout << "Digite dois caracteres:";
				std::cin >> *char_1;
				std::cin >> *char_2;
		imprimi(Compare(*char_1, *char_2)); // imprimi o resultado da função para ponto-fluantes

		// desalocando as variáveis
			delete int_1;
			delete int_2;
			delete float_1;
			delete float_2;
			delete char_1;
			delete char_2;

		return 0;	
	}