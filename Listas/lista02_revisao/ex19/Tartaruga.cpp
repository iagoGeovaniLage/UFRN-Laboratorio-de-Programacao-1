#include <iostream>
#include "Tartaruga.h"
 // construtor padrão
	Tartaruga::Tartaruga() {
		posicao = 0;
	}
// Função que faz o movimento de uma caminhada rapida
	void Tartaruga::CaminhadaRapida() { posicao += 3; }
// Função que faz o movimento de uma escorregada
	void Tartaruga::Escorregada() { 
		posicao -= 6;
		if(posicao < 0) posicao = 0;
	}
// Função que faz o movimento de uma caminhada lenta
	void Tartaruga::CaminhadaLenta() {  posicao++; }
// Função responsável por determinar qual movimento será executado
	void Tartaruga::Movimento(int valor) {
		if(valor <= 5)
			CaminhadaRapida();
		else if(valor > 5 && valor <= 7)
			Escorregada();
		else if(valor > 7)
			CaminhadaLenta();
	}
// metodos set
	int Tartaruga::getPosicao() const { return posicao; }