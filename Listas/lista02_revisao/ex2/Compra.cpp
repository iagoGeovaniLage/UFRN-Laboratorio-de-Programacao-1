#include <iostream>
#include "Compra.h"
// Construtor Padrão
	Compra::Compra() {
		next = NULL;
	}
// Construtor com parâmetros
	Compra::Compra(float v) {
		valor = v;
		next = NULL;
	}
// Metódos SET
	void Compra::setNext(Compra * novo) { next = novo; }
// Metódos GET
	Compra * Compra::getNext() const { return next; }