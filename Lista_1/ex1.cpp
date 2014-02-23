/*
 * Escreva um programa que solicita ao usuário a quantidade de alunos de uma turma e aloca
 * um vetor de notas (números reais). Depois de ler as notas, imprime a média aritmética. Obs:
 * note que não deve ocorrer desperdício de memória, e após a utilização da memória, ela deve
 * ser liberada.
 */

#include <iostream>

int main (){
	// Alocação das variáveis
		int   *qtd   = new int;
		int	  *i     = new int;
		float *media = new float;

	*media = 0; // Inicialização da variável usada na média aritmética

	std::cout << "Digite a quantidade de alunos: ";
	std::cin >> *qtd; // Entrada da quantidade de alunos 
	
	float *notas = new float[*qtd]; // Alocação dinâmica para o vetor de notas dos alunos

	// Laço para preencher o vetor de notas dos alunos
		for(*i = 0; *i < *qtd; (*i)++){
		 	std::cin >> notas[*i]; // Entrada das notas
		 	*media += notas[*i]; // soma todas as notas dos alunos para fazer a média aritmética pela quantidade de alunos
		}
	*media /= *qtd; // cálculo da média aritmética

	std::cout << "A média da turma é: " << *media << std::endl; // saída da média da turma

	// Desalocando todas as variáveis do programa
		delete qtd;
		delete i;
		delete media;
		delete notas;

	return 0;
 }