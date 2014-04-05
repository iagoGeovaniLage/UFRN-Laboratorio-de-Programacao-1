/*
 * Escreva um programa que calcula a soma de duas matrizes MxN de números reais (double).
 * A implementação deste programa deve considerar as dimensões fornecida pelo usuário. Obs:
 * represente a matriz através de variáveis do tipo double**, usando alocação dinâmica de
 * memória. Obs: lembre-se que diversas chamadas à função de alocação de memória devem ser
 * efetuadas para poder construir uma matriz.
 */
 
#include <iostream>
// inclusão de alguns metodos do namespace std
	using std::cout;
	using std::cin;

int main (){
	// Alocação das variáveis de controle
		int *lin = new int;
		int *col = new int;
		int *i   = new int;
		int *j   = new int;

	cout << "Digite o tamanho da linha da matriz: ";
	cin >> *lin; // entrada do tamanho da linha da matriz

	cout << "Digite o tamanho da coluna da matriz: ";
	cin >> *col; // entrada do tamanho da coluna da matriz

	// Alocação da matrizes
		double **mat1 = new double *[*lin];
		double **mat2 = new double *[*lin];
		double **matRes = new double *[*lin];
		for(*i = 0; *i < *lin; (*i)++){
			mat1[*i]   = new double[*col];
			mat2[*i]   = new double[*col];
			matRes[*i] = new double[*col];
		}

	// Entrada e soma das matrizes
		for(*i = 0; *i < *lin; (*i)++){
			for(*j = 0; *j < *col; (*j)++){
				cout << "Mat1 = [" << *i << "][" << *j << "] = ";
				cin >> mat1[*i][*j]; // entrada na matriz 1
				cout << "Mat2 = [" << *i << "][" << *j << "] = ";
				cin >> mat2[*i][*j]; // entrada na matriz 2
				matRes[*i][*j] = mat1[*i][*j] + mat2[*i][*j]; // Soma das matrizes
			}
		}

	// Impressão da matriz resultado
		for(*i = 0; *i < *lin; (*i)++){
			for(*j = 0; *j < *col; (*j)++){
				cout << "[" << *i << "][" << *j << "] = " << matRes[*i][*j] << " ";
			}
			cout << "\n"; // pula linha
		}

	// Desalocação de todas as variáveis
		delete lin;
		delete col;
		delete i;
		delete j;
		delete mat1;
		delete mat2;
		delete matRes;

	return 0;
 }