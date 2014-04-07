#include <iostream>
#include "Compra.h"
#include "Credito.h"
#include "Cliente.h"

using std::cout;

// quantidade total de cliente inicializando
	int Cliente::qtd = 0;

// Construtor Padrão
	Cliente::Cliente(){
		next = NULL;
	}
// Construtor com parâmetros
	Cliente::Cliente(float s, float l) {
		conta = ++qtd;
		saldo = s;
		limite = l;
	}
// Metódos SET
	void Cliente::setCompras(float c) { compras = c; }
	void Cliente::setCreditos(float c) { creditos = c; }
	void Cliente::setNext(Cliente * novo) { next = novo; }
// Metódos GET
	int Cliente::getConta() const{ return conta; }
	float Cliente::getSaldo() const{ return saldo; }
	float Cliente::getCompras() const { return compras; }
	float Cliente::getCreditos() const { return creditos; }
	float Cliente::getLimite() const { return limite; }
	Cliente * Cliente::getNext() const { return next; }
// Metódo para verificar limite de crédito
	void Cliente::verificaCredito() const {
		if((saldo + compras - creditos) > limite)
			cout << "O limite de crédito foi excedido!\n";
	}
// Metódo para inserir uma nova compra na lista
	void Cliente::inserirCompra(float v) {
		Compra * novo = new Compra(v);
		if(primeiraCompra == NULL)
			primeiraCompra = novo;
		else {
			Compra * onde = primeiraCompra;
			while(onde)
				onde = onde->getNext();
			onde->setNext(novo);
		}
	}
// Metódo para inserir um novo crédito na lista
	void Cliente::inserirCredito(float v) {
		Credito * novo = new Credito(v);
		if(primeiroCredito == NULL)
			primeiroCredito = novo;
		else {
			Credito * onde = primeiroCredito;
			while(onde)
				onde = onde->getNext();
			onde->setNext(novo);
		}
	}