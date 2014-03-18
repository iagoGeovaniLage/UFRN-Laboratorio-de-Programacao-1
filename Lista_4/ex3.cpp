/*
 * Escreva uma versão melhorada do Insertion Sort que tenha a capacidade de
 * ordenar diferentes tipos de array. Utilize a função da questão 2 para auxiliar no
 * desenvolvimento.
 */

#include <iostream>

// Criação de uma função usando esse tipo genérico de variável
	template <typename Tipo>
	int Compare(Tipo a, Tipo b) { 
		if ( a == b ) return 0;
		else if( a > b ) return 1;
		else return -1;
	}
// Insertion Sort
	template <typename Tipo>
	void insertionSort(Tipo v[], int n){
		// alocação das váriaveis
			int *i   = new int;
			int *j   = new int;
			Tipo *key = new Tipo;

		//ordenação
            for (*i = 1; *i < n; (*i)++) {
                // considera o elemento i removido de A
                    *key = v[*i];
                    *j = *i - 1;
                while (*j >= 0 && (Compare(v[*j],*key) == 1)){
                    // deslocando os elementos em B
                        v[*j+1] = v[*j];
                        (*j)--;
                }
                // insere o elemento na posição ordenada em B
                    v[*j+1] = *key;
            }

		// desalocação das váriaveis
			delete i;
			delete j;
			delete key;
	}

// função para imprimir vetor
	template <typename Tipo>
	void imprimiVet(Tipo v[], int tam, int tipo){
		if(tipo == 1)
			std::cout << "Vetor antes da ordenação: ";
		else
			std::cout << "Vetor depois da ordenação: ";
		for (int i = 0; i < tam; ++i){
			std::cout << v[i];
			if(i != tam-1)
				std::cout << ", ";
		}
		std::cout << "\n";
	}


// Programa Principal
	int main(){
		// alocação dinâmica dos vetores
			// tipo Int
				int *v1 = new int[10];
			// tipo Float
				float *v2 = new float[10];
			// tipo char
				char *v3 = new char[10];
		// inicialização dos vetores
			v1[0] = 1; v1[1] = 5; v1[2] = 2; v1[3] = 3; v1[4] = 4; v1[5] = 6; v1[6] = 9; v1[7] = 0; v1[8] = 7; v1[9] = 8;
			v2[0] = 1.1; v2[1] = 5.4; v2[2] = 2.0; v2[3] = 2.3; v2[4] = 4.1; v2[5] = 6.0; v2[6] = 9.2; v2[7] = 0.0; v2[8] = 7.2; v2[9] = 7.8;
			v3[0] = 'z'; v3[1] = 'c'; v3[2] = 'a'; v3[3] = 'b'; v3[4] = 'd'; v3[5] = 'e'; v3[6] = 'h'; v3[7] = 'o'; v3[8] = 'p'; v3[9] = 'f';

		// testes ordenação
			// inteiros
				imprimiVet(v1, 10, 1);
				insertionSort(v1, 10);
				imprimiVet(v1, 10, 0);
			std::cout << "\n"; // pula linha

			// ponto flutuantes
				imprimiVet(v2, 10, 1);
				insertionSort(v2, 10);
				imprimiVet(v2, 10, 0);
			std::cout << "\n"; // pula linha

			// caracteres
				imprimiVet(v3,10, 1);
				insertionSort(v3, 10);
				imprimiVet(v3,10, 0);
			std::cout << "\n"; // pula linha

		// desalocando as variáveis
			delete v1;
			delete v2;
			delete v3;

		return 0;	
	}