#ifndef _CLIENTES_H_
	#define _CLIENTES_H_

		#include "Cliente.h"

		class Clientes {
			Cliente * head;
			public:
				// Metódo para inserir um novo crédito na lista
					void inserir(float s, float l);
				// Metódo para imprimir, na saída padrão, todos os clientes
					void listarClientes() const;
				// Metódo para buscar um cliente
					Cliente * buscarCliente(int conta) const;
		};
#endif