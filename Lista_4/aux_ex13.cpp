#include <cstdlib> // para uso da função rand()

// funções auxiliares para os testes
	// Gera vetor aleatório genérico
		template < typename T>
		void geraArray(T v[], int N) {
		    // alocação de variável
		        T *min = new T;
		        *min = 0;
		    for (int i = 0; i < N; ++i) {
			    srand(time(NULL));  
		        v[i] = *min + (rand() % 10);
		        *min = v[i];
		    }
		    // desalocação de variável
		        delete min;
		}

	// gera elemento aleatório
		template <typename T>
		void geraElemento(int tam, T *v) {
	    	srand(time(NULL));  
			*v = rand() % tam;
		}

	// imprimi o vetor e elemento buscado, e o resultado da busca
		template <typename T >
		void imprimi(T v[], int tam, T elemento) {
			for (int i = 0; i < tam; i++ )
				cout << v[i] << " ";
			cout << "\n"; // pula linha
			
			if(buscaBinaria(v, tam, elemento))
				cout << "O elemento " << elemento << " foi encontrado!\n";
			else
				cout << "O elemento " << elemento << " não foi encontrado!\n";
		}
