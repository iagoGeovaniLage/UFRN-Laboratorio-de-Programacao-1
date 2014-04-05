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
			virtual void emitir_Som() { cout << "Animal geral!\n"; }
	};

// Declaração das sub-classes || todas herdadas da classe Animal
	class Gato : public Animal{
		public:
			virtual void emitir_Som(){ cout << "Miau!\n"; }
	};

	class Cachorro : public Animal{
		public:
			virtual void emitir_Som(){ cout << "Au Au!\n"; }
	};

	class Leao : public Animal{
		public:
			virtual void emitir_Som(){ cout << "Waarr!\n"; }
	};

// declaração da sub-classe zoologico
	class Zoologico {
		Animal *jaulas[10];
		static int total;
		public:
			void setJaulas(Animal *animal) {
				jaulas[total] = animal;
				total++;
			}
			void emitir_Som(){
				for (int i = 0; i < total; ++i)
					jaulas[i]->emitir_Som();
			}
	};
	int Zoologico::total = 0;


// Programa Principal
	int main(){
		// alocação dinâmica dos animais
			Animal *cat  = new Gato;
			Animal *leao = new Leao;
			Animal *dog  = new Cachorro;
		// criação do objeto zoologico
			Zoologico zoo;

		// Guardando os animais nas jaulas
			zoo.setJaulas(cat);
			zoo.setJaulas(leao);
			zoo.setJaulas(cat);
			zoo.setJaulas(dog);
			zoo.setJaulas(leao);
			zoo.setJaulas(dog);

		// percorrendo as jaulas para ver quais são os animais
			zoo.emitir_Som();

		// desalocando as variáveis
			delete cat;
			delete dog;
			delete leao;

		return 0;	
	}