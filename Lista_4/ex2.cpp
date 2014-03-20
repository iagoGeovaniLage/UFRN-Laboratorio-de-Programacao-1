/*
 * Escreva uma função chamada Compare(), que recebe dois elementos como
 * parâmetro e retorna 0 se eles são iguais, 1 se o primeiro elemento é maior e -1 se o
 * primeiro elemento for menor que o segundo, esta função deve ser capaz de trabalhar
 * com os tipos de dados float, int e char.
 */

#include <iostream>
// inclusão de alguns metodos do namespace std
	using std::cout;
	using std::cin;

// Criação de uma função usando esse tipo genérico de variável
	template <typename Tipo>
	int Compare(Tipo a, Tipo b) { 
		if ( a == b ) return 0;
		else if( a > b ) return 1;
		else return -1;
	}

#include "aux_ex2.cpp" // incluí funções que serão usadas nos testes

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
			cout << "Digite dois números (int):";
				cin >> *int_1;
				cin >> *int_2;
		imprimi(Compare(*int_1, *int_2)); // imprimi o resultado da função para inteiros

		// leitura dos ponto-flutuantes
			cout << "Digite dois números (float):";
				cin >> *float_1;
				cin >> *float_2;
		imprimi(Compare(*float_1, *float_2)); // imprimi o resultado da função para ponto-fluantes

		// leitura dos char
			cout << "Digite dois caracteres:";
				cin >> *char_1;
				cin >> *char_2;
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