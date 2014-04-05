/*
 * Escreva uma sub-rotina recursiva para transformar um valor inteiro não-negativo em binário.
 * A sub-rotina deve receber um valor inteiro e enviar para a saída padrão os 0s e 1s
 * correspondentes ao valor passado em binário.
 */

#include <iostream>
// inclusão de alguns metodos do namespace std
	using std::cout;
	using std::cin;

// Função de exponenciação, será usada na conversão.
	long int pow(long int n, long int exp) {
		if(exp == 0) 
			return 1;
		else
			return n * pow(n,exp-1);
	}

// Conversão de número n da base decimal para base binária.
	long int converteBinario(long int n, long int i) {
		if(n == 0) // Caso Base
			return 0;
		else
			return (( n % 2 ) * pow(10,i)) + converteBinario(n/2, i+1);
	}

int  main() {
	long int *n = new long int; // alocação de uma variável inteira para conversão

	cout << "Digite um número para conversão: ";
	cin >> *n; // leitura do número para conversão
	if(*n >= 0) {
		cout << *n << " na base 2 é: ";
		cout << converteBinario(*n, 0); // chamada da função de conversão
	} else {
		cout << "O número tem que ser positivo";
	}
	cout << "\n"; // pula linha

	delete n; // desalocação da váriavel

	return 0;
}