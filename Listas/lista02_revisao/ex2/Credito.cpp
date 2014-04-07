#include <iostream>
#include "Credito.h"
// Construstor Padrão
	Credito::Credito() {
		next = NULL;
	}
// Construto 
	Credito::Credito(float v) {
		valor = v;
		next = NULL;
	}
// Metódos SET
	void Credito::setNext(Credito * novo) {
		next = novo;
	}
// Metódos GET
	Credito * Credito::getNext() const {
		return next;
	}