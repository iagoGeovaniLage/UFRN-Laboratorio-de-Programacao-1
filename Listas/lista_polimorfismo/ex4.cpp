/*
 * Crie uma classe Animal, e três subclasses Gato, Cachorro e Leão. Crie um método
 * na classe animal chamado emitir_Som() que deve se comportar diferente nas classe
 * Gato, Cachorro e Leão.
 */

#include <iostream>

// inclusão de alguns metodos do namespace std
	using std::cout;
	using std::cin;

// Declaração da Super Classe
	class Animal{
		public:
			virtual void emitir_Som() { cout << "Animal geral!\n"; }
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


// Programa Principal
	int main(){
		// alocação dinâmica dos vetores
			Gato *gato = new Gato;
			Cachorro *cachorro = new Cachorro;
			Leao *leao = new Leao;

		gato->emitir_Som();
		cachorro->emitir_Som();
		leao->emitir_Som();

		// desalocando as variáveis
			delete gato;
			delete cachorro;
			delete leao;

		return 0;	
	}