#ifndef _COMPRA_H_
	#define _COMPRA_H_
		class Compra{
			float valor;
			Compra * next;
			public:
				// Construtor Padrão
					Compra();
				// Construtor com parâmetros
					Compra(float v);
				// Metódos SET
					void setNext(Compra * novo);
				// Metódos GET
					Compra * getNext() const;
		};
#endif