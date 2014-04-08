#ifndef _CLIENTE_H_
	#define _CLIENTE_H_

		#include "Compra.h"
		#include "Credito.h"

		class Cliente{
			int conta;
			float saldo;

			Compra * primeiraCompra;
			float compras;

			Credito * primeiroCredito;
			float creditos;

			float limite;

			Cliente * next;

			public:
				static int qtd; // total de clientes
				// Construtor padrão
					Cliente();
				// Construtor com parâmetros
					Cliente(float s, float l);
				// Metódos SET
					void setNext(Cliente * novo);
				// Metódos GET
					int getConta() const;
					float getSaldoAtual() const;
					float getLimite() const;
					Cliente * getNext() const;
				// Metódo para verificar limite de crédito
					bool verificaCredito(float valor) const;
				// Metódo para inserir uma nova compra na lista
					void inserirCompra(float v);
				// Metódo para inserir um novo crédito na lista
					void inserirCredito(float v);
		};
#endif