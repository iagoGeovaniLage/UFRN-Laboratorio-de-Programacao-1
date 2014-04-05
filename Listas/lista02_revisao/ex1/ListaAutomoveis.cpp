#include <iostream>
#include "Automovel.h"
#include "ListaAutomoveis.h"

// alguns metódos do namespace std
	using std::cout;
	using std::cin;

// Construtor padrão
	ListaAutomoveis::ListaAutomoveis(){
		head = NULL;
	}
// Método para adicionar um elemento novo ao final da lista.
	void ListaAutomoveis::inserir (float k, float l) { 
        Automovel * novoAutomovel = new Automovel(k,l);
        if (head == NULL)
            head = novoAutomovel;
        else {
            Automovel * onde = head;
            while (onde->getNext())
                onde = onde->getNext();
            onde->setNext(novoAutomovel);
        }
		// mensagem falando do consumo cadastrado
			cout << "\nO consumo desse tanque foi de " << novoAutomovel->getConsumo() << "km/l.\n\n";
    }
// Método para imprimir, na saída padrão, todos os elementos na tela;
    void ListaAutomoveis::imprimir() const {
        Automovel * temp = head;
        int cont = 0;
        cout << "Consumo dos tanques:\n";
        while (temp) {
            cout << "\tTanque " << ++cont << ": " << temp->getConsumo() << "km/l.\n";
            temp = temp->getNext();
        }
        cout << "\n";
    }

// Método para calcular o consumo médio
    float ListaAutomoveis::consumoMedio() const {
        Automovel * temp = head;
        float cont = 0.0;
        float soma = 0.0;
        while(temp) {
            soma += temp->getConsumo();
            temp = temp->getNext();
            cont++;
        }
        return soma / cont++;
    }
