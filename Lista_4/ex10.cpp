/*
 * Desenvolva um programa que contenha a classe Array, utilizando templates para
 * abstrair o tipo dos dados armazenado no vetor e seu tamanho. Esta classe deve
 * possuir um vetor estático de tipo e tamanho definidos pelos templates.
 */

#include <iostream>
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
			// metodo construtor
				Array(int tam);
				virtual ~Array(){ delete vetor; cout << "Apaga\n"; }
	};
	// metodo construtor usando template
		template < class T >
		Array< T >::Array(int tam) {
			tamanho = tam;
			vetor = new T[tamanho]; // criando vetor com o tamanho passado pelo parametro
			cout << "Vetor criado com sucesso!\n";
		}



int main(){
	// declarando e inicializando o variável de tamanho do vetor
	int tam;
		cout << "Digite o tamanho do vetor: ";
		cin >> tam;
	Array< int > vet(tam);

	return 0;
}