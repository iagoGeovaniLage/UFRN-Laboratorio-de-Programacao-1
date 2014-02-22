/*
 * Escreva uma sub-rotina de forma iterativa e usando recursão de cauda
 * para transformar um valor inteiro não-negativo em binário.
 * A sub-rotina deve receber um valor inteiro e enviar para a saída padrão os 0s e 1s
 * correspondentes ao valor passado em binário.
 */

#include <iostream>

// Função de exponenciação, será usada na conversão
	long int pow(long int n, long int exp) {
		if(exp == 0) 
			return 1;
		else
			return n * pow(n,exp-1);
	}

// Conversão de número n da base decimal para base binária com recursão de cauda
	long int converteBin_Cauda(long int n, long int i, long int res) {
		if(n == 0) // Caso Base
			return res;
		else
			return converteBin_Cauda(n/2, i+1, res + (( n % 2 ) * pow(10,i))); // recursão de cauda
	}

// Conversão de número n da base decimal para base binária com recursão de cauda
	long int converteBin_Iterativa(long int n, long int i) {
		long int result = 0;
		while(n != 0){
			result += (( n % 2 ) * pow(10,i));
			n /= 2;
			i++;
		}
		return result;
	}

int  main() {
	long int *n = new long int; // alocação de uma variável inteira para conversão

	std::cout << "Digite um número para conversão: ";
	std::cin >> *n; // leitura do número para conversão
	if(*n >= 0){
		std::cout << *n << " na base 2 é: ";
		std::cout << converteBin_Cauda(*n, 0, 0); // chamada da função de conversão
		std::cout << "\n"; // pula uma linha
		std::cout << converteBin_Iterativa(*n, 0); // chamada da função de conversão
	} else {
		std::cout << "O número tem que ser positivo";
	}
	std::cout << "\n"; // pula linha

	delete n; // desalocação da váriavel

	return 0;
}