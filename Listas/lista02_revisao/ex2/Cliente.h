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

			static int qtd; // total de clientes
			public:
				// Construtor padrão
					Cliente();
				// Construtor com parâmetros
					Cliente(float s, float l);
				// Metódos SET
					void setCompras(float c);
					void setCreditos(float c);
					void setNext(Cliente * novo);
				// Metódos GET
					int getConta() const;
					float getSaldo() const;
					float getCompras() const;
					float getCreditos() const;
					float getLimite() const;
					Cliente * getNext() const;
				// Metódo para verificar limite de crédito
					void verificaCredito() const;
				// Metódo para inserir uma nova compra na lista
					void inserirCompra(float v);
				// Metódo para inserir um novo crédito na lista
					void inserirCredito(float v);
		};
#endif