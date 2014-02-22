#include <iostream>

/*
 * Função 1 = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n...
 */
	float f1( float n ) {
		if( n == 1.0 )
			return 1.0;
		else
			return 1.0/n + f1(n-1.0);
	}

/*
 * Função 1 = 2/4 + 5/5 + 10/6 + 17/7 + ... + n²+1/n+3...
 */
	float f2( float n ) {
		if( n == 0.0 )
			return 0.0;
		else
			return ( ( n*n + 1.0 ) / ( n + 3.0 ) ) + f2(n-1.0);
	}

int  main() {
	float *n = new float; // alocação de uma variável ponto flutuante base para as funções

	std::cout << "Digite um número: ";
	std::cin >> *n; // leitura do número base

	std::cout << f1(*n) << "\n"; // chamada da função 1
	std::cout << f2(*n) << "\n"; // chamada da função 2

	delete n;

	return 0;
}