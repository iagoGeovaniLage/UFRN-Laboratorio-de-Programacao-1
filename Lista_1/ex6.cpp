/*
 * Escreva um programa que lê um valor n, cria dinamicamente um vetor de n elementos, e
 * passa esse vetor para uma função que vai ler os seus elementos. Depois, no programa
 * principal, o vetor preenchido deve ser impresso. Além disso, antes de finalizar o programa,
 * deve-se liberar a área de memória alocada.
 */

#include <iostream>
// inclusão de alguns metodos do namespace std
	using std::cout;
	using std::cin;

void preencheVet(int v[], int *n){
	// alocação da váriavel de controle de laço da função
		int *i = new int;
	// preenchendo o vetor
		for(*i =0; *i < *n; (*i)++)
			std::cin >> v[*i]; // entrada dos dados do vetor
	// desalocação da variável de controle de laço da função
		delete i;
}

int main (){
	// Alocação dinâmica das variáveis de controle
		int *n = new int;
		int *i = new int;

	cout << "Digite um indice para o vetor: ";
	cin >> *n; // Entrada do indice do vetor

	// Alocação do vetor de inteiros 
		int *vet = new int[*n];

	preencheVet(vet, n); // Chamada da função para preencher o vetor

	// impressão do vetor depois de preenchido na função
		for(*i =0; *i < *n; (*i)++)
			cout << "[" << *i << "] = " << vet[*i] << " ";
		cout << "\n";

	// Desalocação de todas as variáveis alocadas
		delete n;
		delete i;
		delete vet;

	return 0;
 }