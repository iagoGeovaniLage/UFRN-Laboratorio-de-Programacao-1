/*
 * Implemente o algoritmo de Busca Binária que seja capaz de encontrar um
 * elemento em um array genérico. Você pode utilizar o código do exercício 9 e a função
 * do exercício 2 juntamente com templates para agilizar na implementação.
 */

#include <iostream>
// inclusão de alguns namespaces
	using std::cout;
	using std::cin;

// Criação de uma função usando esse tipo genérico de variável
	template <typename Tipo>
	int Compare(Tipo a, Tipo b) { 
		if ( a == b ) return 0;
		else if( a > b ) return 1;
		else return -1;
	}

// função de busca binária em um vetor genérico
	template < typename T>
	int buscaBinaria(T v[], long int N, T x){
		int limInf, limSup, meio;
		limInf = 0;
		limSup = N-1;
		while(Compare(limInf,limSup) <= 0){
			meio =  (limInf + limSup) / 2;
			if(Compare(v[meio],x) == 0){
				return 1; 
			} else {
				if(Compare(v[meio],x) == -1) {
					limInf = meio + 1;
				} else {
					limSup = meio - 1;
				}
			}
		}
		return 0;
	}

#include "aux_ex13.cpp" // incluí funções que serão usadas nos testes

int main(){
	// alocañdo e inicializando variável de tamanho dos arrays pela entrada padrão
		int *tam = new int;
			cout << "Digite o tamanho dos vetores para os testes: ";
			cin >> *tam;
	// alocando os vetores para os testes
		int   *vet_int   = new int[*tam]; // inteiro
		char  *vet_char  = new char[*tam]; // caracter
		float *vet_float = new float[*tam]; // ponto-flutuante

	// gerando os array para testes
		geraArray(vet_int, *tam);
		geraArray(vet_char, *tam);
		geraArray(vet_float, *tam);

	// alocando e gerando elementos para serem buscados nos vetores
		int *num_i = new int;
			geraElemento(*tam, num_i);
		char *car = new char;
			geraElemento(*tam, car);
		float *num_f = new float;
			geraElemento(*tam, num_f);

	// fazendo os testes
		imprimi(vet_int, *tam, *num_i); // inteiros
		imprimi(vet_char, *tam, *car); // caracter
		imprimi(vet_float, *tam, *num_f); // ponto flutuante

	// desalocando todas as variáveis
		delete tam;
		delete vet_int;
		delete vet_float;
		delete vet_char;
		delete num_f;
		delete num_i;
		delete car;

	return 0;
}