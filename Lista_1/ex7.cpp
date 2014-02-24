/*
 * Escreva uma função que recebe um valor n, cria dinamicamente um vetor de n elementos, e
 * retorna um ponteiro para este vetor. 
 *
 * Crie uma segunda função que receba um ponteiro para um vetor
 * e um valor n e imprima os n elementos desse vetor.
 *
 * Construa também uma função que receba um ponteiro para um vetor e libere a sua área de memória alocada.
 *
 * Ao final, crie uma função principal que leia um valor n e faça chamada às funções descritas acima para ler
 * os elementos, alocar memória dinamicamente, imprimir os elementos lidos e alocados e finalmente liberar a memória.
 */
#include <iostream>

// Função para alocação do vetor
	int * criaVetor(int n){
		// Alocando o vetor com o tamanho n
			int *v = new int[n];
		return v; // retorn o endereço do vetor
	}

// Função para preencher o vetor para teste de impressão
	void preencheVetor(int *v, int n){
		// preenche o vetor com números em sequencia
		for (int i = 0; i < n; ++i)
			v[i] = i+1;
	}

// Função para imprimir o vetor
	void imprimeVetor(int *v, int n){
		for (int i = 0; i < n; ++i) {
			std::cout << v[i];
			if(i != n-1)
				std::cout << " ";
		}
	}

// Função para desalocação do vetor
	void desalocaVetor(int *v){
		// Desalocando o vetor
			delete v;
	}


int main (){
	// Alocação das variáveis
		int   *n   = new int;
		int   *vet = new int;

	std::cout << "Tamanho do vetor: ";
	std::cin >> *n; // Tamanho do vetor que será alocado

	vet = criaVetor(*n); // alocar o vetor
	preencheVetor(vet, *n); // preencher o vetor
	imprimeVetor(vet, *n); // imprimir o vetor
	desalocaVetor(vet); // desalocar o vetor

	std::cout << "\n"; // pula linha

	// Desalocando todas as variáveis do programa
		delete n;

	return 0;
 }