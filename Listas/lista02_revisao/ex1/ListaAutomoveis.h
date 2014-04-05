#ifndef _LISTAAUTOMOVEIS_H_
	#define _LISTAAUTOMOVEIS_H_
		// Inclusão da classe Automovel
			#include "Automovel.h"
		
		class ListaAutomoveis {
			Automovel * head; // aponta para o primeiro tanque listado
			public:	
				ListaAutomoveis();
				// Método para adicionar um elemento novo ao final da lista.
					void inserir (float k, float l);
				// Método para imprimir, na saída padrão, todos os elementos na tela;
			        void imprimir();
	 	};
#endif