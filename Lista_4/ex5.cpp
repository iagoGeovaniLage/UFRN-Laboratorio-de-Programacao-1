/*
 * Aproveitando o código do exercício 4, crie uma classe Zoologico, com 10 jaulas,
 * coloque em cada jaula um animal diferente, percorra cada jaula e emita o som do
 * animal.
 */

#include <iostream>

using std::cout;
using std::cin;

// Declaração da Super Classe
	class Animal{
		public:
			void emitir_Som() { cout << "Animal geral!\n"; }
	};

// Declaração das sub-classes || todas herdadas da classe Animal
	class Gato : public Animal{
		public:
			void emitir_Som(){ cout << "Miau!\n"; }
	};

	class Cachorro : public Animal{
		public:
			void emitir_Som(){ cout << "Au Au!\n"; }
	};

	class Leao : public Animal{
		public:
			void emitir_Som(){ cout << "Waarr!\n"; }
	};

// declaração da sub-classe zoologico
	class Zoologico {
		static int total;
		public:
			void setJaulas(Animal animal) {
				jaulas[total] = animal;
				total++;
			}
			void emitir_Som(){
				for (int i = 0; i < total; ++i)
					jaulas[i].emitir_Som();
			}
	};
	int Zoologico::total = 0;


// Programa Principal
	int main(){
		// alocação dinâmica dos vetores
			Gato cat1, cat2, cat3;
			Animal dog1, dog2, dog3, dog4;
			Leao leao1, leao2, leao3;

		Zoologico zoo;

		// desalocando as variáveis

		return 0;	
	}