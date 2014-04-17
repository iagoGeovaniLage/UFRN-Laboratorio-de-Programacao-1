#include <iostream>
#include "Lebre.h"

// Construtor padrão
	Lebre::Lebre() {
		posicao = 0;
	}

// Função que faz o movimento de um grande pulo
	void Lebre::GrandePulo() { posicao += 9; }
// Função que faz o movimento de uma grande escorregada
	void Lebre::GrandeEscorregada() {
		posicao -= 12;
		if(posicao < 0) posicao = 0;
	}
// Função que faz o movimento de um pulo pequeno
	void Lebre::PuloPequeno() { posicao++; }
// Função que faz o movimento de uma escorregada pequena
	void Lebre::EscorregadaPequena() {
		posicao -= 2;
		if(posicao < 0) posicao = 0;
	}
// Função responsável por determinar qual movimento será executado
	void Lebre::Movimento(int valor) {
		if(valor > 2 && valor <= 4)
			GrandePulo();
		else if(valor == 5)
			GrandeEscorregada();
		else if(valor > 5 && valor <= 8)
			PuloPequeno();
		else if(valor > 8)
			EscorregadaPequena();
	}
// metodos set
	int Lebre::getPosicao() const { return posicao; }