/*
 * Crie uma classe Animal, e três subclasses Gato, Cachorro e Leão. Crie um método
 * na classe animal chamado emitir_Som() que deve se comportar diferente nas classe
 * Gato, Cachorro e Leão.
 */

#include <iostream>

// Declaração da Super Classe
	class Animal{
		public:
			void emitir_Som() { std::cout << "Animal geral!\n"; }
	};

// Declaração das sub-classes || todas herdadas da classe Animal
	class Gato : public Animal{
		public:
			void emitir_Som(){ std::cout << "Miau!\n"; }
	};

	class Cachorro : public Animal{
		public:
			void emitir_Som(){ std::cout << "Au Au!\n"; }
	};

	class Leao : public Animal{
		public:
			void emitir_Som(){ std::cout << "Waarr!\n"; }
	};


// Programa Principal
	int main(){
		// alocação dinâmica dos vetores
			Animal *animal = new Animal;
			Gato *gato = new Gato;
			Cachorro *cachorro = new Cachorro;
			Leao *leao = new Leao;

		animal->emitir_Som();
		gato->emitir_Som();
		cachorro->emitir_Som();
		leao->emitir_Som();

		// desalocando as variáveis
			delete gato;
			delete cachorro;
			delete leao;

		return 0;	
	}