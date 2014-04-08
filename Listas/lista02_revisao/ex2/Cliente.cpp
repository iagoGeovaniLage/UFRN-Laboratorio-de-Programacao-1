#include <iostream>
#include <cstdlib> // para uso da função system()
#include "Compra.h"
#include "Credito.h"
#include "Cliente.h"

using std::cout;

// quantidade total de cliente inicializando
	int Cliente::qtd = 0;

// Construtor Padrão
	Cliente::Cliente(){
		conta = 0;
		saldo = 0;
		primeiraCompra = NULL;
		compras = 0;
		primeiroCredito = NULL;
		creditos = 0;
		limite = 0;
		next = NULL;
	}
// Construtor com parâmetros
	Cliente::Cliente(float s, float l) {
		conta = ++qtd;
		saldo = s;
		primeiraCompra = NULL;
		compras = 0;
		primeiroCredito = NULL;
		creditos = 0;
		limite = l;
		next = NULL;
	}
// Metódos SET
	void Cliente::setNext(Cliente * novo) { next = novo; }
// Metódos GET
	int Cliente::getConta() const{ return conta; }
	float Cliente::getSaldoAtual() const{ return saldo + compras - creditos; }
	float Cliente::getLimite() const { return limite; }
	Cliente * Cliente::getNext() const { return next; }
// Metódo para verificar limite de crédito
	bool Cliente::verificaCredito(float valor) const {
		if( (getSaldoAtual() + valor) > limite )
			return true;
		else
			return false;
	}
// Metódo para inserir uma nova compra na lista
	void Cliente::inserirCompra(float v) {
		if(verificaCredito(v)){
			system("clear");
			cout << "O limite de crédito foi excedido!\n";
			cout << "O Saldo com a compra seria " << getSaldoAtual() + v << " e o limite é " << getLimite() << ".\n";
		} else {
			Compra * novo = new Compra(v);
			compras += v;
			if(primeiraCompra == NULL) {
				primeiraCompra = novo;
			} else {
				Compra * onde = primeiraCompra;
				while(onde)
					onde = onde->getNext();
				onde->setNext(novo);
			}
			cout << "A compra foi realizada com sucesso!\n";
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
		limite += v;
		cout << "Valor creditado com sucesso!\n";
	}