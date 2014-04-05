#include <iostream>
#include "Automovel.h"

// construtor padrão
	Automovel::Automovel()	{ next = NULL; }

// Construtor com parâmetro
	Automovel::Automovel(float k, float l){
		km      = k;
		litros  = l;
		consumo = km / litros;
		next = NULL;
	}

// metodos set
	void Automovel::setNext(Automovel * novo){
		next = novo;
	}

// metodos get
	float Automovel::getConsumo() const { 
		return consumo; 
	}
	
	Automovel * Automovel::getNext() const { 
		return next; 
	}