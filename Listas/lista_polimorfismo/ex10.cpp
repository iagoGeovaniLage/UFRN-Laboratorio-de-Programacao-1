/*
 * Desenvolva um programa que contenha a classe Array, utilizando templates para
 * abstrair o tipo dos dados armazenado no vetor e seu tamanho. Esta classe deve
 * possuir um vetor estático de tipo e tamanho definidos pelos templates.
 */

#include <iostream>
#include <cstdlib> // para usar o rand()
 
// inclusão de alguns namespaces
	using std::cout;
	using std::cin;

// declaração da classe Array com template
	template < class T >
	class Array {
		// parametros
			T *vetor;
			int tamanho;
		public:
			// contrutor e destrutor
				Array(int tam); // metodo construtor
				virtual ~Array(){ delete vetor; } // metodo destrutor

			// metodo para preencher o array
				void preenche() {
					// alocação de variável
				        T *min = new T;
				        *min = 0;
				    for (int i = 0; i < tamanho; ++i) {
					    srand(time(NULL));  
				        vetor[i] = *min + (rand() % 10);
				        *min = vetor[i];
				    }
				    // desalocação de variável
				        delete min;
				}
			// metodo para imprimir o array
				void imprimi() const { 
					for (int i = 0; i < tamanho; ++i){
						cout << vetor[i];
						if(i != tamanho-1)
							cout << ", ";
					}
					cout << ".\n";
				}
	};
	// metodo construtor usando template, cria o vetor e o inicializa através do metodo preenche()
		template < class T >
		Array< T >::Array(int tam) {
			tamanho = tam;
			vetor = new T[tamanho]; // criando vetor com o tamanho passado pelo parametro
			preenche();
		}

int main(){
	// declarando e inicializando o variável de tamanho do vetor
		int tam;
			cout << "Digite o tamanho do vetor: ";
			cin >> tam;
	Array< int > vet(tam); // instanciando um vetor da classe array
	vet.imprimi();

	return 0;
}